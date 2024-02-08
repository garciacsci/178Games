#include "GLScene.h"

GLScene::GLScene()
{
    //ctor
}

GLScene::~GLScene()
{
    //dtor
}

GLint GLScene::initGL()
{
    glShadeModel(GL_SMOOTH); // for smooth render
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f); // clear background black
    glClearDepth(1.0f); // depth test for layers
    glEnable(GL_DEPTH_TEST); // activate depth test
    glDepthFunc(GL_LEQUAL); // depth function type
    return true;

}

GLint GLScene::drawScene() // do not load objects in this function. It runs 30 times a second so that is bad for optimization. Runs on loop.
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT); //clear bits on each iteration.
    glLoadIdentity();
    glTranslatef(0.0, 0.0, -8.0); // translate object to xyz. In this case, get closer to me.
    glColor3f(0.0, 0.0, 1.0); //color object RGB in this case 1 of blue.
    glPushMatrix();         //group object
        glutSolidTeapot(1.5); // load and render object
    glPopMatrix();          // exit group
    return true;
}

GLvoid GLScene::reSizeScene(GLsizei width, GLsizei height)
{
    GLfloat aspectRatio = (GLfloat)width/(GLfloat)height; // finding aspect ratio of window
    glViewport(0, 0, width, height); // shrinking view with window size
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity(); //always used after glMatrixMode is called.
    gluPerspective(45, aspectRatio, 0.1, 100);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity(); // again we call after glMatrixMode.
    return;
}
