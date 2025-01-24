



#include <stdio.h>
#include <windows.h>  // Header File For Windows
#include <gl\gl.h>   // Header File For The OpenGL32 Library
#include <gl\glu.h>   // Header File For The GLu32 Library
#include <glaux.h>  // Header File For The Glaux Library
#include "texture.h"
#include <cmath>
#include "Model_3DS.h"
#include "gltexture.h"

#include "3DTexture.h"
#include "Point.h"
#include <Windows.h>
#include <MMSystem.h>


HDC   hDC = NULL;  // Private GDI Device Context
HGLRC  hRC = NULL;  // Permanent Rendering Context
HWND  hWnd = NULL;  // Holds Our Window Handle
HINSTANCE hInstance;  // Holds The Instance Of The Application

bool keys[256];   // Array Used For The Keyboard Routine
bool active = TRUE;  // Window Active Flag Set To TRUE By Default
bool fullscreen = TRUE; // Fullscreen Flag Set To Fullscreen Mode By Default

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM); // Declaration For WndProc


float angle = 0;

//Model_3DS *tree;
//GLTexture BARK,Leaf;

Model_3DS *tree, * carModel;
GLTexture BARK,Leaf;
Model_3DS* fountain;
GLTexture water,stone_brushed,tile_boarder, translucent_glass,tile_various;




GLvoid ReSizeGLScene(GLsizei width, GLsizei height)  // Resize And Initialize The GL Window
{
 if (height == 0)          // Prevent A Divide By Zero By
 {
  height = 1;          // Making Height Equal One
 }

 glViewport(0, 0, width, height);      // Reset The Current Viewport

 glMatrixMode(GL_PROJECTION);      // Select The Projection Matrix
 glLoadIdentity();         // Reset The Projection Matrix

              // Calculate The Aspect Ratio Of The Window
 gluPerspective(45.0f, (GLfloat)width / (GLfloat)height, 0.1f, 1000.0f);

 glMatrixMode(GL_MODELVIEW);       // Select The Modelview Matrix
 glLoadIdentity();         // Reset The Modelview Matrix
}

int skyBox;
int gress;
int carpet;
int wall2;
int wall3;
int wall4;
int wall;
int aqsafront;
int aqsaside;
int qmosque;
int walk;
int glass;
int wood2,wood;
int street;
int library;
int libraryname;
int clo1, clo2, clo3, clo4, clo5, clo6, clo7, clo8, clo9,clo10,clo11,clo12,clo14,clo15,clo16;
int r1,r2,r3,r4,r5,r6;
int dro1,dro2,dro3;
int liz;
int liz2;
int walk2;
int building;
int screen;
int ticket;
int wall5;
int wall6;
int roof;
int maxres;
int poncorn;
int coca;
int groundSkybox;
int groundWallTexture2;
int drinkcloset ;
int drinkcloset2 ;
int barcloset ;
int barBG ;
int barfront ;

GLfloat LightDir1[] = { 0.0f,0.0f,-60.0f,1.0f };
GLfloat LightPos1[] = { 0.0f,9.8f,11.5f,1.0f };

GLfloat LightAmb1[] = { 0.1f, 0.1f, 0.3f, 1.0f };
GLfloat LightDiff1[] = { 0.3f, 0.3f, 0.6f, 1.0f };
GLfloat LightSpec1[] = { 0.1f, 0.1f, 0.1f, 1.0f };

GLfloat LightDir2[] = { 0.0f,0.0f,-60.0f,1.0f };
GLfloat LightPos2[] = { 0.0f,9.8f,-11.5f,1.0f };

GLfloat LightAmb2[] = { 0.7,0.3222f,0.3f,1.0f };
GLfloat LightDiff2[] = { 0.6f,0.6f,0.6f,1.0f };
GLfloat LightSpec2[] = { 0.2f,0.2f,0.2f,1.0f };


GLfloat MatAmb[] = { 1.0f,0.0f,0.0f,1.0f };
GLfloat MatDif[] = { 0.6f,0.6f,0.6f,1.0f };
GLfloat MatSpec[] = { 0.2f,0.2f,0.2f,1.0f };

GLfloat MatShn[] = { 128.0f };
int InitGL(GLvoid)          // All Setup For OpenGL Goes Here
{
	 glShadeModel(GL_SMOOTH);       // Enable Smooth Shading
	 glClearColor(0.0f, 0.0f, 0.0f, 0.5f);    // Black Background
	 glClearDepth(1.0f);         // Depth Buffer Setup
	 glEnable(GL_DEPTH_TEST);       // Enables Depth Testing
	 glDepthFunc(GL_LEQUAL);        // The Type Of Depth Testing To Do
	 glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST); // Really Nice Perspective Calculations
	 glEnable(GL_TEXTURE_2D);
	 glEnable(GL_BLEND); 
     glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	
	  skyBox = LoadTexture("texture/skyBox.bmp", 255);
	 carpet = LoadTexture("texture/carpet.bmp", 255);
	 aqsafront = LoadTexture("texture/aqsafront.bmp", 255);
	 wall2 = LoadTexture("texture/wall3.bmp", 255);
	 wall3 = LoadTexture("texture/wall3.bmp", 255);
	 walk = LoadTexture("texture/grass1.bmp", 255);
	 walk2 = LoadTexture("texture/walk.bmp", 255);
	 wall4=LoadTexture("texture/wall4.bmp",255);
	 wall5=LoadTexture("texture/wall5.bmp",255);
	 wall6=LoadTexture("texture/wall6.bmp",255);
	 glass=LoadTexture("texture/glass.bmp",100);
	 wood2 =LoadTexture("texture/wood2.bmp",255);
	  wood =LoadTexture("texture/wood.bmp",255);
	 street=LoadTexture("texture/street.bmp",255);
	 liz=LoadTexture("texture/liz.bmp",255);
	 liz2=LoadTexture("texture/liz2.bmp",255);
	 library =LoadTexture("texture/library.bmp",255);
	 libraryname=LoadTexture("texture/libraryname.bmp",255);
	 building =LoadTexture("texture/building.bmp",255);
	 screen =LoadTexture("texture/cinema.bmp",255);
	 ticket =LoadTexture("texture/ticket.bmp",255);
	 roof =LoadTexture("texture/roof.bmp",255);
	 maxres=LoadTexture("texture/maxres.bmp",255);
	 poncorn=LoadTexture("texture/poncorn.bmp",255);
	 coca=LoadTexture("texture/coca.bmp",255);
	 drinkcloset=  LoadTexture("texture/drinkcloset.bmp", 255);
	barcloset = LoadTexture("texture/barcloset.bmp", 255);
	drinkcloset2 = LoadTexture("texture/drinkcloset2.bmp", 255);
	barBG = LoadTexture("texture/barbg.bmp", 255);
	barfront = LoadTexture("texture/barFront.bmp", 255);

	 clo8 = LoadTexture((char*)"mallTexture/8.bmp");
	clo1 = LoadTexture((char*)"mallTexture/1.bmp");
	clo9 = LoadTexture((char*)"mallTexture/9.bmp");
	clo2 = LoadTexture((char*)"mallTexture/2.bmp");
	clo3 = LoadTexture((char*)"mallTexture/3.bmp");
	clo6 = LoadTexture((char*)"mallTexture/6.bmp");
	clo4 = LoadTexture((char*)"mallTexture/4.bmp");
	clo5 = LoadTexture((char*)"mallTexture/5.bmp");
	clo7 = LoadTexture((char*)"mallTexture/7.bmp");
	clo10 = LoadTexture((char*)"mallTexture/10.bmp");
	clo11 = LoadTexture((char*)"mallTexture/11.bmp");
	clo12 = LoadTexture((char*)"mallTexture/12.bmp");
	clo14 = LoadTexture((char*)"mallTexture/14.bmp");
	clo15 = LoadTexture((char*)"mallTexture/15.bmp");
	clo16 = LoadTexture((char*)"mallTexture/16.bmp");
	r1 = LoadTexture((char*)"mallTexture/r1.bmp");
	r2 = LoadTexture((char*)"mallTexture/r2.bmp");
	r3 = LoadTexture((char*)"mallTexture/r3.bmp");
	r4 = LoadTexture((char*)"mallTexture/r4.bmp");
	r5 = LoadTexture((char*)"mallTexture/r5.bmp");
	r6 = LoadTexture((char*)"mallTexture/r6.bmp");
	dro1 = LoadTexture((char*)"mallTexture/dro1.bmp");
	dro2 = LoadTexture((char*)"mallTexture/dro2.bmp");
	dro3 = LoadTexture((char*)"mallTexture/dro3.bmp");
	groundSkybox = LoadTexture((char*)"texture/groundSkybox.bmp");
	groundWallTexture2 = LoadTexture((char*)"texture/kk.bmp");



	tree = new Model_3DS();
	tree->Load("models/Tree1.3DS");
	Leaf.LoadBMP("models/bat.bmp");
	BARK.LoadBMP("models/bark_loo.bmp");


	tree->Materials[0].tex=BARK;
	tree->Materials[1].tex=Leaf;
	tree->Materials[2].tex=Leaf;
	tree->Materials[3].tex=Leaf;
	tree->Materials[4].tex=Leaf;


	tree->pos.x=0;
	tree->pos.y=0;
	tree->pos.z=0;
	tree->scale=1;

		glLightfv(GL_LIGHT1, GL_POSITION, LightPos1);
	glLightfv(GL_LIGHT1, GL_AMBIENT, LightAmb1);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, LightDiff1);
	glLightfv(GL_LIGHT1, GL_SPECULAR, LightSpec1);

	glLightfv(GL_LIGHT2, GL_POSITION, LightPos2);
	glLightfv(GL_LIGHT2, GL_AMBIENT, LightAmb2);
	glLightfv(GL_LIGHT2, GL_DIFFUSE, LightDiff2);
	glLightfv(GL_LIGHT2, GL_SPECULAR, LightSpec2);


	glMaterialfv(GL_FRONT, GL_AMBIENT, MatAmb);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, MatDif);
	glMaterialfv(GL_FRONT, GL_SPECULAR, MatSpec);
	glMaterialfv(GL_FRONT, GL_SHININESS, MatShn);

	carModel = new Model_3DS();
	carModel->Load((char*)"models/car/car.3DS");
	carModel->Materials[0].tex.LoadBMP((char*)"models/car/car.bmp");
	carModel->Materials[1].tex.LoadBMP((char*)"models/car/glass1.bmp");
	carModel->Materials[2].tex.LoadBMP((char*)"models/car/glass2.bmp");
	carModel->scale = 0.2;
	carModel->rot.y = 270;
	carModel->pos.x = 75;
	carModel->pos.y = 4.5;
	carModel->pos.z = -15;

	fountain = new Model_3DS();
	fountain->Load("models/fountain.3ds");

	fountain->pos.x = 38;
	fountain->pos.y = 1.0;
	fountain->pos.z = 28;
	fountain->scale = 0.009;

	water.LoadBMP("models/water.bmp");
	stone_brushed.LoadBMP("models/stone_brushed.bmp");
	tile_boarder.LoadBMP("models/tile_boarder.bmp");
	translucent_glass.LoadBMP("models/translucent_glass1.bmp");
	tile_various.LoadBMP("models/tile_various.bmp");

	fountain->Materials[1].tex = water;
	fountain->Materials[3].tex = stone_brushed;
	fountain->Materials[5].tex = tile_boarder;
	fountain->Materials[7].tex = translucent_glass;
	fountain->Materials[10].tex = tile_various;

	PlaySound(TEXT("sounds/lost-in-dreams.wav"),NULL,SND_FILENAME | SND_ASYNC);
	 return TRUE;
}
void drawSquare(float x, float y) {
 glBegin(GL_QUADS);
 glVertex3f(x, y, 0);
 glVertex3f(0, y, 0);
 glVertex3f(0, 0, 0);
 glVertex3f(x, 0, 0);
 glEnd();
}
void drawSquareWithPhoto(float x, float y, int photo)
{
	glBindTexture(GL_TEXTURE_2D, photo);

	glBegin(GL_QUADS);
	glTexCoord2d(1,1);
	glVertex3f(x, y, 0);
	glTexCoord2d(0,1);
	glVertex3f(0, y, 0);
	glTexCoord2d(0,0);
	glVertex3f(0, 0, 0);
	glTexCoord2d(1,0);
	glVertex3f(x, 0, 0);
	glEnd();
}
void drawSquareWithPhotoAndRepeating(float x, float y, int photo, int repeatX, int repeatY)
{
	glBindTexture(GL_TEXTURE_2D, photo);

	glBegin(GL_QUADS);
	glTexCoord2d(repeatX,repeatY);
	glVertex3f(x, y, 0);
	glTexCoord2d(0,repeatY);
	glVertex3f(0, y, 0);
	glTexCoord2d(0,0);
	glVertex3f(0, 0, 0);
	glTexCoord2d(repeatX,0);
	glVertex3f(x, 0, 0);
	glEnd();
}

