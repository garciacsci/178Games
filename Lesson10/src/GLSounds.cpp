#include <GLSounds.h>
#include <common.h>

GLSounds::GLSounds() {

}

GLSounds::~GLSounds() {

}

void GLSounds::playMusic(char* File) {

    engine->play2D(File, true);

}


void GLSounds::playSound(char* File) {

    if(!engine -> isCurrentlyPlaying(File))
        engine->play2D(File, false, false);

}

void GLSounds::pauseSound(char* File) {

    engine->play2D(File, true, false);

}


int GLSounds::initSound() {

    if(!engine) {cout << " ERROR: *** The Sound Engine Could Not Start" << endl;
        return(EXIT_FAILURE);}

    return EXIT_SUCCESS;

}