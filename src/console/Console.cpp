/*
 * Console.cpp
 *
 *  Created on: Jul 16, 2013
 *      Author: drom
 */

#include <console/Console.h>
#include <console/ConsoleBuffer.h>
#include <drawing/DrawingContext.h>
#include <GL/gl.h>
#include <key_handlers/ConsoleKeyHandler.h>
#include <outputers/QTextOutputer.h>
#include <new>

Console::Console(DrawingContext* context) {
  this->x = this->y = this->width = this->height = 0;

  this->context = context;
  this->buffer = new ConsoleBuffer(11);
  this->keyHandler = new ConsoleKeyHandler(buffer);
}

Console::~Console() {
  // Don't delete context since someone else provided this
  delete buffer;
  delete keyHandler;
}

void Console::setLocation(GLfloat x, GLfloat y) {
  this->x = x;
  this->y = y;
}

void Console::setSize(GLfloat width, GLfloat height) {
  this->width = width;
  this->height = height;
}

void Console::draw() {
  // Draw border and background of the console
  glPushMatrix();
  context->setLine(2, 1, 0, 0);
  context->setFill(0.25, 0, 0);
  context->drawRectangleFilledWithBorder(x, y, width, height);
  glPopMatrix();

  // Draw the text content of the console
  glPushMatrix();

  // TODO Deltas are very much magic numbers :-(  not sure why this is necessary yet
  buffer->output(x + 15, y - 50, width - 15, height + 50);

  glPopMatrix();
}

bool Console::handleKey(unsigned char key) {
  return keyHandler->handleKey(key);
}

void Console::moveY(GLfloat delta) {
  y += delta;
}

void Console::moveX(GLfloat delta) {
  x += delta;
}
