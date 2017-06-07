#ifndef Player_H
#define Player_H

#include "vector.h"
#include "Apples.hpp"
#include <list>

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
  int up();
  int down(Vector Mapsize);
  int left();
  int right(Vector Mapsize);
};
#endif
