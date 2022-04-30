#ifndef HASHTABLEQUAD_H_
#define HASHTABLEQUAD_H_

#include <vector>
using namespace std;
#include <iostream>
#include <random>
#include <stdio.h>
#include <time.h>

class HashTableQuad
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
	HashTableQuad(int maxNum, double load);

	// required methods
	void insert(int n);
	bool isIn(int n);
	void printKeys();
	void printKeysAndIndexes();
	int getNumKeys();
	int getTableSize();
	double getMaxLoadFactor();
	static std::vector<double> simProbeSuccess();

	// used for testing
	std::vector<int> getTable() {
		return table;
	};
	//add
	bool is_prime(int n);
	double insertCount(int n);

private:
	// required methods
	void rehash();
};

#endif /* HASHTABLEQUAD_H_ */
