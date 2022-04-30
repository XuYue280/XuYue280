#include "BSTSet.h"
#include <iostream>
#include <algorithm> //std::remove
#include <vector>
#include <bits/stdc++.h>
#include "mystack.h"
using namespace std;

BSTSet::BSTSet()
{
	// TODO
	this->root = NULL;
}
//run time n^2, space n
BSTSet::BSTSet(const std::vector<int>& input)
{
	//check if input is empty
	if(input.size()==0){
		BSTSet();
	}
	//pass input to modify function (remove repeated int, and set in order)
	vector<int> new_input = input;
	new_input=remove_duplicates(new_input);

	int length=new_input.size();

	//get the root from BST_balance function
	this->root=BST_balance(new_input,0,length-1);

	//cout<<"constructor success"<<endl;



	// TODO, change following code after completing this function
	//root = new TNode(-1, NULL, NULL);
}
void BSTSet::destory_node(TNode* root){
	if(root == NULL)
		return;
	else if(root->left != NULL)
		return destory_node(root->left);
	else
		return destory_node(root->right);
	delete root;
	//root=NULL;

}
BSTSet::~BSTSet()
{
	// TODO
	TNode* current = this->root;
	destory_node(current);
	this->root = NULL;

}

//run time n^2, space n
vector<int> BSTSet::remove_duplicates(vector<int>& xx){
	//remove repeated int (search from web)
	//https://www.techiedelight.com/remove-duplicates-vector-cpp/
	auto end = xx.end();
	//check if there are repeated int for each int
	for (auto it = xx.begin(); it != end; ++it) {
	    //new end after remove repeated int
		end = std::remove(it + 1, end, *it);
	}
	//delect the int after end
	xx.erase(end, xx.end());

	//Rearrange the order -> smaller to bigger
	sort(xx.begin(), xx.end());

	return xx;
}
//run time n (length of input array), space log(n)
//idea: take the number from middle to L/R end, make it balanced in L/R sub tree
TNode* BSTSet::BST_balance(const std::vector<int>&inputs, int L, int R){
	//boundary condition check (for recursion)
	if(L>R)
		return NULL;
	//take the middle index, (/2 -> choose left if it have remainder)
	int middle=L+(R-L)/2;

	TNode* current=new TNode(inputs[middle],NULL,NULL);
	//create all left children, index must smaller than the middle
	current->left = BST_balance(inputs, L, middle-1);
	//create all right children, index must larger than the middle
	current->right = BST_balance(inputs, middle+1, R);
	return current;
}
//run time-worst n (linear tree), average-log n; space 1
bool BSTSet::isIn(int v)
{
	// TODO
	if(this->root == NULL)
		return false; //change this after completing this function
	TNode* current=root;
	while(current!=NULL){

		if(current->element == v)
			return true;

		else if(v > current->element)
			current=current->right;

		else
			current=current->left;
	}

	return false;
}
//code from lecture (recursion)
//rum time-worst n (linear tree), average log(n)
//space-log(n)
void BSTSet::insert_lecture(const int v, TNode* &t){
	if(t == NULL)
		t = new TNode(v, NULL, NULL);
	else if(v > t->element)
		insert_lecture(v, t->right);
	else if(v < t->element)
		insert_lecture(v, t->left);
}

void BSTSet::add(int v)
{
	// TODO
	insert_lecture(v,this->root);
}
//run time worst n, average log(n)
int BSTSet::right_min(TNode* x){
	x = x->right;
	while(x->left != NULL)
		x = x->left;
	return x->element;
}
//run time worst n, average log(n)
int BSTSet::left_max(TNode* y){
	y = y->left;
	while(y->right != NULL)
		y = y->right;
	return y->element;
}
//t1 - height from root to target, t2 - from target to replace root O(t1+t2)= O(H)
//run time (balanced tree recursion) log(n)
//space (balanced tree recursion) log(n), n=H(tree height)
TNode* BSTSet::delete_node(TNode* root, int v){
	//empty tree
	if(root == NULL)
		return NULL;

	if(v > root->element)
		//search in root->right branch
		//log(n)
		root->right = delete_node(root->right, v);

	else if(v < root->element)
		//search in root->left branch
		//log(n)
		root->left = delete_node(root->left, v);

	//find the node and delete node

	else{
		//if node do NOT have child
		if(root->left == NULL && root->right == NULL)
			root = NULL;

		//have right child (could have left child or no left child)
		//two child OR only have right child
		else if(root->right != NULL){
			//log(n)
			root->element = right_min(root);
			root->right = delete_node(root->right, root->element);
		}
		//only have left child, use left max value to replace root
		else{
			//log(n)
			root->element = left_max(root);
			root->left = delete_node(root->left, root->element);
		}
	}
	return root;
}
bool BSTSet::remove(int v)
{
	bool check;
	if(isIn(v) == true){
		check = true;
		this->root = delete_node(this->root,v);
	}
	else
		check = false;
	return check;
}

//run time n (#node), space 1, same as lecture printtree
void BSTSet::in_order(TNode* n, vector<int> &in_order_result){
	//same approach like
	if(n != NULL){
		in_order(n->left,in_order_result);
		in_order_result.push_back(n->element);
		in_order(n->right,in_order_result);
	}

}

