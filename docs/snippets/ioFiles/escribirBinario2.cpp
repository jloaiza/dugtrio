/*
 * escribirBinario2.cpp
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


#include <iostream>
#include <fstream>
#include <iomanip>
#include <bitset>

const char * filename = "bin";

int main(int argc, char **argv)
{
	char * buffer;
	long size;
	std::ifstream file (filename, std::ios::ate);
	size = file.tellg();
	file.seekg (0, std::ios::beg);
	buffer = new char [size];
	file.read (buffer, size);
	
	for (int ind=0; ind < size; ind++) {
		std::bitset<8> x( ( (int) buffer[ind] ) );
		std::cout << x << " ; ";
	}
	file.close();
	delete[] buffer;
	return 0;
}

