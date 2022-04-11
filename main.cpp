#include <iostream>
#include <GL/freeglut.h>
#include "paddle.h"
#include "ball.h"

using namespace std;

const int PADDLEW = 10;
const int PADDLEH = 100;

Paddle leftPaddle;
Paddle rightPaddle;

void keyPressed(unsigned char key, int x, int y) {
	if(key == 'w') {
		leftPaddle.moveUp();
	}
	if(key == 's') {
		leftPaddle.moveDown();
	}
}

void specialInput(int key, int x, int y) {
	if(key == GLUT_KEY_UP) {
		rightPaddle.moveUp();
	}
	if(key == GLUT_KEY_DOWN) {
		rightPaddle.moveDown();
	}
}

void loop(int id) {
	glutPostRedisplay();
}

void display(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glColor3f(1.0f, 1.0f, 1.0f);	
	glBegin(GL_QUADS);	
	 glVertex2i(-400, leftPaddle.getPosition() - PADDLEH/2);
	 glVertex2i(-400, leftPaddle.getPosition() + PADDLEH/2);
	 glVertex2i(-400 + PADDLEW, leftPaddle.getPosition() + PADDLEH/2);
	 glVertex2i(-400 + PADDLEW, leftPaddle.getPosition() - PADDLEH/2);
	glEnd();
	glBegin(GL_QUADS);	
	 glVertex2i(400, rightPaddle.getPosition() - PADDLEH/2);
	 glVertex2i(400, rightPaddle.getPosition() + PADDLEH/2);
	 glVertex2i(400 - PADDLEW, rightPaddle.getPosition() + PADDLEH/2);
	 glVertex2i(400 - PADDLEW, rightPaddle.getPosition() - PADDLEH/2);
	glEnd();
	
	glutTimerFunc((1/60)*1000, loop, 0);
	glutSwapBuffers();
	glFlush();
}

int main(int argc, char** argv) {

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);

	glutInitWindowSize(800, 600);
	glutInitWindowPosition(0, 0);

	glutCreateWindow("PONG");

	glClearColor(0.0f,0.0f,0.0f,1.0f);
	glColor3f(0,1,0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-400, 400, -300, 300);

	glutDisplayFunc(display);
	glutKeyboardFunc(keyPressed);
	glutSpecialFunc(specialInput);
	glutMainLoop();
	return 0;
}
