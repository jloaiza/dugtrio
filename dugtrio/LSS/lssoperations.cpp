/*
 * lssOperations.cpp
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


#include "lssOperations.h"


void lssOperations::createDisk(char* pFileName, int pFileSize, int pBlockSize, short pID)
{
	// verificar si el archivo existe
	lss * temporalDisk = new lss(pFileName, pID, pFileSize, pBlockSize);
}

void lssOperations::eraseDisk(char* pFileName)
{
	_lss 
}

void lssOperations::saveDisks(char* pXML){
	
}


void lssOperations::loadDisks(char* pXML){
	
}
