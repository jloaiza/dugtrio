
#ifndef NODE_H
#define NODE_H

class Comparable;

class Node {

public:
    Comparable* data;
    Node* next;
	
    Node(Comparable* pData);
	void print();
};

#endif
