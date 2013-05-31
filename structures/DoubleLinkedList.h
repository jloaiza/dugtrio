#ifndef DOUBLELINKEDLIST
#define DOUBLELINKEDLIST

#include "ListNode.h"


template <class t, typename c>
class DoubleLinkedList{

public:

	DoubleLinkedList(){
		_head = _tail = 0;
	}

	void insertCrecient(t* pData);
	void insertDecrecient(t* pData);
	void insertEnd(t* pData);
	void insertStart(t* pData);
	t* search(t* pDataDummy);
	t* erase(t* pDataDummy);

	t* search(c* pData);
	t* erase(c* pData);

private:
	ListNode<t>* searchAux(t* pDataDummy);
	ListNode<t>* searchAux(c* pDataDummy);
	ListNode<t>* _head;
	ListNode<t>* _tail;
};


#endif /* DOUBLELINKEDLIST */

//--------------Definición de los métodos--------------------------------------

template <class t, typename c>
void DoubleLinkedList<t, c>::insertCrecient(t* pData){
	ListNode<t>* newNode = new ListNode<t>(pData);
	if (_head == 0){
		_head = _tail = newNode;

	} else if (*_head.getData() > *pData){
		newNode->setNext(_head);
		_head->setPrevious(newNode);
		_head = newNode;

	} else if (*_tail->getData < *pData) {
		newNode->setPrevious(_tail);
		_tail->setNext(newNode);
		_tail = newNode;

	}else {
		ListNode<t>* iNode = _head;
		while (iNode != 0){
			if (*iNode->getData() > *pData){
				newNode->setNext(iNode);
				newNode->setPrevious(iNode->getPrevious());
				iNode->getPrevious()->setNext(iNode);
				iNode->getNext()->setPrevious(iNode);
				return;
			}
			iNode = iNode->getNext();
		}
	}
}

template <class t, typename c>
void DoubleLinkedList<t, c>::insertDecrecient(t* pData){
	ListNode<t>* newNode = new ListNode<t>(pData);
	if (_head == 0){
		_head = _tail = newNode;

	} else if (*_head.getData() < *pData){
		newNode->setNext(_head);
		_head->setPrevious(newNode);
		_head = newNode;

	} else if (*_tail->getData > *pData) {
		newNode->setPrevious(_tail);
		_tail->setNext(newNode);
		_tail = newNode;

	}else {
		ListNode<t>* iNode = _head;
		while (iNode != 0){
			if (*iNode->getData() < *pData){
				newNode->setNext(iNode);
				newNode->setPrevious(iNode->getPrevious());
				iNode->getPrevious()->setNext(iNode);
				iNode->getNext()->setPrevious(iNode);
				return;
			}
			iNode = iNode->getNext();
		}
	}
}

template <class t, typename c>
void DoubleLinkedList<t, c>::insertStart(t* pData){
	ListNode<t>* newNode = new ListNode<t>(pData);
	newNode->setNext(_head);
	_head->setPrevious(newNode);
	_head = newNode;
}

template <class t, typename c>
void DoubleLinkedList<t, c>::insertEnd(t* pData){
	ListNode<t>* newNode = new ListNode<t>(pData);
	newNode->setPrevious(_tail);
	_tail->setNext(newNode);
	_tail = newNode;
}

template <class t, typename c>
ListNode<t>* DoubleLinkedList<t, c>::searchAux(t* pDataDummy){
	ListNode<t>* iNode = _head;
	while (iNode != 0 && *iNode->getData() != *pDataDummy){
		iNode = iNode->getNext();
	}
	return iNode;
}

template <class t, typename c>
ListNode<t>* DoubleLinkedList<t, c>::searchAux(c* pData){
	ListNode<t>* iNode = _head;
	while (iNode != 0 && *iNode->getData() != *pData){
		iNode = iNode->getNext();
	}
	return iNode;
}

template <class t, typename c>
t* DoubleLinkedList<t, c>::search(t* pDataDummy){
	ListNode<t>* searched = searchAux(pDataDummy);
	return searched != 0 ? searched->getData() : 0;
}

template <class t, typename c>
t* DoubleLinkedList<t, c>::search(c* pData){
	ListNode<t>* searched = searchAux(pData);
	return searched != 0 ? searched->getData() : 0;
}

template <class t, typename c>
t* DoubleLinkedList<t, c>::erase(t* pDataDummy){
	ListNode<t>* toErase = searchAux(pDataDummy);
	if (toErase != 0){
		toErase->getPrevious()->setNext(toErase->getNext());
		toErase->getNext()->setPrevious(toErase->getPrevious);
		t* tmp;
		delete toErase;
		return tmp->getData();
	} else{
		return 0;
	}
}

template <class t, typename c>
t* DoubleLinkedList<t, c>::erase(c* pData){
	ListNode<t>* toErase = searchAux(pData);
	if (toErase != 0){
		toErase->getPrevious()->setNext(toErase->getNext());
		toErase->getNext()->setPrevious(toErase->getPrevious);
		t* tmp;
		delete toErase;
		return tmp->getData();
	} else{
		return 0;
	}
}