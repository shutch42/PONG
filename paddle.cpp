#include "paddle.h"

Paddle::Paddle() {
	position = 0;
}

void Paddle::moveUp() {
	position += speed;
}

void Paddle::moveDown() {
	position -= speed;
}
