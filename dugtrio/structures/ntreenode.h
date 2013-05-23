
#ifndef NTREENODE
#define NTREENODE

#include <string>

class SimpleList;
class iFile;

class nTreeNode {
	
private:
	
    iFile* _file;
    SimpleList* _children;
	
public:

    std::string name;

    /**
     * @brief nTreeNode
     * @param pFile
     * @param pName
     */
    nTreeNode (iFile* pFile, std::string pName);
	
    /**
     * @brief addChild
     * @param pNode
     */
    void addChild(iFile* pNode);

    /**
     * @brief getChild
     * @return
     */
    iFile* getChild(std::string pName);

    /**
     * @brief getChildrenList
     * @return
     */
    SimpleList* getChildrenList();

    /**
     * @brief searchChild
     * @param pName
     * @return
     */
    bool searchChild(std::string pName);

    /**
     * @brief eraseChild
     * @param pName
     */
    void eraseChild(std::string pName);

    /**
     * @brief print
     */
	void print();
	
};
#endif


