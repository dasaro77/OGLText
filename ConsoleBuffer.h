/*
 * ConsoleBuffer.h
 *
 *  Created on: Jul 15, 2013
 *      Author: drom
 */

#ifndef CONSOLEBUFFER_H_
#define CONSOLEBUFFER_H_

#include <string>
#include <deque>

#include "IOutputer.h"

using std::string;
using std::deque;

class ConsoleBuffer {

private:

  IOutputer* outputer;
  unsigned maxSize;
  deque<string*> lines;

public:

  ConsoleBuffer(IOutputer* outputer, unsigned maxSize);
  ~ConsoleBuffer();

  void output();
  string* getCurrentLine();
  void newLine();
  void deleteForwardFromCurrentLine();
  void deleteBackwardFromCurrentLine();
  void addToEndOfCurrentLine(char input);

};

#endif /* CONSOLEBUFFER_H_ */
