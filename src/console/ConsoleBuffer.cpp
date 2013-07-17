/*
 * ConsoleBuffer.cpp
 *
 *  Created on: Jul 15, 2013
 *      Author: drom
 */

#include <console/ConsoleBuffer.h>
#include <GL/gl.h>
#include <outputers/IOutputer.h>
#include <outputers/QTextOutputer.h>
#include <cstddef>
#include <deque>
#include <new>
#include <string>

ConsoleBuffer::ConsoleBuffer(unsigned maxSize) {
  this->outputer = new QTextOutputer(-20);
  this->maxSize = maxSize;
}

ConsoleBuffer::~ConsoleBuffer() {
  for(size_t i = 0; i < lines.size(); ++i) {
    delete lines[i];
  }
}

string* ConsoleBuffer::getCurrentLine() {
  if(lines.empty()) {
    newLine();
  }

  return lines.back();
}

void ConsoleBuffer::newLine() {
  lines.push_back(new string());

  if(lines.size() > maxSize) {
    delete lines.front();
    lines.pop_front();
  }
}

void ConsoleBuffer::deleteForwardFromCurrentLine() {
  // TODO This makes no sense right now, so do nothing!
}

void ConsoleBuffer::deleteBackwardFromCurrentLine() {
  string* line = getCurrentLine();
  if(line->size() > 0) {
    line->erase(line->size() - 1);
  }
}

void ConsoleBuffer::output(GLfloat x, GLfloat y, GLfloat width, GLfloat height) {
  outputer->move(x, y);

  // Render all but the active line
  for(size_t i = 0; i + 1 < lines.size(); ++i) {
    outputer->output(i, lines[i]);
  }

  // Render the active line with a cursor at the end
  // TODO Allow cursor to be moved w/in the line
  string currentLineForOutput = *getCurrentLine() + string("_");
  outputer->output(lines.size() - 1, &currentLineForOutput);
}

void ConsoleBuffer::addToEndOfCurrentLine(char input) {
  (*getCurrentLine()) += input;
}
