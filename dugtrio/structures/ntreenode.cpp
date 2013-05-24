
#include <string>
#include <iostream>
#include "ntreenode.h"
#include "ifile.h"
#include "simplelist.h"


nTreeNode::nTreeNode(iFile* pFile, std::string pName)
{
    name = pName;
    _file = pFile;
    _children = new SimpleList;
}

void nTreeNode::addChild(iFile* pNode)
{
    _children->insert(pNode);
}

iFile* nTreeNode::getChild(std::string pName)
{

    /** TODO **/
}

SimpleList* nTreeNode::getChildrenList(){
    return _children;
}

bool nTreeNode::searchChild(std::string pName)
{
    return _children->search(pName);
}	
	
void nTreeNode::eraseChild(std::string pName)
{
    /** TODO **/
}


void nTreeNode::print()
{
    /** TODO **/
}
