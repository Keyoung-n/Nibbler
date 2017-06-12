#include "gui.hpp"

GUI::GUI() {
  handle = dlopen("./ncurseslib/libncurses.so", RTLD_LAZY);
  if (dlerror() != NULL)  {
    std::cout << "something fucked out" << '\n';
  }

  create = (DynamicGUI* (*)())dlsym(handle, "create_gl");
  destroy = (void (*)(DynamicGUI*))dlsym(handle, "destroy_gl");
  lib = create();
}

GUI::~GUI() {
   destroy(lib);
   dlclose(handle);
}

int GUI::drawFrame(Vector mapsize, std::list<Vector> apples, std::list<Vector> playerCords) {
  lib->drawFrame(mapsize, apples, playerCords);
  return (0);
}
