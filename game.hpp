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
  int score;
  Apples food;
  GUI interface;
  Player snake;
  Vector mapsize;

public:
  Game ( void );
  Game (int, int);
  Game ( Game const & copy );
 // Game & operator=( Game const & copy );
  ~Game ( void );
  void play();
};

 //std::ostream & operator<<(std::ostream & o, Game const & rhs);
#endif
