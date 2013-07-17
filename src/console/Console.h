/*
 * Console.h
 *
 *  Created on: Jul 16, 2013
 *      Author: drom
 */

#ifndef CONSOLE_H_
#define CONSOLE_H_

#include <GL/gl.h>

class ConsoleBuffer;
class ConsoleKeyHandler;
class DrawingContext;
class IOutputer;

class Console {

private:

  GLfloat x, y, width, height;

  DrawingContext* context;
  ConsoleBuffer* buffer;
  ConsoleKeyHandler* keyHandler;

public:

  Console(DrawingContext* context);
  virtual ~Console();

  void setLocation(GLfloat x, GLfloat y);
  void setSize(GLfloat width, GLfloat height);
  void moveY(GLfloat delta);
  void moveX(GLfloat delta);

  void draw();
  bool handleKey(unsigned char key);

};

#endif /* CONSOLE_H_ */
