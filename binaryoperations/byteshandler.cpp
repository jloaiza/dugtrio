#include "byteshandler.h"

#include <iostream>

std::string BytesHandler::unum2bin(unsigned long pNum, int pSize){
	return BaseConverter::unum2bin(pNum, pSize*8);
}

std::string BytesHandler::snum2bin(long pNum, int pSize){
	return BaseConverter::snum2bin(pNum, pSize*8);
}

std::string BytesHandler::string2bin(std::string pString, int pSize){

	std::string buffer;

	for (int i = 0; i < pString.length(); i++){
		buffer += BaseConverter::unum2bin(pString[i], 8);
	}

	buffer += BaseConverter::multChar(0, pSize*8 - buffer.length());

	return buffer;
}

std::string BytesHandler::bin2str(std::string pBinary){
	
	std::string buffer;

	bool onConvertion = true;
	char ichar;

	for (int i = 0; onConvertion && i + 8 <= pBinary.length(); i += 8){
		ichar = BaseConverter::to_ulong(pBinary.substr(i, 8));
		if (ichar == 0){
			onConvertion = false;
		} else {
			buffer += ichar;
		}
	}

	return buffer;
}

int main(){
	std::string binary = BytesHandler::string2bin("a", 1);
	std::string prueba = "1";
	std::cout<<binary.length()<<std::endl;
	std::cout<<"l:"<<prueba.length()<<" "<<BytesHandler::bin2str(binary)<<std::endl;
	return 0;
}