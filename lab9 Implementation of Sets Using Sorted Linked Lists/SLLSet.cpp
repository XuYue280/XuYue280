/*
 * SLLSet.cpp
 *
 *  Created on: Nov. 17, 2021
 *      Author: moham
 */


#include "SLLSet.h"
#include <iostream>

SLLSet::SLLSet()
{
	size = 0;
	head = NULL;
}

//SLLNode is a class type
//int value, SLLNode* next (move to next element)

SLLSet::SLLSet(int sortedArray[], int arrSize)
{
	size=arrSize;
	//assign "head" to a SLLNode with value = first element in sortedArray
	head=new SLLNode(sortedArray[0],NULL);
	SLLNode*current=head;
		//go through sortedArray and create SLLNode for each number
		for(int i=1;i<arrSize;i++){
			//create SLLNode first
			current->next=new SLLNode(sortedArray[i],NULL);
			//then link current to created SLLNode
			current=current->next;
		}
}
int SLLSet::getSize()
{
	
	//fixME
	return size;
}
SLLSet SLLSet::copy()
{
	int length=getSize();
	int new_array[length];
	//make current start at head and move to next
	SLLNode *current=head;
	for(int i=0;i<length;i++){
		//copy each value from linked list and store in a array
		new_array[i]=current->value;
		//move to next element
		current=current->next;
	}
	
	//fixME
	//create and return new linked list by passing value array and length
	 return *(new SLLSet(new_array,length));
}
bool SLLSet::isIn(int v)
{
	int length=getSize();
	//set "current" start from head
	SLLNode*current=head;
	for(int i=0;i<length;i++){
		//if there is v exist, return true
		if(v==current->value){
			return true;
		}
		//if current position value is not equal to v, move current to next position
		else{
			current=current->next;
		}
	}
    //fixME
	//if check in all position is not matched, return false finally
	return false;
}
void SLLSet::add(int v)
{
	//if v is not in linked list, else do nothing
    if(isIn(v)==false){
    	//situation 1 - empty linked list
    	if(this->head==NULL){
    		//set a new head
    		head=new SLLNode(v,NULL);
    		size++;
    		return;
    	}

    	//situation 2 - v is smaller than head, set v as new head
    	else if(v<head->value){

    		SLLNode*add_v=new SLLNode(v,NULL);
    		add_v->next=head;
    		head=add_v;
    		size++;
    		return;
    	}

    	//situation 3 - v is between the linked list
    	else{
    		SLLNode*current=head;
    		while(current->next!=NULL && v>current->next->value){
    			current=current->next;
    		}
    		//add new node after current position
    		SLLNode*add_v=new SLLNode(v,current->next);
    		current->next=add_v;
    		size++;
    		return;
    	}

    }

}




