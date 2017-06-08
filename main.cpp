#include "sdllib.hpp"

//need to make this main use dlopen()
//must create interface base class
//need a factory to instantiate the class within this main


int	main(void)
{
	Sdllib	lib;

	for (int i = 0; i < 40; ++i){
		//First clear the renderer
		lib.RenderClear(lib.ren);
		//Draw the texture
		lib.RenderCopy(lib.ren, lib.tex);
		//Update the screen
		lib.RenderPresent(lib.ren);
		//Take a quick break after all that hard work
		lib.Delay(1000);
	}
	lib.Destroy(lib.win, lib.ren, lib.tex);
	return 0;
}
