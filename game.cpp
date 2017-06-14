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
	bool player_alive = true;
	struct timeval	end;
	struct timeval	start;

	while (player_alive) {
		gettimeofday(&start, NULL);
		interface.drawFrame(mapsize, food.getlistofApples(), snake.getplayerCords());
		player_alive = snake.move(interface.getUserResponse(), &food, mapsize);
		if (score % 100 == 0 || food.Count() == 0)
			food.genApple(mapsize);
		score++;
		gettimeofday(&end, NULL);
		if ((end.tv_usec - start.tv_usec) >= 0)
			usleep( 60000 - (end.tv_usec - start.tv_usec) );
	}
}
