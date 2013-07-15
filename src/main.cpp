#include <gl/gl.h>
#include <gl/glu.h>
#include <gl/glut.h>

#include <string>
#include <deque>

#include "outputers/QTextOutputer.h"
#include "console/ConsoleBuffer.h"
#include "key_handlers/ConsoleKeyHandler.h"

#define WINDOW_WIDTH  500
#define WINDOW_HEIGHT 250

QTextOutputer outputer(-225, 70, -20);
ConsoleBuffer consoleBuffer(&outputer, 10);
ConsoleKeyHandler consoleKeyHandler(&consoleBuffer);

// Main loop
void mainLoopFunction() {
  // Clear the window
  glClearColor(0.0, 0.0, 0.0, 0.0);
  glClear(GL_COLOR_BUFFER_BIT);

  consoleBuffer.output();

  // Swap buffers (color buffers, makes previous render visible)
  glutSwapBuffers();
}

void handleKeyboard(unsigned char key, int x, int y) {
#pragma unused (x, y)

  if(consoleKeyHandler.handleKey(key)) {
    glutPostRedisplay();
  }
}

void handleReshape(int w, int h) {
  GLdouble size;
  GLdouble aspect;

  /* Use the whole window. */
  glViewport(0, 0, w, h);

  /* We are going to do some 2-D orthographic drawing. */
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  size = (GLdouble) ((w >= h) ? w : h) / 2.0;
  if (w <= h) {
    aspect = (GLdouble) h / (GLdouble) w;
    glOrtho(-size, size, -size * aspect, size * aspect, -100000.0, 100000.0);
  } else {
    aspect = (GLdouble) w / (GLdouble) h;
    glOrtho(-size * aspect, size * aspect, -size, size, -100000.0, 100000.0);
  }

  /* Make the world and window coordinates coincide so that 1.0 in */
  /* model space equals one pixel in window space.                 */
  glScaled(aspect, aspect, 1.0);

  /* Now determine where to draw things. */
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();

}

// Initialize GLUT and start main loop
int main(int argc, char** argv) {
  glutInit(&argc, argv);
  glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
  glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
  glutCreateWindow("OGL Text Examples");

  glutDisplayFunc(mainLoopFunction);
  glutKeyboardFunc(handleKeyboard);
  glutReshapeFunc(handleReshape);

  glutMainLoop();
}
