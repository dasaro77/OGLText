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
  GLfloat strokeScale;

public:

  TypeSetMetadata();
  virtual ~TypeSetMetadata();

  GLfloat getStrokeScale() const;
  void setStrokeScale(string strokeScale);
  GLfloat getYild() const;
  void setYild(string yild);

};

#endif /* TYPESETMETADATA_H_ */
