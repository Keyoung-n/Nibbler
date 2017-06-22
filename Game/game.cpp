#include "game.hpp"

Game::Game( void ) {
}

Game::Game(int x, int y) {
	mapsize.x = x;
	mapsize.y = y;
}

Game::~Game ( void ) {
	std::cout << "Your score was " << score << '\n';
}

void Game::play() {
	score = 0;
	int	speed = 60000;
	bool game_alive = true;
	struct timeval	end;
	struct timeval	start;
	Player snake(mapsize);

	while (game_alive) {
		gettimeofday(&start, NULL);
		interface.drawFrame(mapsize, food.getlistofApples(), snake.getplayerCords(), score);
		game_alive = snake.move(interface.getUserResponse(), &food, mapsize);
		if (score % 100 == 0 || food.Count() == 0)
			food.genApple(mapsize, snake.getplayerCords());
		score++;
		gettimeofday(&end, NULL);
		if ((end.tv_usec - start.tv_usec) >= 0)
			usleep( speed - (end.tv_usec - start.tv_usec) / 1000.0);
	}
}

// Canonical stuff

Game::Game(Game const & copy) {
	*this = copy;
}

Game& Game::operator=(Game const & copy) {
	if ( this != &copy ) {
		Game new_game(copy);
		set_food(new_game.get_food());
		set_interface(new_game.get_interface());
		set_mapsize(new_game.get_mapsize());
		set_score(new_game.get_score());
	}
	return *this;
}

std::ostream & operator<<(std::ostream & o, Game const & rhs) {
	Game copy(rhs);
	o << "This game score is " << copy.get_score();
	return o;
}

Apples Game::get_food() 		{ return food; }
GUI Game::get_interface() 	{ return interface; }
Vector Game::get_mapsize()	{ return mapsize; }
int Game::get_score() 			{ return score; }

void Game::set_food(Apples new_food)				{ food = new_food; }
void Game::set_interface(GUI new_interface)	{ interface = new_interface; }
void Game::set_mapsize(Vector new_mapsize)	{ mapsize = new_mapsize; }
void Game::set_score(int new_score)					{ score = new_score; }
