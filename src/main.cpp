/*
 * TODO list
 * - Line wrapping on current input buffer
 * - Response lines for each line of input after CR
 * - Abstract out concept of a text box (location, dimension, styling)
 * - Non-input debug text box
 * - Coordinates at cursor w/ non-input debug text box
 * - Better / alternative build method instead of eclipse maintained makefiles
 */

#include <gl/gl.h>
#include <gl/glu.h>
#include <gl/glut.h>

#include <string>
#include <deque>

#include "drawing/DrawingContext.h"
#include "outputers/QTextOutputer.h"
#include "console/ConsoleBuffer.h"
#include "key_handlers/ConsoleKeyHandler.h"

#define WINDOW_WIDTH  500
#define WINDOW_HEIGHT 250

DrawingContext context;
QTextOutputer outputer(-225, 70, -20);
ConsoleBuffer consoleBuffer(&outputer, 11);
ConsoleKeyHandler consoleKeyHandler(&consoleBuffer);

void handleDisplay() {
  // Clear the window
  glClearColor(0.0, 0.0, 0.0, 0.0);
  glClear(GL_COLOR_BUFFER_BIT);

  // Draw border and background of the console
  glPushMatrix();
  context.setLine(2, 1, 0, 0);
  context.setFill(0.25, 0, 0);
  context.drawRectangleFilledWithBorder(-240, 120, 480, 240);
  glPopMatrix();

  // Draw the text content of the console
  glPushMatrix();
  consoleBuffer.output();
  glPopMatrix();

  // Swap buffers (color buffers, makes previous render visible)
  glutSwapBuffers();
}

void handleKeyboard(unsigned char key, int x, int y) {
#pragma unused (x, y)

  if(consoleKeyHandler.handleKey(key)) {
    glutPostRedisplay();
  }
}

void handleReshape(int width, int height) {
  GLdouble size;
  GLdouble aspect;

  /* Use the whole window. */
  glViewport(0, 0, width, height);

  /* We are going to do some 2-D orthographic drawing. */
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  size = (GLdouble) ((width >= height) ? width : height) / 2.0;
  if (width <= height) {
    aspect = (GLdouble) height / (GLdouble) width;
    glOrtho(-size, size, -size * aspect, size * aspect, -100000.0, 100000.0);
  } else {
    aspect = (GLdouble) width / (GLdouble) height;
    glOrtho(-size * aspect, size * aspect, -size, size, -100000.0, 100000.0);
  }

  /* Make the world and window coordinates coincide so that 1.0 in */
  /* model space equals one pixel in window space.                 */
  glScaled(aspect, aspect, 1.0);

  /* Now determine where to draw things. */
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();

}

int main(int argc, char** argv) {
  glutInit(&argc, argv);
  glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
  glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
  glutCreateWindow("OGL Console Sandbox");

  glutDisplayFunc(handleDisplay);
  glutKeyboardFunc(handleKeyboard);
  glutReshapeFunc(handleReshape);

  glutMainLoop();
}
