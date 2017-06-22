#ifndef NCURSESLIB_HPP
#define NCURSESLIB_HPP

#include "../Game/GUIInterface.hpp"
#include <iterator>
#include <list>
#include <ncurses.h>
#include <string>

class ncurseslib: public DynamicGUI {
public:
  ncurseslib ();
  virtual ~ncurseslib ();
  int userResponse();
  void printPlayer(std::list<Vector>);
  void drawFrame(Vector, std::list<Vector>, std::list<Vector>, int);
};
#endif
