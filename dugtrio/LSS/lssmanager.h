
#ifndef LSSMANAGER
#define LSSMANAGER

#include "lssoperations.h"

class Lss;

class LssManager : public LssOperations {
	
private:
	short _ID;
    Lss * _lss;
public:
	
    LssManager();
	short getFreeBlocks(char* pDiskName);
	short getOccupiedBlocks(char* pDiskName);
	short getOneBlock(char* pDiskName);
	int getDiskSize(char* pDiskName);
	int getBlockSize(char* pDiskName);
	
	void write(char* pText, int pBlock);
	char * read(int pBlock);
	
	
	void createDisk(char* pFileName, int pFileSize, int pBlockSize, short pID);
	void eraseDisk(char* pFileName);
	
	//void createDisk(char* pfileName, int pfileSize, int pBlockSize);
		
	
};

#endif
