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
  GUI(GUI const & copy);
  GUI& operator=(GUI const &);
  DynamicGUI* get_lib();
  int drawFrame(Vector, std::list<Vector>, std::list<Vector>, int);
  int getUserResponse();
  void set_handle(void* handle);
  void set_lib(DynamicGUI* new_lib);
  void switch_lib(int);
  void* get_handle();
};

std::ostream & operator<<(std::ostream & o, GUI const & rhs);
#endif