void drawSquareWithSpecificPoints(float x, float y, int photo, float firstPointX, float firstPointY, float secondPointX, float secondPointY, float thirdPointX, float thirdPointY, float fourthPointX, float fourthPointY)
{
	
	glBindTexture(GL_TEXTURE_2D, photo);

	glBegin(GL_QUADS);
	glTexCoord2d(firstPointX,firstPointY);
	glVertex3f(0, 0, 0);
	glTexCoord2d(secondPointX, secondPointY);
	glVertex3f(x, 0, 0);
	glTexCoord2d(thirdPointX,thirdPointY);
	glVertex3f(x, y, 0);
	glTexCoord2d(fourthPointX,fourthPointY);
	glVertex3f(0, y, 0);
	glEnd();
}
void SkyBox(double x)
{
	glPushMatrix();

	glTranslated(-x/2.0,0,-x/2.0);
	drawSquareWithSpecificPoints(x,2* (x/3),skyBox,0.25, 0.333+0.333/3.0 ,0.5 ,0.333+0.333/3.0 ,0.5,0.666,0.25,0.666);

	

	glRotated(90,0,1,0);
	glTranslated(-x,0,0);
	drawSquareWithSpecificPoints(x,2 * (x/3),skyBox,0,0.333+0.333/3,0.25,0.333+0.333/3,0.25,0.666,0,0.666);
	

	glRotated(90,0,1,0);
	glTranslated(-x,0,0);
	drawSquareWithSpecificPoints(x,2 * (x/3),skyBox,0.75, 0.333+0.333/3 ,1 ,0.333+0.333/3 ,1 ,0.666 ,0.75 ,0.666);
	

	glRotated(90,0,1,0);
	glTranslated(-x,0,0);
	drawSquareWithSpecificPoints(x,2 * (x/3),skyBox,0.5, 0.333+0.333/3, 0.75, 0.333+0.333/3, 0.75, 0.666, 0.5, 0.666);
	glPopMatrix();
	
	glPushMatrix();
	
	//up
	glRotated(90,1,0,0);
	glTranslated(-x/2.0,-x/2.0,-2 * (x/3));
	drawSquareWithSpecificPoints(x,x,skyBox,0.25,0.666,0.5,0.666,0.5,1,0.25,1);

	//down
	glTranslated(0,0,2 * (x/3));
	drawSquareWithPhotoAndRepeating(x,x,walk,70,70);
	glPopMatrix();
	
}
void drawBox(float x, float y, float z, float width, float height, float depth, int texture) {
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texture);

    glBegin(GL_QUADS);

    // الوجه الأمامي
    glNormal3f(0.0f, 0.0f, 1.0f);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(x, y, z);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(x + width, y, z);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(x + width, y + height, z);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(x, y + height, z);

    // الوجه الخلفي
    glNormal3f(0.0f, 0.0f, -1.0f);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(x + width, y, z - depth); // تغيير ترتيب الرؤوس وإحداثيات النسيج
    glTexCoord2f(1.0f, 1.0f); glVertex3f(x + width, y + height, z - depth);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(x, y + height, z - depth);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(x, y, z - depth);

    // الوجه العلوي
    glNormal3f(0.0f, 1.0f, 0.0f);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(x, y + height, z); // تغيير ترتيب إحداثيات النسيج
    glTexCoord2f(1.0f, 1.0f); glVertex3f(x + width, y + height, z);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(x + width, y + height, z - depth);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(x, y + height, z - depth);

    // الوجه السفلي
    glNormal3f(0.0f, -1.0f, 0.0f);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(x, y, z);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(x + width, y, z);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(x + width, y, z - depth);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(x, y, z - depth);

    // الوجه الأيمن
    glNormal3f(1.0f, 0.0f, 0.0f);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(x + width, y, z); // تغيير ترتيب الرؤوس وإحداثيات النسيج
    glTexCoord2f(1.0f, 1.0f); glVertex3f(x + width, y + height, z);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(x + width, y + height, z - depth);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(x + width, y, z - depth);

    // الوجه الأيسر
    glNormal3f(-1.0f, 0.0f, 0.0f);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(x, y, z);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(x, y + height, z);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(x, y + height, z - depth);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(x, y, z - depth);

    glEnd();
    glDisable(GL_TEXTURE_2D);
}
void drawStairs(float startX, float startY, float startZ, int numSteps, float stepRise, float stepRun, float stepWidth,float sideHeight,int texture, int texture2) {
    for (int i = 0; i < numSteps; i++) {
        float x = startX;
        float y = startY + i * stepRise;
        float z = startZ - i * stepRun;

        drawBox(x, y, z, stepWidth, stepRise, stepRun,texture);
		 glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, texture2);

        glBegin(GL_QUADS);

        // الجانب الأيمن
        glNormal3f(1.0f, 0.0f, 0.0f);
        glTexCoord2f(0.0f, 0.0f); glVertex3f(x + stepWidth, y, z);
        glTexCoord2f(1.0f, 0.0f); glVertex3f(x + stepWidth, y, z - stepRun);
        glTexCoord2f(1.0f, 1.0f); glVertex3f(x + stepWidth, y + sideHeight, z - (i < numSteps - 1 ? stepRun : 0));
        glTexCoord2f(0.0f, 1.0f); glVertex3f(x + stepWidth, y + sideHeight, z);

        // الجانب الأيسر
        glNormal3f(-1.0f, 0.0f, 0.0f);
        glTexCoord2f(0.0f, 0.0f); glVertex3f(x, y, z);
        glTexCoord2f(1.0f, 0.0f); glVertex3f(x, y, z - stepRun);
        glTexCoord2f(1.0f, 1.0f); glVertex3f(x, y + sideHeight, z - (i < numSteps - 1 ? stepRun : 0));
        glTexCoord2f(0.0f, 1.0f); glVertex3f(x, y + sideHeight, z);

        glEnd();

    }
}

void drawTexturedQuad(float x1, float y1, float x2, float y2, float repeatX, float repeatY, int texture) {
    
    glBindTexture(GL_TEXTURE_2D, texture);

    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(x1, y1, 0.0f);
    glTexCoord2f(repeatX, 0.0f); glVertex3f(x2, y1, 0.0f);
    glTexCoord2f(repeatX, repeatY); glVertex3f(x2, y2, 0.0f);
    glTexCoord2f(0.0f, repeatY); glVertex3f(x1, y2, 0.0f);
    glEnd();

    
}
void drawBorderBlock2(double width, double height, double depth, float textureRepeat, int texture) {
    // الوجه الأمامي
    glPushMatrix();
    drawTexturedQuad(0.0f, 0.0f, width, height, width / textureRepeat, height / textureRepeat, texture);
    glPopMatrix();

    // الوجه الخلفي
    glPushMatrix();
    glTranslated(0.0, 0.0, -depth);
    drawTexturedQuad(0.0f, 0.0f, width, height, width / textureRepeat, height / textureRepeat, texture);
    glPopMatrix();

    // الجوانب اليمنى واليسرى
    glPushMatrix();
    glRotated(90.0, 0.0, 1.0, 0.0);
    drawTexturedQuad(0.0f, 0.0f, depth, height, depth / textureRepeat, height / textureRepeat, texture);
    glPopMatrix();

    glPushMatrix();
    glTranslated(width, 0.0, 0.0);
    glRotated(90.0, 0.0, 1.0, 0.0);
    drawTexturedQuad(0.0f, 0.0f, depth, height, depth / textureRepeat, height / textureRepeat, texture);
    glPopMatrix();

    // الجوانب العلوية والسفلية
    glPushMatrix();
    glRotated(-90.0, 1.0, 0.0, 0.0);
    drawTexturedQuad(0.0f, 0.0f, width, depth, width / textureRepeat, depth / textureRepeat, texture);
    glPopMatrix();

    glPushMatrix();
    glTranslated(0.0, -height, 0.0);
    glRotated(-90.0, 1.0, 0.0, 0.0);
    drawTexturedQuad(0.0f, 0.0f, width, depth, width / textureRepeat, depth / textureRepeat, texture);
    glPopMatrix();
}
void drawBorderBlock(double width, double height, double depth, int image)
{
	glPushMatrix();
	drawSquareWithPhotoAndRepeating(width,height,image,width,height);
	glTranslated(0,0,-depth);
	drawSquareWithPhotoAndRepeating(width,height,image,width,height);
	glPopMatrix();

	glPushMatrix();
	glRotated(90,0,1,0);
	drawSquareWithPhotoAndRepeating(depth,height,image,depth,height);
	glTranslated(0,0,width);
	drawSquareWithPhotoAndRepeating(depth,height,image,depth,height);
	glTranslated(0,height,0);
	glRotated(-90,1,0,0);
	drawSquareWithPhotoAndRepeating(depth,width,image,depth,width);
	glTranslated(0,0,-height);
	drawSquareWithPhotoAndRepeating(depth,width,image,depth,width);
	glPopMatrix();
}
void drawLand(double width, double depth, int image)
{
	glPushMatrix();

	glBindTexture(GL_TEXTURE_2D, image);
	glBegin(GL_QUADS);
	glColor3d(1,1,1);
	glTexCoord2d(0.2 * width, 0.2 * depth);
	glVertex3d(width,0,-depth);
	glTexCoord2d(0, 0.2 * depth);
	glVertex3d(0,0,-depth);
	glTexCoord2d(0,0);
	glVertex3d(0,0,0);
	glTexCoord2d(0.2 * width, 0);
	glVertex3d(width,0,0);
	glEnd();
	glPopMatrix();
	
}
void drawLand2(double width, double depth, double thickness, int image)
{
    glPushMatrix();

    glBindTexture(GL_TEXTURE_2D, image);

    // الوجه العلوي (كما كان من قبل)
    glBegin(GL_QUADS);
    glColor3d(1, 1, 1);
    glTexCoord2d(0.2 * width, 0.2 * depth); glVertex3d(width, thickness, -depth);
    glTexCoord2d(0, 0.2 * depth); glVertex3d(0, thickness, -depth);
    glTexCoord2d(0, 0); glVertex3d(0, thickness, 0);
    glTexCoord2d(0.2 * width, 0); glVertex3d(width, thickness, 0);
    glEnd();

    // الوجه السفلي
    glBegin(GL_QUADS);
    glColor3d(1, 1, 1);
    glTexCoord2d(0.2 * width, 0.2 * depth); glVertex3d(width, 0, -depth);
    glTexCoord2d(0, 0.2 * depth); glVertex3d(0, 0, -depth);
    glTexCoord2d(0, 0); glVertex3d(0, 0, 0);
    glTexCoord2d(0.2 * width, 0); glVertex3d(width, 0, 0);
    glEnd();

    // الجوانب
    glBegin(GL_QUADS);
    // الجانب الأمامي
    glTexCoord2d(0, 0); glVertex3d(0, 0, 0);
    glTexCoord2d(0.2 * width, 0); glVertex3d(width, 0, 0);
    glTexCoord2d(0.2 * width, 0.2 * thickness); glVertex3d(width, thickness, 0);
    glTexCoord2d(0, 0.2 * thickness); glVertex3d(0, thickness, 0);
    glEnd();

    glBegin(GL_QUADS);
    // الجانب الخلفي
    glTexCoord2d(0, 0); glVertex3d(0, 0, -depth);
    glTexCoord2d(0.2 * width, 0); glVertex3d(width, 0, -depth);
    glTexCoord2d(0.2 * width, 0.2 * thickness); glVertex3d(width, thickness, -depth);
    glTexCoord2d(0, 0.2 * thickness); glVertex3d(0, thickness, -depth);
    glEnd();

    glBegin(GL_QUADS);
    // الجانب الأيسر
    glTexCoord2d(0, 0); glVertex3d(0, 0, -depth);
    glTexCoord2d(0.2 * depth, 0); glVertex3d(0, 0, 0);
    glTexCoord2d(0.2 * depth, 0.2 * thickness); glVertex3d(0, thickness, 0);
    glTexCoord2d(0, 0.2 * thickness); glVertex3d(0, thickness, -depth);
    glEnd();

    glBegin(GL_QUADS);
    // الجانب الأيمن
    glTexCoord2d(0, 0); glVertex3d(width, 0, -depth);
    glTexCoord2d(0.2 * depth, 0); glVertex3d(width, 0, 0);
    glTexCoord2d(0.2 * depth, 0.2 * thickness); glVertex3d(width, thickness, 0);
    glTexCoord2d(0, 0.2 * thickness); glVertex3d(width, thickness, -depth);
    glEnd();

    glPopMatrix();
}
void drawLand3(double width, double depth, double thickness, int image, float textureRepeat)
{
    glPushMatrix();

    glBindTexture(GL_TEXTURE_2D, image);

    // الوجه العلوي
    glBegin(GL_QUADS);
    glColor3d(1, 1, 1);
    glTexCoord2d(textureRepeat * width, textureRepeat * depth); glVertex3d(width, thickness, -depth);
    glTexCoord2d(0, textureRepeat * depth); glVertex3d(0, thickness, -depth);
    glTexCoord2d(0, 0); glVertex3d(0, thickness, 0);
    glTexCoord2d(textureRepeat * width, 0); glVertex3d(width, thickness, 0);
    glEnd();

    // الوجه السفلي
    glBegin(GL_QUADS);
    glColor3d(1, 1, 1);
    glTexCoord2d(textureRepeat * width, textureRepeat * depth); glVertex3d(width, 0, -depth);
    glTexCoord2d(0, textureRepeat * depth); glVertex3d(0, 0, -depth);
    glTexCoord2d(0, 0); glVertex3d(0, 0, 0);
    glTexCoord2d(textureRepeat * width, 0); glVertex3d(width, 0, 0);
    glEnd();

    // الجوانب
    glBegin(GL_QUADS);
    // الجانب الأمامي
    glTexCoord2d(0, 0); glVertex3d(0, 0, 0);
    glTexCoord2d(textureRepeat * width, 0); glVertex3d(width, 0, 0);
    glTexCoord2d(textureRepeat * width, textureRepeat * thickness); glVertex3d(width, thickness, 0);
    glTexCoord2d(0, textureRepeat * thickness); glVertex3d(0, thickness, 0);
    glEnd();

    glBegin(GL_QUADS);
    // الجانب الخلفي
    glTexCoord2d(0, 0); glVertex3d(0, 0, -depth);
    glTexCoord2d(textureRepeat * width, 0); glVertex3d(width, 0, -depth);
    glTexCoord2d(textureRepeat * width, textureRepeat * thickness); glVertex3d(width, thickness, -depth);
    glTexCoord2d(0, textureRepeat * thickness); glVertex3d(0, thickness, -depth);
    glEnd();

    glBegin(GL_QUADS);
    // الجانب الأيسر
    glTexCoord2d(0, 0); glVertex3d(0, 0, -depth);
    glTexCoord2d(textureRepeat * depth, 0); glVertex3d(0, 0, 0);
    glTexCoord2d(textureRepeat * depth, textureRepeat * thickness); glVertex3d(0, thickness, 0);
    glTexCoord2d(0, textureRepeat * thickness); glVertex3d(0, thickness, -depth);
    glEnd();

    glBegin(GL_QUADS);
    // الجانب الأيمن
    glTexCoord2d(0, 0); glVertex3d(width, 0, -depth);
    glTexCoord2d(textureRepeat * depth, 0); glVertex3d(width, 0, 0);
    glTexCoord2d(textureRepeat * depth, textureRepeat * thickness); glVertex3d(width, thickness, 0);
    glTexCoord2d(0, textureRepeat * thickness); glVertex3d(width, thickness, -depth);
    glEnd();

    glPopMatrix();
}
void drawBorder(double width,double high, double depth)
{
	
	glPushMatrix();

	drawBorderBlock2(0.84 * width, high, high/6.0, 10,wall2);
	glTranslated(0.9 * width, high-25, 0);
	glPopMatrix();


	glPushMatrix();
	glTranslated(0,0,-depth);
	drawBorderBlock2(width, high, high/6.0, 10,wall2);
	glPopMatrix();

	glPushMatrix();
	glRotated(90,0,1,0);
	glTranslated(0,0,high/6);
	drawBorderBlock2(depth + high/6,high,high/6.0,10,wall2);
	glTranslated(0,0,width);
	drawBorderBlock2(depth + high/6,high,high/6.0,10,wall2);

	glPopMatrix();
}
void drawDoor(float width, float height, float depth, int image)
{
    glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, image); 
    glEnable(GL_TEXTURE_2D);  
    glColor3f(1.0f, 1.0f, 1.0f); 
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(0.0f, 0.0f, 0.0f);  // الزاوية السفلى اليسرى
    glTexCoord2f(1.0f, 0.0f); glVertex3f(width, 0.0f, 0.0f);  // الزاوية السفلى اليمنى
    glTexCoord2f(1.0f, 1.0f); glVertex3f(width, height, 0.0f); // الزاوية العليا اليمنى
    glTexCoord2f(0.0f, 1.0f); glVertex3f(0.0f, height, 0.0f); // الزاوية العليا اليسرى
    glEnd();

    // رسم الجهة الخلفية للباب (الجانب المقابل)
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(0.0f, 0.0f, depth);  // الزاوية السفلى اليسرى
    glTexCoord2f(1.0f, 0.0f); glVertex3f(width, 0.0f, depth);  // الزاوية السفلى اليمنى
    glTexCoord2f(1.0f, 1.0f); glVertex3f(width, height, depth); // الزاوية العليا اليمنى
    glTexCoord2f(0.0f, 1.0f); glVertex3f(0.0f, height, depth); // الزاوية العليا اليسرى
    glEnd();

    // رسم الجوانب
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(0.0f, 0.0f, 0.0f);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(0.0f, 0.0f, depth);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(0.0f, height, depth);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(0.0f, height, 0.0f);
    glEnd();

    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(width, 0.0f, 0.0f);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(width, 0.0f, depth);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(width, height, depth);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(width, height, 0.0f);
    glEnd();

    // رسم الأجزاء العلوية والسفلية
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(0.0f, height, 0.0f);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(width, height, 0.0f);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(width, height, depth);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(0.0f, height, depth);
    glEnd();

    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(0.0f, 0.0f, 0.0f);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(width, 0.0f, 0.0f);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(width, 0.0f, depth);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(0.0f, 0.0f, depth);
    glEnd();
    glPopMatrix();
 
}


