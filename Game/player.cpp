#include "player.hpp"

Player::Player() {
	tail.x = 0;
	tail.y = 0;
	head.x = 2;
	head.y = 0;
	length = 3;
	direction = 4;
}

Player::Player(Vector mapsize) {
	head.x = mapsize.x / 2;
	head.y = mapsize.y / 2;
	tail.x = head.x - 2;
	tail.y = head.y;

	length = 3;
	direction = 4;
}

Player::~Player() {}

std::list<Vector> Player::getplayerCords() {
	std::list<Vector> snake;
	if (!corners.empty()) {
		snake = corners;
	}
	snake.push_back(head);
	snake.push_front(tail);
	return snake;
}

bool Player::did_player_eat_itself(Vector head_pos) {
	Vector next;
	Vector current;

	for (std::list<Vector>::iterator it = corners.begin(); it != corners.end(); ++it) {
		current = *it;
		if (it != corners.begin())
			next = *(std::next(it, 1));
		else
			next = tail;
		if (next.y == current.y && current.y == head_pos.y) {
			if (next.x > current.x) {
				if (head_pos.x > current.x && head_pos.x < next.x)
					return (true);
			}
			else if (next.x < current.x) {
				if (head_pos.x < current.x && head_pos.x > next.x)
					return (true);
			}
		}
	}
	return (false);
}

bool Player::did_player_eat_apple(std::list<Vector> apples, Vector head_pos) {
	for (std::list<Vector>::iterator current = apples.begin(); current != apples.end() ; ++current) {
		if (current->x == head_pos.x && current->y == head_pos.y)
			return (true);
	}
	return (false);
}

void Player::moveTail() {
	 Vector last_corner;
	 if (corners.size() != 0)
	 	last_corner = corners.front();
   else
	 	last_corner = head;
	 if (last_corner.y < tail.y)
	 	tail.y -= 1;
	 else if (last_corner.y > tail.y)
	 	tail.y += 1;
	 else if (last_corner.x < tail.x)
	 	tail.x -= 1;
	 else if (last_corner.x > tail.x)
	 	tail.x += 1;
	 if ((tail.x == last_corner.x) && (tail.y == last_corner.y)) {
		 corners.erase(corners.begin());
	 }

}

bool Player::moveHead(Vector Mapsize) {
	switch (direction) {
		case 1:
			head.y -= 1;
		break;
		case 2:
			head.y += 1;
		break;
		case 3:
			head.x -= 1;
		break;
		case 4:
			head.x += 1;
		break;
	}
	if (head.y < 0 || head.y > Mapsize.y || head.x < 0 || head.x > Mapsize.x)
		return (true);
	if (did_player_eat_itself(head))
		return (true);
	return false;
}

void Player::eat(Vector pos) {
	length++;
	head = pos;
}

bool Player::up() {
	Vector new_head_pos;
	new_head_pos.x = head.x;
	new_head_pos.y = head.y - 1;
	if (new_head_pos.y < 0)
		return (true);
	if (did_player_eat_itself(new_head_pos))
		return (true);
	corners.push_back(head);
	head = new_head_pos;
	return (false);
}

bool Player::left() {
	Vector new_head_pos;
	new_head_pos.x = head.x - 1;
	new_head_pos.y = head.y;

	if (new_head_pos.x < 0)
		return (true);
	if (did_player_eat_itself(new_head_pos))
		return (true);
	corners.push_back(head);
	head = new_head_pos;
	return (false);
}

bool Player::down(Vector Mapsize) {
	Vector new_head_pos;
	new_head_pos.x = head.x;
	new_head_pos.y = head.y + 1;

	if (new_head_pos.y > Mapsize.y)
		return (true);
	if (did_player_eat_itself(new_head_pos))
		return (true);
	corners.push_back(head);
	head = new_head_pos;
	return (false);
}

bool Player::right(Vector Mapsize) {
	Vector new_head_pos;
	new_head_pos.x = head.x + 1;
	new_head_pos.y = head.y;

	if (new_head_pos.x > Mapsize.x)
		return (true);
	if (did_player_eat_itself(new_head_pos))
		return (true);
	corners.push_back(head);
	head = new_head_pos;
	return (false);
}

bool Player::move(int player_input, Apples* food, Vector mapsize) {
	switch (player_input) {
		case 1:
			if (direction != 2 && direction != 1) {
				if (up())
					return false;
				direction = 1;
			}
			else {
				if (moveHead(mapsize))
					return false;
			}
		break;
		case 2:
			if (direction != 1 && direction != 2) {
				if (down(mapsize))
					return false;
				direction = 2;
			}
			else {
				if (moveHead(mapsize))
					return false;
			}
		break;
		case 3:
			if (direction != 4 && direction != 3) {
				if (left())
					return false;
				direction = 3;
			}
			else {
				if (moveHead(mapsize))
					return false;
			}
		break;
		case 4:
			if (direction != 3 && direction != 4) {
				if (right(mapsize))
					return false;
				direction = 4;
			}
			else {
				if (moveHead(mapsize))
					return false;
			}
		break;
		default:
			if (moveHead(mapsize))
				return false;
		break;
	}
	if (did_player_eat_apple(food->getlistofApples(), head)) {
		eat(head);
		food->eatApple(head);
	}
	else
		moveTail();
	return true;
}

// Canonical stuff

Player::Player(Player const & copy) {
	*this = copy;
}

Player& Player::operator=(Player const & copy) {
	if ( this != &copy ) {
		Player new_player(copy);
		set_corners(new_player.get_corners());
		set_direction(new_player.get_direction());
		set_head(new_player.get_head());
		set_length(new_player.get_length());
		set_tail(new_player.get_tail());
	}
	return *this;
}

std::ostream & operator<<(std::ostream & o, Player const & rhs) {
	Player copy(rhs);
	Vector head = copy.get_head();
	Vector tail = copy.get_tail();
	o << head.x << " " << head.y << " | " << tail.x << " " << tail.y;
	return o;
}

Vector Player::get_head() 							{ return head; }
Vector Player::get_tail() 							{ return tail; }
std::list<Vector> Player::get_corners() { return corners; }
int Player::get_direction() 						{ return direction; }
int Player::get_length() 								{ return length; }

void Player::set_corners(std::list<Vector> new_corners) { corners = new_corners; }
void Player::set_direction(int new_direction) 					{ direction = new_direction; }
void Player::set_head(Vector new_head) 									{ head = new_head; }
void Player::set_length(int new_length) 								{ length = new_length; }
void Player::set_tail(Vector new_tail) 									{ tail = new_tail; }
