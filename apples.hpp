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
  Apples ( Apples const & copy );
  Apples & operator=( Apples const & copy );
  void genApple(Vector);
  void eatApple(Vector);
  int Count();
  std::list<Vector> getlistofApples();
  void set_apples(std::list<Vector> new_apples);
  void set_seed(int new_seed);
  void set_count(int new_count);
  int get_seed();
};

std::ostream & operator<<(std::ostream &, Apples const &);
#endif
