#ifndef GLSCENE_H
#define GLSCENE_H

#include <windows.h>
#include <GL/glut.h>
#include <iostream>

using namespace std;

class GLScene
{
    public:
        GLScene(); //constructor
        virtual ~GLScene(); //destructor
        GLint initGL(); //"***GLint***" changes the amount of bits that this value stores based on the device used. 32-bit, 64-bit, phone, etc.
        GLint drawScene();
        GLvoid reSizeScene(GLsizei, GLsizei);

    protected:

    private:
};

#endif // GLSCENE_H
