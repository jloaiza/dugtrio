#include "exceptions.h"
#include <iostream>

void Exceptions::exception(std::string pPath, int pType){
	std::cerr<<pPath<<" throws: ";
	switch(pType){
		case INCOMPLETE_BYTES_EXCEPTION:
			 std::cerr<<"Incomplete byte chain"<<std::endl;
	}
	exit(1);
}