#include "apples.hpp"

Apples::Apples() {
	seed = 0;
	count = 0;
}

Apples::~Apples() {
}

bool Apples::did_food_spawn_on_player(Vector apple, std::list<Vector> player_cords) {
	std::list<Vector>::iterator next;
	std::list<Vector>::iterator current;

	for (std::list<Vector>::iterator it = player_cords.begin(); it != player_cords.end(); ++it) {
		current = it;
		next = it;
		next++;
		if (next->y == current->y && current->y == apple.y) {
			if (next->x > current->x) {
				if (apple.x > current->x && apple.x < next->x)
					return (true);
			}
			else if (next->x < current->x) {
				if (apple.x < current->x && apple.x > next->x)
					return (true);
			}
		}
	}
	return (false);
}

void Apples::genApple(Vector Mapsize, std::list<Vector> player_cords) {
	Vector new_apple;

	if (count != 5) {
		seed += (unsigned)time(0);
		srand(seed);
		seed++;
		new_apple.y = (rand() % Mapsize.y);
		new_apple.x = (rand() % Mapsize.x);

		if (did_food_spawn_on_player(new_apple, player_cords)) {
			genApple(Mapsize, player_cords);
			return;
		}
		apples.push_back(new_apple);
		count++;
	}
}

void Apples::eatApple(Vector eaten_apple) {
  for (std::list<Vector>::iterator current = apples.begin(); current != apples.end() ; ++current) {
		if (current->x == eaten_apple.x && current->y == eaten_apple.y) {
      		apples.erase(current);
			count--;
      		return ;
    	}
	}
}

int Apples::Count() {
	return count;
}

std::list<Vector> Apples::getlistofApples() {
	return apples;
}

// Canonical stuff

Apples::Apples(Apples const & copy) {
	*this = copy;
}

Apples& Apples::operator=(Apples const & copy) {
	if ( this != &copy ) {
		Apples food(copy);
		set_apples(food.getlistofApples());
		set_count(food.Count());
		set_seed(food.get_seed());
	}
	return *this;
}

void Apples::set_apples(std::list<Vector> new_apples)	{ apples = new_apples; }
void Apples::set_seed(int new_seed)										{ seed = new_seed; }
void Apples::set_count(int new_count)									{ count = new_count; }

int Apples::get_seed() { return seed; }

std::ostream & operator<<(std::ostream & o, Apples const & rhs) {
	Apples copy(rhs);
	o << copy.Count();
	return o;
}
