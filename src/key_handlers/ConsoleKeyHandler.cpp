/*
 * ConsoleKeyHandler.cpp
 *
 *  Created on: Jul 15, 2013
 *      Author: drom
 */

#include "ConsoleKeyHandler.h"

ConsoleKeyHandler::ConsoleKeyHandler(ConsoleBuffer* consoleBuffer) {
  this->consoleBuffer = consoleBuffer;
}

bool ConsoleKeyHandler::handleKey(unsigned char key) {
  switch (key) {

  // Escape quits the app
  case 27:
    exit(1);
    break;

  // Return key
  case 13:
    consoleBuffer->newLine();
    break;

  // Backspace
  case 127:
    consoleBuffer->deleteBackwardFromCurrentLine();
    break;

  // Delete
  case 8:
    consoleBuffer->deleteForwardFromCurrentLine();
    break;

  default:
    if(isalnum(key) || key == ' ') {
      consoleBuffer->addToEndOfCurrentLine(key);
      break;
    }

    // Otherwise don't invalidate if not a valid key
    return false;
  }

  return true;
}
