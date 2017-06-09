#include <iostream>
#include <string>
#include "factory.hpp"

class ncurseslib: public GUI {
private:
  /* data */

public:
  ncurseslib () {

  }
  virtual ~ncurseslib () {

  }
  int  playerMovment() {
    return (1);
  }
  void draw() {
    std::cout << "Drawing gui" << '\n';
  }
};

extern "C" ncurseslib *create_gl() {
    ncurseslib *lib = new ncurseslib;
    return (lib);
}

extern "C" void destroy_gl(ncurseslib *lib) {
    delete lib;
}
