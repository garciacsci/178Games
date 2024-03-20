#include "GLPlayer.h"

GLPlayer::GLPlayer()
{
    //ctor
    verts[0].x = -0.5; verts[0].y = -0.5; verts[0].z = -1.0;
    verts[1].x =  0.5; verts[1].y = -0.5; verts[1].z = -1.0;
    verts[2].x =  0.5; verts[2].y =  0.5; verts[2].z = -1.0;
    verts[3].x = -0.5; verts[3].y =  0.5; verts[3].z = -1.0;

}

GLPlayer::~GLPlayer()
{
    //dtor
}

void GLPlayer::initPlayer(int x, int y, char* fileName)
{
    plPosition.x = 0.0; // initialize positions, can change to anywhere you want
    plPosition.y = -1.5;
    plPosition.z = 10.0;

    plScale.x = 1.0;    // initialize scale
    plScale.y = 1.0;
    plScale.z = 1.0;

    framesX = x;        // record number of frames
    framesY = y;

    texture->loadTexture(fileName);

    xMin = 0;
    yMax = 5.0/(float)framesY;
    xMax = 1.0/(float)framesX;
    yMin = yMax-1.0/(float)framesY;


    actionTrigger = 0;
    myTime->startTime = clock();
}

void GLPlayer::drawPlayer()
{
    glTranslatef(plPosition.x,plPosition.y,plPosition.z);
    glScalef(plScale.x,plScale.y,plScale.z);

    glColor3f(1.0,1.0,1.0);  // white rectangle
    texture->bindTexture();  // binding my texture

    glBegin(GL_QUADS);
        glTexCoord2f(xMin,yMax);
        glVertex3f(verts[0].x,verts[0].y,verts[0].z);

        glTexCoord2f(xMax,yMax);
        glVertex3f(verts[1].x,verts[1].y,verts[1].z);

        glTexCoord2f(xMax,yMin);
        glVertex3f(verts[2].x,verts[2].y,verts[2].z);

        glTexCoord2f(xMin,yMin);
        glVertex3f(verts[3].x,verts[3].y,verts[3].z);
    glEnd();
}

void GLPlayer::actions()
{
    if(clock() - myTime-> startTime > 60)   // frame rate
    {
        switch(actionTrigger)
        {
        case STAND:
            xMin = 0;
            xMax = 1.0/(float)framesX;
            yMax = 2.0/(float)framesY;
            yMin = yMax-1.0/(float)framesY;
            break;

        case WALKRIGHT:
            yMax = 8.0/(float)framesY;
            yMin = yMax-1.0/(float)framesY;
            xMin += 1.0/(float)framesX;
            xMax += 1.0/(float)framesX;
            break;

        case WALKLEFT:
            yMax = 6.0/(float)framesY;
            yMin = yMax-1.0/(float)framesY;
            xMin += 1.0/(float)framesX;
            xMax += 1.0/(float)framesX;
            break;

        case RUN:
            break;

        case JUMP:
            break;

        case ATTACK:
            break;

        default:
            break;
        }
        myTime->startTime = clock();
    }   // end of timer
}
