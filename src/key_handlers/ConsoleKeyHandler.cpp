/*
 * ConsoleKeyHandler.cpp
 *
 *  Created on: Jul 15, 2013
 *      Author: drom
 */

#include <console/BufferLine.h>
#include <console/Console.h>
#include <console/ConsoleBuffer.h>
#include <key_handlers/ConsoleKeyHandler.h>
#include <cctype>
#include <cstdlib>

class Console;

ConsoleKeyHandler::ConsoleKeyHandler(Console* console, ConsoleBuffer* consoleBuffer) {
  this->console = console;
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
    console->execute(consoleBuffer->getCurrentLine()->getText());
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