float left_and_right_angle = -1.57, up_and_down_angle = 0;
float xd = 65, yd = 4.2, zd = 60;
float targetYOffset = 4.0f; 
bool doorOpen = false; 
float doorOffset = 0.0f; 
const float doorSpeed = 0.1f; 
const float doorOpenLimit = 7.0f; 
float moveSpeed = 0.5f;
float counter=2;

void camera()
{
 if (keys[VK_LEFT]) left_and_right_angle -= 0.04;
 if (keys[VK_RIGHT]) left_and_right_angle += 0.04;
 if (keys[VK_UP]) up_and_down_angle += 0.04;
 if (keys[VK_DOWN]) up_and_down_angle -= 0.04;


 if (keys[VK_SPACE]) { yd += 0.9; }  
 if (keys['V']) { yd -= 0.1; }
 if (keys['W']) { zd += 0.5* sin(left_and_right_angle); xd += 0.5*cos(left_and_right_angle); }  // moving Forward 
 if (keys['S']) { zd -= 0.1* sin(left_and_right_angle); xd -= 0.1* cos(left_and_right_angle); }  // moving Backward 
 if (keys['A']) { zd += 0.1*sin(left_and_right_angle - 1.57); xd += 0.1* cos(left_and_right_angle - 1.57); }  //moving to the Left. (moving to Right/Left is the same as moving Forward/Backward but with a different angle. 
 if (keys['D']) { zd -= 0.1*sin(left_and_right_angle - 1.57); xd -= 0.1* cos(left_and_right_angle - 1.57); }  //moving to the Right 


	
	if ( xd >= -34 && xd <= -12 && zd >= -2.5 && zd <= 1.5 && yd < 25 ) {
			 xd-=0.08;
			 yd+=0.08;
	}
	if ( xd >= -34 && xd <= -12 && zd >= -6.5 && zd <= -3.5  && yd >3 &&yd < 25 ) {
			 xd+=0.08;
			 yd-=0.08;
	}
	if ( xd >= -13 && xd <= 8 && zd >= -38 && zd <= -35 && yd >21  ) {
			 xd+=0.08;
			 yd+=0.08;
	}
	if ( xd >= -13 && xd <= 8 && zd >= -44 && zd <= -40 && yd >21  ) {
			 xd-=0.08;
			 yd-=0.08;
	}
	

 
    if (keys['o'] || keys['O']) {
    if (!doorOpen && doorOffset < 7.0f) {
        doorOffset += doorSpeed; 
        if (doorOffset >= 7.0f) { 
            doorOffset = 7.0f;
            doorOpen = true;
        }
    }
}

if (keys['c'] || keys['C']) {
    if (doorOpen && doorOffset > 0.0f) {
        doorOffset -= doorSpeed; 
        if (doorOffset <= 0.0f) { 
            doorOffset = 0.0f;
            doorOpen = false; 
        }
    }
}
if(keys['N']) {
	glEnable(GL_LIGHT1);
	glEnable(GL_LIGHTING);
	glEnable(GL_COLOR_MATERIAL);
} else if(keys['M']) {
	glDisable(GL_LIGHT1);
	glDisable(GL_LIGHTING);
	glDisable(GL_COLOR_MATERIAL);
}
if((yd<22 && counter==2)||(yd<22&& counter==5)){
  PlaySound(TEXT("sounds/lost-in-dreams.wav"),NULL,SND_FILENAME | SND_ASYNC);	
  counter+=1;
	}
	
  if(yd>22 && counter==3){

	   PlaySound(TEXT("sounds/just-relax.wav"),NULL,SND_FILENAME | SND_ASYNC);	
	   counter+=1;
	}
  if(yd>40 && counter==4){

	   PlaySound(TEXT("sounds/horror.wav"),NULL,SND_FILENAME | SND_ASYNC);	
	   counter+=1;
	}
 gluLookAt(xd, yd, zd, cos(left_and_right_angle) + xd, sin(up_and_down_angle) + yd, sin(left_and_right_angle) + zd, 0, 1, 0);

}
void glutSolidroof(GLfloat size)
{
    // Half the size for easier positioning of vertices around the origin
    GLfloat halfSize = size / 2.0f;

    // Front face (z = +halfSize)
    glBegin(GL_QUADS);  
    glNormal3f(0.0f, 0.0f, 1.0f);  // Normal pointing along the z-axis
    glVertex3f(-halfSize, -halfSize, halfSize);  // Bottom-left
    glVertex3f( halfSize, -halfSize, halfSize);  // Bottom-right
    glVertex3f( halfSize,  halfSize, halfSize);  // Top-right
    glVertex3f(-halfSize,  halfSize, halfSize);  // Top-left
    glEnd();

    // Back face (z = -halfSize)
    glBegin(GL_QUADS);
    glNormal3f(0.0f, 0.0f, -1.0f);  // Normal pointing along the negative z-axis
    glVertex3f(-halfSize, -halfSize, -halfSize);  // Bottom-left
    glVertex3f(-halfSize,  halfSize, -halfSize);  // Top-left
    glVertex3f( halfSize,  halfSize, -halfSize);  // Top-right
    glVertex3f( halfSize, -halfSize, -halfSize);  // Bottom-right
    glEnd();

    // Left face (x = -halfSize)
    glBegin(GL_QUADS);
    glNormal3f(-1.0f, 0.0f, 0.0f);  // Normal pointing along the negative x-axis
    glVertex3f(-halfSize, -halfSize, -halfSize);  // Bottom-back
    glVertex3f(-halfSize, -halfSize, halfSize);   // Bottom-front
    glVertex3f(-halfSize,  halfSize, halfSize);   // Top-front
    glVertex3f(-halfSize,  halfSize, -halfSize);  // Top-back
    glEnd();

    // Right face (x = +halfSize)
    glBegin(GL_QUADS);
    glNormal3f(1.0f, 0.0f, 0.0f);  // Normal pointing along the positive x-axis
    glVertex3f(halfSize, -halfSize, -halfSize);  // Bottom-back
    glVertex3f(halfSize, -halfSize, halfSize);   // Bottom-front
    glVertex3f(halfSize,  halfSize, halfSize);   // Top-front
    glVertex3f(halfSize,  halfSize, -halfSize);  // Top-back
    glEnd();

    // Top face (y = +halfSize)
    glBegin(GL_QUADS);
    glNormal3f(0.0f, 1.0f, 0.0f);  // Normal pointing along the positive y-axis
    glVertex3f(-halfSize, halfSize, -halfSize);  // Back-left
    glVertex3f(halfSize, halfSize, -halfSize);   // Back-right
    glVertex3f(halfSize, halfSize, halfSize);    // Front-right
    glVertex3f(-halfSize, halfSize, halfSize);   // Front-left
    glEnd();

    // Bottom face (y = -halfSize)
    glBegin(GL_QUADS);
    glNormal3f(0.0f, -1.0f, 0.0f);  // Normal pointing along the negative y-axis
    glVertex3f(-halfSize, -halfSize, -halfSize);  // Back-left
    glVertex3f(-halfSize, -halfSize, halfSize);   // Front-left
    glVertex3f(halfSize, -halfSize, halfSize);    // Front-right
    glVertex3f(halfSize, -halfSize, -halfSize);   // Back-right
    glEnd();
}

void drawCircle(double radius) {
 glPushMatrix();
 glRotated(-90, 1, 0, 0);
 glBegin(GL_TRIANGLE_FAN);
 glVertex3f(0, 0, 0);
 for (angle = 0.0f; angle <= 2 * 3.14; angle += 3.14 / 500.0f)
 {

  float xx = radius * cos(angle);
  float yy = radius * sin(angle);
  glVertex3f(xx, yy, 0);
 }
 ///glVertex3f(radius, 0, 0);
 glEnd();
 glPopMatrix();
}

void cylinder(double radius, double high) {
	 glPushMatrix();
	 drawCircle(radius);
	 glTranslated(0, high, 0);
	 drawCircle(radius);
	 glPopMatrix();
	 glBegin(GL_TRIANGLE_STRIP);
	 for (angle = 0.0f; angle <= 2 * 3.14; angle += 3.14 / 100.0f)
	 {

	  float x = radius * cos(angle);
	  float y = radius * sin(angle);
	  glVertex3f(x, 0, y);
	  glVertex3f(x, high, y);
	 }
	 glVertex3f(radius, 0, 0);
	 glVertex3f(radius, high, 0);
	 glEnd();
}
void drawCircle(double radius, float textureRepeat) {
    glBegin(GL_TRIANGLE_FAN);
    glTexCoord2f(0.5f, 0.5f); // مركز النسيج
    glVertex3f(0, 0, 0);
    for (float angle = 0.0f; angle <= 2 * 3.14; angle += 3.14 / 100.0f) {
        float x = radius * cos(angle);
        float y = radius * sin(angle);
        glTexCoord2f(0.5f + 0.5f * cos(angle) * textureRepeat, 0.5f + 0.5f * sin(angle) * textureRepeat);
        glVertex3f(x, 0, y);
    }
    glEnd();
}

