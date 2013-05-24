
#include "lssmanager.h"
#include "lss.h"

lssManager::lssManager() { }

/**
 * retorna el tamaño de un disco
 * @param pDiskID id del disco del cual queremos el tamaño
 * @return el tamaño del disco en bytes 
 */
int LssManager::getDiskSize(short pDiskID)
{
	
	Lss temporal(std::to_string(pDiskID).data(), pDiskID, 0);
	
	if ( _lss->search(temporal) )
	{
		temporal = _lss->get(temporal);
		char * buffer = temporal.read(0);
		std::string temp;
		for(int x=0; x<4; x++)
		{
			temp+=buffer[12+x];
		}
		int z = BytesHandler::to_ulong(temp);
	}
}

/**
 * retorna un espacio libre en el disco (en caso de haber)
 * @param pDiskID id del disco del cual queremos un bloque
 * @return numero del bloque libre
 */
short LssManager::getFreeBlock(short pDiskID)
{
	lss temporal(std::to_string(pDiskID).data(), pDiskID, 0);
	if ( _lss->search(temporal) )
	{
		temporal = _lss->get(temporal);
		char * buffer = temporal.read(0);
		std::string temp;
		for(int x=0; x<2; x++)
		{
			temp+=buffer[2+x];
		}
		int z = BytesHandler::to_ulong(temp);
	}
	
}
