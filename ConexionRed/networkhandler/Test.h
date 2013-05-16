/**
*************************************************************
* @file: Test.h
* @brief: Creando un cliente TCP usando Threads!!!!
* @author Yeison Arturo Cruz León :)
* @Universidad: Instituto Tecnológico de Costa Rica.
* @Carnet: 201258348.
* @date 06/07/08 de mayo del 2013
************************************************************
*/

#include <iostream>
#include "NetworkHandler.h"

class Test : public NetworkHandler
{
    public:
        void inMessage(std::string pMessage, int pSocket);
    private:
};


