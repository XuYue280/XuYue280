#include "HugeInteger.h"


//construction 1
HugeInteger::HugeInteger(const std::string& val) {
	//initialize attributes, i is for counting (index)
	int i=0;
	//sign=1;
	//check empty string
	if(val.size()==0){
	    throw "this is a empty string";
	}
	//negative sign always is in front of the number
	if (val[0]=='-'){
		//sign=-1;
		hugeints.push_back("-");
		//move to next index
		i++;
	}
	//if first element is not a number ('-' is included in IF statement)
	//ASCII: 48->57 refers to 0->9
	else if(val[0]<48 || val[0]>57){
	    throw "string contain non-number element";
	}
	//check from first(second "-") letter until to last letter (null character)
	while(val[i]!='\0'){
		//ASCII: check in range 48-57
		if(val[i]>=48 && val[i]<=57){
			//append this number to vector(list)
			hugeints.push_back(string(1,val[i]));
			i++;
		}
		//if the string contain any non-number element
		else{
			//first clean vector
			hugeints.clear();
			//then throw an exception
		    throw "string contain non-number element";
		}
	}

}
//construction 2
HugeInteger::HugeInteger(int n) {
	// TODO
	//sign=1;
	//meaningless if n<=0
	if(n<=0){
		throw "n cannot be <= 0";
	}
	//for n>0 (integer)
	else{
		//there is no requirement for pos/neg int, assume it is positive
		int random_int;
		//generate first random int, from 1->9
		random_int=(rand()%9)+1;
		std::string tostring=std::to_string(random_int);
		//append to vector
		hugeints.push_back(tostring);
		//generate following ints
		for(int i=1;i<n;i++){
			//0->9
			random_int=rand()%10;
			std::string tostring=std::to_string(random_int);
			//append to vector (after)
			hugeints.push_back(tostring);
		}
	}

}


vector<string> HugeInteger::get_copy() const {
    vector<string> copy(hugeints);
    return copy;
}

std::string HugeInteger::VectorToString(vector<string>h){
	/*stringstream ss;
	std::string result="";
	copy(h.begin(),h.end(),ostream_iterator<string>(ss,""));
	result=ss.str();

	//NOT sure how to add '-' for negative
	//if(sign==-1)
		//result.insert(result.begin(),'-');

	return result;*/
	int len=h.size();
	std::string result="";
	for(int i=0;i<len;i++){
		string string_int=h[i];
		char char_int=string_int[0];
		result.insert(result.end(), char_int);
	}
	return result;
}

std::string HugeInteger::universal_add(string THIS, string H){

	std::string num1=THIS;
	std::string num2=H;
	std::string result="";

	int len1=num1.size();
	int len2=num2.size();
	//add 0 at front to fill the position
	if(len1>len2)
		num2.insert(num2.begin(),len1-len2,'0');
	else if(len1<len2)
		num1.insert(num1.begin(),len2-len1,'0');


	//num1 + num2;
	//if both number is positive
		int carry=0;
		//add from last to front
		for(int i=num1.size()-1;i>=0;i--){
			//-'0' str to int
			int sum=(num1[i]-'0')+(num2[i]-'0')+carry;
			if(carry)
				carry=0;
			//insert at front, +'0' int to str
			result.insert(result.begin(),(sum%10)+'0');
			//if sum>10, there is a carry
			if(sum/10)
				carry=1;
		}
		//if after the addition for all digit but still have carry, add it at front
		if(carry)
			result.insert(result.begin(),(carry)+'0');

	return result;
}
bool HugeInteger::comparelen(string num1,string num2){
    //num2 longer than num1 -> return 0
	if(num1.length()<num2.length())
        return  false;
    //num1 longer than num2 -> return 1
    else if(num1.length()>num2.length())
        return true;
	// universal compare
    else
        return num1.compare(num2)>0;
}

//do NOT care input sign, always do positive number - positive number
//result might be negative
std::string HugeInteger::universal_minus(string THIS, string H){
	std::string num1=THIS;
	std::string num2=H;
	std::string result="";

	int len1=num1.size();
	int len2=num2.size();
	//add 0 at front to fill the position
	if(len1>len2)
		num2.insert(num2.begin(),len1-len2,'0');
	else if(len1<len2)
		num1.insert(num1.begin(),len2-len1,'0');

	int newsize=num2.size();
	int borrow=0;

	//always THIS - H
	//big - small , THIS>H
	if(num1.compare(num2)>0){
		for(int i=(newsize-1);i>=0;i--){
			//-'0' str to int
			int diff=(num1[i]-'0')-(num2[i]-'0')-borrow;
			if(borrow)
				borrow--;
			//insert at front, +'0' int to str
			//diff could be negative
			result.insert(result.begin(),((diff+10)%10)+'0');
			//if diff<0, there is a borrow
			if(diff<0)
				borrow++;
		}
		//remove meaningless '0' at front
		int size=result.size();
		for(int i=0;i<size-1;i++){
			if(result.front()!='0'){
				break;
			}
			else{
				result.erase(0,1);
			}

		}
		return result;
	}
	//small-big num1<num2
	//missing first element
	else if(num1.compare(num2)<0){
		for(int i=(newsize-1);i>=0;i--){
			//-'0' str to int
			int diff=(num2[i]-'0')-(num1[i]-'0')-borrow;
			if(borrow)
				borrow--;
			//insert at front, +'0' int to str
			result.insert(result.begin(),((diff+10)%10)+'0');
			//if sum>10, there is a carry
			if(diff<0)
				borrow++;

		}
		//erase all 0 from left to right 0100->100
		int size=result.size();
		for(int i=0;i<size-1;i++){
			if(result.front()!='0'){
				break;
			}
			else{
				result.erase(0,1);
			}
		}
		//small-big ->negative  add '-' sign
		result.insert(result.begin(),'-');
	}
	//if two number are equal
	else
		result="0";
	return result;
}

