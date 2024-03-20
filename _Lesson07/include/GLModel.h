#ifndef GLMODEL_H
#define GLMODEL_H

#include <windows.h>
#include <iostream>
#include <gl/gl.h>
#include <GL/glut.h>

class GLModel
{
    public:
        GLModel();
        virtual ~GLModel();

        GLfloat RotateX;    // for rotation around X
        GLfloat RotateY;    // for rotation around Y
        GLfloat RotateZ;    // for rotation around Z

        GLfloat xPos;   // model x position
        GLfloat yPos;   // model y position, 2D game
        GLfloat zPos;   // model z position, 3D game, same as zoom

        void drawModel();


    protected:

    private:
};

#endif // GLMODEL_H
