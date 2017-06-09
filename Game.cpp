#include "Game.hpp"

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
		std::cout << "drawing" << '\n';
		// Check player's position
		// if (loop % 100 == 0)
					// Generate Food
		player_alive = snake.move(0, food.getlistofApples(), mapsize);
		loop++;
		score++;
		gettimeofday(&end, NULL);
		usleep( 60000 - (end.tv_usec - start.tv_usec) );
	}
}

int main(int argc, char *argv[]) {
	if (argc == 3) {
		int x = atoi(argv[1]);
		int y = atoi(argv[2]);
		if (x != 0 && y != 0) {
			Game current_game(x, y);
			current_game.play();
		}
		else
			std::cout << "Incorect Mapsize input" << '\n';
	}
	else {
		std::cout << "Not enough arguments filled in. " << '\n';
	}
	return 0;
}
