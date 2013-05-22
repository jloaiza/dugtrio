/*
 * lssManager.cpp
 * 
 * Copyright 2013 maikol <maikol@maikol-wander-15>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * 
 */
 
 #include "lssManager.h"

/**
 * crea un disco para almacenamiento
 * @param pFileName nombre del archivo(lss) en la computadora
 * @param pFileSize tamaño del lss
 * @param pBlockSize tamaño del bloque en el lss
 * @param pID id que diferencia al lss de ótros con la misma ip
 */
void lssManager::createDisk(char* pFileName, int pFileSize, int pBlockSize, short pID)
{
	// verificar si el archivo existe
	lss * temporalDisk = new lss(pFileName, pID, pFileSize, pBlockSize);
}

/**
 * borrar un disco
 * @param pFileName nombre del archivo(lss) en la computadora
 */
void lssManager::eraseDisk(char* pFileName)
{
	_lss = NULL;
}
