/*
 * TypeSetMetadata.cpp
 *
 *  Created on: Jul 17, 2013
 *      Author: drom
 */

#include <console/TypeSetMetadata.h>
#include <stdlib.h>
#include <GL/gl.h>
#include <string>

using std::string;

TypeSetMetadata::TypeSetMetadata() {
  reset();
}

TypeSetMetadata::~TypeSetMetadata() {
  // TODO Auto-generated destructor stub
}

GLfloat TypeSetMetadata::getStrokeScale() const {
  return strokeScale;
}

void TypeSetMetadata::setStrokeScale(string strokeScale) {
  GLfloat value = atof(strokeScale.c_str());
  this->strokeScale = value;
}

GLfloat TypeSetMetadata::getYild() const {
  return yild;
}

void TypeSetMetadata::setYild(string yild) {
  GLfloat value = atof(yild.c_str());
  this->yild = value;
}

void TypeSetMetadata::reset() {
  this->yild = 20;
  this->strokeScale = 0.1;
}
