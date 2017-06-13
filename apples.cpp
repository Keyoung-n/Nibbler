#include "apples.hpp"

Apples::Apples() {
	seed = 0;
}

Apples::~Apples() {
}

void Apples::genApple(Vector Mapsize) {
	Vector new_apple;

	seed += (unsigned)time(0);
	srand(seed);
	seed++;
	new_apple.y = rand() % Mapsize.y;
	new_apple.x = rand() % Mapsize.x;

	apples.push_back(new_apple);
}

void Apples::eatApple(Vector eaten_apple) {
  for (std::list<Vector>::iterator current = apples.begin(); current != apples.end() ; ++current) {
		if (current->x == eaten_apple.x && current->y == eaten_apple.y) {
      apples.erase(current);
      return ;
    }
	}
}

std::list<Vector> Apples::getlistofApples() {
	return apples;
}
