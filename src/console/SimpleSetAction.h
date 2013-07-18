/*
 * SimpleSetAction.h
 *
 *  Created on: Jul 17, 2013
 *      Author: drom
 */

#ifndef SIMPLESETACTION_H_
#define SIMPLESETACTION_H_

#include <console/IAction.h>
#include <string>

using std::string;

template <class C>
class SimpleSetAction : public IAction {

private:

  C* instance;
  void (C::*func)(string);

public:

  SimpleSetAction(C* instance, void (C::*func)(string)) {
    this->instance = instance;
    this->func = func;
  }

  virtual ~SimpleSetAction() {}

  void execute(string param) {
    (instance->*func)(param);
  }

};

#endif /* SIMPLESETACTION_H_ */
