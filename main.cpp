#include "game.hpp"

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
