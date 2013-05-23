
#include <iostream>
#include "numero.h"
#include "node.h"
#include "simplelist.h"
#include "simplelist.cpp"
#include "node.cpp"


int main(int argc, char **argv)
{
	simpleList<numero> * lista = new simpleList<numero>();
	
	numero num1(49);
	numero num2(26);
	numero num3(10);
	numero num4(50);
	numero num5(26);
	
	lista->insertStart(num1);
	
	lista->insertStart(num2);
	lista->insertStart(num3);
	lista->insertStart(num4);
	lista->insertStart(num5);
	
	lista->print(); 
	return 0;
}

