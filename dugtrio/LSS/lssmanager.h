/*
 * lssManager.h
 * 
 * Copyright 2013 maikol <maikol@maikol-wander-15>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * 
 */


#ifndef LSSMANAGER
#define LSSMANAGER

#include "lssOperations.h"

class lssManager : public lssOperations {
	
private:
	short _ID;
	lss * _lss;	
public:
	
	lssManager();
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

#endif //LSSMANAGER
