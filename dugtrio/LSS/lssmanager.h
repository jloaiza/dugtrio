#ifndef LSSMANAGER
#define LSSMANAGER

class Lss;
class SimpleList;
class LssManager{
	
private:
	SimpleList* _lss;
	short _disponibleID;
	short _ID;
public:
	LssManager(short pID);
	void write(char* pData, short pID, int pBlock);
	char* read(short pID, int pBlock);
	void createDisk(int pFileSize);
	void showDisks();
	void eraseDisk(short pID);
	//int getDiskSize(short pID);
	int getBlockSize(short pID);
	void format(short pID, int pBlockSize);
	short getFreeBlock(short pID);
	void write(char* pData, short pID, int pBlock, int pOffset, int pSize);
	char* read(short pID, int pBlock, int pOffset, int pSize);
};

#endif
