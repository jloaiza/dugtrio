#include "lssnetworkhandler.h"
#include "../tokenizer.h"
#include <exception>
#include <cstdlib>
#include "lssoperations.h"

void LSSNetworkHandler::inMessage(std::string pMessage, int pSocket){
	std::string command = Tokenizer::getCommandSpace(pMessage, 1);
	std::string param = Tokenizer::getParameters(pMessage);

	if (command == "connect"){
		connect(pSocket, param);

	} else if (command == "getFreeBlock"){
		getFreeBlock(pSocket, param);

	} else if (command == "readBlock"){
		readBlock(pSocket, param);

	} else if (command == "writeBlock"){
		writeBlock(pSocket, param);

	} else if (command == "getLssList"){
		getLssList(pSocket);
	
	} else if (command == "getSize"){
		getSize(pSocket, param);
	
	} else if (command == "writeBytes"){
		writeBytes(pSocket, param);

	} else if (command == "readBytes"){
		readBytes(pSocket, param);

	} else {
		defaultCase(pSocket, command);

	}
}

void LssNetworkHandler::connect(int pSocket, std::string pParam){
	try {
		short diskID = stoi(Tokenizer::getCommandSpace(pParam, 1));
		std::string secKey = Tokenizer::getCommandSpace(pParam, 2);
		if (secKey == ""){
			outMessage("?Error: El comando 'connect' espera dos atributos\n", pSocket);
		} else {
			outMessage(LSSOperations::connect(diskID, secKey, _lssList), pSocket);
		}
	} catch (std::exception e){
		outMessage("?Error: El primer paremetro debe ser un número\n", pSocket);
	}
}

void LssNetworkHandler::getFreeBlock(int pSocket, std::string pParam){
	try {
		short diskID = stoi(Tokenizer::getCommandSpace(pParam, 1));
		
		outMessage(LSSOperations::getFreeBlock(diskID, _lssList), pSocket);

	} catch (std::exception e){
		outMessage("?Error: Error de tipo, algunos parametros debe ser números\n", pSocket);
	}
}

void LssNetworkHandler::readBlock(int pSocket, std::string pParam){
	try {
		short diskID = stoi(Tokenizer::getCommandSpace(pParam, 1));
		int block = stoi(Tokenizer::getCommandSpace(pParam, 2));

		outMessage(LSSOperations::readBlock(diskID, block, _lssList), pSocket);

	} catch (std::exception e){
		outMessage("?Error: Error de tipo, algunos parametros debe ser números\n", pSocket);
	}
}

void LssNetworkHandler::writeBlock(int pSocket, std::string pParam){
	try {
		short diskID = stoi(Tokenizer::getCommandSpace(pParam, 1));
		int block = stoi(Tokenizer::getCommandSpace(pParam, 2));
		std::string data = Tokenizer::getCommandSpace(pParam, 3);
		if (data == ""){
			outMessage("?Error: El comando 'writeBlock' espera tres atributos\n", pSocket);
		} else {
			outMessage(LSSOperations::writeBlock(diskID, block, data, _lssList), pSocket);
		}
	} catch (std::exception e){
		outMessage("?Error: El primer paremetro debe ser un número\n", pSocket);
	}
}

void LssNetworkHandler::getLssList(int pSocket){
	outMessage(LSSOperations::getLssList(), pSocket);
}

void LssNetworkHandler::getSize(int pSocket, std::string pParam){
	try {
		short diskID = stoi(Tokenizer::getCommandSpace(pParam, 1));
		outMessage(LSSOperations::getSize(diskID), pSocket);

	} catch (std::exception e){
		outMessage("?Error: El paremetro debe ser un número\n", pSocket);
	}
}

void LssNetworkHandler::writeBytes(int pSocket, std::string pParam){
	try {
		short diskID = stoi(Tokenizer::getCommandSpace(pParam, 1));
		int block = stoi(Tokenizer::getCommandSpace(pParam, 2));
		int size = stoi(Tokenizer::getCommandSpace(pParam, 3));
		std::string data = Tokenizer::getCommandSpace(pParam, 4);
		if (data == ""){
			outMessage("?Error: El comando 'writeBytes' espera cuatro atributos\n", pSocket);
		} else {
			outMessage(LSSOperations::writeBytes(diskID, block, size, data, _lssList), pSocket);
		}
	} catch (std::exception e){
		outMessage("?Error: Error de tipo, algunos parametros debe ser números\n", pSocket);
	}
}

void LssNetworkHandler::readBytes(int pSocket, std::string pParam){
	try {
		short diskID = stoi(Tokenizer::getCommandSpace(pParam, 1));
		int block = stoi(Tokenizer::getCommandSpace(pParam, 2));
		int size = stoi(Tokenizer::getCommandSpace(pParam, 3));

		outMessage(LSSOperations::writeBytes(diskID, block, size, data, _lssList), pSocket);

	} catch (std::exception e){
		outMessage("?Error: Error de tipo, algunos parametros debe ser números\n", pSocket);
	}
}

void LssNetworkHandler::defaultCase(int pSocket, std::string pCommand){
	outMessage("?Error: El el comando '" + pCommand + "' no fue encontrado\n", pSocket);
}
