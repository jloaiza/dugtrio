#ifndef LSSOPERATIONS
#define LSSOPERATIONS

class Lss;
class SimpleList;

class LssOperations {
	
protected:
	SimpleList* _lss;
	short _disponibleID;
public:
	LssOperations();
	void createDisk(int pFileSize);
	void showDisks();
	void eraseDisk(short pFileName);
};

#endif
