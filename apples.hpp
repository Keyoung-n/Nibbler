#ifndef APPLES_HPP
#define APPLES_HPP

#include "vector.h"
#include <list>
#include <iterator>
#include <stdlib.h>
#include <time.h>

class Apples {
private:
  std::list<Vector> apples;
  int seed;
  int count;

public:
  Apples ();
  ~Apples ();
  void genApple(Vector);
  void eatApple(Vector);
  std::list<Vector> getlistofApples();
};
#endif
