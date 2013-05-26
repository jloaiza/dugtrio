
#include <iostream>
#include "networkhandler.h"
#include <string>

class Test : public NetworkHandler
{
    public:
    	Test(std::string pMessage);
        void inMessage(std::string pMessage, int pSocket);
        std::string unic;
    private:
};


