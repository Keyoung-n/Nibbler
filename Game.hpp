#ifndef Game_HPP
#define Game_HPP
// #include "Draw.hpp"
#include "Player.hpp"
#include "Apples.hpp"
#include <ctime>
#include <iostream>
#include <sys/time.h>
#include <unistd.h>
#include <string>

class Game {
private:
  int score;
  Apples food;
  Player snake;

public:
  Game ( void );
  Game ( Game const & copy );
 // Game & operator=( Game const & copy );
  ~Game ( void );
  void play();
};

 //std::ostream & operator<<(std::ostream & o, Game const & rhs);
#endif