//only multiply two positive number a>=b in digits
std::string HugeInteger::universal_multiply(string a, string b){
	//create an array to store result
	//the sum size will not bigger than size a + size b

	int len1=a.size();
	int len2=b.size();
	//add 0 at front to fill the position
	if(len1>len2)
		b.insert(b.begin(),len1-len2,'0');
	else if(len1<len2)
		a.insert(a.begin(),len2-len1,'0');

	//get new size after fill with 0
	int size_a=a.size();
	int size_b=b.size();

	int oldsize=size_a+size_b;
	//create an array to store product sum
	int result_int[oldsize]={};
	std::string result="";

	//first use digit in a multiply all digit in b, then move to next digit in a.
	//(from right to left -> higher to lower)
	for(int i=size_a-1;i>=0;i--){
		for(int j=size_b-1;j>=0;j--){
			//add each product in corresponding index
			int index=size_a-1-i + size_b-1-j;
			//order is backward e.g. index 0 store the product for last 2 number from a&b
			result_int[index]+=(a[i]-'0')*(b[j]-'0');
		}
	}

	//carry addition
	int size_result_int=sizeof(result_int)/sizeof(int);
	for(int i=0;i<size_result_int-1;i++){
		result_int[i+1]+=result_int[i]/10;
		result_int[i]=result_int[i]%10;
	}

	//sizeof(result_int)-1 refers to the last element in array, right to left, remove all 0
	int index2=(sizeof(result_int)/sizeof(int))-1;
	while(result_int[index2]==0){
		//[39854600000]->[398546] (645893 is the true value)
		index2--;
	}
	//copy digit from backward ([result_int array] to [result string])
	while(index2>=0){
		result.insert(result.end(),result_int[index2]+'0');
		index2--;
	}
	//if the result is empty, means all index are 0 and been cleared, return 0
	if(result==""){
		return "0";
	}

	return result;
}




HugeInteger HugeInteger::add(const HugeInteger& h){
	// TODO
	vector<string> h_copy=h.get_copy();
	std::string num1=VectorToString(hugeints);
	std::string num2=VectorToString(h_copy);
	std::string result;
		if(num1[0]=='-'&& num2[0]!='-'){ //negative a, positive b, -9+18=9 =18-9
			num1.erase(0,1);
	         result=universal_minus(num2,num1);
	     }
	     else if(num1[0]!='-'&& num2[0]=='-'){//positive a, negative b, 13-24=-11 = 13-24
	    	 num2.erase(0,1);
	    	 result=universal_minus(num1,num2);
	     }
	     else if(num1[0]!='-'&& num2[0]!='-') {//positive a, positive b, 8+16=8+16=24
	         result=universal_add(num1,num2);
	     }
	     else{ //negative a, negative b, -17-26=-(17+26)
	    	 //erase '-'
	    	 num1.erase(0,1);
	    	 num2.erase(0,1);
	         result=universal_add(num1,num2);
	         result.insert(result.begin(),'-');
	     }


    HugeInteger newHugeInteger = HugeInteger(result);
	return newHugeInteger;
}

HugeInteger HugeInteger::subtract(const HugeInteger& h){
	// TODO
	vector<string> h_copy=h.get_copy();
	std::string num1=VectorToString(hugeints);
	std::string num2=VectorToString(h_copy);
	std::string result="";

	if(num1[0]=='-'&& num2[0]!='-'){//negative a, positive b, (-a) - b = -(a+b) -7-5=-12=-(5+7)
		num1.erase(0,1);
         result=universal_add(num2,num1);
         result.insert(result.begin(),'-');
     }
     else if(num1[0]!='-'&& num2[0]=='-'){//positive a, negative b, a - (-b) = a+b 7-(-19)=26=7+19
    	 num2.erase(0,1);
    	 result=universal_add(num1,num2);
     }
     else if(num1[0]!='-'&& num2[0]!='-'){//positive a, negative, a - b
         result=universal_minus(num1,num2);
     }
     else{//negative a, negative b, -a - (-b) = b-a -9-(-13)= 4 =13-9
    	 //erase '-'
    	 num1.erase(0,1);
    	 num2.erase(0,1);
         result=universal_minus(num2,num1);
     }

    HugeInteger newHugeInteger = HugeInteger(result);
	return newHugeInteger;
}

