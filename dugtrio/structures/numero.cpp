/*
 * numero.cpp
 * 
 * Copyright 2013 maikol barrantes <maikol@maikol-wander-15>
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
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */

#include "numero.h"
#include <iostream>

<<<<<<< HEAD
numero::numero(int pData) 
=======
numero::numero (int pData) 
>>>>>>> fd044aceca801fa546b3952cdcbf83d6919d799e
{ 
	_data = pData; 
}

<<<<<<< HEAD
numero::numero() 
{ 

}

=======
>>>>>>> fd044aceca801fa546b3952cdcbf83d6919d799e
bool numero::mayor(numero pData) 
{ 
	return _data > pData._data;
}
	
<<<<<<< HEAD
bool numero::eql(numero pData)
=======
bool numero::eql (numero pData)
>>>>>>> fd044aceca801fa546b3952cdcbf83d6919d799e
{ 
	return _data == pData._data;
}

<<<<<<< HEAD
void numero::print() 
{ 
	std::cout << _data << " - "; 
=======
void numero::print () 
{ 
	std::cout << _data; 
>>>>>>> fd044aceca801fa546b3952cdcbf83d6919d799e
}
