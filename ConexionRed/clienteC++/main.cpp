/**
*************************************************************
* @file: main.CPP
* @brief: Creando un cliente TCP!!!!
* @author Yeison Arturo Cruz León :)
* @Universidad: Instituto Tecnológico de Costa Rica.
* @Carnet: 201258348.
* @date 10 de mayo del 2013
************************************************************
*/

#include <cstdlib>
#include "Client.h"

int main(int argc, char** argv) 
{
    Client *client = new Client("localhost",9999);
    client->Connect();
    client->sendMessage("HOLA MUNDO");
    client->sendMessage("disconnect");
    return 0;
}

