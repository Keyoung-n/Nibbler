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
  Player(Vector);
  Player(Player const & copy);
  Player& operator=(Player const &);
  std::list<Vector> get_corners();
  std::list<Vector> getplayerCords();
  Vector get_head();
  Vector get_tail();
  bool did_player_eat_apple(std::list<Vector>, Vector);
  bool did_player_eat_itself(Vector);
  bool down(Vector);
  bool left();
  bool move(int, Apples*, Vector);
  bool moveHead(Vector);
  bool right(Vector);
  bool up();
  int get_direction();
  int get_length();
  void eat(Vector);
  void moveTail();
  void set_corners(std::list<Vector>);
  void set_direction(int);
  void set_head(Vector);
  void set_length(int);
  void set_tail(Vector);
};

std::ostream & operator<<(std::ostream & o, Player const & rhs);
#endif
