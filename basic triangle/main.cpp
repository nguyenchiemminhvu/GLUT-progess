/*********** The first project in openGL progress **************/

#include <stdlib.h>
#include <windows.h>
#include <GL/glut.h>

void keyPress(unsigned char key, int x, int y)  {

    switch (key)    {

    case 27:
        exit(0);

    default:
        break;
    }
}

void display()  {

    glClearColor(0,0,0,0);
    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_TRIANGLES);

    glColor3f(1,0,0);
    glVertex2f(0.0f,1.0f);
    glColor3f(0,1,0);
    glVertex2f(-1.0f,-1.0f);
    glColor3f(0,0,1);
    glVertex2f(1.0f,-1.0f);

    glEnd();
    glFlush();
}

int main(int argc, char** argv) {

    glutInit(&argc, argv);
    glutInitWindowSize(500,400);
    glutInitWindowPosition(300,100);

    glutCreateWindow("First openGL project");

    glutDisplayFunc(display);
    glutKeyboardFunc(keyPress);

    glutMainLoop();
    return 0;
}
