/*
 * ConsoleKeyHandler.h
 *
 *  Created on: Jul 15, 2013
 *      Author: drom
 */

#ifndef CONSOLEKEYHANDLER_H_
#define CONSOLEKEYHANDLER_H_

#include <key_handlers/IKeyHandler.h>

class Console;
class ConsoleBuffer;

class ConsoleKeyHandler : public IKeyHandler {

private:

  Console* console;
  ConsoleBuffer* consoleBuffer;

public:

  ConsoleKeyHandler(Console* console, ConsoleBuffer* consoleBuffer);
  ~ConsoleKeyHandler() {}

  bool handleKey(unsigned char key);

};

#endif /* CONSOLEKEYHANDLER_H_ */