void cylinderWithTextureAndDoor(double radius, double high, int texture, float textureRepeat, double doorWidth, double doorHeight) {
    glBindTexture(GL_TEXTURE_2D, texture);

    glPushMatrix();

    // رسم القاعدة العلوية
    glPushMatrix();
    glTranslated(0, high, 0);
    drawCircle(radius, textureRepeat);
    glPopMatrix();

    // حساب زاوية بداية ونهاية الباب
    double doorStartAngle = -doorWidth / 2.0 / radius; // زاوية بداية الباب (المنتصف)
    double doorEndAngle = doorWidth / 2.0 / radius;   // زاوية نهاية الباب (المنتصف)

    // رسم القاعدة السفلية (باستثناء فتحة الباب)
    glBegin(GL_TRIANGLE_FAN);
    glTexCoord2f(0.5f, 0.5f);
    glVertex3f(0, 0, 0);

    // الجزء الأول من الدائرة قبل الباب
    for (float angle = -3.14; angle <= doorStartAngle; angle += 3.14 / 100.0f) {
        float x = radius * cos(angle);
        float z = radius * sin(angle);
        glTexCoord2f(0.5f + 0.5f * cos(angle) * textureRepeat, 0.5f + 0.5f * sin(angle) * textureRepeat);
        glVertex3f(x, 0, z);
    }
    // الجزء الثاني من الدائرة بعد الباب
    for (float angle = doorEndAngle; angle <= 3.14; angle += 3.14 / 100.0f) {
        float x = radius * cos(angle);
        float z = radius * sin(angle);
        glTexCoord2f(0.5f + 0.5f * cos(angle) * textureRepeat, 0.5f + 0.5f * sin(angle) * textureRepeat);
        glVertex3f(x, 0, z);
    }
    glEnd();

    // رسم الجوانب (باستثناء فتحة الباب) باستخدام GL_QUAD_STRIP
    glBegin(GL_QUAD_STRIP);

    // الجزء الأول من الجوانب قبل الباب
    for (float angle = -3.14; angle <= doorStartAngle; angle += 3.14 / 100.0f) {
        float x = radius * cos(angle);
        float z = radius * sin(angle);
        glTexCoord2f((angle + 3.14) / (2 * 3.14) * textureRepeat, 0); glVertex3f(x, 0, z);
        glTexCoord2f((angle + 3.14) / (2 * 3.14) * textureRepeat, textureRepeat); glVertex3f(x, high, z);
    }

    // الجزء الثاني من الجوانب بعد الباب
    for (float angle = doorEndAngle; angle <= 3.14; angle += 3.14 / 100.0f) {
        float x = radius * cos(angle);
        float z = radius * sin(angle);
        glTexCoord2f((angle + 3.14) / (2 * 3.14) * textureRepeat, 0); glVertex3f(x, 0, z);
        glTexCoord2f((angle + 3.14) / (2 * 3.14) * textureRepeat, textureRepeat); glVertex3f(x, high, z);
    }
    glEnd();

    glPopMatrix();
}
void drawCicleTable(float x, float z ,double cylinderradius, double cylinderhigh,double smallradius,double bigradius ){
			glPushMatrix();
			glTranslatef(x, 0.01 , z); 
			glColor3ub(238, 206, 215  );
			cylinder(cylinderradius, cylinderhigh);
			glColor3ub(62, 39, 46   );
			drawCircle(smallradius);               
			glTranslatef(0, cylinderhigh, 0);  
			glColor3ub(62, 39, 46 );
			drawCircle(bigradius); 
			glPopMatrix();
}
void drawChair3(double radius, double height, double legHeight, int texture) {
    if (texture) {
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, texture);
    }

GLUquadric* quad = gluNewQuadric();
    if (texture) gluQuadricTexture(quad, GL_TRUE);

    glPushMatrix();
    glTranslated(0, legHeight-1, 0);
    glRotated(-90, 1, 0, 0);    
    gluCylinder(quad, radius, radius, height, 32, 32);

   
    glPushMatrix();
    glTranslated(0, 0, height);
    gluDisk(quad, 0, radius, 32, 1);
    glPopMatrix();

   
    glPushMatrix();
    gluDisk(quad, 0, radius, 32, 1);
    glPopMatrix();

    glPopMatrix();


    double legWidth = 0.1 * radius;
    for (int i = 0; i < 4; i++) {
        double x = (i < 2) ? -radius / 2 + legWidth / 2 : radius / 2 - legWidth / 2;
        double z = (i % 2 == 0) ? -radius / 2 + legWidth / 2 : radius / 2 - legWidth / 2;

        glPushMatrix();
		glColor3d(0,0,0) ;
        glTranslated(x, 2, z);
        glScaled(legWidth, legHeight, legWidth);
        glutSolidroof(1.0);
        glPopMatrix();
    }
glDisable(texture);
glColor3d(1,1,1) ;
}

 float seatWidth = 1.0f, seatHeight = 0.8f, seatDepth = 1.0f, legChairWidth = 0.05f;
void drawChair5(float x, float z, float angle) {
    glPushMatrix();
    glTranslatef(x, 0, z); 
    glRotatef(angle, 0, 1, 0); 

    // رسم المقعد
    glPushMatrix();
    glColor3ub(96, 5, 48 );
    glTranslatef(0, seatHeight, 0);
    glScalef(seatWidth, 0.1f, seatDepth);
    glutSolidroof(1.0);
    glPopMatrix();

    // رسم المحيط حول المقعد
    float frameThickness = 0.05f; // سمك المحيط
    glColor3ub(53, 57, 51); // لون المحيط

    // الإطار الأمامي والخلفي للمقعد
    for (int i = -1; i <= 1; i += 2) {
        glPushMatrix();
        glTranslatef(0, seatHeight + frameThickness / 2, i * (seatDepth / 2));
        glScalef(seatWidth + frameThickness, frameThickness, frameThickness);
        glutSolidroof(1.0);
        glPopMatrix();
    }

    // الإطار الجانبي للمقعد
    for (int i = -1; i <= 1; i += 2) {
        glPushMatrix();
        glTranslatef(i * (seatWidth / 2), seatHeight + frameThickness / 2, 0);
        glScalef(frameThickness, frameThickness, seatDepth);
        glutSolidroof(1.0);
        glPopMatrix();
    }

    // رسم الأرجل
    for (int i = -1; i <= 1; i += 2) {
        for (int j = -1; j <= 1; j += 2) {
            glPushMatrix();
            glColor3ub(53, 57, 51);
            glTranslatef(i * (seatWidth / 2 - legChairWidth / 2), seatHeight / 2, j * (seatDepth / 2 - legChairWidth / 2));
            glScalef(legChairWidth, seatHeight, legChairWidth);
            glutSolidroof(1.0);
            glPopMatrix();
        }
    }

    // رسم الظهر
    glPushMatrix();
    glColor3ub(96, 5, 48 );
    glTranslatef(0, seatHeight + 0.5, -(seatDepth / 2 - legChairWidth / 2));
    glScalef(seatWidth, 1.0f, legChairWidth);
    glutSolidroof(1.0);
    glPopMatrix();

    // رسم المحيط حول الظهر
    float backrestHeight = 1.0f; // ارتفاع الظهر
    glColor3ub(53, 57, 51); // لون المحيط

    // الإطار العلوي والسفلي للظهر
    for (int i = -1; i <= 1; i += 2) {
        glPushMatrix();
        glTranslatef(0, seatHeight + backrestHeight * i / 2, -(seatDepth / 2));
        glScalef(seatWidth + frameThickness, frameThickness, frameThickness);
        glutSolidroof(1.0);
        glPopMatrix();
    }

    // الإطار الجانبي للظهر
    for (int i = -1; i <= 1; i += 2) {
        glPushMatrix();
        glTranslatef(i * (seatWidth / 2), seatHeight + backrestHeight / 2, -(seatDepth / 2));
        glScalef(frameThickness, backrestHeight, frameThickness);
        glutSolidroof(1.0);
        glPopMatrix();
    }

    // رسم مساند الذراعين
    float armrestHeight = 0.4f;
    float armrestWidth = 0.1f;
    float armrestDepth = 0.8f;

    for (int i = -1; i <= 1; i += 2) {
        glPushMatrix();
        glColor3ub(243, 155, 196 );
        glTranslatef(i * (seatWidth / 2 - armrestWidth / 2), seatHeight + armrestHeight / 2, 0);
        glScalef(armrestWidth, armrestHeight, armrestDepth);
        glutSolidroof(1.0);
        glPopMatrix();
    }

    glPopMatrix();
}
void drawTablesAndChairs(float centerX, float centerY, float centerZ,float scaleX, float scaleY, float scaleZ ,int numTables) {
    float spacing = 6.0f; // Spacing between tables

    glPushMatrix(); // Save the current matrix
    glTranslatef(centerX, centerY, centerZ); // Translate to the desired center
	glScalef(scaleX, scaleY, scaleZ);
	
     for (int i = 0; i < numTables; i++) {
        glPushMatrix();
        glTranslatef(-((numTables - 1) * spacing) / 2.0f + i * spacing, 0.0f, 0.0f);

        glColor3ub(255, 255, 255);
        drawCicleTable(0, 0, 0.1, 1.5, 0.5, 1);

        // رسم الكراسي مباشرة داخل الحلقة، بدون دالة منفصلة
        drawChair5(-1.5f, 0.0f, 90.0f);    // يسار
        drawChair5(1.5f, 0.0f, -90.0f);   // يمين
        drawChair5(0.0f, -1.5f, 0.0f);    // أمام
        drawChair5(0.0f, 1.5f, 180.0f);   // خلف

        glPopMatrix();
    }

    glPopMatrix(); // Restore the original matrix
}
void drawRectangleWithTexture(float width, float height, float depth, int img) {
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, img);

    glBegin(GL_QUADS);

    // الواجهة الأمامية
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-width / 2, -height / 2, depth / 2);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(width / 2, -height / 2, depth / 2);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(width / 2, height / 2, depth / 2);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-width / 2, height / 2, depth / 2);

    // الواجهة الخلفية (عكس ترتيب النقاط وإحداثيات النسيج)
    glTexCoord2f(1.0f, 0.0f); glVertex3f(-width / 2, -height / 2, -depth / 2);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(-width / 2, height / 2, -depth / 2);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(width / 2, height / 2, -depth / 2);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(width / 2, -height / 2, -depth / 2);

    // الواجهة اليمنى
    glTexCoord2f(0.0f, 0.0f); glVertex3f(width / 2, -height / 2, -depth / 2);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(width / 2, height / 2, -depth / 2);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(width / 2, height / 2, depth / 2);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(width / 2, -height / 2, depth / 2);

    // الواجهة اليسرى (عكس ترتيب النقاط وإحداثيات النسيج)
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-width / 2, -height / 2, -depth / 2);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(-width / 2, -height / 2, depth / 2);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(-width / 2, height / 2, depth / 2);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-width / 2, height / 2, -depth / 2);

    // السطح العلوي
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-width / 2, height / 2, depth / 2);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(width / 2, height / 2, depth / 2);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(width / 2, height / 2, -depth / 2);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-width / 2, height / 2, -depth / 2);

    // السطح السفلي (عكس ترتيب النقاط وإحداثيات النسيج)
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-width / 2, -height / 2, depth / 2);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-width / 2, -height / 2, -depth / 2);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(width / 2, -height / 2, -depth / 2);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(width / 2, -height / 2, depth / 2);

    glEnd();
}
void drawLibrary(float x, float y, float z, float shelfWidth, float shelfHeight, float shelfDepth, int numShelves,int Rotate, int img) {
    float spacing = 2;

    glPushMatrix(); // حفظ مصفوفة التحويل الحالية

    glTranslatef(x, y, z); // تحريك المكتبة بأكملها إلى الموضع المحدد
	glRotated(Rotate,0,1,0);
    for (int i = 0; i < numShelves; ++i) {
        glPushMatrix(); // حفظ مصفوفة التحويل قبل تحريك الرف الحالي

        glTranslatef(0.0f, i * (shelfHeight + spacing), 0.0f); // تحريك الرف الحالي للأعلى بالنسبة للمكتبة

        drawRectangleWithTexture(shelfWidth, shelfHeight, shelfDepth, img); // رسم الرف مع النسيج

        glPopMatrix(); // استعادة مصفوفة التحويل السابقة (إزالة تأثير تحريك الرف الحالي)
    }

    glPopMatrix(); // استعادة مصفوفة التحويل الأصلية (إزالة تأثير تحريك المكتبة بأكملها)
}
void drawCloset(float length, float width , float depth , GLuint closettexture) {
    
 // الوجه الأمامي
 glBindTexture(GL_TEXTURE_2D , closettexture) ;
    glBegin(GL_QUADS);
 glNormal3d(0,1,0) ;
 glTexCoord2d(0,0) ;
    glVertex3f(-length/2, -width/2, depth/2);

 glTexCoord2d(1,0) ;
    glVertex3f(length/2, -width/2, depth/2);

 glTexCoord2d(1,1) ;
    glVertex3f(length/2, width/2, depth/2);

 glTexCoord2d(0,1) ;
    glVertex3f(-length/2, width/2, depth/2);
     glEnd() ;

    // الوجه الخلفي
   
  glBegin(GL_QUADS);
	  glNormal3d(0,1,0) ;
	 glTexCoord2d(0,0) ;
    glVertex3f(-length/2, -width/2, -depth/2);
	glTexCoord2d(1,0) ;
    glVertex3f(length/2, -width/2, -depth/2);
	glTexCoord2d(1,1) ;
    glVertex3f(length/2, width/2, -depth/2);
	glTexCoord2d(0,1) ;
    glVertex3f(-length/2, width/2, -depth/2);
 glEnd() ;
   
    // الوجه العلوي
   
  glBegin(GL_QUADS);
    glVertex3f(-length/2, width/2, depth/2);
    glVertex3f(length/2, width/2, depth/2);
    glVertex3f(length/2, width/2, -depth/2);
    glVertex3f(-length/2, width/2, -depth/2);
 glEnd() ;
   
    // الوجه السفلي
   
  glBegin(GL_QUADS);
    glVertex3f(-length/2, -width/2, depth/2);
    glVertex3f(length/2, -width/2, depth/2);
    glVertex3f(length/2, -width/2, -depth/2);
    glVertex3f(-length/2, -width/2, -depth/2);
 glEnd() ;
   
    // الوجه اليمين
   
  glBegin(GL_QUADS);
    glVertex3f(length/2, -width/2, depth/2);
    glVertex3f(length/2, width/2, depth/2);
    glVertex3f(length/2, width/2, -depth/2);
    glVertex3f(length/2, -width/2, -depth/2);
 glEnd() ;
   
    // الوجه اليسار
    
  glBegin(GL_QUADS);
    glVertex3f(-length/2, -width/2, depth/2);
    glVertex3f(-length/2, width/2, depth/2);
    glVertex3f(-length/2, width/2, -depth/2);
    glVertex3f(-length/2, -width/2, -depth/2);
    glEnd();
   
   // glutSwapBuffers();
}
void drawCloset1(float length, float width , float depth , GLuint closettexture) {
    
 // الوجه الأمامي
 glBindTexture(GL_TEXTURE_2D , closettexture) ;
    glBegin(GL_QUADS);
 glNormal3d(0,1,0) ;
 glTexCoord2d(0,0) ;
    glVertex3f(-length/2, -width/2, depth/2);

 glTexCoord2d(1,0) ;
    glVertex3f(length/2, -width/2, depth/2);

 glTexCoord2d(1,1) ;
    glVertex3f(length/2, width/2, depth/2);

 glTexCoord2d(0,1) ;
    glVertex3f(-length/2, width/2, depth/2);
     glEnd() ;

    // الوجه الخلفي
   
  glBegin(GL_QUADS);
    glVertex3f(-length/2, -width/2, -depth/2);
    glVertex3f(length/2, -width/2, -depth/2);
    glVertex3f(length/2, width/2, -depth/2);
    glVertex3f(-length/2, width/2, -depth/2);
 glEnd() ;
   
    // الوجه العلوي
   
  glBegin(GL_QUADS);
    glVertex3f(-length/2, width/2, depth/2);
    glVertex3f(length/2, width/2, depth/2);
    glVertex3f(length/2, width/2, -depth/2);
    glVertex3f(-length/2, width/2, -depth/2);
 glEnd() ;
   
    // الوجه السفلي
   
  glBegin(GL_QUADS);
    glVertex3f(-length/2, -width/2, depth/2);
    glVertex3f(length/2, -width/2, depth/2);
    glVertex3f(length/2, -width/2, -depth/2);
    glVertex3f(-length/2, -width/2, -depth/2);
 glEnd() ;
   
    // الوجه اليمين
   
  glBegin(GL_QUADS);
    glVertex3f(length/2, -width/2, depth/2);
    glVertex3f(length/2, width/2, depth/2);
    glVertex3f(length/2, width/2, -depth/2);
    glVertex3f(length/2, -width/2, -depth/2);
 glEnd() ;
   
    // الوجه اليسار
    
  glBegin(GL_QUADS);
    glVertex3f(-length/2, -width/2, depth/2);
    glVertex3f(-length/2, width/2, depth/2);
    glVertex3f(-length/2, width/2, -depth/2);
    glVertex3f(-length/2, -width/2, -depth/2);
    glEnd();
   
   // glutSwapBuffers();
}
void drawLibrary2(float x, float y, float z, float shelfWidth, float shelfHeight, float shelfDepth,int Rotate, int img) {
   
    glPushMatrix(); // حفظ مصفوفة التحويل الحالية
    glTranslatef(x, y, z); // تحريك المكتبة بأكملها إلى الموضع المحدد
	glRotated(Rotate,0,1,0);
    glPushMatrix(); // حفظ مصفوفة التحويل قبل تحريك الرف الحالي
    drawCloset(shelfWidth, shelfHeight, shelfDepth, img); // رسم الرف مع النسيج
    glPopMatrix(); // استعادة مصفوفة التحويل السابقة (إزالة تأثير تحريك الرف الحالي)
    glPopMatrix(); // استعادة مصفوفة التحويل الأصلية (إزالة تأثير تحريك المكتبة بأكملها)
}
void drawLibrary1(float x, float y, float z, float shelfWidth, float shelfHeight, float shelfDepth,int Rotate, int img) {
   
    glPushMatrix(); // حفظ مصفوفة التحويل الحالية
    glTranslatef(x, y, z); // تحريك المكتبة بأكملها إلى الموضع المحدد
	glRotated(Rotate,0,1,0);
    glPushMatrix(); // حفظ مصفوفة التحويل قبل تحريك الرف الحالي
    drawRectangleWithTexture(shelfWidth, shelfHeight, shelfDepth, img); // رسم الرف مع النسيج
    glPopMatrix(); // استعادة مصفوفة التحويل السابقة (إزالة تأثير تحريك الرف الحالي)
    glPopMatrix(); // استعادة مصفوفة التحويل الأصلية (إزالة تأثير تحريك المكتبة بأكملها)
}

