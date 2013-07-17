/*
 * Console.h
 *
 *  Created on: Jul 16, 2013
 *      Author: drom
 */

#ifndef CONSOLE_H_
#define CONSOLE_H_

#include <drawing/DisplayBox.h>

class ConsoleBuffer;
class ConsoleKeyHandler;
class DrawingContext;
class IOutputer;

class Console : public DisplayBox {

private:

  ConsoleBuffer* buffer;

public:

  Console(DrawingContext* context);
  virtual ~Console();

  void draw();

};

#endif /* CONSOLE_H_ */
