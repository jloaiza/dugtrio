/*
 * nTreeNode.cpp
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
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */


#include "nTreeNode.h";

nTreeNode::nTreeNode(iFile* pFile, string pName)
{
	_File = pFile;
	_childs = new listasimple<nTreeNode>;
	_name = pName;
}

void nTreeNode::addChild(nTreeNode * pNode) 
{
	_childs->insertar(pNode);
}

nTreeNode nTreeNode::getChild(string pName) 
{
	_child->get(pName);
}

bool nTreeNode::searchChild(string pName)
{
	_child->search(pName);
}	
	
void nTreeNode::eraseChild(string pName)
{
	_child->erase(pName);
}


void nTreeNode::print()
{
	
}
