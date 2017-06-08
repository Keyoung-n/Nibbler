#include <iostream>
#include <string>

extern "C" void foo(void) {
    std::cout << "hello";
}
