#ifndef Game_HPP
#define Game_HPP
#include "Draw.hpp"
#include "Player.hpp"
#include "Food.hpp"

class Game {
private:

public:
  Game ( void );
  Game ( Game const & copy );
 // Game & operator=( Game const & copy );
  ~Game ( void );
  void start();
};

 //std::ostream & operator<<(std::ostream & o, Game const & rhs);
#endif
