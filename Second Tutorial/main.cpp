#include <windows.h>
#include <stdlib.h>

#ifdef __APPLE__
#include <OpenGL/glut.h>
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif // __APPLE__

//Called when a key is pressed
void handleKeyPress(unsigned char key, int x, int y)    {

    if(key == 27)   //escape key
        exit(0); //exit the program
}

//initializes 3d rendering
void initRendering()    {

    //Make 3d drawing work when something is in front of something else
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_COLOR_MATERIAL); //Enable to use color
}

//Called when the window is resized
void handleResize(int w, int h) {

    //Tell OpenGL how to convert from coordinates to pixels value
    glViewport(0, 0, w, h);

    glMatrixMode(GL_PROJECTION); //switch to setting the camera perspective

    glLoadIdentity(); //reset the camera
    gluPerspective(45.0, //the camera angle
                    (double)w / (double)h, //the width to height ratio
                    1.0, //the near z clipping coordinates
                     200.0); //the far z clipping coordinates
}

float angle = 45.0f;
float cameraAngle = 0.0f;
//draws 3d scene
void drawing()  {

    //Clear information from last draw
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(0.7f, 0.9f, 1.0f, 1);
    glMatrixMode(GL_MODELVIEW); //switch to the drawing perspective
    glLoadIdentity(); //Reset the drawing perspective
    glRotatef(-cameraAngle, 0.0f, 1.0f, 0.0f); // Rotated the camera to 10 degrees
    glTranslatef(0.0f, 0.0f, -5.0f); //Move forward 5 units

    glPushMatrix(); //Save the transformation perform thus far

    glTranslatef(0.0f, -1.0f, 0.0f);
    glRotatef(angle, 0.0f, 0.0f, 1.0f);
    glBegin(GL_QUADS);
    //Trapezoid
    glColor3f(0.5f, 0.0f, 0.8f);
    glVertex3f(-0.7f, -0.5f, 0.0f);
    glColor3f(0.0f, 0.9f, 0.0f);
    glVertex3f(0.7f, -0.5f, 0.0f);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex3f(0.4f, 0.5f, 0.0f);
    glColor3f(0.0f, 0.65f, 0.65f);
    glVertex3f(-0.4f, 0.5f, 0.0f);
    glEnd();

    glPopMatrix(); //Undo the move to the center of the trapezoid

    glPushMatrix();
    glTranslatef(1.0f, 1.0f, 0.0f);
    glRotatef(angle, 0.0f, 1.0f, 0.0f);
    glScalef(0.7f, 0.7f, 0.7f); //shrink the polygon to 70%
    glBegin(GL_POLYGON); //Begin triangle coordinates
    //Pentagon
    glColor3f(0.0f, 0.75f, 0.0f);
    glVertex3f(-0.5f, -0.5f, 0.0f);
    glVertex3f(0.5f, -0.5f, 0.0f);
    glVertex3f(0.5f, 0.0f, 0.0f);
    glVertex3f(0.0f, 0.5f, 0.0f);
    glVertex3f(-0.5f, 0.0f, 0.0f);
    glEnd();

    glPopMatrix();

    glPushMatrix();
    glTranslatef(-1.0f, 1.0f, 0.0f);
    glRotatef(angle, 1.0f, 2.0f, 3.0f);
    glColor3f(0.0f, 0.6f, 0.6f);
    glBegin(GL_TRIANGLES);
    //Triangle
    glColor3f(1.0f, 0.7f, 0.0f);
    glVertex3f(0.5f, -0.5f, 0.0f);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(0.0f, 0.5f, 0.0f);
    glColor3f(-0.5f, 0.0f, 1.0f);
    glVertex3f(-0.5f, -0.5f, 0.0f);
    glEnd();

    glPopMatrix();

    glutSwapBuffers(); //Send the 3d scene to the screen
}

void update(int value)  {

    angle += 20.0f;
    if(angle > 360) {

        angle -= 360;
    }

    glutPostRedisplay();
    glutTimerFunc(25, update, 0);
}


int main(int argc, char** argv)     {

    //Initialize GLUT
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(300, 100);

    glutCreateWindow("My first practice");
    initRendering();

    glutDisplayFunc(drawing);
    glutKeyboardFunc(handleKeyPress);
    glutReshapeFunc(handleResize);
    glutTimerFunc(25, update, 0);

    glutMainLoop();
    return 0;
}
