class Ball {
	public:
		Ball();
		int getX();
		int getY();
		int speed;
		void bounceTop();
		void bounceBottom();
		void bounceLeft();
		void bounceRight();
		void refreshPosition();
	private:
		int x;
		int y;
		int vx;
		int vy;
};
