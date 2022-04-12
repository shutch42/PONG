class Paddle {
	public:
		Paddle();
		void moveUp();
		void moveDown();
		int getPosition();
	private:
		int position;
		int speed = 10;
};
