#include "Player.hpp"

Player::Player() {
}

Player::~Player() {
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
	if (!corners.empty())
		last_corner = corners.back();
	else
		last_corner = head;
	if (last_corner.y < tail.y)
		tail.y += 1;
	else if (last_corner.y > tail.y)
		tail.y -= 1;
	else if (last_corner.x < tail.x)
		tail.x -= 1;
	else if (last_corner.x > tail.x)
		tail.x += 1;
	if ((tail.x == last_corner.x) && (tail.y == last_corner.y))
		corners.pop_back();
}

bool Player::moveHead(Vector Mapsize) {
	Vector first_corner;
	if (!corners.empty())
		first_corner = corners.front();
	else
		first_corner = tail;
	if (first_corner.y < head.y)
		head.y -= 1;
	else if (first_corner.y > head.y)
		head.y += 1;
	else if (first_corner.x < head.x)
		head.x += 1;
	else if (first_corner.x > head.x)
		head.x -= 1;
	if (head.y < 0 && head.y > Mapsize.y && head.x < 0 && head.x > Mapsize.x)
		return (true);
	if (did_player_eat_itself(head))
		return (true);
	return false;
}

void Player::eat(Vector pos) {
	length++;
	head = pos;
}

bool Player::up(std::list<Vector> apples) {
	Vector new_head_pos;
	new_head_pos.x = head.x;
	new_head_pos.y = head.y - 1;

	if (new_head_pos.y < 0)
		return (true);
	if (did_player_eat_itself(new_head_pos))
		return (true);
	if (head.y != new_head_pos.y)
		corners.push_back(head);
	head = new_head_pos;
	if (did_player_eat_apple(apples, head))
		eat(head);
	else
		moveTail();
	return (false);
}

bool Player::left(std::list<Vector> apples) {
	Vector new_head_pos;
	new_head_pos.x = head.x - 1;
	new_head_pos.y = head.y;

	if (new_head_pos.x < 0)
		return (true);
	if (did_player_eat_itself(new_head_pos))
		return (true);
	if (head.x != new_head_pos.x)
		corners.push_back(head);
	head = new_head_pos;
	if (did_player_eat_apple(apples, head))
		eat(head);
	else
		moveTail();
	return (false);
}

bool Player::down(std::list<Vector> apples, Vector Mapsize) {
	Vector new_head_pos;
	new_head_pos.x = head.x;
	new_head_pos.y = head.y + 1;

	if (new_head_pos.y > Mapsize.y)
		return (true);
	if (did_player_eat_itself(new_head_pos))
		return (true);
	if (head.y != new_head_pos.y)
		corners.push_back(head);
	head = new_head_pos;
	if (did_player_eat_apple(apples, head))
		eat(head);
	else
		moveTail();
	return (false);
}

bool Player::right(std::list<Vector> apples, Vector Mapsize) {
	Vector new_head_pos;
	new_head_pos.x = head.x + 1;
	new_head_pos.y = head.y;

	if (new_head_pos.x > Mapsize.x)
		return (true);
	if (did_player_eat_itself(new_head_pos))
		return (true);
	if (head.x != new_head_pos.x)
		corners.push_back(head);
	head = new_head_pos;
	if (did_player_eat_apple(apples, head))
		eat(head);
	else
		moveTail();
	return (false);
}
