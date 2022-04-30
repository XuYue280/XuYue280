#ifndef HUGEINTEGER_H_
#define HUGEINTEGER_H_
#include <iostream>
#include <vector>
#include "vector"
#include <sstream>
#include <iterator>
#include <string>
#include <cmath>
#include <chrono>
#include <boost/multiprecision/cpp_int.hpp>
using namespace boost::multiprecision;
using namespace std::chrono;
using namespace std;

class HugeInteger
{
private:
	//positive/negative
	//int sign;
	
	//store each digit (for extraction)

	//vector<int> hugeints;
	vector<string> hugeints;//string

public:
	// Required methods
	HugeInteger(const std::string& val);
	HugeInteger(int n);
	HugeInteger add(const HugeInteger& h);
	HugeInteger subtract(const HugeInteger& h);
	HugeInteger multiply(const HugeInteger& h);
	int compareTo(const HugeInteger& h);
	std::string toString();
	cpp_int add_boost(const HugeInteger& h);
	cpp_int minus_boost(const HugeInteger& h);
	cpp_int compare_boost(const HugeInteger& h);
	cpp_int multiply_boost(const HugeInteger& h);
	//added
    vector<string> get_copy() const;
    std::string VectorToString(vector<string>h);
    std::string universal_add(string THIS, string H);
    std::string universal_minus(string THIS, string H);
    std::string universal_multiply(string a, string b);
    bool comparelen(string num1,string num2);

    //timing

};

#endif /* HUGEINTEGER_H_ */
