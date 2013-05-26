#include "lssnetworkhandler.h"
#include "../tokenizer.h"

void LSSNetworkHandler::inMessage(std::string pMessage, int pSocket){
	std::string ip = Tokenizer::getCommandSpace(pMessage, 2);
	std::string id = Tokenizer::getCommandSpace(pMessage, 3);

	switch (Tokenizer::getCommandSpace(pMessage, 1)){
		case "getFreeBlock":
			getFreeBlock(pSocket, ip);
			break;

		case "readBlock":
			int block = std::stoi(Tokenizer::getCommandSpace(pMessage, 4));
			readBlock(pSocket, ip, id, block);
			break;

		case "writeBlock":
			int block = std::stoi(Tokenizer::getCommandSpace(pMessage, 4));
			std::string message; = Tokenizer::getCommandSpace(pMessage, 5);
			writeBlock(pSocket, ip, block, message);
			break;

		case "getLssList":
			lgndfljgnlkg
			break;

		case "getSize":
			lksdlksgmlv
			break;

		case "writeBytes":
			int block = std::stoi(Tokenizer::getCommandSpace(pMessage, 4));
			int offset = std::stoi(Tokenizer::getCommandSpace(pMessage, 5));
			int size = std::stoi(Tokenizer::getCommandSpace(pMessage, 6));
			std::string message = Tokenizer::getCommandSpace(pMessage, 7);
			writeBytes(pSocket, ip, id, block, offset, size, message);
			break;

		case "readBytes":
			int block = std::stoi(Tokenizer::getCommandSpace(pMessage, 4));
			int offset = std::stoi(Tokenizer::getCommandSpace(pMessage, 5));
			int size = std::stoi(Tokenizer::getCommandSpace(pMessage, 6));
			readBytes(pSocket, ip, id, block, offset, size);
			break;

		case default:
			defaultCase();
			break;
	}
}