void drawSimpleTriangle(double base , double high)
{
	glPushMatrix();
	glBegin(GL_TRIANGLE_FAN);
	
	glVertex3d(base/2.0,high,0);
	glVertex3d(0,0,0);
	glVertex3d(base,0,0);
	
	glEnd();
	glPopMatrix();
}
void drowroof(double width, double height, double depth, int textureID)
{
	glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glBindTexture(GL_TEXTURE_2D, textureID); // ربط النسيج (الصورة)

    glPushMatrix();
    // رسم الواجهة الأمامية
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f); glVertex3d(0, 0, 0);
    glTexCoord2f(1.0f, 0.0f); glVertex3d(width, 0, 0);
    glTexCoord2f(1.0f, 1.0f); glVertex3d(width, height, 0);
    glTexCoord2f(0.0f, 1.0f); glVertex3d(0, height, 0);
    glEnd();

    // الانتقال للجانب الأيمن
    glTranslated(width, 0, 0);
    glRotated(90, 0, 1, 0);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f); glVertex3d(0, 0, 0);
    glTexCoord2f(1.0f, 0.0f); glVertex3d(depth, 0, 0);
    glTexCoord2f(1.0f, 1.0f); glVertex3d(depth, height, 0);
    glTexCoord2f(0.0f, 1.0f); glVertex3d(0, height, 0);
    glEnd();

    // الانتقال للجانب الخلفي
    glTranslated(depth, 0, 0);
    glRotated(90, 0, 1, 0);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f); glVertex3d(0, 0, 0);
    glTexCoord2f(1.0f, 0.0f); glVertex3d(width, 0, 0);
    glTexCoord2f(1.0f, 1.0f); glVertex3d(width, height, 0);
    glTexCoord2f(0.0f, 1.0f); glVertex3d(0, height, 0);
    glEnd();

    // الانتقال للجانب الأيسر
    glTranslated(width, 0, 0);
    glRotated(90, 0, 1, 0);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f); glVertex3d(0, 0, 0);
    glTexCoord2f(1.0f, 0.0f); glVertex3d(depth, 0, 0);
    glTexCoord2f(1.0f, 1.0f); glVertex3d(depth, height, 0);
    glTexCoord2f(0.0f, 1.0f); glVertex3d(0, height, 0);
    glEnd();

    glPopMatrix();

    glPushMatrix();
    // رسم السطح العلوي
    glTranslated(0, height, 0);
    glRotated(-90, 1, 0, 0);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f); glVertex3d(0, 0, 0);
    glTexCoord2f(1.0f, 0.0f); glVertex3d(width, 0, 0);
    glTexCoord2f(1.0f, 1.0f); glVertex3d(width, depth, 0);
    glTexCoord2f(0.0f, 1.0f); glVertex3d(0, depth, 0);
    glEnd();

    // رسم السطح السفلي
    glTranslated(0, 0, -height);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f); glVertex3d(0, 0, 0);
    glTexCoord2f(1.0f, 0.0f); glVertex3d(width, 0, 0);
    glTexCoord2f(1.0f, 1.0f); glVertex3d(width, depth, 0);
    glTexCoord2f(0.0f, 1.0f); glVertex3d(0, depth, 0);
    glEnd();

    glPopMatrix();
}
void drawTriangleQuad(float x, float y, float z)
{
	glPushMatrix();
	drawSimpleTriangle(x,y);
	glTranslated(0,0,-z);
	drawSimpleTriangle(x,y);
	glPopMatrix();


	glPushMatrix();
	glBegin(GL_QUADS);
	glVertex3d(0,0,0);
	glVertex3d(x/2.0,y,0);
	glVertex3d(x/2.0,y,-z);
	glVertex3d(0,0,-z);
	glEnd();


	glBegin(GL_QUADS);
	glVertex3d(x,0,0);
	glVertex3d(x,0,-z);
	glVertex3d(x/2.0,y,-z);
	glVertex3d(x/2.0,y,0);
	glEnd();

	
	glPopMatrix();
}

void drawTexturedWall(float x, float y, float z, float width, float height,int Rotate ,int texture) {
    glEnable(GL_TEXTURE_2D); 
    glBindTexture(GL_TEXTURE_2D, texture); 

    glPushMatrix(); 

    glTranslated(x, y, z); 
	glRotated(Rotate,0,1,0);
    glBegin(GL_QUADS); 

    // الوجه الأمامي
    glTexCoord2f(0.0f, 0.0f); glVertex3f(0.0f, 0.0f, 0.0f);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(width, 0.0f, 0.0f);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(width, height, 0.0f);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(0.0f, height, 0.0f);

    glEnd();


    glPopMatrix(); 
   
}

void drawTexturedWall2(float x, float y, float z, float width, float height, float thickness, int Rotate, int texture) {
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texture);

    glPushMatrix();

    glTranslated(x, y, z);
    glRotated(Rotate, 0, 1, 0);

    glBegin(GL_QUADS);

    // الوجه الأمامي
    glTexCoord2f(0.0f, 0.0f); glVertex3f(0.0f, 0.0f, 0.0f);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(width, 0.0f, 0.0f);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(width, height, 0.0f);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(0.0f, height, 0.0f);

    // الوجه الخلفي (مع إزاحة في محور z)
    glTexCoord2f(0.0f, 0.0f); glVertex3f(0.0f, 0.0f, thickness);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(width, 0.0f, thickness);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(width, height, thickness);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(0.0f, height, thickness);

    //الوجه الجانبي الايمن
    glTexCoord2f(0.0f, 0.0f); glVertex3f(width, 0.0f, 0.0f);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(width, 0.0f, thickness);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(width, height, thickness);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(width, height, 0.0f);

    //الوجه الجانبي الايسر
    glTexCoord2f(0.0f, 0.0f); glVertex3f(0.0f, 0.0f, 0.0f);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(0.0f, 0.0f, thickness);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(0.0f, height, thickness);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(0.0f, height, 0.0f);

    //الوجه العلوي
    glTexCoord2f(0.0f, 0.0f); glVertex3f(0.0f, height, 0.0f);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(width, height, 0.0f);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(width, height, thickness);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(0.0f, height, thickness);

    //الوجه السفلي
    glTexCoord2f(0.0f, 0.0f); glVertex3f(0.0f, 0.0f, 0.0f);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(width, 0.0f, 0.0f);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(width, 0.0f, thickness);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(0.0f, 0.0f, thickness);



    glEnd();

    glPopMatrix();
}
void drawPot(float bottomRadius, float topRadius, float height) {
    GLUquadric* quadric = gluNewQuadric(); // إنشاء كائن أسطوانة

    // رسم الأسطوانة (الجدران الجانبية للحوض)
    glPushMatrix();
    glColor3f(0.6f, 0.3f, 0.1f); // لون بني للحوض
    gluCylinder(quadric, bottomRadius, topRadius, height, 32, 32); // أسطوانة مع أقطار مختلفة
    glPopMatrix();

    // رسم القاعدة السفلية
    glPushMatrix();
    glColor3f(0.4f, 0.2f, 0.1f); // لون القاعدة (بني أغمق)
    glTranslatef(0, 0, 0); // القاعدة في الأسفل
    gluDisk(quadric, 0.0f, bottomRadius, 32, 32); // رسم قرص القاعدة
    glPopMatrix();

    // رسم القاعدة العلوية (التربة)
    glPushMatrix();
    glColor3f(0.3f, 0.2f, 0.0f); // لون التربة (بني داكن)
    glTranslatef(0, 0, height); // وضع التربة في أعلى الحوض
    gluDisk(quadric, 0.0f, topRadius, 32, 32); // رسم قرص التربة
    glPopMatrix();

    //gluDeleteQuadric(quadric); // تحرير الموارد
}

void drawcinemachair(float x, float z, float angle) {
    glPushMatrix();
    glTranslatef(x, 3, z); 
    glRotatef(angle, 0, 1, 0); 

    // رسم المقعد
    glPushMatrix();
    glColor3ub(173, 23, 46  );
    glTranslatef(0, seatHeight, 0);
    glScalef(seatWidth, 0.1f, seatDepth);
    glutSolidroof(1.0);
    glPopMatrix();
     // رسم المحيط حول المقعد
    float frameThickness = 0.05f; // سمك المحيط
     glColor3ub(50, 30, 0); // لون المحيط

  
    // الإطار الجانبي للمقعد
    for (int i = -1; i <= 1; i += 2) {
        glPushMatrix();
        glTranslatef(i * (seatWidth / 2), seatHeight + frameThickness / 2, 0);
        glScalef(frameThickness, frameThickness, seatDepth);
        glutSolidroof(1.0);
        glPopMatrix();
    }

 
    // رسم الظهر
	 glPushMatrix();
   glColor3ub(173, 23, 46 );
    glTranslatef(0, seatHeight + 0.5, -(seatDepth / 2 - legChairWidth / 2));
    glScalef(seatWidth, 1.0f, legChairWidth);
    glutSolidroof(1.0);
    glPopMatrix();

    // رسم المحيط حول الظهر
    float backrestHeight = 1.0f; // ارتفاع الظهر
    glColor3ub(50, 0, 0); // لون المحيط

    // الإطار العلوي والسفلي للظهر
   /* for (int i = -1; i <= 1; i += 2) {
        glPushMatrix();
        glTranslatef(0, seatHeight + backrestHeight * i / 2, -(seatDepth / 2));
        glScalef(seatWidth + frameThickness, frameThickness, frameThickness);
        glutSolidroof(1.0);
        glPopMatrix();
    }*/

    // الإطار الجانبي للظهر
    for (int i = -1; i <= 1; i += 2) {
        glPushMatrix();
        glTranslatef(i * (seatWidth / 2), seatHeight + backrestHeight / 2, -(seatDepth / 2));
        glScalef(frameThickness, backrestHeight, frameThickness);
        glutSolidroof(1.0);
        glPopMatrix();
    }
	    float armrestHeight = 0.4f;
    float armrestWidth = 0.1f;
    float armrestDepth = 0.8f;

    for (int i = -1; i <= 1; i += 2) {
        glPushMatrix();
        glColor3ub(0, 0, 0 );
        glTranslatef(i * (seatWidth / 2 - armrestWidth / 2), seatHeight + armrestHeight / 2, 0);
        glScalef(armrestWidth, armrestHeight, armrestDepth);
        glutSolidroof(1.0);
        glPopMatrix();
    }
	  // رسم المحيط حول الظهر
   

    // الإطار العلوي والسفلي للظهر
    for (int i = 0; i <= 0; i += 2) {
        glPushMatrix();
        glTranslatef(0, seatHeight + backrestHeight * i / 2, -(seatDepth / 2));
        glScalef(seatWidth + frameThickness, frameThickness, frameThickness);
        glutSolidroof(1.0);
        glPopMatrix();
    }

    // الإطار الجانبي للظهر
    for (int i = -1; i <= 1; i += 2) {
        glPushMatrix();
        glTranslatef(i * (seatWidth / 2), seatHeight + backrestHeight / 2, -(seatDepth / 2));
        glScalef(frameThickness, backrestHeight, frameThickness);
        glutSolidroof(1.0);
        glPopMatrix();
    }
 
    glPopMatrix();
}

