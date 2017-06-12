#include "game.hpp"

Game::Game( void ) {

}

Game::Game(int x, int y) {
	mapsize.x = x;
	mapsize.y = y;
}

Game::Game(Game const & copy) {
	*this = copy;
}

Game::~Game ( void ) {
	std::cout << "Your score was " << score << '\n';
}

void Game::play() {
	score = 0;
	int loop 	= 0;
	struct timeval	start;
	struct timeval	end;
	bool player_alive = true;
	//Draw Gui
	while (player_alive) {
		gettimeofday(&start, NULL);
		// Draw Gui
		interface.drawFrame(mapsize, food.getlistofApples(), snake.getplayerCords());
		// Check player's position
		if (loop % 100 == 0)
			food.genApple(mapsize);
		if (loop % 25 == 0)
			player_alive = snake.move(0, food.getlistofApples(), mapsize);
		loop++;
		score++;
		gettimeofday(&end, NULL);
		usleep( 60000 - (end.tv_usec - start.tv_usec) );
	}
}
