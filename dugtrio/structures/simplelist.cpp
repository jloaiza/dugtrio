
#include "simplelist.h"

#include <iostream>
#include "node.h"
#include "comparable.h"

SimpleList::SimpleList()
{
	_size = 0;
    _head = 0;
}

void SimpleList::insert(Comparable *pData)
{
    Node* newNode = new Node(pData);
    newNode->next = _head;
	_head = newNode;
	_size++;
}

bool SimpleList::search(std::string pName)
{
    Node* iterNode = _head;

    while (iterNode != 0){
        if (iterNode->data->name.compare(pName) == 0){
            return true;
        }
    }

    return false;
}


void SimpleList::erase(Comparable *pData)
{
    if (_head == 0) { /* Nothing to erase */ }
    else {

        if (_size == 1 && pData->eql(_head->data)){
            _head = NULL;
            return;
        }

        else {

            Node* iterNode = _head;

            while(iterNode->next != NULL && !(iterNode->next->data->eql(pData))){
                iterNode = iterNode->next;
            }

            iterNode->next = iterNode->next->next;
        }
	}
}

Comparable* SimpleList::get(std::string pName)
{

    Node* iterNode = _head;

    while (iterNode != NULL){

        if (iterNode->data->name.compare(pName) == 0){

            return iterNode->data;
        }
    }

    return 0;
}

void SimpleList::print()
{
    Node* iterNode= _head;
    if (_head == NULL){
        std::cout << "Empty List";
	}
    else
	{
        while(iterNode != NULL)
		{
            iterNode->data->print();
		}
	}
	std::cout << std::endl;
}