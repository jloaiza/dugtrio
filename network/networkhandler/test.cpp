
#include "test.h"

Test::Test(std::string pMessage){
	unic = pMessage;
}

void Test::inMessage(std::string pMessage, int pSocket)
{
    if (pMessage.substr(0, pMessage.find(' ')) == "modify"){
    	unic = pMessage.substr(pMessage.find(' ')+1, pMessage.length());
    	outMessage("Felicidades ha cambiado el valor de la variable", pSocket);
    }
    outMessage("Variable: " + unic, pSocket);
}

