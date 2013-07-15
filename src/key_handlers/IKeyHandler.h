/*
 * IKeyHandler.h
 *
 *  Created on: Jul 15, 2013
 *      Author: drom
 */

#ifndef IKEYHANDLER_H_
#define IKEYHANDLER_H_

class IKeyHandler {

public:

  IKeyHandler() {};
  virtual ~IKeyHandler() {};

  /**
   * Checks to see if it should react to the given key press and returns
   * true if it did in a fashion that should invalidate the screen.
   */
  virtual bool handleKey(unsigned char key)=0;

};

#endif /* IKEYHANDLER_H_ */
