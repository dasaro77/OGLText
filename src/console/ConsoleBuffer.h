/*
 * ConsoleBuffer.h
 *
 *  Created on: Jul 15, 2013
 *      Author: drom
 */

#ifndef CONSOLEBUFFER_H_
#define CONSOLEBUFFER_H_

#include <console/TypeSetMetadata.h>
#include <console/BufferLine.h>
#include <GL/gl.h>
#include <deque>

class ConsoleBuffer {

private:

  unsigned maxSize;
  std::deque<BufferLine*> lines;
  TypeSetMetadata typeSetMetadata;

public:

  ConsoleBuffer(unsigned maxSize);
  ~ConsoleBuffer();

  void output(GLfloat x, GLfloat y, GLfloat width, GLfloat height);
  unsigned int size();
  BufferLine* getCurrentLine();
  BufferLine* getLine(unsigned int index);
  void newLine();
  void deleteForwardFromCurrentLine();
  void deleteBackwardFromCurrentLine();
  void addToEndOfCurrentLine(char input);
  TypeSetMetadata* getTypeSetMetadata();

};

#endif /* CONSOLEBUFFER_H_ */
