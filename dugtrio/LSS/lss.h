#ifndef LSS
#define LSS

#include "../comparable.h"

class Lss : public Comparable {
	
private:
    const char* _disk;
	bool _busy;
	int _size;
	int _blockSize;
	short _id;	
public:
    Lss(const char*  pDisk, short pID, int pSize);
    void header();
	void write(char* pText, int pBlock);
	char * read(int pBlock);
	bool eql(Comparable* arg);
	bool gtr(Comparable* arg);
	bool lss(Comparable* arg);
	void print();
};

#endif
