
#include <cstdlib>
#include "test.h"

int main(int argc, char** argv) 
{
    NetworkHandler* Server = new Test("Hello, welcome to here!");
    Server->Run();
    return 0;
}

