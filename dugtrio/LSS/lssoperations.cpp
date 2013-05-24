#include "lssoperations.h"
#include "lss.h"

lssOperations::lssOperations()
{
	_disponibleID = 0;
	_lss = new simpleList<lss>();
}

/**
 * crea un disco para almacenamiento
 * @param pFileSize tamaño del lss
 */
void lssOperations::createDisk(int pFileSize)
{
	short * temp = new short();
	*temp = _disponibleID;
	_disponibleID++;
	
	lss temporalDisk( std::to_string(*temp).data(), *temp, pFileSize);
	_lss->insertStart(temporalDisk);
	
}

/**
 * muestra los discos disponibles para almacenamiento
 */
void lssOperations::showDisks()
{
	_lss->print();
}


/**
 * borrar un disco
 * @param pID nombre del archivo(lss) en la computadora
 */
void lssOperations::eraseDisk(short pID)
{	
	lss temporalDisk( std::to_string(pID).data(), pID, 0);
	_lss->erase(temporalDisk);
}

/*
void lssOperations::saveDisks(char* pXML){
	
}


void lssOperations::loadDisks(char* pXML){
	
}
*/
