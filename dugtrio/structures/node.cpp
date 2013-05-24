
#include "node.h"
#include "comparable.h"

Node::Node(Comparable *pData) {
    data = pData;
    next = 0;
}

void Node::print() {
    data->print();
}
