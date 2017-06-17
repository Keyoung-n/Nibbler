#include "gui.hpp"

GUI::GUI() {
  //handle = dlopen("./ncurseslib/libncurses.so", RTLD_LAZY);
  handle = dlopen("./allegrolib/liballegro.so", RTLD_LAZY);
  if (dlerror() != NULL)  {
    std::cout << "Couldn't load sdl lib. :'(" << '\n';
    exit(0);
  }
  create = (DynamicGUI* (*)())dlsym(handle, "create_gl");
  destroy = (void (*)(DynamicGUI*))dlsym(handle, "destroy_gl");
  lib = create();
}

GUI::~GUI() {
   destroy(lib);
   dlclose(handle);
}

int GUI::drawFrame(Vector mapsize, std::list<Vector> apples, std::list<Vector> playerCords, int score) {
  lib->drawFrame(mapsize, apples, playerCords, score);
  return (0);
}

void GUI::switch_lib(int new_lib) {
  	destroy(lib);
  	dlclose(handle);
  	if (new_lib == 5) {
		handle = dlopen("./sdllib/lib1.so", RTLD_LAZY);
		if (dlerror() != NULL) {
			std::cout << "Could not load ncurseslib. :(" << std::endl;
			exit(0);
		}
		create = (DynamicGUI* (*)())dlsym(handle, "create_gl");
		destroy = (void (*)(DynamicGUI*))dlsym(handle, "destroy_gl");
		lib = create();
	}
	else {
		std::cout << "Error: Segmentation Fault (core Dumped)" << std::endl;
		std::cout << "SIKE NIGGA!! invalid keypress, that's all" << std::endl;
		exit(0);
	}
}

int GUI::getUserResponse() {
  int response = lib->userResponse();
  if (response == -1) {
    destroy(lib);
    dlclose(handle);
    std::cout << "Bye :)" << '\n';
    exit(0);
  }
  if (response > 4) {
    switch_lib(response);
    return 0;
  }
  return response;
}