void SLLSet::remove(int v)
{
	//if v is in linked list then remove. else do nothing
	if(isIn(v)==true){
   SLLNode*current=head;

   //if v is equal head, remove head and set new head
   if(v==head->value){
	   current=current->next;
	   //delete old head
	   delete head;
	   //set new head
	   head=current;
	   size--;
	   return;
   }
   else{
	   //check if next vale is equal to v
	   while(current->next->value!=v){
		   //if not, move to next value
		   current=current->next;
	   }
	   //if next value match, link current element to next after next element
	   current->next=current->next->next;
	   size--;

   }
}
}
SLLSet SLLSet::setUnion(SLLSet s)
{
	SLLNode*list_1=this->head;
	SLLNode*list_2=s.head;
	SLLSet*new_list=new SLLSet();//size=0,head=NULL
	SLLNode*current=NULL;//make a NULL starting point

	//if list1 and list2 are not empty
	while(list_1!=NULL && list_2!=NULL){
		//situation 1, if value are same
		if(list_1->value==list_2->value){
			//if new_list is empty, create head (first time use)
			if(current==NULL){
				new_list->head=new SLLNode(list_1->value,NULL);
				current=new_list->head;
			}
			//if new_list is not empty, append new node after it
			else{
				current->next=new SLLNode(list_1->value,NULL);
				current=current->next;
			}
			//after adding node, increase size by 1, move to next position
			new_list->size++;
			list_1=list_1->next;
			list_2=list_2->next;
		}
		//situation 2
		//if value in list_1 < list_2, append value in list_1
		else if(list_1->value<list_2->value){
			//if new_list is empty, create head (first time use)
			if(current==NULL){
				new_list->head=new SLLNode(list_1->value,NULL);
				current=new_list->head;
			}
			else{
				current->next=new SLLNode(list_1->value,NULL);
				current=current->next;
			}
			//move list_1 to next position, hold position in list_2
			new_list->size++;
			list_1=list_1->next;

		}
		//situation 3
		//if value in list_1 is > list_2, append value in list_1
		else{
			//if new_list is empty, create head (first time use)
			if(current==NULL){
				new_list->head=new SLLNode(list_2->value,NULL);
				current=new_list->head;
			}
			else{
				current->next=new SLLNode(list_2->value,NULL);
				current=current->next;
			}
			//move list_2 to next position, hold position in list_1
			new_list->size++;
			list_2=list_2->next;

		}
		}
	//run through all element in list_2 (nothing left in list_2)
	while(list_1!=NULL){
		if(current==NULL){
			new_list->head=new SLLNode(list_1->value,NULL);
			current=new_list->head;
		}
		else{
			current->next=new SLLNode(list_1->value,NULL);
			current=current->next;
		}
		new_list->size++;
		list_1=list_1->next;
	}
	//run through all element in list_1 (nothing left in list_1)
	while(list_2!=NULL){
			if(current==NULL){
				new_list->head=new SLLNode(list_2->value,NULL);
				current=new_list->head;
			}
			else{
				current->next=new SLLNode(list_2->value,NULL);
				current=current->next;
			}
			new_list->size++;
			list_2=list_2->next;
		}
return *new_list;

}
SLLSet SLLSet::intersection(SLLSet s)
{
	SLLNode*list1=this->head;
	SLLNode*list2=s.head;
	SLLSet*new_list=new SLLSet();//size=0,head=NULL
	SLLNode*current=NULL;//make a NULL starting point

	//situation 1
	//if both linked list is not empty
	while(list1!=NULL && list2!=NULL){
		//if they have same value
		if(list1->value==list2->value){
			//if new_list is empty, set new head
			if(current==NULL){
				new_list->head=new SLLNode(list1->value,NULL);
				current=new_list->head;
			}
			//if there are elements exist, add new one after that
			else{
				current->next=new SLLNode(list1->value,NULL);
				current=current->next;
			}
			//move both list to next position
			list1=list1->next;
			list2=list2->next;
			new_list->size++;
		}
		//if list1 value < list2 value
		else if(list1->value < list2->value){
			//move list1 to next position, hold list2 position
			//since goal is find intersection, do nothing
			list1=list1->next;
		}
		//if list1 value > list2 value
		else{
			list2=list2->next;
		}
	//situation2
	//list1 OR list2 is running out(empty),do nothing
	while(list1==NULL || list2==NULL){
		break;
	}
	}
	 return *new_list;
}

SLLSet SLLSet::difference(SLLSet s)
{
	SLLSet* new_list=new SLLSet();
	//current1 start from 'this head'
	SLLNode*current1=this->head;
	//current2 start from 's head'
	SLLNode*current2=s.head;

	//create new linked list = this
	while(current1!=NULL){
		new_list->add(current1->value);
		current1=current1->next;
	}
	//remove common elements
	while(current2!=NULL){
		//if element in list2 which is not in list1, do not affect(do nothing)
		new_list->remove(current2->value);
		current2=current2->next;
	}
	//left part is the difference
	return *(new_list);
}

SLLSet SLLSet::setUnion(SLLSet sArray[],int size)
{
	//Initialize by using first linked list in sArray
	SLLSet*unionSet=new SLLSet(sArray[0]);
	for(int i=1;i<size;i++){
		//union each linked list to previous list
		*unionSet=unionSet->setUnion(sArray[i]);
	}
	return *(unionSet);
}
string SLLSet::toString()
{
	string output="";
	if(getSize()==0){
		return output;
	}
	SLLNode* current=head;

	while(current!=NULL){
		output+=(to_string(current->value));
		current=current->next;
		//only add commas and space before hit last element
		if(current!=NULL){
			output+=", ";
		}
	}

	return output;

	//return output;



}

