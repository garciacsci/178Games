#ifndef GLPLAYER_H
#define GLPLAYER_H

#include<common.h>
#include<GLTexture.h>
#include<GLTimer.h>

class GLPlayer
{
    public:
        GLPlayer();
        virtual ~GLPlayer();

        GLTexture *texture = new GLTexture();
        GLTimer   *myTime = new GLTimer();

        void initPlayer();
        void drawPlayer();

        vec3 plPosition;
        float xMax,xMin,yMax,yMin;

    protected:

    private:
};

#endif // GLPLAYER_H
