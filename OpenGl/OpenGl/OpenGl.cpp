#include <GL/freeglut.h>
#include <math.h>
#include <stdio.h>
#include "OpenGl.h"



void init();
void display(void);
void keyboard(unsigned char, int , int );
void centerOnScreen();
void drawObject();
void drawObject2();
void trabajo();
void reshape(int width, int heiht);
struct Punto3d {
	double x = 0;
	double y = 0;
	double z = 0;
}Punto1,Punto2;
//  define the window position on screen
int window_x;
int window_y;

int hazPerspectiva = 0;

GLint ancho = 400;
GLint alto = 400;
//  variables representing the window size
int window_width = 480;
int window_height = 480;

//  variable representing the window title
char *window_title = "Sample OpenGL FreeGlut App";

//-------------------------------------------------------------------------
//  Program Main method.
//-------------------------------------------------------------------------
void main(int argc, char **argv)
{
	//  Connect to the windowing system + create a window
	//  with the specified dimensions and position9
	//  + set the display mode + specify the window title.
	glutInit(&argc, argv);
	trabajo();
	//  Start GLUT event processing loop
	glutMainLoop();
	
}
void trabajo()
{
	centerOnScreen();
	glutInitWindowSize(window_width, window_height);
	glutInitWindowPosition(window_x, window_y);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
	glutCreateWindow(window_title);

	//  Set OpenGL program initial state.
	init();

	// Set the callback functions
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
}
//-------------------------------------------------------------------------
//  Set OpenGL program initial state.
//-------------------------------------------------------------------------
void init()
{
	glEnable(GL_DEPTH_TEST);
	//  Set the frame buffer clear color to black. 
	glClearColor(0.0, 0.0, 0.0, 0.0);
}

//-------------------------------------------------------------------------
//  This function is passed to glutDisplayFunc in order to display 
//  OpenGL contents on the window.
//-------------------------------------------------------------------------
void display(void)
{
	//  Clear the window or more specifically the frame buffer...
	//  This happens by replacing all the contents of the frame
	//  buffer by the clear color (black in our case)
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//  Draw object
	drawObject();

	//  Swap contents of backward and forward frame buffers
	glutSwapBuffers();
}

//-------------------------------------------------------------------------
//  Draws our object.
//-------------------------------------------------------------------------
void drawObject()
{
	//  Draw Icosahedron
	//glutWireIcosahedron();
	//glutWireRhombicDodecahedron();
	//glutWireOctahedron();
	glPointSize(2);
	glBegin(GL_POINTS);
	GLdouble x = 0.1;
	GLdouble y = 1;
	for (double i=-1.0; i < y; i=(i + x)) {
		for (double j = -1.0; j < y; j = (j + x)) {
			for (double k = -1.0; k < y; k = (k + x)) {
				glVertex3d(i, j, k);
			}
			}

	}
	glEnd();
}
void drawObject2()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//  Draw Icosahedron
	//glutWireIcosahedron();
	//glutWireRhombicDodecahedron();
//	glutWireOctahedron();
	glPointSize(5);
	glBegin(GL_POINTS);
	glVertex3d(Punto1.x, Punto1.y, Punto1.z);
	glVertex3d(Punto2.x, Punto2.y, Punto2.z);
	glEnd();
	glutSwapBuffers();
}


//-------------------------------------------------------------------------
//  This function sets the window x and y coordinates
//  such that the window becomes centered
//-------------------------------------------------------------------------
void centerOnScreen()
{
	window_x = (glutGet(GLUT_SCREEN_WIDTH) - window_width) / 2;
	window_y = (glutGet(GLUT_SCREEN_HEIGHT) - window_height) / 2;
}
void reshape(int width, int height)
{
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	if (hazPerspectiva)
		gluPerspective(60.0f, (GLfloat)width / (GLfloat)height, 1.0f, 20.0f);
	else

		glOrtho(-4, 4, -4, 4, 1, 10);

	glMatrixMode(GL_MODELVIEW);

	ancho = width;
	alto = height;
}

void keyboard(unsigned char key, int x, int y) {
	switch (key) {
	case 'p':
	case 'P':
		hazPerspectiva = 1;
		reshape(ancho, alto);
		break;

	case 'o':
	case 'O':
		hazPerspectiva = 0;
		reshape(ancho, alto);
		break;
	case 'h':
		printf("o = Perspectiva ortogonal");
		printf("p = perspectiva de proyeccion");
		printf("c - Toggle culling\n");
		printf("ESC = escape");
		break;
	case '1':
		glRotatef(1.0, 1., 0., 0.);
		break;
	case '3':
		glRotatef(1.0, 0., 1., 0.);
		break;
	case '5':
		glRotatef(1.0, 0., 0., 1.);
		break;
	case '2':
		glRotatef(1.0, -1., 0., 0.);
		break;
	case '4':
		glRotatef(1.0, 0., -1., 0.);
		break;
	case '6':
		glRotatef(1.0, 0., 0., -1.);
		break;
	case '7':
		glScalef(0.5,0.5,0.5);
		break;
	case '8':
		glScalef(2, 2, 2);
		break;
	case '9':
		glutDisplayFunc(drawObject2);
		break;
	case 27:
		exit(0);
		break;
	}
	glutPostRedisplay();
}
