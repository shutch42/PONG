#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include "table.h"

using namespace std;

const int PADDLEW = 10;
const int PADDLEH = 100;

Paddle leftPaddle;
Paddle rightPaddle;
Ball b;
int scoreL = 0;
int scoreR = 0;
char l[256];
char r[256];

void loop(int id) {
	b.refreshPosition();
	if(b.getY() >= 300) {
		b.bounceTop();
	}
	if(b.getY() <= -300) {
		b.bounceBottom();
	}
	if(b.getX() >= 400) {
		b.bounceRight();
		scoreL++;
	}
	if(b.getX() <= -400) {
		b.bounceLeft();
		scoreR++;
	}
	if(b.getX() >= (390 + b.speed) && b.getY() >= rightPaddle.getPosition()-PADDLEH/2 && b.getY() <= rightPaddle.getPosition()+PADDLEH/2) {
		b.bounceRight();
	}
	if(b.getX() <= (-390 - b.speed) && b.getY() >= leftPaddle.getPosition()-PADDLEH/2 && b.getY() <= leftPaddle.getPosition()+PADDLEH/2) {
		b.bounceLeft();
	}
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
	glBegin(GL_POINTS);
	 glVertex2i(b.getX(), b.getY());
	glEnd();
	glRasterPos2i(-200,250);
	sprintf(l, "%i", scoreL);
	glutBitmapString(GLUT_BITMAP_TIMES_ROMAN_24, (const unsigned char*)l);
	glRasterPos2i(200,250);
	sprintf(r, "%i", scoreR);
	glutBitmapString(GLUT_BITMAP_TIMES_ROMAN_24, (const unsigned char*)r);
	glutTimerFunc((1/60)*1000, loop, 0);
	glutSwapBuffers();
	glFlush();
}

void moveRight(int key, int x, int y) {
	if(key == GLUT_KEY_UP) {
		rightPaddle.moveUp();
	}
	if(key == GLUT_KEY_DOWN) {
		rightPaddle.moveDown();
	}
}

void moveLeft(unsigned char key, int x, int y) {
	if(key == 'w') {
		leftPaddle.moveUp();
	}
	if(key == 's') {
		leftPaddle.moveDown();
	}
}

int main(int argc, char** argv) {

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);

	glutInitWindowSize(800, 600);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("PONG");

	glClearColor(0.0f,0.0f,0.0f,1.0f);
	glColor3f(0,1,0);
	glPointSize(10);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-400, 400, -300, 300);

	glutDisplayFunc(display);
	glutKeyboardFunc(moveLeft);
	glutSpecialFunc(moveRight);
	glutMainLoop();
	return 0;
}
