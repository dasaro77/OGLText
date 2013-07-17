/*
 * Console.cpp
 *
 *  Created on: Jul 16, 2013
 *      Author: drom
 */

#include <console/Console.h>
#include <console/ConsoleBuffer.h>
#include <drawing/DisplayBox.h>
#include <GL/gl.h>
#include <key_handlers/ConsoleKeyHandler.h>
#include <key_handlers/IKeyHandler.h>
#include <new>

class DrawingContext;

Console::Console(DrawingContext* context) : DisplayBox(context) {
  this->buffer = new ConsoleBuffer(11);
  setKeyHandler(new ConsoleKeyHandler(buffer));

  // Default display box stylings
  setLine(2, 1, 0, 0);
  setFill(0.25, 0, 0);
}

Console::~Console() {
  delete buffer;
}

void Console::draw() {
  DisplayBox::draw();

  // Draw the text content of the console
  glPushMatrix();

  // TODO Deltas are very much magic numbers :-(  not sure why this is necessary yet
  buffer->output(getX() + 15, getY() - 50, getWidth() - 15, getHeight() + 50);

  glPopMatrix();
}
