/*
 * node.h
 * 
 * Copyright 2013 201230364 Maikol Barrantes Garcia <mibarrantes@TM-OP>
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


#ifndef NODE_H
#define NODE_H

#include <iostream>

template <class T> class node
{
public:
	T _data;
	node<T> * _next;
	
	node(T pData);
	void print();
};

#endif // NODE_H
