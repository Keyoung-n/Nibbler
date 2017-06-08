#include "sdllib.hpp"
#include <dlfcn.h>

//need to make this main use dlopen()
//must create interface base class
//need a factory to instantiate the class within this main


int	main(void)
{

//get handle
	void* handle = dlopen("./lib1.so", RTLD_LAZY);
//create_gl and delete_gl
	Sdllib* (*create_gl)();
	void (*destroy)(Sdllib*);
//run dlsym for create and delete
	create = (Sdllib* (*)())dlsym(handle, "create_gl");
	destroy = (void (*)(Sdllib*))dlsym(handle, "destroy_gl");
//instantiate class
	Sdllib* lib = (*Sdllib)create();
//do something
	for (int i = 0; i < 40; ++i){
		//First clear the renderer
		lib->RenderClear(lib->ren);
		//Draw the texture
		lib->RenderCopy(lib->ren, lib->tex);
		//Update the screen
		lib->RenderPresent(lib->ren);
		//Take a quick break after all that hard work
		lib->Delay(1000);
	}
	destroy(Sdllib);
	return 0;
}
