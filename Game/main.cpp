#include "game.hpp"

bool checkMapSize(int x, int y) {
	if (x < 10 || y < 10) {
		std::cout << "Map too small" << '\n';
		return false;
	}
	else if ( x > 60 || y > 45 ){
		std::cout << "Map too big" << '\n';
		return false;
	}
	return true;
}

int main(int argc, char *argv[]) {
	if (argc == 3) {
		int x = atoi(argv[1]);
		int y = atoi(argv[2]);
		if (checkMapSize(x, y)) {
			Game current_game(x, y);
			current_game.play();
		}
	}
	else
		std::cout << "Not enough arguments filled in. " << '\n';
	return 0;
}
