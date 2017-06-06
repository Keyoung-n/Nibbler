#ifndef Player_H
#define Player_H

#include "vector.h"

class Player {
private:
  Vector coords;
  list::Vector corners;
public:
  Player ();
  ~Player ();
};
#endif
