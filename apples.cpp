#include "apples.hpp"

Apples::Apples() {
	seed = 0;
	count = 0;
}

Apples::~Apples() {
}

void Apples::genApple(Vector Mapsize) {
	Vector new_apple;

	if (count != 5) {
		seed += (unsigned)time(0);
		srand(seed);
		seed++;
		new_apple.y = (rand() % Mapsize.y);
		new_apple.x = (rand() % Mapsize.x);

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

void Apples::set_apples(std::list<Vector> new_apples) { apples = new_apples; }
void Apples::set_seed(int new_seed) { seed = new_seed; }
void Apples::set_count(int new_count) { count = new_count; }
int Apples::get_seed() { return seed; }

std::ostream & operator<<(std::ostream & o, Apples const & rhs) {
	Apples copy(rhs);
	o << copy.Count();
	return o;
}
