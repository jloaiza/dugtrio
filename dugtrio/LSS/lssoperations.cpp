
#include "lssoperations.h"
#include "lss.h"


void LssOperations::createDisk(char* pFileName, int pFileSize, int pBlockSize, short pID)
{
	// verificar si el archivo existe
    Lss * temporalDisk = new Lss(pFileName, pID, pFileSize, pBlockSize);
}

void LssOperations::eraseDisk(char* pFileName)
{
    /** TODO **/
}

void LssOperations::saveDisks(char* pXML){
	
}


void LssOperations::loadDisks(char* pXML){
	
}
