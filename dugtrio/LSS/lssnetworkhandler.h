#ifndef LSSNETWORKHANDLER
#define LSSNETWORKHANDLER

#include "../../network/networkhandler/networkhandler.h"
#include "lssmanager.h"
#include "lss.h"
#include "../../structures/DoubleLinkedList.h"

class LSSNetworkHanlder : public NetworkHandler
{
public:
	void inMessage(std::string pMessage, int pSocket);

private:
	DoubleLinkedList<Lss, short>* _lssList;

	void connect(int pSocket, std::string pParam);
	void getFreeBlock(int pSocket, std::string pParam);
	void readBlock(int pSocket, std::string pParam);
	void writeBlock(int pSocket, std::string pParam);
	void getLssList(int pSocket);
	void getSize(int pSocket, std::string pParam);
	void writeBytes(int pSocket, std::string pParam);
	void readBytes(int pSocket, std::string pParam);
	void defaultCase(int pSocket, std::string pCommand);
};


#endif /* LSSNETWORKHANDLER */