#ifndef GUIINTERFACE_HPP
#define GUIINTERFACE_HPP

#include "vector.h"

class DynamicGUI {
public:
   // pure virtual function providing interface framework.
   virtual int  playerMovment() = 0;
   virtual void drawFrame(Vector) = 0;
};
#endif
