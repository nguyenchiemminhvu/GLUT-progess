#include <stdlib.h>
#include <windows.h>
#include <GL/glut.h>

void initialize()   {

    glutInitDisplayMode(GLUT_DEPTH | GLUT_RGBA);
    glEnable(GL_DEPTH_TEST);
}

void close(int value)    {

    exit(value);
}

void display()  {

    glClearColor(0,0,0,1);
    glClear(GL_COLOR_BUFFER_BIT);
    /*
    glBegin(GL_POINTS);

    glVertex2f(0.1, 0.2);
    glVertex2f(-0.5, 0.2);

    glVertex2f(0.1, -0.1);
    glVertex2f(-0.5, -0.1);

    glVertex2f(0.1, -0.4);
    glVertex2f(-0.5, -0.4);
    */
    /*
    glBegin(GL_LINES);

    glVertex2f(0.1, 0.2);
    glVertex2f(-0.5, 0.2);

    glVertex2f(0.1, -0.1);
    glVertex2f(-0.5, -0.1);

    glVertex2f(0.1, -0.4);
    glVertex2f(-0.5, -0.4);
    */
    /*
    glBegin(GL_TRIANGLES);

    glVertex2f(0.1, 0.2);
    glVertex2f(-0.5, 0.2);

    glVertex2f(0.1, -0.1);
    glVertex2f(-0.5, -0.1);

    glVertex2f(0.1, -0.4);
    glVertex2f(-0.5, -0.4);
    */
    /*
    glBegin(GL_LINE_STRIP);

    glVertex2f(0.1, 0.2);
    glVertex2f(-0.5, 0.2);

    glVertex2f(0.1, -0.1);
    glVertex2f(-0.5, -0.1);

    glVertex2f(0.1, -0.4);
    glVertex2f(-0.5, -0.4);
    */
    /*
    glBegin(GL_LINE_LOOP);

    glVertex2f(0.1, 0.2);
    glVertex2f(-0.5, 0.2);

    glVertex2f(0.1, -0.1);
    glVertex2f(-0.5, -0.1);

    glVertex2f(0.1, -0.4);
    glVertex2f(-0.5, -0.4);
    */

    glBegin(GL_QUADS);

    glColor4f(1,0,0,1);
    glVertex2f(0.1, 0.2);

    glColor4f(0,1,0,1);
    glVertex2f(-0.5, 0.2);

    glColor4f(0,0,1,1);
    glVertex2f(-0.5, -0.1);

    glColor4f(1,0,1,1);
    glVertex2f(0.1, -0.1);

    /*
    glBegin(GL_POLYGON);

    glVertex2f(0.1, 0.2);
    glVertex2f(-0.5, 0.2);

    glVertex2f(0.1, -0.1);
    glVertex2f(-0.5, -0.1);

    glVertex2f(0.1, -0.4);
    glVertex2f(-0.5, -0.4);
    */
    /*
    glBegin(GL_POLYGON);

    glVertex2f(0.1, 0.2);
    glVertex2f(-0.5, 0.2);

    glVertex2f(0.1, -0.1);
    glVertex2f(-0.5, -0.1);

    glVertex2f(0.1, -0.4);
    glVertex2f(-0.5, -0.4);
    */
    glEnd();

    glFlush();
}

int main(int argc, char** argv) {

    glutInit(&argc, argv);
    glutInitWindowPosition(400, 100);
    glutInitWindowSize(500,500);

    initialize();

    glutCreateWindow("Some basic shape");
    glutDisplayFunc(display);
    glutTimerFunc(3000, close, 5);

    glutMainLoop();
    return 0;
}
