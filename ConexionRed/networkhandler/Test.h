
#include <iostream>
#include "NetworkHandler.h"

class Test : public NetworkHandler
{
    public:
        void inMessage(std::string pMessage, int pSocket);
    private:
};


