#include "AVLTree.h"
#include <cstdlib>

int main(){
	AVLTree<int>* tree = new AVLTree<int>;

	for (int i = 0; i < 10; i++){
		int* toInsert = new int(rand()%200);
		std::cout<<"inserting:"<<*toInsert<<std::endl;
		tree->insert(toInsert);
		// tree->printTree(AVLTree<int>::PRE_ORDER_TRAVERSAL);
		// std::cout<<"**** INSERT ****\n"<<std::endl;
	}

	std::cout<<"\n----------- INSERTED ------------"<<std::endl;
	tree->printTree(AVLTree<int>::PRE_ORDER_TRAVERSAL);

	int del = 0;

	std::cout<<"\n----------- TO ERASE ------------"<<std::endl;
	while(del != -1){
		std::cout<<"Digite un número para borrar"<<std::endl;
		cin>>del;
		std::cout<<"----.----"<<std::endl;
		tree->erase(&del);
		//tree->insert(new int(del));
		tree->printTree(AVLTree<int>::PRE_ORDER_TRAVERSAL);
	}

	return 0;
}