/*
 * ConsoleBuffer.cpp
 *
 *  Created on: Jul 15, 2013
 *      Author: drom
 */

#include <console/ConsoleBuffer.h>

ConsoleBuffer::ConsoleBuffer(unsigned maxSize) {
  this->maxSize = maxSize;

  // Guarantee that at least one line exists
  newLine();
}

ConsoleBuffer::~ConsoleBuffer() {
  for(size_t i = 0; i < lines.size(); ++i) {
    delete lines[i];
  }
}

unsigned int ConsoleBuffer::size() {
  return lines.size();
}

BufferLine* ConsoleBuffer::getCurrentLine() {
  if(lines.empty()) {
    newLine();
  }

  return lines.back();
}

BufferLine* ConsoleBuffer::getLine(unsigned int index) {
  if(index >= lines.size()) {
    return NULL;
  }

  return lines[index];
}

void ConsoleBuffer::newLine() {
  lines.push_back(new BufferLine());

  if(lines.size() > maxSize) {
    delete lines.front();
    lines.pop_front();
  }
}

void ConsoleBuffer::deleteForwardFromCurrentLine() {
  // TODO This makes no sense right now, so do nothing!
}

void ConsoleBuffer::deleteBackwardFromCurrentLine() {
  getCurrentLine()->deleteLastChar();
}

void ConsoleBuffer::output(GLfloat x, GLfloat y, GLfloat width, GLfloat height) {
  // Render all but the active line
  for(size_t i = 0; i < lines.size(); ++i) {
    lines[i]->draw(typeSetMetadata, x, y - 20*i, i == lines.size() - 1);
  }
}

TypeSetMetadata* ConsoleBuffer::getTypeSetMetadata() {
  return &typeSetMetadata;
}

void ConsoleBuffer::addToEndOfCurrentLine(char input) {
  getCurrentLine()->append(input);
}
