/*
 * lssGUI.cpp
 * 
 * Copyright 2013 maikol barrantes <maikol@maikol-wander-15>
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
#include "info.h"
#include "lssmanager.h"

void title()
{
	std::cout << lssmenuL << "\n" << lssmenuS << "\n" << lssmenu3 << "\n" << lssmenu4 << "\n";
	std::cout << lssmenu5 << "\n" << lssmenu6 << "\n" << lssmenu7 << "\n" << lssmenu8 << "\n";
	std::cout << lssmenu9 << "\n" << lssmenuS << "\n" << lssmenuL << "\n";
}


int main(int argc, char **argv)
{
	LssManager* diskManager = new lssManager();
	
	title();	
	
	while (true)
	{
		int clave = 0;
		std::cin >> clave;
		
		if (clave == 1)
		{
			int fileSize;
			std::cout << SIZE1;
			std::cin >> fileSize;		
			diskManager->createDisk(fileSize);		
		}
		 
		else if (clave == 2)
		{
			short fileName;
			std::cout << NAME;
			std::cin >> fileName;
			diskManager->eraseDisk(fileName);
		}
		
		else if (clave == 3)
		{
			diskManager->showDisks();
		}
				
		else if (clave == 4)
		{
			//diskManager->saveDisks();
		}
		
		else if (clave == 5)
		{
			char * fileName;
			std::cout << NAME2;
			std::cin >> fileName;
			//diskManager->loadDisks();
		}
		
		else if (clave == 6)
		{
			break;
		}
		
	}
	
	return 0;
	
	
}
