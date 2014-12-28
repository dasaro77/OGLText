/*
 * Console.h
 *
 *  Created on: Jul 16, 2013
 *      Author: drom
 */

#ifndef CONSOLE_H_
#define CONSOLE_H_

#include <console/IAction.h>
#include <drawing/DisplayBox.h>
#include <map>
#include <string>
#include <utility>

using std::map;

class ConsoleBuffer;
class ConsoleKeyHandler;
class DrawingContext;
class IOutputer;

class Console : public DisplayBox {

private:

  ConsoleBuffer* buffer;
  map<string, IAction*> basicLanguage;

public:

  Console(DrawingContext* context);
  virtual ~Console();

  void draw();
  void execute(const string& line);

};

#endif /* CONSOLE_H_ */
