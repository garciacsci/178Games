#ifndef GLINPUTS_H
#define GLINPUTS_H

#include <GLModel.h>
#include <GLParallax.h>
#include <GLPlayer.h>
#include <common.h>


class GLInputs
{
    public:
        GLInputs();
        virtual ~GLInputs();

        void keyPress(GLModel*, GLPlayer*);    // when key pressed
        void keyUp(GLPlayer*);               // when key released
        void keyBackground(GLParallax *, float);    // parallax model & speed

        void mouseEventDown(GLModel *, double, double); // mouse button pressed
        void mouseEventUp();                            // mouse button released
        void mouseWheel(GLModel *, double);             // mouse wheel rolled
        void mouseMove(GLModel *, double, double);      // mouse moved

        double prev_MouseX;     // current mouse X location before action
        double prev_MouseY;     // current mouse Y location before action

        bool mouse_Translate;   // if mouse moved
        bool mouse_Rotate;      // if mouse moved for rotation

        WPARAM wParam;          // catching input interrupts

    protected:

    private:
};

#endif // GLINPUTS_H