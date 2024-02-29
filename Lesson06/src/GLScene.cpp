#include "GLScene.h"
#include<GLLight.h>
#include<GLTexture.h>
#include<GLModel.h>
#include<GLInputs.h>

GLTexture *teapotTex = new GLTexture();  // texture object
GLModel *teaPotModel = new GLModel();    // model object
GLInputs *KbMs       = new GLInputs();   // keyboard and Mouse

GLScene::GLScene()
{
    //ctor
}

GLScene::~GLScene()
{
    //dtor
}

GLint GLScene::initGL()
{
    glShadeModel(GL_SMOOTH); // for smooth render
    glClearColor(0.0f,0.0f,0.0f,0.0f); // clear background to black
    glClearDepth(2.0f);            // depth test for layers
    glEnable(GL_DEPTH_TEST);       // activate depth test
    glDepthFunc(GL_LEQUAL);         // depth function type

    GLLight Light(GL_LIGHT0);
    Light.setLight(GL_LIGHT0);

    glEnable(GL_TEXTURE_2D);  //enable textures
    teapotTex->loadTexture("images/teapot.jpg");//load texture
    return true;
}

GLint GLScene::drawScene()    // this function runs on a loop
                              // DO NOT ABUSE ME
{
   glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);// clear bits in each itterration
   glLoadIdentity();
   glTranslatef(0.0,0.0,-8.0); //translate object to xyz

   glColor3f(1.0,1.0,1.0);     //color the object red

   teapotTex->bindTexture();   //activate texture handler
   glPushMatrix();             //group object
     teaPotModel->drawModel();   // draw model obj
   glPopMatrix();              // exit group

   return true;
}

GLvoid GLScene::resizeScene(GLsizei width, GLsizei height)
{
    GLfloat aspectRatio = (GLfloat)width/(GLfloat)height; // keep track of the ratio
    glViewport(0,0,width,height); // adjusting the viewport
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45,aspectRatio,0.1,100.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

int GLScene::windMsg(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch(uMsg)   // check for inputs
    {
        case WM_KEYDOWN:
             KbMs->wParam = wParam;
             KbMs->keyPress(teaPotModel);
             break;

         case WM_KEYUP:
             KbMs->wParam = wParam;
             KbMs->keyUP();
             break;

         case WM_LBUTTONDOWN:
            KbMs->wParam = wParam;
            KbMs->mouseEventDown(teaPotModel, LOWORD(lParam), HIWORD(lParam));
            break;

        case WM_RBUTTONDOWN:
            KbMs->wParam = wParam;
            KbMs->mouseEventDown(teaPotModel, LOWORD(lParam), HIWORD(lParam));
            break;

        case WM_LBUTTONUP:
        case WM_RBUTTONUP:
        case WM_MBUTTONUP:
            KbMs->mouseEventUP();
            break;

        case WM_MOUSEMOVE:
            KbMs->mouseMove(teaPotModel, LOWORD(lParam), HIWORD(lParam));
            break;

        case WM_MOUSEWHEEL:
            KbMs->wParam = wParam;
            KbMs->mouseWheel(teaPotModel, (double)GET_WHEEL_DELTA_WPARAM(wParam));
            break;
    }
}


