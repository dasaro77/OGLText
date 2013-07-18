/*
 * BufferLine.h
 *
 *  Created on: Jul 17, 2013
 *      Author: drom
 */

#ifndef BUFFERLINE_H_
#define BUFFERLINE_H_

#include <GL/gl.h>
#include <string>

class TypeSetMetadata;

using std::string;

class BufferLine {

private:

  enum Justification { JUST_LEFT, JUST_RIGHT };

  string text;
  Justification justification;
  GLfloat r, g, b, lineWidth;

public:

  BufferLine();
  virtual ~BufferLine();

  void draw(TypeSetMetadata tsm, GLfloat x, GLfloat y, bool isCurrent);

  void setText(const string& text);
  void setColor(GLfloat r, GLfloat g, GLfloat b);
  void setLineWidth(GLfloat lineWidth);
  void justifyLeft();
  void justifyRight();

  const string& getText();

  void append(unsigned char letter);
  void deleteLastChar();

};

#endif /* BUFFERLINE_H_ */
