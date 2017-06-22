#include "gui.hpp"

GUI::GUI() {
	handle = dlopen("./libncurses.dylib", RTLD_LAZY);
	if (dlerror() != NULL)  {
		std::cout << "Couldn't load ncurses lib. :'(" << '\n';
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

int GUI::drawFrame(Vector mapsize, std::list<Vector> apples, std::list<Vector> GUICords, int score) {
	lib->drawFrame(mapsize, apples, GUICords, score);
	return (0);
}

void GUI::switch_lib(int new_lib) {
	destroy(lib);
	dlclose(handle);
	if (new_lib == 5) {
		handle = dlopen("./libSDL.dylib", RTLD_LAZY);
		if (dlerror() != NULL) {
			std::cout << "Could not load SDLlib. :(" << std::endl;
			exit(0);
		}
		create = (DynamicGUI* (*)())dlsym(handle, "create_gl");
		destroy = (void (*)(DynamicGUI*))dlsym(handle, "destroy_gl");
		lib = create();
	}
	else if (new_lib == 6) {
		handle = dlopen("./allegrolib/liballegro.so", RTLD_LAZY);
		if (dlerror() != NULL) {
			std::cout << "Could not load allegro lib. :(" << std::endl;
			exit(0);
		}
		create = (DynamicGUI* (*)())dlsym(handle, "create_gl");
		destroy = (void (*)(DynamicGUI*))dlsym(handle, "destroy_gl");
		lib = create();
	}
	else if (new_lib == 7) {
		handle = dlopen("./libncurses.dylib", RTLD_LAZY);
		if (dlerror() != NULL) {
			std::cout << "Could not load ncurses lib. :(" << std::endl;
			exit(0);
		}
		create = (DynamicGUI* (*)())dlsym(handle, "create_gl");
		destroy = (void (*)(DynamicGUI*))dlsym(handle, "destroy_gl");
		lib = create();
	}
	else {
		std::cout << "error: lib switching didn't work" << '\n';
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

// Canonical stuff

GUI::GUI(GUI const & copy) {
	*this = copy;
}

GUI& GUI::operator=(GUI const & copy) {
	if ( this != &copy ) {
		GUI new_gui(copy);
		set_lib(new_gui.get_lib());
		set_handle(new_gui.get_handle());
	}
	return *this;
}

std::ostream & operator<<(std::ostream & o, GUI const & rhs) {
	GUI copy(rhs);
	o << "This lib is working";
	return o;
}

DynamicGUI* GUI::get_lib()	{ return lib; }
void* GUI::get_handle() 		{ return handle; }

void GUI::set_lib(DynamicGUI* new_lib) { lib = new_lib; }
void GUI::set_handle(void* new_handle) { handle = new_handle; }
