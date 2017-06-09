#include "factory.hpp"
#include <dlfcn.h>

//need to make this main use dlopen()
//must create interface base class
//need a factory to instantiate the class within this main

int	main(void)
{
	//get handle
	void* handle = dlopen("./libtest.so", RTLD_LAZY);
	//create_gl and delete_gl
	GUI* (*create)();
	void (*destroy)(GUI*);
	//run dlsym for create and delete
	create = (GUI* (*)())dlsym(handle, "create_gl");
	destroy = (void (*)(GUI*))dlsym(handle, "destroy_gl");
	//instantiate class
	GUI* lib = create();
	//do something
	for (int i = 0; i < 40; ++i) {
	 	lib->draw();
	}
	// destroy(lib);
	return 0;
}
