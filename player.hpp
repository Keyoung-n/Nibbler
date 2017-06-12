#ifndef Player_HPP
#define Player_HPP

#include "vector.h"
#include "apples.hpp"
#include <list>
#include <iterator>

class Player {
private:
  Vector head, tail;
  std::list<Vector> corners;
  int length;

public:
  Player ();
  ~Player ();
  bool did_player_eat_apple(std::list<Vector>, Vector);
  bool did_player_eat_itself(Vector);
  bool down(Vector);
  bool left();
  bool move(int, std::list<Vector>, Vector);
  bool moveHead(Vector);
  bool right(Vector);
  bool up();
  void eat(Vector);
  void moveTail();
  std::list<Vector> getplayerCords();
};

#endif
