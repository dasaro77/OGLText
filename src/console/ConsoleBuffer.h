/*
 * ConsoleBuffer.h
 *
 *  Created on: Jul 15, 2013
 *      Author: drom
 */

#ifndef CONSOLEBUFFER_H_
#define CONSOLEBUFFER_H_

#include <console/TypeSetMetadata.h>
#include <GL/gl.h>
#include <deque>
#include <string>

class BufferLine;
class IOutputer;

using std::string;
using std::deque;

class ConsoleBuffer {

private:

  unsigned maxSize;
  deque<BufferLine*> lines;
  TypeSetMetadata typeSetMetadata;

public:

  ConsoleBuffer(unsigned maxSize);
  ~ConsoleBuffer();

  void output(GLfloat x, GLfloat y, GLfloat width, GLfloat height);
  BufferLine* getCurrentLine();
  void newLine();
  void deleteForwardFromCurrentLine();
  void deleteBackwardFromCurrentLine();
  void addToEndOfCurrentLine(char input);
  TypeSetMetadata* getTypeSetMetadata();

};

#endif /* CONSOLEBUFFER_H_ */
