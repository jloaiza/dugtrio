
#ifndef LssOPERATIONS
#define LssOPERATIONS

#include "lss.h"
#include "../../structures/DoubleLinkedList.h"
#include "lssmanager.h"

class SimpleList;

class LssOperations {
	
public:
	
	static std::string getFreeBlock(short pID, DoubleLinkedList<Lss, short>* pDiskList);
	static std::string getSize(short pID, LssManager* pManager);
	static std::string connect(short pID, std::string pKey, DoubleLinkedList<Lss, short>* pDiskList, LssManager* pManager);
	static std::string readBlock(short pID, int pBlock, DoubleLinkedList<Lss, short>* pDiskList);
	static std::string writeBlock(short pID, int pBlock, std::string pData, DoubleLinkedList<Lss, short>* pDiskList);
	static std::string writeBytes(short pID, int pBlock, int pOffset, int pSize, std::string pData, DoubleLinkedList<Lss, short>* pDiskList);
	static std::string readBytes (short pID, int pBlock, int pOffset, int pSize, DoubleLinkedList<Lss, short>* pDiskList);
	static std::string getLssList(short pID, LssManager* pManager);

};
#endif
