/*
 * TODO list
 * - Line wrapping on current input buffer
 * - Response lines for each line of input after CR
 * - Abstract out concept of a text box (location, dimension, styling)
 * - Non-input debug text box
 * - Coordinates at cursor w/ non-input debug text box
 * - Better / alternative build method instead of eclipse maintained makefiles
 * - Movable input cursor / implement delete key
 */

#include <console/Console.h>
#include <drawing/DisplayBox.h>
#include <drawing/DrawingContext.h>
#include <drawing/TextBox.h>
#include <gl/glut.h>
#include <GL/gl.h>
#include <sstream>
#include <string>

#define WINDOW_WIDTH  1024
#define WINDOW_HEIGHT 760

#define WORLD_MOVE_STEP_SIZE 3

void handleMouseMove(int x, int y);

DrawingContext context;
Console console(&context);
TextBox coordinates(&context);

void handleDisplay() {
  // Clear the window
  glClearColor(0.0, 0.0, 0.0, 0.0);
  glClear(GL_COLOR_BUFFER_BIT);

  console.draw();
  coordinates.draw();

  // Swap buffers (color buffers, makes previous render visible)
  glutSwapBuffers();
}

void handleKeyboard(unsigned char key, int x, int y) {
#pragma unused (x, y)

  if(key == '`' || key == '~') {
    static bool motionCallbackSet = false;
    if(motionCallbackSet) {
      motionCallbackSet = false;
      glutPassiveMotionFunc(NULL);
    }
    else {
      motionCallbackSet = true;
      glutPassiveMotionFunc(handleMouseMove);
    }
  }
  else if(console.handleKey(key)) {
    glutPostRedisplay();
  }
}

void handleSpecialKeyboard(int key, int x, int y) {
#pragma unused (x, y)

  int modifiers = glutGetModifiers();
  if(modifiers & GLUT_ACTIVE_SHIFT) {
    switch(key) {
      case GLUT_KEY_UP:
        console.moveY(WORLD_MOVE_STEP_SIZE);
        break;

      case GLUT_KEY_DOWN:
        console.moveY(-WORLD_MOVE_STEP_SIZE);
        break;

      case GLUT_KEY_LEFT:
        console.moveX(-WORLD_MOVE_STEP_SIZE);
        break;

      case GLUT_KEY_RIGHT:
        console.moveX(WORLD_MOVE_STEP_SIZE);
        break;

      default:
        return;
      }

      glutPostRedisplay();
  }
}

void handleMouse(int button, int state, int x, int y) {
  handleMouseMove(x, y);
}

void handleMouseMove(int x, int y) {
  std::ostringstream msg;
    msg << "X:" << x << ", Y:" << y;

  coordinates.setText(msg.str());
  glutPostRedisplay();
}

/* Note that this results with an origin in the center of the screen.  Not sure that
 * I'm too wild about this so that might change in the future.
 */
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

  coordinates.setLocation(-width / 2.0 + 2, height / 2.0 - 2);
}

int main(int argc, char** argv) {
  glutInit(&argc, argv);
  glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
  glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
  glutCreateWindow("OGL Console Sandbox");

  console.setLocation(-240, 120);
  console.setSize(480, 240);

  coordinates.setLocation(0, 0);
  coordinates.setSize(150, 30);

  glutDisplayFunc(handleDisplay);
  glutKeyboardFunc(handleKeyboard);
  glutSpecialFunc(handleSpecialKeyboard);
  glutReshapeFunc(handleReshape);
  glutMouseFunc(handleMouse);

  glutMainLoop();
}
