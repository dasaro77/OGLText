/*
 * TypeSetMetadata.cpp
 *
 *  Created on: Jul 17, 2013
 *      Author: drom
 */

#include <console/TypeSetMetadata.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <cstdlib>
#include <string>

using std::string;

TypeSetMetadata::TypeSetMetadata() {
  this->yild = 20;
  this->fontSize = 12;
}

TypeSetMetadata::~TypeSetMetadata() {
  // TODO Auto-generated destructor stub
}

GLfloat TypeSetMetadata::getFontSize() const {
  return fontSize;
}

void TypeSetMetadata::setFontSize(string fontSize) {
  GLfloat value = atof(fontSize.c_str());
  this->fontSize = value;
}

GLfloat TypeSetMetadata::getYild() const {
  return yild;
}

void TypeSetMetadata::setYild(string yild) {
  GLfloat value = atof(yild.c_str());
  this->yild = value;
}

GLfloat TypeSetMetadata::getLineHeight() {
  // Was:  20
  return fontSize * fontSize / 120;
}

GLfloat TypeSetMetadata::getScaleFactor() {
  double modelview[16];
//  double projection[16];
  int viewport[4];
  glGetDoublev(GL_MODELVIEW_MATRIX, modelview);
//  glGetDoublev(GL_PROJECTION_MATRIX, projection);
  glGetIntegerv(GL_VIEWPORT, viewport);

  return fontSize / 120 * viewport[3] / 1;

  // return fontSize / 120;
}
