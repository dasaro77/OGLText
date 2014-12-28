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

template <class C>
class SimpleSetAction : public IAction {

private:

  C* instance;
  void (C::*funcSingleParam)(string);
  void (C::*funcAction)();

public:

  SimpleSetAction(C* instance, void (C::*func)()) {
    this->instance = instance;
    this->funcSingleParam = NULL;
    this->funcAction = func;
  }

  SimpleSetAction(C* instance, void (C::*func)(string)) {
    this->instance = instance;
    this->funcSingleParam = func;
    this->funcAction = NULL;
  }

  virtual ~SimpleSetAction() {}

  void execute(string param) {
    if(funcAction) {
      (instance->*funcAction)();
    }
    else {
      (instance->*funcSingleParam)(param);
    }
  }

};

#endif /* SIMPLESETACTION_H_ */
