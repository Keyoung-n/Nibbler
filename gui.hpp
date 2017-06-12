#ifndef GUI_HPP
#define GUI_HPP

#include "GUIInterface.hpp"
#include <dlfcn.h>
#include <iostream>
#include <string>

class GUI {
private:
  DynamicGUI* (*create)();
  DynamicGUI* lib;
  void (*destroy)(DynamicGUI*);
  void* handle;
public:
  GUI();
  ~GUI();
  int drawFrame(Vector);
};
#endif
