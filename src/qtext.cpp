/* Really, really quick (q) and dirty implementation of text rendering in
 * OpenGL.  Very unconfigurable, but it's super easy to work with quickly!
 * Anything that uses this should really be made to use something more
 * robust (e.g., various fonts, stylings, typeset metadata, etc) in the
 * future.
 */

#include <stdio.h>
#include <string.h>

#include <gl/glut.h>

#include "qtext.h"

void printString(const char* s) {
  if (s && strlen(s)) {
    while (*s) {
      glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, *s);
      s++;
    }
  }
}

void printStrokeString(GLfloat x, GLfloat y, const char* toPrint) {
  if(toPrint && strlen(toPrint)) {
    glColor3f(0.0, 1.0, 0.0);
    glLineWidth(1.0);

    GLfloat yild = 20.0;
    GLfloat strokeScale = 0.1f;

    glPushMatrix();
    glTranslatef(x, y + 1.25 * yild, 0.0);
    glScalef(strokeScale, strokeScale, strokeScale);
    printString(toPrint);
    glPopMatrix();
  }
}
