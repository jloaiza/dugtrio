#include "lss.h"
#include "../comparable.h"

/**
 * constructor de la clase LSS
 * @param pDisk nombre o directorio del lss (archivo real)
 * @param pID nombre del lss, para comparaciones
 * @param pSize tamaño maximo del disco;
 */
Lss::Lss(const char * pDisk, short pID, int pSize)
{
	char * temp = new char();
	std::strcpy(temp, pDisk);
	_disk = temp;
	_busy = false;
	_id = pID;
	_size = pSize;
	_blockSize = 12;
	header();
}

/**
 * construye el header del lss (binario)
 */
void Lss::header()
{
	char * data = new char[12];
	for (int x=0; x<6; x++)
	{
		data[x]=0;
	}
	std::string tmp = BytesHandler::bin2str( BytesHandler::unum2bin(1, 2) );
	data[6] = tmp[0];
	data[7] = tmp[1];
	tmp = BytesHandler::bin2str( BytesHandler::unum2bin(_size, 4) );
	data[8] = tmp[0];
	data[9] = tmp[1];
	data[10] = tmp[2];
	data[11] = tmp[3];
	std::ofstream File;
	File.open(_disk);
	File.write (data, _blockSize);
	File.close();
	delete[] data;
}

/**
 * escribe en el disco
 * @param pText informacion que escribiremos en el disco
 * @param pBlock bloque sobre el cual escribiremos
 */
void Lss::write(char* pText, int pBlock)
{
	/* abre el archivo */
	std::fstream File;
	File.open(_disk);
	
	/* mueve el puntero al final para verificar el tamaño del archivo */
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

bool eql(Comparable* arg)
{
	return _id == ((Lss)arg)->_id;
}

bool gtr(Comparable* arg)
{
	
}

bool lss(Comparable* arg)
{
	
}

void print()
{
	
}

