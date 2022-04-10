class Paddle {
	public:
		Paddle();
		void moveUp();
		void moveDown();
	private:
		int position;
		int speed = 1;
};
