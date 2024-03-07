#ifndef GLTEXTURE_H
#define GLTEXTURE_H

#include <windows.h>
#include <GL/gl.h>
#include <SOIL.h>
#include <iostream>

using namespace std;

class GLTexture
{
    public:
        GLTexture();
        virtual ~GLTexture();
        GLuint tex;
        GLint width,height;
        unsigned char* image;
        void loadTexture(char *);
        void bindTexture();

    protected:

    private:
};

#endif // GLTEXTURE_H
