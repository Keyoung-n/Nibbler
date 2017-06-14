#ifndef Player_HPP
#define Player_HPP

#include "apples.hpp"
#include "vector.h"
#include <iostream>
#include <iterator>
#include <list>

class Player {
private:
  Vector head, tail;
  std::list<Vector> corners;
  int length;
  int direction;
  
public:
  Player ();
  ~Player ();
  bool did_player_eat_apple(std::list<Vector>, Vector);
  bool did_player_eat_itself(Vector);
  bool down(Vector);
  bool left();
  bool move(int, Apples*, Vector);
  bool moveHead(Vector);
  bool right(Vector);
  bool up();
  void eat(Vector);
  void moveTail();
  std::list<Vector> getplayerCords();
};

#endif