//run time n (first add all number in THIS then check s), space n (2 vector to store THIS and s)
void BSTSet::Union(const BSTSet& s)
{
	// TODO
	//if they are both empty tree - do nothing
	if(this->root == NULL && s.root ==NULL){
		return;
	}
	//if s is empty ONLY
	else if(this->root != NULL && s.root == NULL){
		// nothing change
		return;
	}
	//if this is empty tree ONLY
	else if(this->root == NULL && s.root != NULL){
		//create an empty vector to store tree element
		vector<int> new_tree_int;
		//get in-order vector, pass to constructor
		in_order(s.root,new_tree_int);
		BSTSet new_tree(new_tree_int);
		this->root = new_tree.root;
	}
	// both this and s are not empty
	else{
	//result to hold union
	vector<int> result={};
	vector<int> this_vector;
	vector<int> s_vector;

	//get in order of THIS and s
	in_order(this->root,this_vector);
	in_order(s.root,s_vector);

	int this_size = this_vector.size();
	int s_size = s_vector.size();

	//first add all number in THIS
	for(int i=0;i<this_size;i++){
		result.push_back(this_vector[i]);
	}
	//add number that THIS do NOT have
	for(int j=0;j<s_size;j++){
		if(!isIn(s_vector[j])){
			result.push_back(s_vector[j]);
		}
	}
	//clear THIS, use the Union result to reconstruct the tree
	this->~BSTSet();
	BSTSet new_tree(result);
	this->root = new_tree.root;
	}
}
//run time n (in-order + compare), space n(two vector to store number in THIS and s)
void BSTSet::intersection(const BSTSet& s)
{
	// TODO
	//if both THIS and s is empty - do nothing
	if(this->root == NULL && s.root == NULL)
		return;
	//if s is empty only - destroy THIS
	else if(this->root != NULL && s.root == NULL)
		this->~BSTSet();
	//if THIS is empty only, do nothing
	else if(this->root == NULL && s.root != NULL)
		return;

	//if THIS and s is both NOT empty
	else{
		vector<int> result={};
		vector<int> this_vector;
		vector<int> s_vector;

		in_order(this->root,this_vector);
		in_order(s.root,s_vector);

		int this_size = this_vector.size();
		int s_size = s_vector.size();
		int i=0,j=0;

		//in-order consideration, worst cast, compare 2n time
		while(i<this_size && j<s_size){
			//same number, add to result
			if(this_vector[i]==s_vector[j]){
				result.push_back(this_vector[i]);
				i++;
				j++;
			}
			//if THIS number is bigger, move s to next index
			else if(this_vector[i] > s_vector[j])
				j++;
			//is s number is bigger, move THIS to next index
			else
				i++;
		}
		//clear tree, and build a new one
		this->~BSTSet();
		BSTSet new_tree(result);
		this->root = new_tree.root;
	}

}
//run time n (get two in-order vector, then comparison run 2n time in worst case)
//space n (create two vector to store in-order number)
void BSTSet::difference(const BSTSet& s)
{
	// TODO
	//if both THIS and s is empty - do nothing
	if(this->root == NULL){
		return;
	}
	//only s is empty - do nothing
	else if(this->root != NULL && s.root == NULL){
		return;
	}
	//both THIS and s is NOT empty
	else{
		vector<int> result={};
		vector<int> this_vector;
		vector<int> s_vector;

		in_order(this->root, this_vector);
		in_order(s.root, s_vector);

		int this_size = this_vector.size();
		int s_size = s_vector.size();
		int i=0, j=0;

		//in-order comparison
		while(i<this_size){
			//if two number is equal, both move to next index
			//j>s_size condition is when no number is left in s_vector, add rest of the numbers in THIS
			if(this_vector[i] == s_vector[j] || j>s_size){
				i++;
				j++;
			}
			//if THIS number is smaller, it is unique, add to result
			else if(this_vector[i] < s_vector[j]){
				result.push_back(this_vector[i]);
				i++;
			}
			//if THIS number is larger, move s to next index
			else{
				j++;
			}
		}
		this->~BSTSet();
		BSTSet new_tree(result);
		this->root = new_tree.root;
	}
}

int BSTSet::size()
{
	// TODO
	vector<int> allNum;
	in_order(this->root, allNum);
	int size = allNum.size();
    return size; //change this after completing this function
}

//to get the maximum height between left subtree or right subtree
int BSTSet::getheight(TNode* root){
	if(root == NULL)
		return -1;
	//get the maximum, each recursion - if root is NOT NULL, +1
	return max(getheight(root->left), getheight(root->right))+1;
}

int BSTSet::height()
{
	// TODO
    return getheight(this->root);
}
//run time n (#of node), space n (stack to store n node)
void BSTSet::printNonRec(TNode* root){
	//create an empty stack
	mystack in_order;
	while(root != NULL || !in_order.isempty()){
		// if left child is NOT empty, push all left child into stack
		if(root != NULL){
			in_order.push(root);
			root = root->left;
		}
		//once left child is empty, print left child->element, pop root node, then go to right child
		else{
			root= in_order.pop();
			cout<<root->element<<",";
			root=root->right;
		}
	}

}

// create and use class MyStack
void BSTSet::printNonRec()
{
	//quick check - if THIS is empty - do nothing
	if(this->root == NULL)
		return;
	printNonRec(this->root);
}

// Do not modify following provided methods

void BSTSet::printBSTSet()
{
    if (root == NULL)
        std::cout << "";
    else {
        printBSTSet(root);
    }
}

void BSTSet::printBSTSet(TNode* t)
{
    if (t != NULL) {
        printBSTSet(t->left);
        std::cout << t->element << ",";
        printBSTSet(t->right);
    }
}
