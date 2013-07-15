/*
 * QTextOutputer.cpp
 *
 *  Created on: Jul 15, 2013
 *      Author: drom
 */

#include "QTextOutputer.h"
#include "qtext.h"

QTextOutputer::QTextOutputer(GLfloat xBase, GLfloat yBase, GLfloat yDelta) {
  this->xBase = xBase;
  this->yBase = yBase;
  this->yDelta = yDelta;
}

void QTextOutputer::output(size_t index, string* str) {
  if(str && str->size()) {
    printStrokeString(xBase, yBase + index*yDelta, str->c_str());
  }
}
