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
	int getDiskSize(short pDiskID);
	short getFreeBlock(short pDiskID);
};

#endif
