#ifndef Player_H
#define Player_H

#include "vector.h"
#include "Apples.hpp"
#include <list>
#include <iterator>

class Player {
private:
  Vector head, tail;
  std::list<Vector> corners;
  int length;
  void moveTail();

public:
  Player ();
  ~Player ();
  void eat(Vector);
  bool up(std::list<Vector>);
  bool down(std::list<Vector>, Vector);
  bool left(std::list<Vector>);
  bool right(std::list<Vector>, Vector);
  bool did_player_eat_itself(Vector);
  bool did_player_eat_apple(std::list<Vector>, Vector);
};

#endif
