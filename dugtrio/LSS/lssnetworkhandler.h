#ifndef LSSNETWORKHANDLER
#define LSSNETWORKHANDLER

#include "../network/networkhandler/networkhandler.h"
#include "lssmanager.h"

class LSSNetworkHanlder : public NetworkHandler
{
public:
	void inMessage(std::string pMessage, int pSocket);

private:
	LSSManager* _manager;
	
};


#endif /* LSSNETWORKHANDLER */