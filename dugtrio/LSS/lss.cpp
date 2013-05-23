#include "lss.h"

/**
 * constructor de la clase LSS
 * @param pDisk nombre (directorio) del archivo que contendrá los datos del disco
 * @param pID nombre unico del disco, en caso de existir mas de uno en el mismo servidor
 * @param pSize tamaño maximo del disco;
 */
Lss::Lss(const char * pDisk, short pID, int pSize, int pBlockSize){
	_disk = pDisk;
	_busy = false;
	_id = pID;
	_size = pSize;
	_blockSize = pBlockSize;
}

/**
 * metodo para escribir en el disco
 * @param pText informacion que escribiremos en el disco
 * @param pBlock bloque sobre el cual escribiremos
 */
void Lss::write(char* pText, int pBlock)
{
	/* abre el archivo */
	std::fstream File;
	File.open(_disk);
	File.seekp (File.end);
	long sizeFile = File.tellp();
	if ( (sizeFile + _blockSize) >= _size ) 
	{
		std::cout << "el disco esta lleno" << std::endl;
	}
	else
	{
		File.seekp (pBlock, File.beg);
		File.write (pText, _blockSize);
		File.close();
		delete[] pText;
	}
	
}

/**
 * metodo para leer el disco
 * @param pBlock bloque que se va a leer
 * @param pBlockSize tamaño del bloque que vamos a leer
 */
char * Lss::read(int pBlock)
{
	/* arreglo para contener los datos leídos */
	char * buffer = new char [_blockSize];
	
	/* abre el archivo */
	std::ifstream file (_disk);
	
	/* mueve el puntero desde la posicion inicial hasta la posicion pBlock */
	file.seekg (pBlock, file.beg);
		
	/* lee directamente el archivo desde pBlock hasta (pBlock + pBlockSize) */
	file.read (buffer, _blockSize);
	file.close();
	return buffer;
}
