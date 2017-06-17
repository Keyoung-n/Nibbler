#ifndef ALLEGROLIB_HPP
#define ALLEGROLIB_HPP

#include "../GUIInterface.hpp"
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro.h>
#include <iostream>
#include <iterator>
#include <list>
#include <string>

class allegrolib: public DynamicGUI {
private:
  ALLEGRO_DISPLAY *display;
  ALLEGRO_EVENT_QUEUE* event_queue;
  float scale;

public:
  allegrolib();
  allegrolib(int, int);
  virtual ~allegrolib();
  int userResponse();
  void drawFrame(Vector, std::list<Vector>, std::list<Vector>, int);
  void printPlayer(std::list<Vector>);
};
#endif
