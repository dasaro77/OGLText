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

using std::string;

class TypeSetMetadata {

private:

  GLfloat yild;
  GLfloat fontSize;

public:

  TypeSetMetadata();
  virtual ~TypeSetMetadata();

  GLfloat getFontSize() const;
  void setFontSize(string strokeScale);
  GLfloat getYild() const;
  void setYild(string yild);

  GLfloat getLineHeight();
  GLfloat getScaleFactor();

};

#endif /* TYPESETMETADATA_H_ */
