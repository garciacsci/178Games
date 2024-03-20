#include "GLScene.h"
#include <GLLight.h>
#include <GLTexture.h>
#include <GLModel.h>
#include <GLInputs.h>
#include <GLParallax.h>
#include <GLPlayer.h>
#include <GLEnms.h>
#include <GLTimer.h>

GLTexture *teapotTex = new GLTexture();     // texture object
GLModel *teapotModel = new GLModel();       // model object
GLInputs *KbMs       = new GLInputs();      // keyboard and mouse
GLParallax *plx      = new GLParallax();    // parallax
GLParallax *plx1     = new GLParallax();    // parallax
GLPlayer *pl         = new GLPlayer();      // player

GLTexture *EnmsTex      = new GLTexture();     // enemy texture
GLEnms E[20];

GLTimer *T = new GLTimer();

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
    glShadeModel(GL_SMOOTH);            // for smooth render
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);  // background to given color
    glClearDepth(1.0f);                 // depth test for layers
    glEnable(GL_DEPTH_TEST);            // activate depth test
    glDepthFunc(GL_LEQUAL);             // depth function

    GLLight Light(GL_LIGHT0);
    Light.setLight(GL_LIGHT0);

    glEnable(GL_BLEND);                                 // transparent effect on pngs
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glEnable(GL_TEXTURE_2D);            // enable texture handler
    teapotTex->loadTexture("images/marble.jpg");    // load texture
    //plx->parallaxInit("images/parallax1.png");
    plx->parallaxInit("images/pax.jpg");
    pl->initPlayer(10,8, "images/link.png");
    pl->actionTrigger = pl->STAND;

    EnmsTex->loadTexture("images/enemy.png");

    for(int i=0; i<20; i++)
    {
        E[i].pos.x = (float)rand()/(float)RAND_MAX*5-2.5;
        E[i].pos.y = -0.5;
    }

    return true;
}

GLint GLScene::drawScene()      // this function runs on a loop
                                // DO NOT ABUSE ME
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);     // clear bits in each iteration

    glLoadIdentity();
    glTranslatef(0.0,0.0,-15.0);    // translate object to xyz
    glColor3f(1.0,1.0,1.0);         // color the object

    glPushMatrix();                 // group object
        glScalef(10,10,1.0);        // scale parallax image for background
        glDisable(GL_LIGHTING);

        plx1->parallaxDraw(screenWidth, screenHeight);      // draw parallax
        plx->parallaxDraw(screenWidth, screenHeight);       // draw parallax
        //plx->parallaxScroll(true,"left",0.01);              // parallax Auto mode
        plx->parallaxScroll(false,"left",0.01);             // parallax User mode
        glEnable(GL_LIGHTING);
    glPopMatrix();
    
    glPushMatrix();
        EnmsTex->bindTexture();
        for(int i=0; i<20; i++)
        {
            E[i].drawEnemy();
            E[i].actions();
        }
    glPopMatrix();

    glPushMatrix();
        glDisable(GL_LIGHTING);
        pl->drawPlayer();
        pl->actions();
        glEnable(GL_LIGHTING);
    glPopMatrix();

    teapotTex->bindTexture();       // activate texture handler
    glPushMatrix();                 // group object
        teapotModel->drawModel();   // draw model obj
    glPopMatrix();                  // exit group
    

    EnmsTex->bindTexture();
    glDisable(GL_LIGHTING);
    for(int i=0; i<20; i++)
    {
        if(E[i].pos.x > 2.0) {
            E[i].action = 0;
            E[i].speed = -0.01;
        }

        if(E[i].pos.x < -2.0) {
            E[i].action = 1;
            E[i].speed = 0.01;
        }

        E[i].drawEnemy();
        E[i].actions();
    }

    return true;
}

GLvoid GLScene::resizeScene(GLsizei width, GLsizei height)
{
    GLfloat aspectRatio = (GLfloat)width/(GLfloat)height;   // keep track of the ratio
    glViewport(0,0,width,height);                           // adjusting the viewport
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45,aspectRatio,0.1,100.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

int GLScene::windMsg(HWND hWhd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch(uMsg)    // check for inputs
    {
    case WM_KEYDOWN:
        KbMs->wParam = wParam;
        KbMs->keyPress(teapotModel, pl);
        KbMs->keyBackground(plx,0.05);
        KbMs->keyBackground(plx1,0.005);
        break;

    case WM_KEYUP:
        KbMs->wParam = wParam;
        KbMs->keyUp(pl);
        break;

    case WM_LBUTTONDOWN:
        KbMs->wParam = wParam;
        KbMs->mouseEventDown(teapotModel,LOWORD(lParam),HIWORD(lParam));
        break;

    case WM_RBUTTONDOWN:
        KbMs->wParam = wParam;
        KbMs->mouseEventDown(teapotModel,LOWORD(lParam),HIWORD(lParam));
        break;

    case WM_LBUTTONUP:
    case WM_RBUTTONUP:
    case WM_MBUTTONUP:
        KbMs->mouseEventUp();
        break;

    case WM_MOUSEMOVE:
        KbMs->wParam = wParam;
        KbMs->mouseMove(teapotModel,LOWORD(lParam),HIWORD(lParam));
        break;

    case WM_MOUSEWHEEL:
        KbMs->mouseWheel(teapotModel,(double)GET_WHEEL_DELTA_WPARAM(wParam));
        break;
    }
}


