#ifndef GUI_HPP
#define GUI_HPP

#include "GUIInterface.hpp"
#include <dlfcn.h>
#include <iostream>
#include <string>
#include <cstdlib>

class GUI {
private:
  DynamicGUI* (*create)();
  DynamicGUI* lib;
  void (*destroy)(DynamicGUI*);
  void* handle;
public:
  GUI();
  ~GUI();
  int drawFrame(Vector, std::list<Vector>, std::list<Vector>);
  int getUserResponse();
  void switch_lib(int);
};
#endif
