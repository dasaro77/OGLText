/*
 * ConsoleBuffer.cpp
 *
 *  Created on: Jul 15, 2013
 *      Author: drom
 */

#include "console/ConsoleBuffer.h"

ConsoleBuffer::ConsoleBuffer(IOutputer* outputer, unsigned maxSize) {
  this->outputer = outputer;
  this->maxSize = 10;
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

void ConsoleBuffer::output() {
  for(size_t i = 0; i < lines.size(); ++i) {
    outputer->output(i, lines[i]);
  }
}

void ConsoleBuffer::addToEndOfCurrentLine(char input) {
  (*getCurrentLine()) += input;
}
