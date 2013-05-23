
#include <cstdlib>
#include "client.h"

int main(int argc, char** argv) 
{
    Client *client = new Client("localhost",9999);
    client->Connect();
    client->sendMessage("HOLA MUNDO");
    client->sendMessage("disconnect");
    return 0;
}

