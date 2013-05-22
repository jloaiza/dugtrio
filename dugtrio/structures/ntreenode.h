/*
 * nTreeNode.h
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


#ifndef NTREENODE
#define NTREENODE

class nTreeNode {
	
private:
	
	iFile * _File;
	listasimple<nTreeNode> * _childs;
	string _name;
	
public:

    /**
     * @brief nTreeNode
     * @param pFile
     * @param pName
     */
	nTreeNode (iFile* pFile, string pName);
	
    /**
     * @brief addChild
     * @param pNode
     */
	void addChild(nTreeNode * pNode);

    /**
     * @brief getChild
     * @return
     */
	nTreeNode getChild();

    /**
     * @brief searchChild
     * @param pName
     * @return
     */
	bool searchChild(string pName);

    /**
     * @brief eraseChild
     * @param pName
     */
	void eraseChild(string pName);

    /**
     * @brief print
     */
	void print();
	
};
#endif //NTREENODE


