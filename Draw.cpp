#include "Draw.hpp"

Draw::Draw() {
  void *handle;

  handle = dlopen ("/lib/libm.so.6", RTLD_LAZY);
    if (!handle) {
       // fputs (dlerror(), stderr);
        //exit(1);
    }
  }
