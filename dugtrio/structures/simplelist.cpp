/*
 * simpleList.cpp
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

#include <iostream>
#include "simplelist.h"

template <class T>
simpleList<T>::simpleList() 
{
	_size = 0;
	_head = NULL;
}


template <typename T>
void simpleList<T>::insertStart(T pData) 
{
	node<T> * newNode = new node<T> (pData);
	newNode->_next = _head;
	_head = newNode;
	_size++;
}

template <class T>
void simpleList<T>::insertEnd(T pData)
{
	_size++;
	node<T> * newNode = new node<T> (pData);
	if (!_head) 
	{
		_head = newNode;
	}
	else 
	{
		node<T> * temp = _head;
		while (temp->_next != NULL)
		{
			temp = temp->_next;
		}
		temp->_next = newNode;
	}
}

template <class T>
bool simpleList<T>::search(T pData)
{
	if (!_head){
		return false;
	}
	else{
		node<T> *tmp = _head;
		while (tmp){
			if (tmp->getdato().igual(pData)) {
				return true;
			}
			tmp = tmp->siguiente;
		}
		return false;
	}
}



template <class T>
void simpleList<T>::erase(T pData)
{
	if (!_head) { }
	else 
	{
		if ( (_head->_data()).eql(pData))
		{
			node<T> *tmp = _head;
			_head = _head->_next;
			tmp->_next = NULL;
		}
		else{
			node<T> *tmp = _head;
			while(! ((tmp->_next)->_data).eql(pData))
			{
				tmp = tmp->_next;
			}
			node<T> *tmp2 = tmp->_next;
			tmp->_next = tmp2->_next;
			tmp2->_next = NULL;
			return true;
		}
	}
}

template <class T>
void simpleList<T>::print()
{
	node<T> * tmp = _head;
	if (!_head) 
	{
		std::cout << "la lista esta vacia";
	}
	else 
	{
		while(tmp)
		{
			tmp->print();
			if (!tmp->_next) std::cout << "NULL";
			tmp = tmp->_next;
		}
	}
	std::cout << std::endl;
}
