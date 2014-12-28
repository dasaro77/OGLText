/*
 * DisplayBox.h
 *
 *  Created on: Jul 17, 2013
 *      Author: drom
 */

#ifndef DISPLAYBOX_H_
#define DISPLAYBOX_H_

#include <GL/gl.h>

class DrawingContext;
class IKeyHandler;

class DisplayBox {

private:

  GLfloat x, y, width, height;

  GLfloat lineWidth;
  GLfloat lineR, lineG, lineB;

  bool drawFill;
  GLfloat fillR, fillG, fillB;

  DrawingContext* context;
  IKeyHandler* keyHandler;

public:

  DisplayBox(DrawingContext* context);
  virtual ~DisplayBox();

  GLfloat getX();
  GLfloat getY();
  GLfloat getWidth();
  GLfloat getHeight();

  void setLocation(GLfloat x, GLfloat y);
  void setSize(GLfloat width, GLfloat height);
  void moveY(GLfloat delta);
  void moveX(GLfloat delta);

  void setLine(GLfloat width, GLfloat r, GLfloat g, GLfloat b);
  void setFill(GLfloat r, GLfloat g, GLfloat b);

  void draw();
  bool handleKey(unsigned char key);

protected:

  void setKeyHandler(IKeyHandler* keyHandler);
  DrawingContext* getContext();

};

#endif /* DISPLAYBOX_H_ */
