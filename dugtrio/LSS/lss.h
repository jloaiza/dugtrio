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
	char *read(int pPos, int pSize);
	void write(int pPos, int pSize, char* pData);
	void header();
public:
    Lss(const char*  pDisk, short pID, int pSize);
	void write(char* pText, int pBlock);
	char * read(int pBlock);
	int getFreeBlock();
	void eraseBlock(int pBlock);
	int getBlockSize();
	void format(int pBlockSize);
	void write(char* pText, int pBlock, int pOffset, int pSize);
	char* read(int pBlock, int pOffset, int pSize);
	
	bool eql(Comparable* arg);
	bool gtr(Comparable* arg);
	bool lss(Comparable* arg);
	void print();

	bool operator != (const short& pToCompare);
	bool operator == (const short& pToCompare);
	bool operator < (const short& pToCompare);
	bool operator <= (const short& pToCompare);
	bool operator > (const short& pToCompare);
	bool operator >= (const short& pToCompare);

};

#endif
