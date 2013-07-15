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
    glColor4f(0.0, 1.0, 0.0, 0.0);

    GLfloat yild = 20.0;
    GLfloat strokeScale = 0.1f;

    glMatrixMode(GL_MODELVIEW);

    glPushMatrix();
    glTranslatef(x, y + 1.25 * yild, 0.0);
    glScalef(strokeScale, strokeScale, strokeScale);
    printString(toPrint);
    glPopMatrix();
  }
}
