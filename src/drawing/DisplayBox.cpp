/*
 * DisplayBox.cpp
 *
 *  Created on: Jul 17, 2013
 *      Author: drom
 */

#include <drawing/DisplayBox.h>
#include <drawing/DrawingContext.h>
#include <GL/gl.h>
#include <key_handlers/IKeyHandler.h>

DisplayBox::DisplayBox(DrawingContext* context) {
  this->x = this->y = this->width = this->height = 0;
  this->context = context;
  this->keyHandler = NULL;
}

DisplayBox::~DisplayBox() {
  // Don't destroy context or keyhandler here since others provided it
}

void DisplayBox::setLocation(GLfloat x, GLfloat y) {
  this->x = x;
  this->y = y;
}

void DisplayBox::setSize(GLfloat width, GLfloat height) {
  this->width = width;
  this->height = height;
}

void DisplayBox::draw() {
  // Draw border and background of the console
  glPushMatrix();
  context->setLine(2, 1, 0, 0);
  context->setFill(0.25, 0, 0);
  context->drawRectangleFilledWithBorder(x, y, width, height);
  glPopMatrix();
}

bool DisplayBox::handleKey(unsigned char key) {
  if(keyHandler) {
    return keyHandler->handleKey(key);
  }

  return false;
}

void DisplayBox::moveY(GLfloat delta) {
  y += delta;
}

void DisplayBox::moveX(GLfloat delta) {
  x += delta;
}

GLfloat DisplayBox::getX() {
  return x;
}

GLfloat DisplayBox::getY() {
  return y;
}

GLfloat DisplayBox::getWidth() {
  return width;
}

GLfloat DisplayBox::getHeight() {
  return height;
}

void DisplayBox::setKeyHandler(IKeyHandler* keyHandler) {
  this->keyHandler = keyHandler;
}
