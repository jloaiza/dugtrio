#include "byteshandler.h"
#include "../exceptions.h"
#include <cstdlib>
#include <bitset>
#include <cmath>

#include <iostream>

//Para compilar usar estandar 11 (-std=c++0x)

std::string BytesHandler::getBinary(long pNumber, int pSize){
	std::bitset<32> bin(pNumber);
	return bin.to_string().substr(32-pSize*8, pSize*8);
}

std::string BytesHandler::getBinary(std::string pString, int pSize){
	std::string buffer;
	for (int i = 0; i < pString.length(); i++){
		std::bitset<8> chr(pString[i]);
		buffer += chr.to_string();
	}
	std::string extra;
	for (int i = 0; i < pSize-pString.length(); i++){
		extra += "00000000";
	}
	return extra+buffer;
}

long BytesHandler::getSignedNumber(std::string pBytes, int pSize, int pStartBytes){
	pBytes = pBytes.substr(pStartBytes*8, pSize*8);
	//pBytes = invertBytes(pBytes); //Descomentar solo si se lee un número guardado directamente como casteo a char y no como binario

	if (pBytes[0] == '1'){

		pBytes = complement(pBytes.substr(1, pBytes.length()-1));

		return strtol(pBytes.data(), 0, 2) * -1;
	} else {
		return strtol(pBytes.data(), 0, 2);
	}

}

unsigned long BytesHandler::getUnsignedNumber(std::string pBytes, int pSize, int pStartBytes){
	pBytes = pBytes.substr(pStartBytes*8, pSize*8);
	std::cout<<pBytes<<std::endl;
	unsigned long result = 0;
	for (float i = pBytes.length()-1, j = 0; i >= 0; i--, j++){
		std::cout<<"bit:"<<pBytes[i]<<"  added:"<<(pBytes[i]-'0')*pow(2.0, j)<<" value:"<<result<<std::endl;
		result += (pBytes[i]-'0') * pow(2, j);
	}
	return result;
}

std::string BytesHandler::getString(std::string pBytes, int pSize, int pStartBytes){
	pBytes = pBytes.substr(pStartBytes*8, pSize*8);

	if (pBytes.length()%8 != 0){
		Exceptions::exception("BytesHandler/getString", Exceptions::INCOMPLETE_BYTES_EXCEPTION);
	} else {
		std::string buffer;
		unsigned char tmp;
		for (int i = 0; i+8 <= pBytes.length(); i+=8){
			tmp = (unsigned char)strtol(pBytes.substr(i, 8).data(), 0, 2);
			buffer += tmp;
		}
		return buffer;
	}
}

std::string BytesHandler::complement(std::string pBytes){

	std::string baseStr = "1";
	for (int i = 0; i < pBytes.length(); i++){
		baseStr += "0";
	}

	long value = strtol(pBytes.data(), 0, 2);
	long base = strtol(baseStr.data(), 0, 2);

	unsigned long result = base-value;
	std::bitset<32> resultBin(baseStr.length()==32?result+1:result);

	return resultBin.to_string();
}

std::string BytesHandler::invertBytes(std::string pBytes){
	std::string buffer;

	if (pBytes.length()%8 != 0){
		Exceptions::exception("BytesHandler/invertBytes", Exceptions::INCOMPLETE_BYTES_EXCEPTION);
	} else {
		for (int i = pBytes.length(); i >= 8; i -= 8){
			buffer += pBytes.substr(i-8, 8);
		}
		return buffer;
	}
}

int main(){
	std::string bin = BytesHandler::getBinary(2.2, 4);
	std::cout<<bin<<std::endl;
	//bin = BytesHandler::invertBytes(bin);

	std::cout<<BytesHandler::getUnsignedNumber(bin, 4, 0)<<std::endl;
	//std::cout<<BytesHandler::getSignedNumber(bin, 4, 0)<<std::endl;



	// std::string bin = BytesHandler::getBinary("Hello, world!", 32);
	// std::cout<<bin<<std::endl;
	// std::cout<<BytesHandler::getString(bin, 32, 0)<<std::endl;

	//std::cout<<BytesHandler::getNumber("11111101", 2, 0)<<std::endl;
	//std::cout<<BytesHandler::complement("11111100")<<std::endl;
	//std::cout<<BytesHandler::invertBytes("0000001000000000")<<std::endl;
	return 0;
}