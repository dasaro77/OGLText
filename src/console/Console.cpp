/*
 * Console.cpp
 *
 *  Created on: Jul 16, 2013
 *      Author: drom
 */

#include <console/Console.h>
#include <console/ConsoleBuffer.h>
#include <console/SimpleSetAction.h>
#include <console/TypeSetMetadata.h>
#include <drawing/DisplayBox.h>
#include <GL/gl.h>
#include <key_handlers/ConsoleKeyHandler.h>
#include <key_handlers/IKeyHandler.h>
#include <StringUtil.h>
#include <map>
#include <new>
#include <string>
#include <utility>
#include <vector>

class DrawingContext;

Console::Console(DrawingContext* context) : DisplayBox(context) {
  this->buffer = new ConsoleBuffer(11);
  this->loadedBufferLine = -1;

  setKeyHandler(new ConsoleKeyHandler(this, buffer));

  // Default display box stylings
  setLine(2, 1, 0, 0);
  setFill(0.25, 0, 0);

  // Bind typeset config into basic language
  basicLanguage["yild"] = new SimpleSetAction<TypeSetMetadata>(
      buffer->getTypeSetMetadata(),
      &TypeSetMetadata::setYild);

  basicLanguage["strokeScale"] = new SimpleSetAction<TypeSetMetadata>(
      buffer->getTypeSetMetadata(),
      &TypeSetMetadata::setStrokeScale);

  basicLanguage["reset"] = new SimpleSetAction<TypeSetMetadata>(
      buffer->getTypeSetMetadata(),
      &TypeSetMetadata::reset);
}

Console::~Console() {
  delete buffer;
}

void Console::draw() {
  DisplayBox::draw();

  // Draw the text content of the console
  glPushMatrix();

  // TODO Deltas are very much magic numbers :-(  not sure why this is necessary yet
  buffer->output(getX() + 15, getY() - 50, getWidth() - 15, getHeight() + 50);

  glPopMatrix();
}

void Console::execute(const string& line) {
  vector<string> parts = StringUtil::split(line, ' ');
  if(parts.size() > 0) {
    string command = parts[0];
    IAction* action = basicLanguage[command];
    if(action) {
      string param;
      if(parts.size() > 1) {
        param = parts[1];
      }
      else {
        param = "";
      }

      action->execute(param);
    }
  }
}

void Console::newLine() {
  this->loadedBufferLine = -1;
  buffer->newLine();
}

void Console::loadOlderBufferLine() {
  if(loadedBufferLine < 0) {
    this->tempCurrentLineText = buffer->getCurrentLine()->getText();
    loadedBufferLine = buffer->size() - 1;
  }

  loadBufferLine(--loadedBufferLine) || ++loadedBufferLine;
}

void Console::loadNewerBufferLine() {
  if(loadedBufferLine < 0) {
    // Can't move to a newer buffer if we've never navigated back at all
    return;
  }

  loadBufferLine(++loadedBufferLine) || --loadedBufferLine;
}

bool Console::loadBufferLine(unsigned int index) {
  if(index == buffer->size() - 1) {
    // When navigating back to the current line, reset buffer navigator completely
    buffer->getCurrentLine()->setText(tempCurrentLineText);
    loadedBufferLine = -1;
    return false;
  }

  BufferLine* line = buffer->getLine(index);
  if(line != NULL) {
    buffer->getCurrentLine()->setText(line->getText());
    return true;
  }

  return false;
}
