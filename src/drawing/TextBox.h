/*
 * TextBox.h
 *
 *  Created on: Jul 17, 2013
 *      Author: drom
 */

#ifndef TEXTBOX_H_
#define TEXTBOX_H_

#include <drawing/DisplayBox.h>
#include <string>

using std::string;

class TextBox : public DisplayBox {

private:

  string text;

public:

  TextBox(DrawingContext* context);
  virtual ~TextBox();

  void setText(const string& text);
  const string& getText();

  void draw();

};

#endif /* TEXTBOX_H_ */
