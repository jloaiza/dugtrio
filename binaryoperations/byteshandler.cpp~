#include "byteshandler.h"

#include <iostream>

std::string BytesHandler::unum2bin(unsigned long pNum, int pSize){
	return BaseConverter::unum2bin(pNum, pSize*8);
}

std::string BytesHandler::snum2bin(long pNum, int pSize){
	return BaseConverter::snum2bin(pNum, pSize*8);
}

std::string BytesHandler::string2bin(std::string pString, int pSize){

	std::cout<<"entry:"<<(int)pString[0]<<" "<<(int)pString[1]<<std::endl;
	std::cout<<"entry:"<<pString.length()<<std::endl;

	std::string buffer;
	pString += BaseConverter::multChar(0, pSize*8 - pString.length()*8);

	std::cout<<"entry:"<<pString.length()<<std::endl;

	for (int i = 0; i < pString.length(); i++){
		buffer += BaseConverter::unum2bin(pString[i], 8);
	}

	return buffer;
}

std::string BytesHandler::bin2str(std::string pBinary){
	
	std::string buffer;
	char ichar;

	for (int i = 0; i + 8 <= pBinary.length(); i += 8){
		ichar = BaseConverter::to_ulong(pBinary.substr(i, 8));
		buffer += ichar;
	}

	return buffer;
}

int main(){
	std::string d = "123456789";
	std::cout<<d.find('9')<<std::endl;
	std::cout<<BytesHandler::string2bin("Hello", 10)<<std::endl;
	std::cout<<BytesHandler::bin2str(BytesHandler::string2bin("Hello", 10))<<std::endl;

	std::cout<<BytesHandler::bin2str("0000000000000001")<<std::endl;
	std::cout<<BytesHandler::string2bin(BytesHandler::bin2str("0000000000000001"), 2)<<std::endl;
	return 0;
}