#ifndef GLMODEL_H
#define GLMODEL_H

#include <GL/GL.h>
#include <windows.h>
#include <iostream>
#include <GL/glut.h>


class GLModel
{
    public:
        GLModel();
        virtual ~GLModel();


        GLfloat RotateX; // for rotation about X
        GLfloat RotateY; // for rotation about Y
        GLfloat RotateZ; // for rotation about Z

        GLfloat zoom;   // zoom
        GLfloat xPos;   // model x position
        GLfloat yPos;   // model y position
        GLfloat zPos;   // model x position

        void drawModel();


    protected:

    private:
};

#endif // GLMODEL_H
