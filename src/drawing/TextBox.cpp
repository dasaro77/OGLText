/*
 * TextBox.cpp
 *
 *  Created on: Jul 17, 2013
 *      Author: drom
 */

#include <drawing/DisplayBox.h>
#include <drawing/TextBox.h>
#include <qtext.h>

class DrawingContext;

TextBox::TextBox(DrawingContext* context) : DisplayBox(context) {
  this->text = string("");

  // Default display box stylings
  setLine(2, 0, 1, 0);
  setFill(0, 0.25, 0);
}

TextBox::~TextBox() {
  // TODO Auto-generated destructor stub
}

void TextBox::setText(const string& text) {
  this->text = text;
}

const string& TextBox::getText() {
  return text;
}

void TextBox::draw() {
  DisplayBox::draw();

  printStrokeString(getX() + 5, getY() - 45, text.c_str());
}
