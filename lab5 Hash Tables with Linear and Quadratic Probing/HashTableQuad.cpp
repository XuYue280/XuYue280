#include "HashTableQuad.h"
using namespace std;

HashTableQuad::HashTableQuad(int maxNum, double load)
{
    // TODO
	bool is_prime=true;
	load_factor = load;
	num_key = 0;
	size=0;

	double double_size = maxNum / load;
	int int_size = maxNum / load;

	//if and else - to check is the ine_size the prime number
	if(double_size == int_size){
		for(int i=2 ; i<int_size ; i++){
			if(int_size % i == 0){
				is_prime=false;
				break;
			}
		}
	}
	else{
		int_size++;
		for(int i=2 ; i<int_size ; i++){
			if(int_size % i == 0){
				is_prime=false;
			}
		}
	}
//if int_size is NOT a prime number, add 1 once a time, to find the min prime number
	while(is_prime == false){
		int_size++;
		is_prime = true;
		for(int i=2;i<int_size;i++){
			if(int_size % i ==0){
				is_prime = false;
				break;
			}
		}
	}

	//if int_size is prime number, go here directly
	//however, if int_size is NOT, run while loop and go here
	for(int i=0;i<int_size;i++){
		table.push_back(0);
		size++;
	}
}

void HashTableQuad::insert(int n)
{
    // TODO
	bool is_in = isIn(n);
	if(is_in)
		//do nothing
		return;
	else{
		//if the index is empty, insert directly
		if(table[n%size] == 0){
			table[n%size] = n;
			num_key++;
		}
		else{
			int index = (n%size +1) %size;
			int i=2;
			//original position
			while(index!= n%size){
				//empty spot, insert
				if(table[index]==0){
					table[index]=n;
					num_key++;
					//exit the loop
					break;
				}
				//move to next index, avoid index overflow problem-back to top
				index = (n%size + i*i)%size;
				i++;
			}
		}
		//insert might not be satisfied (loop to original position, unlike linear probing-full table)
		double new_load = double (num_key)/size;
		//if the table is full, rehash
		if(new_load > load_factor){
			rehash();
		}
	}
}
bool HashTableQuad::is_prime(int n){
	for(int i=2;i<n;i++){
		if(n%i == 0)
			return false;
	}
	return true;
}
void HashTableQuad::rehash()
{
    // TODO
	vector<int> new_table={};
	//double the size
	size *= 2;
	num_key = 0;
	//find prime size
	while(is_prime(size)==false){
		size++;
	}

	//create an empty, double size table
	for(int i=0;i<size;i++){
		new_table.push_back(0);
	}
	//copy number in old table to new table, (assume all elements are type int)
	for(auto j=table.begin();j!=table.end();j++){
		if(*j!=0){
			if(new_table[*j%size] == 0){
				new_table[*j%size]=*j;
				num_key++;
			}
			else{
				int i=2;
				int index = (*j%size +1) %size;
				//avoid original position
				while(index!= *j%size){
					//empty spot, insert
					if(new_table[index]==0){
						new_table[index]=*j;
						num_key++;
						//exit the function
						break;
					}
					//move to next index, avoid index overflow problem-back to top
					index = (*j%size + i*i)%size;
					i++;
			}
		}
	}
}
	table=new_table;
}

bool HashTableQuad::isIn(int n)
{
    // TODO, change following code after completing this function
	//is in the table
	if(table[n%size]==n)
		return true;
	else{
		int i=2;
		int index = (n%size + 1)%size;
		while(index!=n%size){
			if(table[index]==n)
				return true;
			else if(table[index] == 0)
				return false;
			//avoid index overflow problem
			index = (n%size + i*i)%size;
			i++;
		}
	}
	//==0, do NOT exist
	return false;

}

void HashTableQuad::printKeys()
{
    // TODO
	for(int i=0;i<size;i++){
		if(table[i] != 0)
			cout<<table[i]<<endl;
	}
}

void HashTableQuad::printKeysAndIndexes()
{
    // TODO
	for(int i=0;i<size;i++){
		if(table[i]!=0){
			cout<<"index = "<< i <<", key = "<< table[i] <<endl;
		}
	}

}

int HashTableQuad::getNumKeys() {
	// TODO, change following code after completing this function
    return num_key;
}

int HashTableQuad::getTableSize() {
	// TODO, change following code after completing this function
    return size;
}

double HashTableQuad::getMaxLoadFactor() {
	// TODO, change following code after completing this function
    return load_factor;
}

double HashTableQuad::insertCount(int n) {
	//add n to table and return the # probe at the same time
    double count = 0;
    int index = n % size;
    int i=2;
    while(index!=size){
    	count++;
    	if(table[index] == 0){
    		table[index] = n;
    		num_key++;
    		break;
    	}
    	//avoid index overflow problem
    	index = (index + i*i)%size;
    	i++;
    }
    return count;

}

std::vector<double> HashTableQuad::simProbeSuccess()
{
	//for random number
	srand(time(0));
    vector<double> result(9);
    for (int i = 1;i <= 9;i++) {
        //average probes for each lambda
    	double average = 0.0;
        //100 iteration
        for (int j=0;j<100;j++) {
        	double total_pb = 0.0;
            double each_run_pb = 0.0;
            double load = i*0.1;
            HashTableQuad success_table = HashTableQuad(10000, load);
            for (long int k=1;k<=10000;k++) {
                //get more than 32000 limit for rand()
                //a very large number
                int random_int = (rand() % 10000 + 1) * (rand() % 10000 + 1);
                //cout<<random_int<<endl;
            	if(!success_table.isIn(random_int)){
            		total_pb += success_table.insertCount(random_int);
            		each_run_pb += 1.0;
                    //cout<<"size of table = "<<success_table.size<<" num_key = "<<success_table.num_key<<" total = "<<total_pb<<" each_run_pb = "<<each_run_pb<<" random_int_1 = "<< random_int_1<<" ranom_int_2 = "<<random_int_2<<" random ="<<random_int<<endl;
            	}
            }
            average += (total_pb / each_run_pb);
        }
        result[i - 1] = average / 100.0;
    }
    return result;
}