void chairsrow(float xx,float yy, float zz,float x,float z){
	glPushMatrix();
	
	glTranslated(xx,yy,zz);
	for(float i=14.4;i<34.8;i+=1.3){
	drawcinemachair( x+i, z,180);
	}
	glPopMatrix();
}
int y=0,x=0;

void DrawTree(Point center)
{
	glPushMatrix();
	glScalef(1,1.3,1);
	glTranslated(center.x, center.y, center.z);
	tree->Draw();
	glPopMatrix();
}
void DrawTrees()
{
	//down between the two staires
	//DrawTree(Point(25, 0,18));
	DrawTree(Point(55, 0,18));
	DrawTree(Point(25, 0,48));
	DrawTree(Point(55, 0,48));
	//DrawTree(Point(25, 0,-18));
	DrawTree(Point(55, 0,-18));
	DrawTree(Point(25, 0,-48));
	DrawTree(Point(55, 0,-48));
	//left down the yard

}
void Drawbuilding(){
			drawBox(105, 0,-80,40,90,40, building);
			drawBox(105, 0,0,40,90,40, building);
			drawBox(105, 0,80,40,90,40, building);

			glPushMatrix();
			glRotated(-90,0,1,0);
			 drawBox(115, 0,30,40,90,40, building);
			 drawBox(115, 0,110,40,90,40, building);
			glPopMatrix();

			glPushMatrix();
			glRotated(90,0,1,0);
			drawBox(110, 0,-90,40,90,40, building);
			drawBox(110, 0,-10,40,90,40, building);
			drawBox(110, 0,70,40,90,40, building);
			glPopMatrix();
}
void drawfountain(){
		 fountain->pos.z = 30;
	fountain->Draw();
	 fountain->pos.z = -25;
	 	fountain->Draw();
}
void rectXY(float x, float y, float z, float w, float h,int N, int texture, float sld, float tld, float srd, float trd, float sru, float tru, float slu, float tlu) {
		
		glBindTexture(GL_TEXTURE_2D, texture);
		
		glNormal3d(0, 0, N);
		glBegin(GL_QUADS);
		glTexCoord2d(sld, tld);
		glVertex3f(x, y, z);
		glTexCoord2d(srd, trd);
		glVertex3f(x + w, y, z);
		glTexCoord2d(sru, tru);
		glVertex3f(x + w, y + h, z);
		glTexCoord2d(slu, tlu);
		glVertex3f(x, y + h, z);
		glEnd();

	}
void rectXZ(float x, float y, float z, float w, float h,int N, int texture, float sld, float tld, float srd, float trd, float sru, float tru, float slu, float tlu) {
		
		glBindTexture(GL_TEXTURE_2D, texture);

		glNormal3d(0, N, 0);
		glBegin(GL_QUADS);
		glTexCoord2d(sld, tld);
		glVertex3f(x, y, z);
		glTexCoord2d(srd, trd);
		glVertex3f(x + w, y, z);
		glTexCoord2d(sru, tru);
		glVertex3f(x + w, y, z - h);
		glTexCoord2d(slu, tlu);
		glVertex3f(x, y, z - h);
		glEnd();

	}
void rectYZ(float x, float y, float z, float w, float h, int N, int texture, float sld, float tld, float srd, float trd, float sru, float tru, float slu, float tlu) {
		
		glBindTexture(GL_TEXTURE_2D, texture);

		glNormal3d(N, 0, 0);
		glBegin(GL_QUADS);
		glTexCoord2d(sld, tld);
		glVertex3f(x, y, z);
		glTexCoord2d(srd, trd);
		glVertex3f(x, y, z - w);
		glTexCoord2d(sru, tru);
		glVertex3f(x, y + h, z - w);
		glTexCoord2d(slu, tlu);
		glVertex3f(x, y + h, z);
		glEnd();

	}
void cone(float x, float y, float z, float h, float r, int texture, float sld, float tld, float srd, float trd, float sru, float tru, float slu, float tlu)
	{
		glBindTexture(GL_TEXTURE_2D, texture);
		glBegin(GL_QUADS);
		for (float i = 0; i < 2 * 3.14; i += 0.3)
		{
			glNormal3d(sin(i), atan2(r , h)+3.14, cos(i));
			float xx = r * cos(i);
			float zz = r * sin(i);
			float xxx = r * cos(i + 0.3);
			float zzz = r * sin(i + 0.3);
			glTexCoord2d(sld, tld);
			glVertex3f(x + xx, y, z - zz);
			glTexCoord2d(srd, trd);
			glVertex3f(x + xxx, y, z - zzz);
			glTexCoord2d(sru, tru);
			glVertex3f(x + xxx, y + h, z - zzz);
			glTexCoord2d(slu, tlu);
			glVertex3f(x + xx, y + h, z - zz);

		}
		glEnd();
	}
void parallel_rect(float x, float y, float z, float w, float h, float d, int texture)
	{
		rectXY(x, y, z, w, h,1, texture, 0, 0, 1, 0, 1, 1, 0, 1);
		rectXY(x, y, z-d, w, h,-1, texture, 0, 0, 1, 0, 1, 1, 0, 1);
		rectXZ(x, y, z, w, d,-1, texture, 0, 0, 1, 0, 1, 1, 0, 1);
		rectXZ(x, y+h, z, w, d,1, texture, 0, 0, 1, 0, 1, 1, 0, 1);
		rectYZ(x, y, z, d, h,-1, texture, 0, 0, 1, 0, 1, 1, 0, 1);
		rectYZ(x+w, y, z, d, h,1, texture, 0, 0, 1, 0, 1, 1, 0, 1);
	}
void drawwall(float x, float y, float z, float h, int texture, int texture2)
	{
		for (float i = 0; i <= h; i += 1) {
			cone(x + i, y, z, 1, 0.1, texture, 0, 0, 1, 0, 1, 1, 0, 1);
		}
		parallel_rect(x, y + 1, z + 0.1, h, 0.2, 0.2, texture2);
	}
