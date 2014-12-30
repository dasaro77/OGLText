/*
 * TypeSetMetadata.h
 *
 *  Created on: Jul 17, 2013
 *      Author: drom
 */

#ifndef TYPESETMETADATA_H_
#define TYPESETMETADATA_H_

#include <GL/gl.h>
#include <string>
#include <stdlib.h>

using std::string;

class TypeSetMetadata {

private:

  GLfloat yild;
  GLfloat strokeScale;
  GLfloat red;
  GLfloat green;
  GLfloat blue;
  GLfloat lineWidth;

public:

  TypeSetMetadata() { reset(); }
  virtual ~TypeSetMetadata() {}

  GLfloat getStrokeScale() const { return strokeScale; }
  void setStrokeScale(const string& value) { this->strokeScale = strToGLfloat(value); }

  GLfloat getYild() const { return yild; }
  void setYild(const string& value) { this->yild = strToGLfloat(value); }

  GLfloat getRed() const { return red; }
  void setRed(const string& value) { this->red = strToGLfloat(value); }

  GLfloat getGreen() const { return green; }
  void setGreen(const string& value) { this->green = strToGLfloat(value); }

  GLfloat getBlue() const { return blue; }
  void setBlue(const string& value) { this->blue = strToGLfloat(value); }

  GLfloat getLineWidth() const { return lineWidth; }
  void setLineWidth(const string& value) { this->lineWidth = strToGLfloat(value); }

  void reset() {
    this->yild = 20;
    this->strokeScale = 0.1;
    this->red = 0;
    this->green = 1;
    this->blue = 0;
    this->lineWidth = 1;
  }

private:

  GLfloat strToGLfloat(const string& value) { return atof(value.c_str()); }

};

#endif /* TYPESETMETADATA_H_ */
