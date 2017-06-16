#ifndef GUIINTERFACE_HPP
#define GUIINTERFACE_HPP

#include "vector.h"
#include <list>

class DynamicGUI {
public:
   // pure virtual function providing interface framework.
   virtual int  userResponse() = 0;
   virtual void drawFrame(Vector, std::list<Vector>, std::list<Vector>, int) = 0;
};
#endif
