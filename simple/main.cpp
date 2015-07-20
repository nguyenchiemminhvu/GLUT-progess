#include <windows.h>
#include <GL/glut.h>
#include <stdlib.h>

int listCursor[] = { GLUT_CURSOR_INFO,
                     GLUT_CURSOR_SPRAY,
                     GLUT_CURSOR_TEXT,
                     GLUT_CURSOR_CROSSHAIR,
                     GLUT_CURSOR_WAIT
                    };
int currentIndexOfCursor;

void keyboardEvent(unsigned char key, int x, int y)  {

    switch (key)    {

    case 27:
        exit(0);
    default:
        break;
    }
}

void nextMouseCursor()  {

    currentIndexOfCursor++;
    if(currentIndexOfCursor > 4)
        currentIndexOfCursor = 0;

    glutSetCursor(listCursor[currentIndexOfCursor]);
}

void mouseEvent(int button, int state, int x, int y)    {

    switch (button) {

    case GLUT_LEFT_BUTTON:
        nextMouseCursor();
        break;

    default:
        break;
    }
}

void displayFunction()  {

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glBegin(GL_TRIANGLES);

    glColor3f(1,0,0);
    glVertex2f(-0.5,-0.5);
    glColor3f(0,1,0);
    glVertex2f(-0.5,0.0);
    glColor3f(0,0,1);
    glVertex2f(0.0,0.5);

    glEnd();

    glutSwapBuffers();
}

int main(int argc, char** argv) {

    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE| GLUT_RGB);
    glutInitWindowPosition(300,100);
    glutInitWindowSize(600,500);
    glutCreateWindow("Simple project");

    currentIndexOfCursor = 0;
    glutSetCursor(listCursor[currentIndexOfCursor]);

    glutDisplayFunc(displayFunction);
    glutKeyboardFunc(keyboardEvent);
    glutMouseFunc(mouseEvent);

    glutMainLoop();

    return 0;
}
