#ifndef Game_HPP
#define Game_HPP

#include "apples.hpp"
#include "gui.hpp"
#include "player.hpp"
#include <ctime>
#include <iostream>
#include <string>
#include <sys/time.h>
#include <unistd.h>

class Game {
private:
  Apples food;
  GUI interface;
  Vector mapsize;
  int score;

public:
  Game ( void );
  Game (int, int);
  Game ( Game const & copy );
  Game & operator=( Game const & copy );
  ~Game ( void );
  Apples get_food();
  GUI get_interface();
  Vector get_mapsize();
  int get_score();
  void play();
  void set_food(Apples);
  void set_interface(GUI);
  void set_mapsize(Vector);
  void set_score(int);
};

std::ostream & operator<<(std::ostream & o, Game const & rhs);
#endif
