#include "Player.hpp"

int check_snake_pos(Vector head_pos) {
  return (0);
}

void Player::moveTail() {
  Vector last_corner = corners.back();
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

void Player::eat(Vector pos) {
  length++;
  head = pos;
}

int Player::up() {
  Vector new_head_pos;
  new_head_pos.x = head.x;
  new_head_pos.y = head.y - 1;

  if (new_head_pos.y < 0)
    return (1);
  if (check_snake_pos(new_head_pos))
    return (1);
  if (head.y != new_head_pos.y)
    corners.push_back(head);
  head = new_head_pos;
  moveTail();
  return (0);
}

int Player::left() {
  Vector new_head_pos;
  new_head_pos.x = head.x - 1;
  new_head_pos.y = head.y;

  if (new_head_pos.x < 0)
    return (1);
  if (check_snake_pos(new_head_pos))
    return (1);
  if (head.x != new_head_pos.x)
    corners.push_back(head);
  head = new_head_pos;
  moveTail();
  return (0);
}

int Player::down(Vector Mapsize) {
  Vector new_head_pos;
  new_head_pos.x = head.x;
  new_head_pos.y = head.y + 1;

  if (new_head_pos.y > Mapsize.y)
    return (1);
  if (check_snake_pos(new_head_pos))
    return (1);
  if (head.y != new_head_pos.y)
    corners.push_back(head);
  head = new_head_pos;
  moveTail();
  return (0);
}

int Player::right(Vector Mapsize) {
  Vector new_head_pos;
  new_head_pos.x = head.x + 1;
  new_head_pos.y = head.y;

  if (new_head_pos.x > Mapsize.x)
    return (1);
  if (check_snake_pos(new_head_pos))
    return (1);
  if (head.x != new_head_pos.x)
    corners.push_back(head);
  head = new_head_pos;
  moveTail();
  return (0);
}
