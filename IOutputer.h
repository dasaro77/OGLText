/*
 * IOutputer.h
 *
 *  Created on: Jul 15, 2013
 *      Author: drom
 */

#ifndef IOUTPUTER_H_
#define IOUTPUTER_H_

#include <string>

using std::string;

class IOutputer {

public:
  IOutputer() {}

  virtual void output(size_t index, string* str)=0;

};

#endif /* IOUTPUTER_H_ */
