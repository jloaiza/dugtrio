
#include "lssmanager.h"
#include "lss.h"

/**
 * crea un disco para almacenamiento
 * @param pFileName nombre del archivo(lss) en la computadora
 * @param pFileSize tamaño del lss
 * @param pBlockSize tamaño del bloque en el lss
 * @param pID id que diferencia al lss de ótros con la misma ip
 */
void LssManager::createDisk(char* pFileName, int pFileSize, int pBlockSize, short pID){
	// verificar si el archivo existe
    Lss * temporalDisk = new Lss(pFileName, pID, pFileSize, pBlockSize);
}

/**
 * borrar un disco
 * @param pFileName nombre del archivo(lss) en la computadora
 */
void LssManager::eraseDisk(char* pFileName)
{
	_lss = NULL;
}
