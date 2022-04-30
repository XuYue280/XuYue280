//Xu Yue, xuy280, 400273753

#include "HashTableLin.h"
using namespace std;



//run time n, space c
HashTableLin::HashTableLin(int maxNum, double load)
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

	//double_size have fraction, use int_size + 1 to get rid of fraction
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
//run time best:c, worst:n^2, avg:n, space best:c, worst:n, avg:c
void HashTableLin::insert(int n)
{
    // TODO
	bool is_in = isIn(n);
	if(is_in)
		//do nothing
		return;
	else{
//linear probing will always work if and only if the table is not full && load factor is within certain value
		double new_load = double (num_key + 1)/size;
		//if the table is full, double the size
		if(new_load > load_factor)
			rehash();
		//if the index is empty, insert directly
		if(table[n%size] == 0){
			table[n%size] = n;
			num_key++;
		}
		//if the index is occupied, move to next index
		else{
			int index = (n%size +1) %size;
			//original position
			while(index!= n%size){
				//empty spot, insert
				if(table[index]==0){
					table[index]=n;
					num_key++;
					//after insertion, exit the function
					return;
				}
				//move to next index, avoid index overflow problem-back to top
				index = (index + 1)%size;
			}
		}
	}
}

bool HashTableLin::is_prime(int n){
	for(int i=2;i<n;i++){
		if(n%i == 0)
			return false;
	}
	return true;
}

//run time n^2, space n
void HashTableLin::rehash()
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
					index = (index + 1)%size;
			}
		}
	}
}
	table=new_table;
}
//runtime: best->1, worst->n, space:c
bool HashTableLin::isIn(int n)
{
    // TODO, change following code after completing this function
	//is in the table
	if(table[n%size]==n)
		return true;
	else{
		int index = n%size;
		while(index!=size){
			if(table[index]==n)
				return true;
			else if(table[index] == 0)
				return false;
			//avoid index overflow problem
			index = (index+1)%size;
		}
	}
	//==0, do NOT exist
	return false;

}
//runtime:n, space:c
void HashTableLin::printKeys()
{
    // TODO
	for(int i=0;i<size;i++){
		if(table[i]!=0)
			cout<<table[i]<<endl;
	}
}
//runtime:n, space:c
void HashTableLin::printKeysAndIndexes()
{
    // TODO
	for(int i=0;i<size;i++){
		if(table[i]!=0){
			cout<<"index = "<< i <<", key = "<< table[i] <<endl;
		}
	}
}

int HashTableLin::getNumKeys() {
	// TODO, change following code after completing this function
    return num_key;
}

int HashTableLin::getTableSize() {
	// TODO, change following code after completing this function
    return size;
}

double HashTableLin::getMaxLoadFactor() {
	// TODO, change following code after completing this function
    return load_factor;
}

//runtime: best->1, worst->size
double HashTableLin::insertCount(int n) {
	//add n to table and return the # probe at the same time
	//assume n is NOT in the table
    double count = 0;
    int index = n % size;
    while(index!=size){
    	count++;
    	if(table[index] == 0){
    		//insert n
    		table[index] = n;
    		num_key++;
    		break;
    	}
    	//avoid index overflow problem
    	index = (index + 1)%size;
    }
    return count;
}
void HashTableLin::clear(){
	for (int i=0;i<size;i++){
		table[i]=0;
	}
}

//run time: n^2 ,space:c
std::vector<double> HashTableLin::simProbeSuccess()
{
	//for random number
	srand(time(0));
    vector<double> result(9);
    // i refers to lambda 0.1 -> 0.9
    for (int i = 1;i <= 9;i++) {
    	double average = 0.0;
        //100 iteration
        for (int j=0;j<100;j++) {
        	double total_pb = 0.0;
            double each_run_pb = 0.0;
            double load = i*0.1;
            HashTableLin success_table = HashTableLin(10000, load);
            for (long int k=1;k<=10000;k++) {
                //get more than 32000 limit for rand()
                //a very large number
                int random_int = (rand() % 10000 + 1) * (rand() % 10000 + 1);
                //cout<<random_int<<endl;
            	if(!success_table.isIn(random_int)){
            		//insertCount function do both #probes & insert
            		total_pb += success_table.insertCount(random_int);
            		each_run_pb += 1.0;
                    //cout<<"size of table = "<<success_table.size<<" num_key = "<<success_table.num_key<<" total = "<<total_pb<<" each_run_pb = "<<each_run_pb<<" random_int_1 = "<< random_int_1<<" ranom_int_2 = "<<random_int_2<<" random ="<<random_int<<endl;
            	}
            }
            //sum of successful probed for 100 iterations
            average += (total_pb / each_run_pb);
        }
        result[i - 1] = average / 100.0;
    }
    return result;
}


double HashTableLin::unCount(int n) {
   //assume n is NOT in the table
	double count = 0.0;
    int index = n % size;
    while(index!=size){
    	count++;
    	//if index is empty, n is not in the table
    	if(table[index] == 0){
    		break;
    	}
    	//if index is occupied, check next index
    	else if(table[index] != n){
    		index = (index + 1) % size;
    	}
    }
    return count;
}


std::vector<double> HashTableLin::simProbeUnsuccess()
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
        	//unsuccessful probe happen, #n not in the table
            double each_run_pb = 0.0;
            double load = i*0.1;
            HashTableLin unsuccess_table = HashTableLin(10000, load);
            for (int k=0;k<10000;k++) {
                //get more than 32000 limit for rand()
                //a very large number
                int random_int = (rand() % 10000 + 1) * (rand() % 10000 + 1);
                //cout<<random_int<<endl;
                //first insert random_int
                unsuccess_table.insert(random_int);
            }
            for(int e=0;e<10000;e++){
            	//generate new int to check is in the table
                int random_int_2 = (rand() % 10000 + 1) * (rand() % 10000 + 1);
                cout<<random_int_2<<endl;
            	if(!unsuccess_table.isIn(random_int_2)){
            		total_pb += unsuccess_table.unCount(random_int_2);
            		each_run_pb += 1.0;
            	}
            }
            //sum of unsuccessful probed for 100 iterations
            average += total_pb / each_run_pb;
        }
        result[i-1] = average / 100.0;
    }
    return result;
    //first insert
}
