#ifndef COMMON_H_INCLUDED
#define COMMON_H_INCLUDED

#include <windows.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include <SOIL.h>
#include <iostream>
#include <time.h>

using namespace std;

typedef struct  // positions in 2D graphics
{
    float x;
    float y;
}vec2;

typedef struct  // positions in 3D graphics
{
    float x;
    float y;
    float z;
}vec3;

typedef struct  // shader positions in 3D
{
    float x;
    float y;
    float z;
    float w;
}vec4;


#endif // COMMON_H_INCLUDED
