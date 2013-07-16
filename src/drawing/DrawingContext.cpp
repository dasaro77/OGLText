/*
 * DrawingContext.cpp
 *
 *  Created on: Jul 16, 2013
 *      Author: drom
 */

#include <gl/gl.h>

#include "DrawingContext.h"

DrawingContext::DrawingContext() {
  this->lineWidth = 1;
  this->lineR = this->lineG = this->lineB = 0;
  this->fillR = this->fillG = this->fillB = 0;
}

DrawingContext::~DrawingContext() {
  // TODO Auto-generated destructor stub
}

void DrawingContext::drawRectangleUnfilledWithBorder(GLfloat x, GLfloat y, GLfloat width, GLfloat height) {
  glLineWidth(lineWidth);
  glColor3f(lineR, lineG, lineB);
  drawRectangle(GL_LINE_LOOP, x, y, width, height);
}

void DrawingContext::drawRectangleFilled(GLfloat x, GLfloat y, GLfloat width, GLfloat height) {
  glLineWidth(0);
  glColor3f(fillR, fillG, fillB);
  drawRectangle(GL_QUADS, x, y, width, height);
}

void DrawingContext::drawRectangleFilledWithBorder(GLfloat x, GLfloat y, GLfloat width, GLfloat height) {
  glLineWidth(0);
  glColor3f(fillR, fillG, fillB);
  drawRectangle(GL_QUADS, x, y, width, height);

  glLineWidth(lineWidth);
  glColor3f(lineR, lineG, lineB);
  drawRectangle(GL_LINE_LOOP, x, y, width, height);
}

void DrawingContext::setLineWidth(GLfloat width) {
  this->lineWidth = width;
}

void DrawingContext::setLine(GLfloat width, GLfloat r, GLfloat g, GLfloat b) {
  this->lineWidth = width;
  this->lineR = r;
  this->lineG = g;
  this->lineB = b;
}

void DrawingContext::setFill(GLfloat r, GLfloat g, GLfloat b) {
  this->fillR = r;
  this->fillG = g;
  this->fillB = b;
}

void DrawingContext::drawRectangle(GLenum mode, GLfloat x, GLfloat y, GLfloat width, GLfloat height) {
  glBegin(mode);
  glVertex2d(x, y);
  glVertex2d(x + width, y);
  glVertex2d(x + width, y - height);
  glVertex2d(x, y - height);
  glEnd();
}
