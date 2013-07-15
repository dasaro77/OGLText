/*
 * ConsoleKeyHandler.h
 *
 *  Created on: Jul 15, 2013
 *      Author: drom
 */

#ifndef CONSOLEKEYHANDLER_H_
#define CONSOLEKEYHANDLER_H_

#include "IKeyHandler.h"
#include "console/ConsoleBuffer.h"

class ConsoleKeyHandler : public IKeyHandler {

private:

  ConsoleBuffer* consoleBuffer;

public:

  ConsoleKeyHandler(ConsoleBuffer* consoleBuffer);
  ~ConsoleKeyHandler() {}

  bool handleKey(unsigned char key);

};

#endif /* CONSOLEKEYHANDLER_H_ */
