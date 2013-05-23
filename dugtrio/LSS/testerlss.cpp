
#include <iostream>
#include "lss.h"

const short size = 10;

int main(int argc, char **argv)
{
	lss * discoPrueba = new lss("disk1", 1, 200, 10);
	char * text = discoPrueba->read(20);
	/*
	for (int ind=0; ind < size; ind++) {
		std::cout << ( (int) text[ind] ) << " ; ";
	}
	*/
	
	text[0] = 4;
	text[1] = 4;
	text[2] = 4;
	text[3] = 4;
	text[4] = 4;
	text[5] = 4;
	text[6] = 4;
	text[7] = 4;
	text[8] = 4;
	text[9] = 4;
	
	discoPrueba->write(text, 30);
	 
	return 0;
}

