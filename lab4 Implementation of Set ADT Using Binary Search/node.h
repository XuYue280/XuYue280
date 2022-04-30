/*
 * node.h
 *
 *  Created on: 2022Äê3ÔÂ21ÈÕ
 *      Author: yuexu
 */
#include "TNode.h"
#ifndef NODE_H_
#define NODE_H_
//node contain element <TNode*> and next*
//it is the node in linked-list stack
class node{
public:
	TNode* element;
	node *next;

	//constructor, create a new node with element = e(TNode*) and next point to n(node)
	node(TNode*& e, node*n){
		element=e;
		next=n;
	}
};

#endif /* NODE_H_ */
