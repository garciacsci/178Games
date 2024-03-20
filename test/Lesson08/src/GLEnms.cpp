#include <GLEnms.h>

GLEnms::GLEnms()
{
    //ctor


    // Default Position Settings //
    pos.x = 0;
    pos.y = 0;
    pos.z = -5;

    // Default Scaling Settings //
    eScale.x = 1;
    eScale.y = 1;
    
    // Default Rotation Settings //
    eRotate.x = 0;
    eRotate.y = 0;
    eRotate.z = 0;

    // Animation Settings //
    framesX = 0; // num columns for sprite sheet
    framesY = 0; // num rows for sprite sheet

    xMax = 1.0/framesX; // default image
    xMin = 0;
    yMax = 1.0/framesY;
    yMin = 0;

    speed = 0.01;   // moving speed
    action = 0;     // set action



}

GLEnms::~GLEnms()
{
    //dtor
}

void GLEnms::drawEnemy()
{
    glPushMatrix();
    glTranslatef(pos.x,pos.y,pos.z);

    glScalef(eScale.x,eScale.y,1.0);

    glRotatef(eRotate.x,1,0,0);
    glRotatef(eRotate.y,0,1,0);
    glRotatef(eRotate.z,0,0,1);



    glBegin(GL_QUADS);
        glTexCoord2f(xMin,yMax);
        glVertex3f(-1, -1, 0);

        glTexCoord2f(xMax,yMax);
        glVertex3f(1, -1, 0);

        glTexCoord2f(xMax,yMin);
        glVertex3f(1, 1, 0);

        glTexCoord2f(xMin,yMin);
        glVertex3f(-1, 1, 0);
    glEnd();

    glPopMatrix();
}

void GLEnms::PlaceEnemy(vec3 p)
{
    pos.x = p.x;
    pos.y = p.y;
    pos.z = p.z;


}

void GLEnms::actions()
{
    switch(action)
    {
        case 0:
            xMin += 1.0/framesX;
            xMax += 1.0/framesX;

            // Select second row of sprite sheet
            yMin = 0.5;
            yMax = 1.0;

        case 1:
            xMin += 1.0/framesX;
            xMax += 1.0/framesX;

            yMin = 0.0;
            yMax = 0.5;
    }

}