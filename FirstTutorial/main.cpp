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

//draws 3d scene
void drawing()  {

    //Clear information from last draw
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW); //switch to the drawing perspective
    glLoadIdentity(); //Reset the drawing perspective

    glBegin(GL_QUADS);
    //Trapezoid
    glVertex3f(-0.7f, -1.5f, -5.0f);
    glVertex3f(0.7f, -1.5f, -5.0f);
    glVertex3f(0.4f, -0.5f, -5.0f);
    glVertex3f(-0.4f, -0.5f, -5.0f);

    glEnd();

    glBegin(GL_POLYGON); //Begin triangle coordinates
    //Pentagon
    glVertex3f(0.5f, 0.5f, -5.0f);
    glVertex3f(1.5f, 0.5f, -5.0f);
    glVertex3f(1.5f, 1.0f, -5.0f);
    glVertex3f(1.0f, 1.5f, -5.0f);
    glVertex3f(0.5f, 1.0f, -5.0f);

    glEnd();

    glBegin(GL_TRIANGLES);
    //Triangle
    glVertex3f(-0.5f, 0.5f, -5.0f);
    glVertex3f(-1.0f, 1.5f, -5.0f);
    glVertex3f(-1.5f, 0.5f, -5.0f);

    glEnd();

    glutSwapBuffers(); //Send the 3d scene to the screen
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

    glutMainLoop();
    return 0;
}
