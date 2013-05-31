
#include <cstdlib>
#include <iostream>
#include "test.h"

int main() 
{
    NetworkHandler* Server = new Test();
    Server->start();
    Server->getThread()->join(); 
    return 0;
}