void drawfence(){
	//first floor
	glPushMatrix();
	glScaled(1,2,1);
	drawwall(-33, 10.5, -15.1, 18, groundWallTexture2, groundSkybox);//right
	drawwall(-33, 10.5, 25.1, 18, groundWallTexture2, groundSkybox);//left
	glPushMatrix();
	glRotated(-90,0,1,0);
	//drawwall(-31, 20, 23.1, 17, groundWallTexture2, groundSkybox);
	drawwall(-15, 10.5, 33.1, 13, groundWallTexture2, groundSkybox);//back right
	drawwall(7, 10.5, 33.1, 18, groundWallTexture2, groundSkybox);//back left
	drawwall(-15, 10.5, 15.1, 40, groundWallTexture2, groundSkybox);//face 
	glPopMatrix();
	glPopMatrix();
	//glTranslated(-31.3,35,-43);
	drawTexturedWall2(-34,35,-45,22,5,0.2,0,libraryname);
	//second floor
	glPushMatrix();
	glScaled(1,2,1);//( xd >= -13 && xd <= 8 && zd >= -44 && zd <= -40 && yd >21  )
	drawwall(-13, 20.5, -40, 18, groundWallTexture2, groundSkybox);//right
	drawwall(-13, 20.5, -25, 18, groundWallTexture2, groundSkybox);//left

	glPushMatrix();
	glRotated(-90,0,1,0);
 	drawwall(-40, 20.5, 13.1, 15, groundWallTexture2, groundSkybox);//back right
 
	glPopMatrix();
	glPopMatrix();

}
void mall(float xx)
{  
	drawTexturedWall2(-15.5f,0,-32,30,20,1,0,clo1);
	drawTexturedWall2(-46.0f,0,-32,30,20,1,0,clo2);
	drawTexturedWall2(-76.5f,0,-32,30,20,1,0,clo3);


	drawTexturedWall(15.0f,0,-32,35,20,-90,clo10);
	drawTexturedWall(15.0f,0,10,35,20,-90,clo10);

	drawTexturedWall(37.0f,0,-32,40,20,-90,clo7);
	drawTexturedWall(37.0f,0,0,40,20,-90,clo7);

	drawTexturedWall(15.0f,0,-30,22,20,0,clo11);
	drawTexturedWall(15.0f,0,40,22,20,0,clo11);

	drawTexturedWall(-75.0f,0,-31,35,20,-90,clo5);
	drawTexturedWall(-75.0f,0,10,35,20,-90,clo5);

	drawTexturedWall(-98.0f,0,-32,40,20,-90,clo14);
	drawTexturedWall(-98.0f,0,0,40,20,-90,clo14);

	drawTexturedWall(-98.0f,0,-30,22,20,0,clo16);
	drawTexturedWall(-98.0f,0,40,22,20,0,clo16);
	
	//
	/*drawLibrary(-96,23,5,60,0.1,4,6,-90,liz);
	drawLibrary(-87,23,5,25,2.5,2.5,1,-90,liz);*/
	//
	 drawLibrary2(27,27,30,10,12,2.5,0,library);
	drawLibrary2(27,27,15,10,12,2.5,0,library);
	drawLibrary2(27,27,0,10,12,2.5,0,library);
	drawLibrary2(27,27,-15,10,12,2.5,0,library);
	
	
	//drawTexturedWall(-98.0f,21,-33,78,19,-90,walk2);
	drawTexturedWall(37.0f,21,-32,75,19,-90,wood2);
	drawTexturedWall(16,21,-31,22,19,0,wood2);
	drawTexturedWall(16,21,43,22,19,0,wood2);

	

	/*drawTexturedWall(-75.0f,21,-3,30,19,90,walk2);
	drawTexturedWall(-75.0f,21,44,30,19,90,walk2);*/


	
	drawTexturedWall(16,21,-2,30,19,90,wood2);
	drawTexturedWall(16,21,44.2,30,19,90,wood2);

	drawTexturedWall2(15.5,21,-2,30,19,0.3,90,wall4);
	drawTexturedWall2(15.5,21,44.3,30,19,0.3,90,wall4);

	drawTexturedWall(-15.0f,24,-30,25,15,0,dro1);
	drawTexturedWall(-42.0f,24,-30,25,15,0,dro2);
	drawTexturedWall(-70.0f,24,-30,25,15,0,dro3);
	
	drawTablesAndChairs(-60,21.2,-24,2.5,2.5,2.5,2);
	drawTablesAndChairs(-60,21.2,-10,2.5,2.5,2.5,2);
	drawTablesAndChairs(0,21.2,-24,2.5,2.5,2.5,2);
	drawTablesAndChairs(0,21.2,-10,2.5,2.5,2.5,2);
	drawTablesAndChairs(-60,21.2,23,2.5,2.5,2.5,2);
	drawTablesAndChairs(-60,21.2,37,2.5,2.5,2.5,2);
	drawTablesAndChairs(-20,21.2,23,2.5,2.5,2.5,2);
	drawTablesAndChairs(-20,21.2,37,2.5,2.5,2.5,2);
	

	//restaurant and bar
	glColor3ub(255,255,255);
	glPushMatrix() ;
	glTranslated(-95,27,-25) ;
	glRotated(90 , 0 , 1 , 0) ;
	//glPopMatrix();
	glPushMatrix() ;
	glTranslated(0 , 2 , 0) ;
	drawCloset(10 , 15 , 3 , drinkcloset2 ) ;
	glPopMatrix() ;

	glTranslated(-16 , 2 , 0 ) ;
	drawCloset(15 , 18 , 3 , drinkcloset) ;

	glTranslated(-13 , 7.5 , 0 ) ;
	drawCloset(10 , 5 , 3 , barcloset) ;

	glTranslated(-10.7 , 0 , 0 ) ;
	drawCloset(10 , 5 , 3 , barcloset) ;

	glTranslated(-10.5 , 0 , 0 ) ;
	drawCloset(10 , 5 , 3 , barcloset) ;

	glTranslated(10.7 , -6 , -1) ;
	drawCloset(31.5 , 6.5 , 1 , barBG) ;

	glTranslated(0 , -6 , 9 ) ;
	drawCloset(32 , 7 , 5 , barfront) ;

	glPopMatrix() ;

                 
	//glPopMatrix() ;

	glPushMatrix() ;
	glTranslated(-81,22, 0) ;
	//glRotated(20 , 0 , 1 , 0) ;
	for (int i = 0; i < 5; i++)
	{
	glTranslated(0 , 0  , 5) ;
     drawChair3(1.5 , 1 , 5 , barcloset) ;
	}
	
	glPopMatrix() ;


	glPushMatrix() ;
	glTranslated(8 , 1 , -20) ;
    drawChair3(1.5 , 1 , 6 , barcloset) ;

	glTranslated(0 , 0 ,55) ;
    drawChair3(1.5 , 1 , 6 , barcloset) ;

	glPopMatrix() ;


	glPushMatrix() ;
	glTranslated(-70 , 1 , -20) ;
    drawChair3(1.5 , 1 , 6 , barcloset) ;

	glTranslated(0 , 0 ,55) ;
    drawChair3(1.5 , 1 , 6 , barcloset) ;

	glPopMatrix() ;

    glPushMatrix() ;
	glTranslated(-30.5 , 1 , 15.5) ;
	glRotated(-45 , 1 , 0 , 0) ;
    drawCloset(3.5 , 50 , 1 ,liz) ;

	glTranslated(-4, 0 , 0) ;
	drawCloset(3.5 , 50 , 1 ,liz) ;
	glPopMatrix() ;



	glPushMatrix() ;
	glTranslated(4.50f  , 31  ,  26);
	glRotated(45 , 1 , 0 ,0 ) ;
     drawCloset(3.5 , 27 , 1 ,liz) ;

	glTranslated(-4, 0 , 0) ;
	drawCloset(3.5 , 27 , 1 ,liz) ;
	glPopMatrix() ;


	//cinema wall

	
	
	drawTexturedWall2(-98.0f,41,-33,78,29,1,-90,wall5);
	drawTexturedWall2(37.0f,41,-32,75,29,1,-90,wall5);
	drawTexturedWall2(-10.0f,41,-20,65,29,1,-90,wall5);
	drawTexturedWall2(-11.0f,42,-18,60,25,0.5,-90,maxres);
	glColor3ub(255,255,255);
	drawTexturedWall2(-98, 41,43 ,136,29,1,0,wall5);
	drawTexturedWall2(-98, 41,-32 ,136,29,1,0,wall5);

	glPushMatrix();
	glScaled(2.8,2.8,2.8);
	glRotated(-90,0,1,0);
	chairsrow(17,11.4,13.5,-37,2);
	chairsrow(17,11.8,17,-37,2);
	chairsrow(17,12.2,20.3,-37,2);
	chairsrow(17,12.6,24,-37,2);
	chairsrow(17,13,27.5,-37,2);
	chairsrow(17,13.4,31,-37,2);
	glPopMatrix();
	

	

	//for cenima
	glColor3ub(255,255,255);
	drawLibrary(-93,44,  5,76,7,10,1,-90,roof);
	drawLibrary(-83,43.5,5,76,6,10,1,-90,roof);
	drawLibrary(-73,43,  5,76,5,10,1,-90,roof);
	drawLibrary(-63,42.5,5,76,4,10,1,-90,roof);
	drawLibrary(-53,42,  5,76,3,10,1,-90,roof);
	drawLibrary(-43,41.5,5,76,2,10,1,-90,roof);

	
	

	glPushMatrix();
	glTranslated(28,48,5);
	glRotated(90,0,1,0);
	drawCloset(8,15,8,coca);
	glPopMatrix();
	drawLibrary1(28,48,-19,8,15,8,0,ticket);
	drawLibrary1(28,48,30,8,15,8,0,poncorn);
	//wall
	glColor3d(1,1,1);
	glPushMatrix();
	glTranslated(40 * xx,0,46.5 * xx);
	glRotated(90,0,1,0);
	drawBorderBlock2(80 * xx, 70 * xx, 0.4 * xx,50,wall4);
	glPopMatrix();

	glPushMatrix();
	glTranslated(-100 * xx,0,46.5 * xx);
	glRotated(90,0,1,0);
	drawBorderBlock2(80 * xx,70 * xx,1 * xx,50,wall4);
	glPopMatrix();

	glPushMatrix();
	glTranslated(-100,0,-33);
	drawBorderBlock2(140,70,0.4,50,wall4);
	glPopMatrix();
	//=========================================
	glPushMatrix();
	glTranslated(-100,70,45);
	glRotated(180,1,0,0);
	drawBorderBlock2(70,30,0.4,50,wall4);
	glPopMatrix();

	glPushMatrix();
	glTranslated(-30,70,45);
	glRotated(180,1,0,0);
	drawBorderBlock2(70,30,0.4,50,wall4);
	glPopMatrix();
	//========================================
	glPushMatrix();
	glTranslated(-100,0,45);
	drawBorderBlock2(25,40,0.4,50,wall4);
	glPopMatrix();

	glPushMatrix();
	glTranslated(15,0,45);
	drawBorderBlock2(25,40,0.4,50,wall4);
	glPopMatrix();
	//----------------------------------------------
	glPushMatrix();
	glTranslated(-40 * xx,0.3,95 * xx);
	drawLand3(20,50,0.3,street,0.1);
	glRotated(90,0,1,0);
	glTranslated(-25 * xx,0,110 * xx);
	drawLand3(30,200,0.3,street,0.1);
	glRotated(-180,0,1,0);
	
	glPopMatrix();

	
	
	//----------------------------------------------

	glPushMatrix();
	glTranslated(-32.0f  , 0  ,  17);
	drawStairs(0.0f, 0.0f, 0.0f, 34, 0.6f, 0.6f, 3.0f,3,wood2,liz);
	glTranslated(-4, 0  ,  0);
	drawStairs(0.0f, 0.0f, 0.0f, 34, 0.6f, 0.6f, 3.0f,3,wood2,liz);
	glPopMatrix();

	glPushMatrix();
	glTranslated(2.0f  , 21  ,  15);
	glRotated(180,0,1,0);
	drawStairs(0.0f, 0.0f, 0.0f, 33, 0.6f, 0.6f, 3.0f,3,wood2,liz);
	glTranslated(-4, 0  ,  0);
	drawStairs(0.0f, 0.0f, 0.0f, 33, 0.6f, 0.6f, 3.0f,3,wood2,liz);
	glPopMatrix();


	//----------------------------------------------
	glPushMatrix();
	glTranslated(-100 * xx,0,47 * xx);
	drawLand2(140,80,1,carpet);
	glPopMatrix();
	//roof 1
	glPushMatrix();
	glTranslated(-100 * xx,20,44.5 * xx);
	drawLand2(45,77.5,1,wood2);
	glPopMatrix();

	glPushMatrix();
	glTranslated(-15 * xx,20,44.5 * xx);
	drawLand2(30,77.5,1,wood2);
	glPopMatrix();

	glPushMatrix();
	glTranslated(20.5 * xx,20,44.5 * xx);
	drawLand2(19,77.5,1,wood2);
	glPopMatrix();


	glPushMatrix();
	glTranslated(-75 * xx,20,-33 * xx);
	glRotated(-90,0,1,0);
	drawLand2(30,70,1,wood2);
	glPopMatrix();

	glPushMatrix();
	glTranslated(10 * xx,20,-33 * xx);
	glRotated(-90,0,1,0);
	drawLand2(60,15,1,wood2);
	glPopMatrix();

	glPushMatrix();
	glTranslated(10 * xx,20,14.5 * xx);
	glRotated(-90,0,1,0);
	drawLand2(30,15,1,wood2);
	glPopMatrix();

	glPushMatrix();
	glTranslated(-75 * xx,20,14.5* xx);
	glRotated(-90,0,1,0);
	drawLand2(30,70,1,wood2);
	glPopMatrix();

	//-----------------------------------------



	//roof 2
	glPushMatrix();
	glTranslated(-100 * xx,40,44.5 * xx);
	drawLand2(70,77.5,1,wood2);
	glPopMatrix();

	glPushMatrix();
	glTranslated(-30 * xx,40,17 * xx);
	drawLand2(40,50,1,wood2);
	glPopMatrix();

	glPushMatrix();
	glTranslated(20.5 * xx,40,44.5 * xx);
	drawLand2(19,77.5,1,wood2);
	glPopMatrix();

	//
	glPushMatrix();
	glTranslated(-75 * xx,40,-33 * xx);
	glRotated(-90,0,1,0);
	drawLand2(30,70,1,wood2);
	glPopMatrix();
	//
	glPushMatrix();
	glTranslated(10 * xx,40,-33 * xx);
	glRotated(-90,0,1,0);
	drawLand2(60,15,1,wood2);
	glPopMatrix();
	//
	glPushMatrix();
	glTranslated(10 * xx,40,14.5 * xx);
	glRotated(-90,0,1,0);
	drawLand2(30,15,1,wood2);
	glPopMatrix();
	//
	glPushMatrix();
	glTranslated(-75 * xx,40,14.5* xx);
	glRotated(-90,0,1,0);
	drawLand2(30,70,1,wood2);
	glPopMatrix();

	glPushMatrix();
	glTranslated(-5 * xx,40,44.5 * xx);
	drawLand2(15,10,1,wood2);
	glPopMatrix();
	//-------------------------------------------

	glPushMatrix();
	glColor3ub(160, 232, 241 );
	glTranslated(-100 * xx,70,47 * xx);
	drowroof(140* xx ,1 *xx ,80 *xx , roof);
	glPopMatrix();
	glColor3ub(255,255,255);


	glColor3ub(255, 255, 255 );
	glPushMatrix();
	glTranslated( -75,0,45);
	drawBorderBlock2(35* xx  ,  20* xx  , 0.2*xx ,5, glass );
	glTranslated(55 *xx ,0,0);
	drawBorderBlock2(35* xx  ,  20* xx  , 0.2*xx , 5, glass );
	glPopMatrix();

	glPushMatrix();
	glTranslated( -75,20,45);
	drawBorderBlock2(90* xx  ,  20* xx  , 0.2*xx ,5, glass );
	glPopMatrix();

	glPushMatrix();
	glTranslated( -40,20,45);
	glRotated(180,1,0,0);
	drawBorderBlock2(20* xx  ,  5* xx  , 0.2*xx , 5, glass );
	glPopMatrix();

	glPushMatrix();
	glTranslated( -40.0f - doorOffset  , 0  , 45.5);
	drawDoor(10*xx, 15* xx  , 0.1*xx  , glass );
	glPopMatrix();
	glPushMatrix();
	glTranslated(-30.0f + doorOffset  , 0  , 45.5);
	drawDoor(10*xx, 15* xx  , 0.1*xx  , glass );
	glPopMatrix();
	

	
}
void drowTrees1(){
	glPushMatrix();
	glTranslated(20  ,1.5,-9);
		glScaled(0.5,0.5,0.5);
		glColor3f(1.0, 1.0, 1.0);
		tree->Draw();
		glTranslated(0,  -2  , 0);
		glRotated(-90,1,0,0);
		drawPot(2,4,4);
		glColor3f(1.0, 1.0, 1.0);
	glPopMatrix();

	glPushMatrix();
	glTranslated(20  ,1.5,9);
		glScaled(0.5,0.5,0.5);
		glColor3f(1.0, 1.0, 1.0);
		tree->Draw();
		glTranslated(0,  -2  , 0);
		glRotated(-90,1,0,0);
		drawPot(2,4,4);
		glColor3f(1.0, 1.0, 1.0);
	glPopMatrix();

	glPushMatrix();
	glTranslated(10  ,21.5,9);
		glScaled(0.5,0.5,0.5);
		glColor3f(1.0, 1.0, 1.0);
		tree->Draw();
		glTranslated(0,  -2  , 0);
		glRotated(-90,1,0,0);
		drawPot(2,4,4);
	glPopMatrix();

	glPushMatrix();
	glTranslated(-55  ,21.5,9);
		glScaled(0.5,0.5,0.5);
		glColor3f(1.0, 1.0, 1.0);
		tree->Draw();
		glTranslated(0,  -2  , 0);
		glRotated(-90,1,0,0);
		drawPot(2,4,4);
	glPopMatrix();

	glPushMatrix();
	glTranslated(-55  ,21.5,-9);
		glScaled(0.5,0.5,0.5);
		glColor3f(1.0, 1.0, 1.0);
		tree->Draw();
		glTranslated(0,  -2  , 0);
		glRotated(-90,1,0,0);
		drawPot(2,4,4);
		glColor3f(1.0, 1.0, 1.0);
	glPopMatrix();
	
}

//void mainAxis()
//{
//	
//	glBegin(GL_LINES);
//	glColor3d(1,1,1);
//	//X
//	glVertex3d(-3,0,0);
//	glVertex3d(3,0,0);
//	//Y
//	glVertex3d(0,-2,0);
//	glVertex3d(0,2,0);
//	//Z
//	glVertex3d(0,0,-3);
//	glVertex3d(0,0,3);
//	glEnd();
//}

void draw(float dynamic) 
{
	
	glPushMatrix();
	SkyBox(300 * dynamic);
	glTranslated(-100 * dynamic,0,100 * dynamic);
	drawBorder(190 * dynamic,30 * dynamic,190 * dynamic);
	glPopMatrix();	
	
	
	
	glPushMatrix();
	drowTrees1();
	 
	 glPopMatrix();


	glPushMatrix();
	glScaled(1,1,1);
	glColor3d(0.8,0.8,0.8);
	glTranslated(-30 * dynamic,0,-30);
	glRotated(90,0,1,0);
	mall(1 * dynamic);
	glPopMatrix();
	

}
	
void DrawGLScene(GLvoid)         // Here's Where We Do All The Drawing
{
 
	
 glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear Screen And Depth Buffer
 glLoadIdentity();         // Reset The Current Modelview Matrix

 camera();
 
 
 glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
 //glBindTexture(GL_TEXTURE_2D, img1);
 
 glTranslated(0, -1, -6);
 //mainAxis();

 DrawTrees();
 Drawbuilding();
 drawfountain();
 carModel->Draw();
 drawfence();
 glColor3ub(255,255,255);
 draw(1);
 



 SwapBuffers(hDC);

}

