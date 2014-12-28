/*
 * BufferLine.cpp
 *
 *  Created on: Jul 17, 2013
 *      Author: drom
 */

#include <console/BufferLine.h>
#include <console/TypeSetMetadata.h>
#include <GL/freeglut_std.h>
#include <GL/gl.h>
#include <string>

BufferLine::BufferLine() {
  this->lineWidth = 1;
  this->g = 1;
  this->r = this->b = 0;
  this->justification = JUST_LEFT;
  this->text = "";
}

BufferLine::~BufferLine() {
  // TODO Auto-generated destructor stub
}

void BufferLine::draw(TypeSetMetadata& tsm, GLfloat x, GLfloat y, bool isCurrent) {
  glColor3f(r, g, b);
  glLineWidth(lineWidth);

  GLfloat strokeScale = tsm.getScaleFactor();
  GLfloat lineHeight = tsm.getLineHeight();

  glPushMatrix();

  //ORIG:  glTranslatef(x, y + 1.25 * tsm.getYild(), 0.0);
  glTranslatef(x, y + 1.25 * lineHeight, 0.0);
//  glTranslatef(x, y, 0.0);
  glScalef(strokeScale, strokeScale, 1);

  const char* s = text.c_str();
  while (*s) {
    glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, *s);
    s++;
  }

  if(isCurrent) {
    // Add cursor if this is the current line
    glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, '_');
  }

  glPopMatrix();
}

void BufferLine::setText(const string& text) {
  this->text = text;
}

void BufferLine::setColor(GLfloat r, GLfloat g, GLfloat b) {
  this->r = r;
  this->g = g;
  this->b = b;
}

void BufferLine::setLineWidth(GLfloat lineWidth) {
  this->lineWidth = lineWidth;
}

void BufferLine::justifyLeft() {
  this->justification = JUST_LEFT;
}

void BufferLine::justifyRight() {
  this->justification = JUST_RIGHT;
}

const string& BufferLine::getText() {
  return text;
}

void BufferLine::append(unsigned char letter) {
  text += letter;
}

void BufferLine::deleteLastChar() {
  if(text.size() > 0) {
    text.erase(text.size() - 1);
  }
}
