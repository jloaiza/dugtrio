
#ifndef LSSOPERATIONS
#define LSSOPERATIONS

class Lss;

class LssOperations {
	
private:
    Lss * _lss;
public:
	LssOperations();
	void createDisk(char* pFileName, int pFileSize, int pBlockSize, short pID);
	void eraseDisk(char* pFileName);
	void saveDisks(char* pFileName);
	void loadDisks(char* pFileName);
};

#endif
