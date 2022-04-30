#include "ball.h"
#include <stdlib.h>
#include <time.h>
#include <math.h>

Ball::Ball() {
	srand(time(0));
	int angle = (rand() % 90 - 45)/(2*M_PI);
	int direction = rand() % 2;
	if(direction) {
		angle *= -1;
	}
	speed = 5;
	x = 0;
	y = 0;
	vx = speed*cos(angle);
	vy = speed*sin(angle);
}

int Ball::getX() {
	return x;
}

int Ball::getY() {
	return y;
}

void Ball::bounceTop() {
	vy = -vy;
}

void Ball::bounceBottom() {
	vy = -vy;
}

void Ball::bounceLeft() {
	vx = -vx;
}

void Ball::bounceRight() {
	vx = -vx;
}

void Ball::refreshPosition() {
	x += vx;
	y += vy;
}
