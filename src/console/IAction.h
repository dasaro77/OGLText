/*
 * IAction.h
 *
 *  Created on: Jul 17, 2013
 *      Author: drom
 */

#ifndef IACTION_H_
#define IACTION_H_

#include <string>

using std::string;

class IAction {

public:

  IAction() {}
  virtual ~IAction() {};

  virtual void execute(string arg)=0;

};

#endif /* IACTION_H_ */
