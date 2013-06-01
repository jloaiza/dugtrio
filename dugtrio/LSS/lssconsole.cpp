#include "lssconsole.h"
#include "info.h"
#include <iostream>

inline void LssConsole::start(){
	_thread = new std::thread(callRun, this);
}

inline void LssConsole::stop(){
	_onRun = false;
}

void LssConsole::callRun(LssConsole* pConsole){
	pConsole->run();
}

void LssConsole::run(){
	title();	
	
	while (_onRun)
	{
		int clave = 0;
		std::cin >> clave;
		
		if (clave == 1)
		{
			int fileSize;
			std::cout << SIZE1;
			std::cin >> fileSize;		
			_diskManager->createDisk(fileSize);		
		}
		 
		else if (clave == 2)
		{
			short fileName;
			std::cout << NAME;
			std::cin >> fileName;
			_diskManager->eraseDisk(fileName);
		}
		
		else if (clave == 3)
		{
			_diskManager->showDisks();
		}
				
		else if (clave == 4)
		{
			//_diskManager->saveDisks();
		}
		
		else if (clave == 5)
		{
			char * fileName;
			std::cout << NAME2;
			std::cin >> fileName;
			//_diskManager->loadDisks();
		}
		
		else if (clave == 6)
		{
			break;
		}
		
	}
}

void LssConsole::title(){
	std::cout << lssmenuL << "\n" << lssmenuS << "\n" << lssmenu3 << "\n" << lssmenu4 << "\n";
	std::cout << lssmenu5 << "\n" << lssmenu6 << "\n" << lssmenu7 << "\n" << lssmenu8 << "\n";
	std::cout << lssmenu9 << "\n" << lssmenuS << "\n" << lssmenuL << "\n";
}