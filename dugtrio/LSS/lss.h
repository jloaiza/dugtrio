/*
 * lss.h
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


#ifndef LSS
#define LSS

#include <iostream>
#include <fstream>
#include <iomanip>

class lss {
	
private:

	const char * _disk;
	bool _busy;
	char _id;
	int _size;
	int _blockSize;
			
public:
	
	lss(const char *  pDisk, short pID, int pSize, int pBlockSize);
	void write(char* pText, int pBlock);
	char * read(int pBlock);
	
};

#endif //LSS
