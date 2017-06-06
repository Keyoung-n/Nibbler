#include "Game.hpp"

Game::Game(Game const & copy) {
	*this = copy;
}

void Game::play() {
	score = 0;
	int loop 	= 0;
	struct timeval	start;
	struct timeval	end;
	//Draw Gui
	while (1) {
		gettimeofday(&start, NULL);
		// Draw Gui
		// Check player's position
		// if (loop % 100 == 0)
					// Generate Food
		loop++;
		score++;
		gettimeofday(&end, NULL);
		usleep( 60000 - (end.tv_usec - start.tv_usec) );
	}
}

Game::~Game ( void ) {
	std::cout << "Your score was " << score << '\n';
}
