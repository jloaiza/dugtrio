/*
 * excribirBinario3.cpp
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


#include <iostream>
#include <fstream>
#include <iomanip>

int main(int argc, char **argv)
{
	
	int size = 5;
	
	std::ofstream newFile;
	newFile.open("newBin", std::ios::out | std::ios::binary);
	
	char * buffer = new char[size];
	
	buffer[0] = 127;
	buffer[1] = 76;
	buffer[2] = 20;
	buffer[3] = 200;
	buffer[4] = 200;
	newFile.write (buffer, size);
	
	newFile.close();
	delete[] buffer;
	
	return 0;
}

