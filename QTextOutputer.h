/*
 * QTextOutputer.h
 *
 *  Created on: Jul 15, 2013
 *      Author: drom
 */

#ifndef QTEXTOUTPUTER_H_
#define QTEXTOUTPUTER_H_

#include <gl/gl.h>

#include "IOutputer.h"

class QTextOutputer: public IOutputer {

private:

  GLfloat xBase;
  GLfloat yBase;
  GLfloat yDelta;

public:

  QTextOutputer(GLfloat xBase, GLfloat yBase, GLfloat yDelta);
  ~QTextOutputer() {};

  void output(size_t index, string* str);

};

#endif /* QTEXTOUTPUTER_H_ */