GLvoid KillGLWindow(GLvoid)        // Properly Kill The Window
{
 if (fullscreen)          // Are We In Fullscreen Mode?
 {
  ChangeDisplaySettings(NULL, 0);     // If So Switch Back To The Desktop
  ShowCursor(TRUE);        // Show Mouse Pointer
 }

 if (hRC)           // Do We Have A Rendering Context?
 {
  if (!wglMakeCurrent(NULL, NULL))     // Are We Able To Release The DC And RC Contexts?
  {
   MessageBox(NULL, "Release Of DC And RC Failed.", "SHUTDOWN ERROR", MB_OK | MB_ICONINFORMATION);
  }

  if (!wglDeleteContext(hRC))      // Are We Able To Delete The RC?
  {
   MessageBox(NULL, "Release Rendering Context Failed.", "SHUTDOWN ERROR", MB_OK | MB_ICONINFORMATION);
  }
  hRC = NULL;          // Set RC To NULL
 }

 if (hDC && !ReleaseDC(hWnd, hDC))     // Are We Able To Release The DC
 {
  MessageBox(NULL, "Release Device Context Failed.", "SHUTDOWN ERROR", MB_OK | MB_ICONINFORMATION);
  hDC = NULL;          // Set DC To NULL
 }

 if (hWnd && !DestroyWindow(hWnd))     // Are We Able To Destroy The Window?
 {
  MessageBox(NULL, "Could Not Release hWnd.", "SHUTDOWN ERROR", MB_OK | MB_ICONINFORMATION);
  hWnd = NULL;          // Set hWnd To NULL
 }

 if (!UnregisterClass("OpenGL", hInstance))   // Are We Able To Unregister Class
 {
  MessageBox(NULL, "Could Not Unregister Class.", "SHUTDOWN ERROR", MB_OK | MB_ICONINFORMATION);
  hInstance = NULL;         // Set hInstance To NULL
 }
}

/* This Code Creates Our OpenGL Window.  Parameters Are:     *
* title   - Title To Appear At The Top Of The Window    *
* width   - Width Of The GL Window Or Fullscreen Mode    *
* height   - Height Of The GL Window Or Fullscreen Mode   *
* bits   - Number Of Bits To Use For Color (8/16/24/32)   *
* fullscreenflag - Use Fullscreen Mode (TRUE) Or Windowed Mode (FALSE) */

BOOL CreateGLWindow(char* title, int width, int height, int bits, bool fullscreenflag)
{
 GLuint  PixelFormat;   // Holds The Results After Searching For A Match
 WNDCLASS wc;      // Windows Class Structure
 DWORD  dwExStyle;    // Window Extended Style
 DWORD  dwStyle;    // Window Style
 RECT  WindowRect;    // Grabs Rectangle Upper Left / Lower Right Values
 WindowRect.left = (long)0;   // Set Left Value To 0
 WindowRect.right = (long)width;  // Set Right Value To Requested Width
 WindowRect.top = (long)0;    // Set Top Value To 0
 WindowRect.bottom = (long)height;  // Set Bottom Value To Requested Height

 fullscreen = fullscreenflag;   // Set The Global Fullscreen Flag

 hInstance = GetModuleHandle(NULL);    // Grab An Instance For Our Window
 wc.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC; // Redraw On Size, And Own DC For Window.
 wc.lpfnWndProc = (WNDPROC)WndProc;     // WndProc Handles Messages
 wc.cbClsExtra = 0;         // No Extra Window Data
 wc.cbWndExtra = 0;         // No Extra Window Data
 wc.hInstance = hInstance;       // Set The Instance
 wc.hIcon = LoadIcon(NULL, IDI_WINLOGO);   // Load The Default Icon
 wc.hCursor = LoadCursor(NULL, IDC_ARROW);   // Load The Arrow Pointer
 wc.hbrBackground = NULL;         // No Background Required For GL
 wc.lpszMenuName = NULL;         // We Don't Want A Menu
 wc.lpszClassName = "OpenGL";        // Set The Class Name

 if (!RegisterClass(&wc))         // Attempt To Register The Window Class
 {
  MessageBox(NULL, "Failed To Register The Window Class.", "ERROR", MB_OK | MB_ICONEXCLAMATION);
  return FALSE;           // Return FALSE
 }

 if (fullscreen)            // Attempt Fullscreen Mode?
 {
  DEVMODE dmScreenSettings;        // Device Mode
  memset(&dmScreenSettings, 0, sizeof(dmScreenSettings)); // Makes Sure Memory's Cleared
  dmScreenSettings.dmSize = sizeof(dmScreenSettings);  // Size Of The Devmode Structure
  dmScreenSettings.dmPelsWidth = width;    // Selected Screen Width
  dmScreenSettings.dmPelsHeight = height;    // Selected Screen Height
  dmScreenSettings.dmBitsPerPel = bits;     // Selected Bits Per Pixel
  dmScreenSettings.dmFields = DM_BITSPERPEL | DM_PELSWIDTH | DM_PELSHEIGHT;


// Try To Set Selected Mode And Get Results.  NOTE: CDS_FULLSCREEN Gets Rid Of Start Bar.
  if (ChangeDisplaySettings(&dmScreenSettings, CDS_FULLSCREEN) != DISP_CHANGE_SUCCESSFUL)
  {
   // If The Mode Fails, Offer Two Options.  Quit Or Use Windowed Mode.
   if (MessageBox(NULL, "The Requested Fullscreen Mode Is Not Supported By\nYour Video Card. Use Windowed Mode Instead?", "NeHe GL", MB_YESNO | MB_ICONEXCLAMATION) == IDYES)
   {
    fullscreen = FALSE;  // Windowed Mode Selected.  Fullscreen = FALSE
   }
   else
   {
    // Pop Up A Message Box Letting User Know The Program Is Closing.
    MessageBox(NULL, "Program Will Now Close.", "ERROR", MB_OK | MB_ICONSTOP);
    return FALSE;         // Return FALSE
   }
  }
 }

 if (fullscreen)            // Are We Still In Fullscreen Mode?
 {
  dwExStyle = WS_EX_APPWINDOW;        // Window Extended Style
  dwStyle = WS_POPUP;          // Windows Style
  ShowCursor(FALSE);          // Hide Mouse Pointer
 }
 else
 {
  dwExStyle = WS_EX_APPWINDOW | WS_EX_WINDOWEDGE;   // Window Extended Style
  dwStyle = WS_OVERLAPPEDWINDOW;       // Windows Style
 }

 AdjustWindowRectEx(&WindowRect, dwStyle, FALSE, dwExStyle);  // Adjust Window To True Requested Size

                 // Create The Window
 if (!(hWnd = CreateWindowEx(dwExStyle,       // Extended Style For The Window
  "OpenGL",       // Class Name
  title,        // Window Title
  dwStyle |       // Defined Window Style
  WS_CLIPSIBLINGS |     // Required Window Style
  WS_CLIPCHILDREN,     // Required Window Style
  0, 0,        // Window Position
  WindowRect.right - WindowRect.left, // Calculate Window Width
  WindowRect.bottom - WindowRect.top, // Calculate Window Height
  NULL,        // No Parent Window
  NULL,        // No Menu
  hInstance,       // Instance
  NULL)))        // Dont Pass Anything To WM_CREATE
 {
  KillGLWindow();        // Reset The Display
  MessageBox(NULL, "Window Creation Error.", "ERROR", MB_OK | MB_ICONEXCLAMATION);
  return FALSE;        // Return FALSE
 }

 static PIXELFORMATDESCRIPTOR pfd =    // pfd Tells Windows How We Want Things To Be
 {
  sizeof(PIXELFORMATDESCRIPTOR),    // Size Of This Pixel Format Descriptor
  1,           // Version Number
  PFD_DRAW_TO_WINDOW |      // Format Must Support Window
  PFD_SUPPORT_OPENGL |      // Format Must Support OpenGL
  PFD_DOUBLEBUFFER,       // Must Support Double Buffering
  PFD_TYPE_RGBA,        // Request An RGBA Format
  bits,          // Select Our Color Depth
  0, 0, 0, 0, 0, 0,       // Color Bits Ignored
  0,           // No Alpha Buffer
  0,           // Shift Bit Ignored
  0,           // No Accumulation Buffer
  0, 0, 0, 0,         // Accumulation Bits Ignored
  16,           // 16Bit Z-Buffer (Depth Buffer)  
  0,           // No Stencil Buffer
  0,           // No Auxiliary Buffer
  PFD_MAIN_PLANE,        // Main Drawing Layer
  0,           // Reserved
  0, 0, 0          // Layer Masks Ignored
 };

 if (!(hDC = GetDC(hWnd)))       // Did We Get A Device Context?
 {
  KillGLWindow();        // Reset The Display
  MessageBox(NULL, "Can't Create A GL Device Context.", "ERROR", MB_OK | MB_ICONEXCLAMATION);
  return FALSE;        // Return FALSE
 }

 if (!(PixelFormat = ChoosePixelFormat(hDC, &pfd))) // Did Windows Find A Matching Pixel Format?
 {
  KillGLWindow();        // Reset The Display
  MessageBox(NULL, "Can't Find A Suitable PixelFormat.", "ERROR", MB_OK | MB_ICONEXCLAMATION);
  return FALSE;        // Return FALSE
 }

 if (!SetPixelFormat(hDC, PixelFormat, &pfd))  // Are We Able To Set The Pixel Format?
 {
  KillGLWindow();        // Reset The Display
  MessageBox(NULL, "Can't Set The PixelFormat.", "ERROR", MB_OK | MB_ICONEXCLAMATION);
  return FALSE;        // Return FALSE
 }

 if (!(hRC = wglCreateContext(hDC)))    // Are We Able To Get A Rendering Context?
 {
  KillGLWindow();        // Reset The Display
  MessageBox(NULL, "Can't Create A GL Rendering Context.", "ERROR", MB_OK | MB_ICONEXCLAMATION);
  return FALSE;        // Return FALSE
 }


if (!wglMakeCurrent(hDC, hRC))     // Try To Activate The Rendering Context
 {
  KillGLWindow();        // Reset The Display
  MessageBox(NULL, "Can't Activate The GL Rendering Context.", "ERROR", MB_OK | MB_ICONEXCLAMATION);
  return FALSE;        // Return FALSE
 }

 ShowWindow(hWnd, SW_SHOW);      // Show The Window
 SetForegroundWindow(hWnd);      // Slightly Higher Priority
 SetFocus(hWnd);         // Sets Keyboard Focus To The Window
 ReSizeGLScene(width, height);     // Set Up Our Perspective GL Screen

 if (!InitGL())         // Initialize Our Newly Created GL Window
 {
  KillGLWindow();        // Reset The Display
  MessageBox(NULL, "Initialization Failed.", "ERROR", MB_OK | MB_ICONEXCLAMATION);
  return FALSE;        // Return FALSE
 }

 return TRUE;         // Success
}

LRESULT CALLBACK WndProc(HWND hWnd,   // Handle For This Window
 UINT uMsg,   // Message For This Window
 WPARAM wParam,   // Additional Message Information
 LPARAM lParam)   // Additional Message Information
{
 static PAINTSTRUCT ps;

 switch (uMsg)         // Check For Windows Messages
 {
 case WM_PAINT:
  DrawGLScene();
  BeginPaint(hWnd, &ps);
  EndPaint(hWnd, &ps);
  return 0;
 
 case WM_TIMER:
  DrawGLScene();
  return 0;

 case WM_ACTIVATE:       // Watch For Window Activate Message
 {
  if (!HIWORD(wParam))     // Check Minimization State
  {
   active = TRUE;      // Program Is Active
  }
  else
  {
   active = FALSE;      // Program Is No Longer Active
  }

  return 0;        // Return To The Message Loop
 }

 case WM_SYSCOMMAND:       // Intercept System Commands
 {
  switch (wParam)       // Check System Calls
  {
  case SC_SCREENSAVE:     // Screensaver Trying To Start?
  case SC_MONITORPOWER:    // Monitor Trying To Enter Powersave?
   return 0;       // Prevent From Happening
  }
  break;         // Exit
 }

 case WM_CLOSE:        // Did We Receive A Close Message?
 {
  PostQuitMessage(0);      // Send A Quit Message
  return 0;        // Jump Back
 }

 case WM_KEYDOWN:       // Is A Key Being Held Down?
 {
  keys[wParam] = TRUE;     // If So, Mark It As TRUE
  return 0;        // Jump Back
 }

 case WM_KEYUP:        // Has A Key Been Released?
 {
  keys[wParam] = FALSE;     // If So, Mark It As FALSE
  return 0;        // Jump Back
 }

 case WM_SIZE:        // Resize The OpenGL Window
 {
  ReSizeGLScene(LOWORD(lParam), HIWORD(lParam));  // LoWord=Width, HiWord=Height
  return 0;        // Jump Back
 }
 }

 // Pass All Unhandled Messages To DefWindowProc
 return DefWindowProc(hWnd, uMsg, wParam, lParam);
}

int WINAPI WinMain(HINSTANCE hInstance,   // Instance
 HINSTANCE hPrevInstance,  // Previous Instance
 LPSTR  lpCmdLine,   // Command Line Parameters
 int   nCmdShow)   // Window Show State
{
 MSG  msg;         // Windows Message Structure
 BOOL done = FALSE;        // Bool Variable To Exit Loop

              // Ask The User Which Screen Mode They Prefer
              //if (MessageBox(NULL,"Would You Like To Run In Fullscreen Mode?", "Start FullScreen?",MB_YESNO|MB_ICONQUESTION)==IDNO)
 {
  fullscreen = FALSE;       // Windowed Mode
 }

 // Create Our OpenGL Window
 char c[] = "";
 if (!CreateGLWindow(c, 640, 480, 16, fullscreen))
 {
  return 0;         // Quit If Window Was Not Created
 }


 //Set drawing timer to 20 frame per second
 UINT timer = SetTimer(hWnd, 0, 50, (TIMERPROC)NULL);

 while (GetMessage(&msg, NULL, 0, 0))
 {
  TranslateMessage(&msg);
  DispatchMessage(&msg);
 }

 return 0;

}