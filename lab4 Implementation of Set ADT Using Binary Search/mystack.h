/*
 * mystack.h
 *
 *  Created on: 2022Äê3ÔÂ21ÈÕ
 *      Author: yuexu
 */
#include "BSTSet.h"
#include "node.h"
#ifndef MYSTACK_H_
#define MYSTACK_H_

class mystack{
private:
	node* head;
public:
	mystack(){head = NULL;}
	bool isempty();
	void push(TNode* root);
	TNode* pop();

};

#endif /* MYSTACK_H_ */