HugeInteger	HugeInteger::multiply(const HugeInteger& h){
	// TODO
	vector<string> h_copy=h.get_copy();
	std::string num1=VectorToString(hugeints);
	std::string num2=VectorToString(h_copy);
	std::string result="";

	//both positive
	if(num1[0]!='-' && num2[0]!='-'){
		result=universal_multiply(num1,num2);
	}
	//both negative, result still positive
	else if(num1[0]=='-' && num2[0]=='-'){
		//num1,num2 remove '-' sign
		num1.erase(0,1);
		num2.erase(0,1);
		result=universal_multiply(num1,num2);
	}
	//num1 negative, num2 positive
	else if(num1[0]=='-' && num2[0]!='-'){
		num1.erase(0,1);
		result=universal_multiply(num1,num2);
		//product is negative, add '-' sign
		if(result[0]!='0'){
		result.insert(result.begin(),'-');
		}
		//if result=0, no need to add minus sign
	}
	//num1 positive, num2 negative
	else if(num1[0]!='-' && num2[0]=='-'){
		num2.erase(0,1);
		result=universal_multiply(num1,num2);
		//product is negative, add '-' sign
		if(result[0]!='0'){
		result.insert(result.begin(),'-');
		}
		//if result=0, no need to add minus sign
	}
	HugeInteger newHugeInteger = HugeInteger(result);
	return newHugeInteger;
}

//compare two hugeinterger, (THIS & H)
int HugeInteger::compareTo(const HugeInteger& h){
	// TODO
	//return -1 if THIS<h , 1 if THIS>h, 0 if THIS==h
	vector<string> h_copy=h.get_copy();
	std::string THIS=VectorToString(hugeints);
	std::string H=VectorToString(h_copy);

	//fast check (1 positive, 1 negative)
	if(THIS[0]=='-' && H[0]!='-'){
		return -1;
	}
	else if(THIS[0]!= '-' && H[0]=='-'){
		return 1;
	}

	//both negative
	else if(THIS[0]=='-' && H[0]=='-'){
		//remove '-' sign
		THIS.erase(0,1);
		H.erase(0,1);
		int len1=THIS.size();
		int len2=H.size();
		//add 0 at front, make their size equal
		if(len1>len2)
			H.insert(H.begin(),len1-len2,'0');
		else if(len1<len2)
			THIS.insert(THIS.begin(),len2-len1,'0');
		int newlen1=THIS.size();
		//compare -> from left to right
		for(int i=0;i<newlen1;i++){
			if(THIS[i]>H[i])
				return -1;
			else if(THIS[i]<H[i])
				return 1;
			//if the number in current index is equal, then move on
			else
				continue;
		}
		return 0;
	}
	//both positive
	else if(THIS[0] != '-' && H[0] != '-'){
		int len1=THIS.size();
		int len2=H.size();
		if(len1>len2)
			H.insert(H.begin(),len1-len2,'0');
		else if(len1<len2)
			THIS.insert(THIS.begin(),len2-len1,'0');
		int newlen1=THIS.size();
		for(int i=0;i<newlen1;i++){
			if(THIS[i]>H[i])
				return 1;
			else if(THIS[i]<H[i])
				return -1;
			else
				continue;
		}
		return 0;
	}
	return 0;
}

cpp_int HugeInteger::add_boost(const HugeInteger& h){
	vector<string> h_copy=h.get_copy();
	std::string THIS=VectorToString(hugeints);
	std::string H=VectorToString(h_copy);
	cpp_int i(THIS);
	cpp_int j,k;
	j.assign(H);
	k=i+j;
	//std::cout<<"addition result k = "<<k<<std::endl;
	return k;
}
cpp_int HugeInteger::minus_boost(const HugeInteger& h){
	vector<string> h_copy=h.get_copy();
	std::string THIS=VectorToString(hugeints);
	std::string H=VectorToString(h_copy);
	cpp_int i(THIS);
	cpp_int j,k;
	j.assign(H);
	k=i-j;
	return k;
}
cpp_int HugeInteger::compare_boost(const HugeInteger& h){
	vector<string> h_copy=h.get_copy();
	std::string THIS=VectorToString(hugeints);
	std::string H=VectorToString(h_copy);
	cpp_int i(THIS);
	cpp_int j,k;
	j.assign(H);
	if(j==i){
		return 0;
	}
	return(j>i);
}
cpp_int HugeInteger::multiply_boost(const HugeInteger& h){
	vector<string> h_copy=h.get_copy();
	std::string THIS=VectorToString(hugeints);
	std::string H=VectorToString(h_copy);
	cpp_int i(THIS);
	cpp_int j,k;
	j.assign(H);
	k=i*j;
	return k;
}


std::string HugeInteger::toString(){
	// TODO
	//create an empty string
	std::string str_value="";
	int size=hugeints.size();
	//if the integer is negative, add "-" at the begining
	//if(sign==-1)
		//str_value+='-';
	//index refers to how much numbers it contain in this HugeInteger
	for(int i=0;i<size;i++){
		//append to str_value from left->right
		str_value+=hugeints[i];
	}
	return str_value;
}
