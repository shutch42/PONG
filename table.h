#include <GL/freeglut.h>
#include "paddle.h"
#include "ball.h"

class Table {
	public:
		Table();
		void checkCollision();
	private:
		Paddle left;
		Paddle right;
		Ball b;
};
