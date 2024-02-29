#include "GLScene.h"
#include<GLLight.h>
#include<GLTexture.h>
#include<GLModel.h>
#include<GLInputs.h>
#include<GLParallax.h>
#include <GLPlayer.h>

GLTexture *teapotTex = new GLTexture();  // texture object
GLModel *teaPotModel = new GLModel();    // model object
GLInputs *KbMs       = new GLInputs();   // keyboard and Mouse
GLParallax *plx      = new GLParallax(); // parallax

GLParallax *plx1     = new GLParallax(); // parallax
GLPlayer *pl         = new GLPlayer();

GLScene::GLScene()
{
    //ctor

    screenWidth  = GetSystemMetrics(SM_CXSCREEN);
    screenHeight = GetSystemMetrics(SM_CYSCREEN);
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

    glEnable(GL_BLEND);             // Transparent effect of pngs
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glEnable(GL_TEXTURE_2D);  //enable textures
    teapotTex->loadTexture("images/teapot.jpg");//load texture
    plx->parallaxInit("images/p.png");
    plx1->parallaxInit("images/plx.png");
    pl->initPlayer(5,2,"images/player.png");
    pl->actionTrigger= pl->WALK;

    return true;
}

GLint GLScene::drawScene()    // this function runs on a loop
                              // DO NOT ABUSE ME
{
   glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);// clear bits in each itterration
   glLoadIdentity();
   glColor3f(1.0,1.0,1.0);     //color the object red

   glPushMatrix(); //group object

     glScaled(3.33,3.33,1.0);
     glDisable(GL_LIGHTING);

     plx1->parallaxDraw(screenWidth,screenHeight);   // draw model obj
     plx->parallaxDraw(screenWidth,screenHeight);   // draw model obj
   //  plx->parallaxScroll(true,"left", 0.01);      // parallax Auto mode
     glEnable(GL_LIGHTING);
   glPopMatrix();

   glPushMatrix();
    glDisable(GL_LIGHTING);
    pl->drawPlayer();
    pl->actions();
    glEnable(GL_LIGHTING);


   teapotTex->bindTexture();   //activate texture handler
   glPushMatrix();             //group object
     teaPotModel->drawModel();   // draw model obj
   glPopMatrix();              // exit group

   pl->drawPlayer();

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
         KbMs->keyBackground(plx,0.005);
         KbMs->keyBackground(plx1,0.001);
         break;

    case WM_KEYUP:
         KbMs->wParam = wParam;
         KbMs->keyUP();
         break;

    case WM_LBUTTONDOWN:
         KbMs->wParam = wParam;
         KbMs->mouseEventDown(teaPotModel,LOWORD(lParam),HIWORD(lParam));
         break;

    case WM_RBUTTONDOWN:
         KbMs->wParam = wParam;
         KbMs->mouseEventDown(teaPotModel,LOWORD(lParam),HIWORD(lParam));
         break;

    case WM_LBUTTONUP:
    case WM_RBUTTONUP:
    case WM_MBUTTONUP:
        KbMs->mouseEventUp();
        break;

    case WM_MOUSEMOVE:
        KbMs->wParam = wParam;
        KbMs->mouseMove(teaPotModel,LOWORD(lParam),HIWORD(lParam));
         break;
    case WM_MOUSEWHEEL:

        KbMs->mouseWheel(teaPotModel, (double)GET_WHEEL_DELTA_WPARAM(wParam));
       break;
    }
}


