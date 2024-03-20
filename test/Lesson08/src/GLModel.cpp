#include "GLModel.h"

GLModel::GLModel()
{
    //ctor
    RotateX = 0.0;  // init X
    RotateY = 0.0;  // init Y
    RotateZ = 0.0;  // init Z

    xPos = 0.0;     // init x pos
    yPos = 0.0;     // init y pos
    zPos = 0.0;    // init z pos, zoom
}

GLModel::~GLModel()
{
    //dtor
}

void GLModel::drawModel()
{
    glColor3f(1.0,1.0,1.0);
    glTranslatef(xPos,yPos,zPos);

    glRotatef(RotateX, 1,0,0);
    glRotatef(RotateY, 0,1,0);
    glRotatef(RotateZ, 0,0,1);

    glutSolidTeapot(0.5);       // load and render object
}

