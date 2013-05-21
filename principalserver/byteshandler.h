#ifndef BYTESHANDLER
#define BYTESHANDLER

#include <string>

class BytesHandler
{
public:

	static long getSignedNumber(std::string pBytes, int pSize, int pStartBytes);
	static unsigned long getUnsignedNumber(std::string pBytes, int pSize, int pStartBytes);
	static std::string getString(std::string pBytes, int pSize, int pStartBytes);

	static std::string getBinary(long pNumber, int pSize);
	static std::string getBinary(std::string pString, int pSize);

private:
	static std::string invertBytes(std::string pBytes);
	static std::string complement(std::string pBytes);
};


#endif /* BYTESHANDLER */