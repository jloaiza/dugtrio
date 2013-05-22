/*
 * iFile.h
 * 
 * Copyright 2013 201230364 Maikol Barrantes Garcia <mibarrantes@TM-OP>
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


//#include <iostream>
//int main(int argc, char **argv) { return 0; }

#ifndef IFILE
#define IFILE

class iFile 
{
	
private:

		string _name;
		int _pointer;		//recuerde que esto no es un entero, simplemente es un tipo de dato temporal para pruebas
		
public:
	
	iFile(string pName, int pPointer);
	int getPointer();
	void setPointer(pPointer);
		
};
#endif IFILE
