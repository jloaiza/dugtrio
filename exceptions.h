#ifndef EXCEPTIONS
#define EXCEPTIONS

#include <string>

class Exceptions
{
public:
	static const int INCOMPLETE_BYTES_EXCEPTION = 0;

	static void exception(std::string pPath, int pType);

};

#endif /* EXCEPTIONS */