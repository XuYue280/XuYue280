#ifndef BSTSET_H_
#define BSTSET_H_
#include "TNode.h"
#include <vector>
#include <algorithm>
using namespace std;


class BSTSet
{
private:
	// must contain only one private field
	TNode* root;// =NULL

public:
	// required constructors/destructor
	BSTSet();
	BSTSet(const std::vector<int>& input);
	~BSTSet();


	// required methods
	bool isIn(int v);
	void add(int v);

	void insert_lecture(const int v, TNode* &t);

	bool remove(int v);
	void Union(const BSTSet& s);
	void intersection(const BSTSet& s);
	void difference(const BSTSet& s);
	int size();
	int height();
	void printNonRec(); // create and use class MyStack

	// provided recursive print method
	void printBSTSet();

	// Used for testing
	TNode* getRoot()
	{
		return root;
	}
	//self create
	TNode* BST_balance(const std::vector<int> &nums,int L, int R);
	vector<int> remove_duplicates(std::vector<int>& input);
	TNode* delete_node(TNode* root, int v);
	int left_max(TNode* x);
	int right_min(TNode* y);
	void in_order (TNode* n, vector<int> &in_order_result);
	void destory_node(TNode* root);
	int getheight(TNode* root);
	void printNonRec(TNode* root);
private:
	// provided helper methods
	void printBSTSet(TNode* t);
};

#endif /* BSTSET_H_ */
