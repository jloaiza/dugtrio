
#include <cstdlib>
#include "Test.h"

int main(int argc, char** argv) 
{
    NetworkHandler* Server = new Test();
    Server->Run();
    return 0;
}

