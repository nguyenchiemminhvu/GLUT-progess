#include <windows.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <GL/glu.h>
#include <string>

using namespace std;

const string name = "Nguyen Chiem Minh Vu";
float angle = 0;

void initRendering()    {

    glEnable(GL_DEPTH_TEST);
}

void handleResize(int w, int h) {

    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluPerspective(45, float(w) / float(h), 1, 200);
}

void display()  {

    angle += 1.0f;
    if(angle > 360)
        angle -= 360;

    glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glTranslatef(0, 0, -5);

    glRotatef(angle, 0, 1, 0);
    glBegin(GL_TRIANGLES);

        glColor3f(1,1,0);
        glVertex3f(0, 1, 0);
        glColor3f(0, 0, 1);
        glVertex3f(-1, -1, 0);
        glColor3f(0.1, 1, 0.2);
        glVertex3f(1, -1, 0);

    glEnd();

    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
    gluOrtho2D(0, 400, 0, 400);
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();
    glRasterPos2i(10, 10);
    glColor3f(1,1,0);
    for(int i = 0; i < name.size(); i++) {

        glutBitmapCharacter(GLUT_BITMAP_9_BY_15, (int)name[i]);
    }
    glMatrixMode(GL_MODELVIEW);
    glPopMatrix();
    glMatrixMode(GL_PROJECTION);
    glPopMatrix();

    glutSwapBuffers();
    glutPostRedisplay();
}

int main(int argc, char** argv) {

    glutInit(&argc, argv);
    glutInitWindowSize(400, 400);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGB);

    initRendering();
    glutCreateWindow("Show text");

    glutDisplayFunc(display);
    glutReshapeFunc(handleResize);

    glutMainLoop();
    return 0;
}

