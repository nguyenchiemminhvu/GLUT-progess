#include <windows.h>
#include <stdlib.h>
#include <GL/glut.h>

int currentX, currentY;
float Hangle = 0, Vangle = 0;

void handleResize(int w, int h) {

    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluPerspective(45.0, (double)w / (double)h, 1.0, 500);
}

void drawing()  {

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(0.2, 1.0, 0.6, 1.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glTranslatef(0, 0, -10);
    glRotatef(Hangle, 0, 1, 0);
    glRotatef(Vangle, 1, 0, 0);

    glBegin(GL_QUADS);

    glColor3f(1, 0, 0);
    glVertex3f(0, 0, 0);
    glVertex3f(1, 0, 0);
    glVertex3f(1, 1, 0);
    glVertex3f(0, 1, 0);

    glEnd();

    glutSwapBuffers();
}

void update(int value)  {

    glutPostRedisplay();
}

void handleMouseMove(int x, int y)  {

    if(x > currentX)    {

        Hangle += 2.0f;
        if(Hangle > 360)
            Hangle -= 360;
    }
    else if(x < currentX)   {

        Hangle -= 2.0f;
        if(Hangle < 0)
            Hangle += 360;
    }

    if(y > currentY)   {

        Vangle += 2.0f;
        if(Vangle > 360)
            Vangle -= 360;
    }
    else if(y < currentY)   {

        Vangle -= 2.0f;
        if(Vangle < 0)
            Vangle += 360;
    }

    currentX = x;
    currentY = y;

    update(0);
    //glutWarpPointer(currentX, currentY);
}

void handleKeyPress(unsigned char key, int x, int y)    {

    if(key == 27)
        exit(0);
}

int main(int argc, char** argv)    {

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(400,400);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_COLOR_MATERIAL);

    glutCreateWindow("Test");
    currentX = currentY = 200;
    glutWarpPointer(currentX,currentY);

    glutDisplayFunc(drawing);
    glutMotionFunc(handleMouseMove);
    glutKeyboardFunc(handleKeyPress);
    glutReshapeFunc(handleResize);

    glutMainLoop();
    return 0;
}
