#ifndef APPLES_HPP
#define APPLES_HPP

#include "vector.h"
#include <list>
#include <iterator>
#include <stdlib.h>
#include <time.h>
#include <iostream>

class Apples {
private:
  std::list<Vector> apples;
  int seed;
  int count;

public:
  Apples ();
  ~Apples ();
  Apples ( Apples const & );
  Apples & operator=( Apples const &);
  std::list<Vector> getlistofApples();
  bool did_food_spawn_on_player(Vector, std::list<Vector>);
  int Count();
  int get_seed();
  void eatApple(Vector);
  void genApple(Vector, std::list<Vector>);
  void set_apples(std::list<Vector>);
  void set_count(int);
  void set_seed(int);
};

std::ostream & operator<<(std::ostream &, Apples const &);
#endif
