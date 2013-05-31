#ifndef SERVERNETWORKHANDLER
#define SERVERNETWORKHANDLER

#include "../network/networkhandler/networkhandler.h"
#include "session.h"
#include <string>


class ServerNetworkHandler : public NetworkHandler
{

public:


private:

	Session* _session;

	void inMessage(std::string pMessage, int pSocket);

	void outMessageValidate(std::string pMessage, int pSocket);
	void get(std::string pParameters, int pSocket);
	void cd(std::string pParameters, int pSocket);
	void rm(std::string pParameters, int pSocket);
	void touch(std::string pParameters, int pSocket);
	void connect(std::string pParameters, int pSocket);
	void adduser(std::string pParameters, int pSocket);
	void openfile(std::string pParameters, int pSocket);
	void appendReg(std::string pParameters, int pSocket);
	void delActualReg(int pSocket);
	void delReg(std::string pParameters, int pSocket);
	void write(std::string pParameters, int pSocket);
	void seek(std::string pParameters, int pSocket);
	void addReg(std::string pParameters, int pSocket);
	void readActual(int pSocket);
	void readRegister(std::string pParameters, int pSocket);
	void close(int pSocket);
	void consoleMode(std::string pParameters, int pSocket);
	void consoleUI(int pSocket);
};



#endif /* SERVERNETWORKHANDLER */