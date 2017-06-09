#include "draw.hpp"

Draw::Draw() {
  handle = dlopen ("./Ncurses/libfoo.so", RTLD_GLOBAL);
  if (!handle) {
    fputs (dlerror(), stderr);
    exit(1);
  }

  str = (void (*)(void))dlsym(handle, "foo");
  if ((error = dlerror()) != NULL)  {
    fputs(error, stderr);
    exit(1);
  }

  str();
  dlclose(handle);
}

Draw::~Draw() {

}
