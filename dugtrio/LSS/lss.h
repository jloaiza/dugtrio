

#ifndef LSS
#define LSS

#include <iostream>
#include <fstream>
#include <iomanip>

class Lss {
	
private:

    const char* _disk;
	bool _busy;
	char _id;
	int _size;
	int _blockSize;
			
public:

    Lss(const char*  pDisk, short pID, int pSize, int pBlockSize);
	void write(char* pText, int pBlock);
	char * read(int pBlock);
	
};

#endif
