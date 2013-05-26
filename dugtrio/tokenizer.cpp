#include "tokenizer.h"

#include <iostream>

int Tokenizer::charIndex(std::string pString, char pChar, int pNumber){
	int index = -1;
	for (;pNumber > 0;pNumber--){

		if (index > (int)pString.length()) {
			return -1;
		}

		index = pString.find(pChar, index+1);
	}
	return index;
}

std::string Tokenizer::getCommandSpace(std::string pString, int pNumber){
	int start = 0;
	int final = -1;

	for (; pNumber > 0; pNumber--){
		start = final+1;
		if (pString[start] == '"'){
			final = pString.find('"', start+1) + 1;
		} else {
			final = pString.find(' ', start+1);
		}
	}
	return pString.substr(start, final-start);
}

std::string Tokenizer::getRegister(std::string pRegisters, int pRegNum){
	int prevSemicolon = charIndex(pRegisters, ';', pRegNum-1);
	int nextSemicolon = charIndex(pRegisters, ';', pRegNum);

	return pRegisters.substr(prevSemicolon+1, nextSemicolon - prevSemicolon -1);

}

std::string Tokenizer::getRegName(std::string pRegister){
	int final = charIndex(pRegister, '#', 1);
	return pRegister.substr(0, final);
}

std::string Tokenizer::getRegType(std::string pRegister){
	int start = charIndex(pRegister, '#', 1)+1;
	int final = charIndex(pRegister, '#', 2);
	return pRegister.substr(start, final-start);
}

std::string Tokenizer::getRegSize(std::string pRegister){
	int start = charIndex(pRegister, '#', 2)+1;
	return pRegister.substr(start, pRegister.length()-start);
}