#include "GLPlayer.h"

GLPlayer::GLPlayer()
{
    //ctor
    vert[0].x = -0.5; vert[0].y = -0.5; vert[0].z = -1;
    vert[1].x =  0.5; vert[1].y = -0.5; vert[1].z = -1;
    vert[2].x =  0.5; vert[2].y =  0.5; vert[2].z = -1;
    vert[3].x = -0.5; vert[3].y =  0.5; vert[3].z = -1;




}

GLPlayer::~GLPlayer()
{
    //dtor
}

void GLPlayer::initPlayer(int x, int y, char* fileName)
{
    plPosition.x = 0.0;         // initialize positions
    plPosition.y = 0.0;
    plPosition.z = -1.0;


    plScale.x = 1.0;            // initialize scale
    plScale.y = 1.0;
    plScale.z = 1.0;

    framesX = x;                // initialize frames
    framesY = y;

    texture->loadTexture(fileName); // loading my player texture

    xMin = 0;
    yMin = 0;
    xMax = 1.0/(float)framesX;
    yMax = 1.0/(float)framesY;


}

void GLPlayer::drawPlayer()
{

    glTranslatef(plPosition.x, plPosition.y, plPosition.z);
    glScalef(plScale.x, plScale.y, plScale.z);

    glColor3f(1.0,1.0,1.0); //white rectangle
    texture->bindTexture();    //binding my background

    glBegin(GL_QUADS);
        glTexCoord2f(xMin, yMax);
        glVertex3f(vert[0].x, vert[0].y, vert[0].z);

        glTexCoord2f(xMax, yMax);
        glVertex3f(vert[1].x, vert[1].y, vert[1].z);

        glTexCoord2f(xMax, yMin);
        glVertex3f(vert[2].x, vert[2].y, vert[2].z);

        glTexCoord2f(xMin, yMin);
        glVertex3f(vert[3].x, vert[3].y, vert[3].z);



    glEnd();


}

void GLPlayer::actions()
{

}
