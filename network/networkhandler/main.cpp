
#include <cstdlib>
#include <iostream>
#include "test.h"

int main() 
{
<<<<<<< HEAD
    NetworkHandler* Server = new Test("Hello, welcome to here!");
    Server->Run();
=======
    NetworkHandler* Server = new Test();
    Server->start();
    Server->getThread()->join(); 
>>>>>>> be203ef42d849ee7b8ee2c0512b28e02cf27f18c
    return 0;
}

