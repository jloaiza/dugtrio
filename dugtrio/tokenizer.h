#ifndef TOKENIZER
#define TOKENIZER

#include <string>
#include <array>

class Tokenizer {
public: 

	static std::string getParameters(std::string pMessage);

	static std::string getRegister(std::string pRegisters, int pRegNum);

	static std::string cleanEntry(std::string pEntry);
	

	static std::string getRegName(std::string pRegister);
	static std::string getRegType(std::string pRegister);
	static std::string getRegSize(std::string pRegister);

	static int charIndex(std::string pString, char pChar, int pNumber);

	static std::string getCommandSpace(std::string pString, int pNumber);

private:
	static bool isRestringedChar(char pChar);
	
	static const char _restringedChars[];
};



#endif /* TOKENIZER */