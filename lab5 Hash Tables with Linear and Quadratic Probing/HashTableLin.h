#ifndef HASHTABLELIN_H_
#define HASHTABLELIN_H_

#include <vector>
using namespace std;
#include <iostream>
#include <random>
#include <stdio.h>
#include <time.h>


class HashTableLin
{
private:
	// must contain this private field
	std::vector<int> table;
	// define other private fields to store:
	int size;// 1. the size of the table
	int num_key;// 2. the number of keys stored in the table
	double load_factor;// 3. the maximum load factor allowed

public:
	// required constructor
	HashTableLin(int maxNum, double load);

	// required methods
	void insert(int n);
	bool isIn(int n);
	void printKeys();
	void printKeysAndIndexes();
	int getNumKeys();
	int getTableSize();
	double getMaxLoadFactor();
	static std::vector<double> simProbeSuccess();
	static std::vector<double> simProbeUnsuccess(); // for bonus

	// used for testing
	std::vector<int> getTable() {
		return table;
	};
	//add
	bool is_prime(int n);
	double insertCount(int n);
	double unCount(int n);
	void clear();

private:
	// required methods
	void rehash();
};

#endif /* HASHTABLELIN_H_ */
