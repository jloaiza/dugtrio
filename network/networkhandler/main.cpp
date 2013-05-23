
#include <cstdlib>
#include "test.h"

int main(int argc, char** argv) 
{
    NetworkHandler* Server = new Test();
    Server->Run();
    return 0;
}

