/**
*************************************************************
* @file: main.cpp
* @brief: Creando un cliente TCP usando Threads!!!!
* @author Yeison Arturo Cruz León :)
* @Universidad: Instituto Tecnológico de Costa Rica.
* @Carnet: 201258348.
* @date 06/07/08 de mayo del 2013
************************************************************
*/

#include <cstdlib>
#include "Test.h"

int main(int argc, char** argv) 
{
    NetworkHandler* Server = new Test();
    Server->Run();
    return 0;
}

