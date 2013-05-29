#include "lss.h"
#include "../structures/simplelist.h"
#include "../structures/node.h"

#include "lssoperations.h"

LssOperations::LssOperations()
{
	_disponibleID = 0;
	_lss = new SimpleList();
}

/**
 * crea un disco para almacenamiento
 * @param pFileSize tamaño del lss
 */
void LssOperations::createDisk(int pFileSize)
{
	short * temp = new short();
	*temp = _disponibleID;
	_disponibleID++;
	
	Lss temporalDisk( std::to_string(*temp).data(), *temp, pFileSize);
	_lss->insert(&temporalDisk);
	
}

/**
 * muestra los discos disponibles para almacenamiento
 */
void LssOperations::showDisks()
{
	_lss->print();
}


/**
 * borrar un disco
 * @param pID nombre del archivo(lss) en la computadora
 */
void LssOperations::eraseDisk(short pID)
{	
	Lss temporalDisk( std::to_string(pID).data(), pID, 0);
	_lss->erase(&temporalDisk);
}

/*
void lssOperations::saveDisks(char* pXML){
	
}


void lssOperations::loadDisks(char* pXML){
	
}
*/
