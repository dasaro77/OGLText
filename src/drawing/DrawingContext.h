/*
 * DrawingContext.h
 *
 *  Created on: Jul 16, 2013
 *      Author: drom
 */

#ifndef DRAWINGCONTEXT_H_
#define DRAWINGCONTEXT_H_

#include <gl/gl.h>

class DrawingContext {

private:

  GLfloat lineWidth, lineR, lineG, lineB;
  GLfloat fillR, fillG, fillB;

public:
  DrawingContext();
  virtual ~DrawingContext();

  void setLineWidth(GLfloat width);
  void setLine(GLfloat width, GLfloat r, GLfloat g, GLfloat b);
  void setFill(GLfloat r, GLfloat g, GLfloat b);

  void drawRectangleUnfilledWithBorder(GLfloat x, GLfloat y, GLfloat width, GLfloat height);
  void drawRectangleFilled(GLfloat x, GLfloat y, GLfloat width, GLfloat height);
  void drawRectangleFilledWithBorder(GLfloat x, GLfloat y, GLfloat width, GLfloat height);


protected:

  void drawRectangle(GLenum mode, GLfloat x, GLfloat y, GLfloat width, GLfloat height);

};

#endif /* DRAWINGCONTEXT_H_ */
