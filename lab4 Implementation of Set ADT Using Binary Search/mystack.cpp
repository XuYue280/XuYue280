/*
 * mystack.cpp
 *
 *  Created on: 2022Äê3ÔÂ21ÈÕ
 *      Author: yuexu
 */
#include "mystack.h"
#include "node.h"
#include <iostream>

bool mystack::isempty(){
	return(head == NULL);
}

void mystack::push(TNode* root){
	//call node constructor (node need to add, pointer point to next)
	head = new node(root,head);
}
TNode* mystack::pop(){
	if(isempty())
		throw;
	else{
		node* oldhead = head;
		TNode* e = head->element;//head->element is node<TNode>, not TNode->element
		head = head->next;
		delete oldhead;
		return e;
	}
}
