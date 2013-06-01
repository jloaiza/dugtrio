
#include "test.h"

Test::Test(std::string pMessage){
	unic = pMessage;
}

void Test::inMessage(std::string pMessage, int pSocket)
{
<<<<<<< HEAD
    if (pMessage.substr(0, pMessage.find(' ')) == "modify"){
    	unic = pMessage.substr(pMessage.find(' ')+1, pMessage.length());
    	outMessage("Felicidades ha cambiado el valor de la variable", pSocket);
    }
    outMessage("Variable: " + unic, pSocket);
=======
    std::cout << pMessage << std::endl;
    if (!strncmp(pMessage.c_str(), "disconnect", 10))
    {
        NetworkHandler::disconnectClient();
    }
    else if(!strncmp(pMessage.c_str(), "closeserver", 11))
    {
        NetworkHandler::closeServer();
    }
>>>>>>> be203ef42d849ee7b8ee2c0512b28e02cf27f18c
}

