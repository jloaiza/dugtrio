#include <cstring>

#include "lss.h"
#include "../../binaryoperations/byteshandler.h"
#include "../structures/simplelist.h"
#include "../structures/node.h"
#include "lssmanager.h"

LssManager::LssManager(short pID) 
{ 
	_lss = new SimpleList();
	_disponibleID = 0;
	_ID = pID;
}

void LssManager::write(char* pData, short pID, int pBlock)
{
	Lss* temporal = (Lss*)( _lss->get( std::to_string(pID).data() ) );
	temporal->write(pData, pBlock);
}

char * LssManager::read(short pID, int pBlock)
{
	Lss* temporal = (Lss*)( _lss->get( std::to_string(pID).data() ) );
	return temporal->read(pBlock);	
}
	
void LssManager::createDisk(int pFileSize)
{
	short * temp = new short();
	*temp = _disponibleID;
	_disponibleID++;
	Lss * temporal = new Lss(std::to_string(*temp).data(), *temp, pFileSize);
	_lss->insert(temporal);
}

void LssManager::showDisks()
{
	_lss->print();
}

void LssManager::eraseDisk(short pID)
{
	Lss * temporal = new Lss(std::to_string(pID).data(), pID, 0);
	_lss->erase(temporal);
}

/*
int LssManager::getDiskSize(short pID)
{
	Lss* temporal = (Lss*)( _lss->get( std::to_string(pID).data() ) );
	return temporal->getDiskSize();
}
*/

int LssManager::getBlockSize(short pID)
{
	Lss* temporal = (Lss*)( _lss->get( std::to_string(pID).data() ) );
	return temporal->getBlockSize();
}

void LssManager::format(short pID, int pBlockSize)
{
	Lss* temporal = (Lss*)( _lss->get( std::to_string(pID).data() ) );
	temporal->format(pBlockSize);
}

short LssManager::getFreeBlock(short pID)
{
	Lss* temporal = (Lss*)( _lss->get( std::to_string(pID).data() ) );
	return temporal->getFreeBlock();
}

void LssManager::write(char* pData, short pID, int pBlock, int pOffset, int pSize)
{
	Lss* temporal = (Lss*)( _lss->get( std::to_string(pID).data() ) );
	temporal->write(pData, pBlock, pOffset, pSize);
}

char* LssManager::read(short pID, int pBlock, int pOffset, int pSize)
{
	Lss* temporal = (Lss*)( _lss->get( std::to_string(pID).data() ) );
	temporal->read(pBlock, pOffset, pSize);	
}
