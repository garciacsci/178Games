#include "GLModel.h"

GLModel::GLModel()
{
    //ctor

    GLfloat RotateX= 0.0;   // init rotations
    GLfloat RotateY= 0.0;
    GLfloat RotateZ= 0.0;

    //GLfloat zoom= -8.0;
    GLfloat xPos= 0.0;  // init position
    GLfloat yPos= 0.0;
    GLfloat zPos= 0.0;
}

GLModel::~GLModel()
{
    //dtor
}

void GLModel::drawModel()
{
    glColor3f(1.0, 1.0, 1.0);       // set model color
    glTranslatef(xPos, yPos, zPos); // set model location

    glRotatef(RotateX, 1, 0, 0);    // rotation controllers
    glRotatef(RotateY, 0, 1, 0);
    glRotatef(RotateZ, 0, 0, 1);


    glutSolidTeapot(1.5); // load and render object

}
