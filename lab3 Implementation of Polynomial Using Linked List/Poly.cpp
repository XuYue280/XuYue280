#include "Poly.h"

Poly::Poly()
{
	//dummy head
	head=new PolyNode(-1,0.0,NULL);
	// TODO	
}

Poly::Poly(const std::vector<int>& deg, const std::vector<double>& coeff)
{
	int size=deg.size();
	if(size==0){
		//dummy head
		head=new PolyNode(-1,0.0,NULL);
	}
	else{
		//dummy head
		head=new PolyNode(-1,0.0,NULL);
		PolyNode* current= head;

		for(int j=0;j<size;j++){
			PolyNode* p = new PolyNode(deg[j],coeff[j],NULL);
			current->next = p;
			//move to next index
			current=current->next;
		}
	}

	// TODO	
}

Poly::~Poly()
{
	while(head->next != NULL){
		PolyNode* temp=head->next;
		head->next=temp->next;
		delete temp;
	}
	//delete dummy header
	delete head;
	// TODO
}
//run time worst case: n (add at last position)
void Poly::addMono(int i, double c)
{
	//c==0 is meaningless
	if(c!=0){
	//just dummy header, empty linked list
		if(head->next == NULL){
			//add new node after dummy header
			head->next = new PolyNode(i,c,NULL);
		}
		//if there are nodes exist, insert new node
		else{
			PolyNode* current = head;
			//find correct position to insert
			while((current->next != NULL) && (i < current->next->deg) ){
				current = current->next;
			}

			//add after last term
			if(current->next == NULL){
				//if degree is same, edit it
				if(current->deg==i){
					current->coeff += c;
					//if degree after editing become 0, delete this term
					if(current->coeff==0)
						delete current;
				}
				//if degree is diff, create new node at the end
				else{
					current->next = new PolyNode(i,c,NULL);
				}
			}


			//add in the middle term - same degree - edit
			else if(current->next->deg==i){
				current->next->coeff += c;
				//if coeff == 0 after editing, delete this term
				if(current->next->coeff == 0){
					//if current->next term is the last term
					if(current->next == NULL){
						delete current->next;
					}
					//if current->next term is in the middle
					else{
						PolyNode* delete_node=current->next;
						current->next=current->next->next;
						delete delete_node;
					}
				}
			}


			//add in the middle term - not same degree - create node
			else{
				PolyNode* insert_node = new PolyNode(i,c,current->next);
				current->next=insert_node;
			}
		}
	}
	// TODO
}

//run time worst case: m*n
void Poly::addPoly(const Poly& p)
{
	//create a node from Poly p dummy header
	PolyNode* p_current=p.head;
	//if p is NOT a empty list
	while(p_current->next != NULL){
		//add each term once a time
		this->addMono(p_current->next->deg, p_current->next->coeff);
		//then move to next term in p
		p_current=p_current->next;
	}
	//if Poly p is empty(just have dummy header) then do nothing
	// TODO
}

void Poly::multiplyMono(int i, double c)
{
	if(c==0){
		//if c ==0 call destructor,
		this->~Poly();
		//Notes: since destructor delete the dummy header, need to create a new dummy header
		this->head=new PolyNode(-1,0.0,NULL);
	}
	else{
		//if THIS poly is not an empty list
		if(this->head->next != NULL){
			PolyNode* current=this->head->next;
			while(current !=NULL){
				current->deg += i;
				current->coeff *= c;
				current=current->next;
			}
		}
		//if THIS poly is empty (just have dummy header), do nothing
	}

	// TODO
}

//space complexity = Big Theta (n*m)
//time complexity = Big Theta (n*m)

void Poly::multiplyPoly(const Poly& p)
{
	//create an empty vector to store the multiplication result
	std::vector<PolyNode*> result_term ;

	//if p is not an empty poly
	if(p.head->next != NULL){
		PolyNode* this_current = this->head->next;
		PolyNode* p_current = p.head->next;
		//worst case: n^2, n=m
		while(p_current != NULL){
			while(this_current != NULL){
				//store the result into result term
				result_term.push_back(new PolyNode(p_current->deg+this_current->deg, p_current->coeff*this_current->coeff,NULL));
				this_current = this_current->next;
			}
			//res
			this_current=this->head->next;
			p_current=p_current->next;
		}
		//destructe this Poly
		this->~Poly();
		//recreate a dummy header
		tet the position for this_currenthis->head = new PolyNode(-1,0.0,NULL);
		//add each node as Mono Poly
		int size=result_term.size();
		//worst case: n^2, n=m, n(1+n)/2
		for(int i=0;i<size;i++){
			this->addMono(result_term[i]->deg,result_term[i]->coeff);
		}
	}
	//if Poly p is empty, clean THIS, recreate dummy header
	else{
		this->~Poly();
		this->head = new PolyNode(-1,0.0,NULL);
	}
	// TODO
}

void Poly::duplicate(Poly& outputPoly)
{
	//clear outputPoly
	outputPoly.~Poly();
	//recreate a dummy header
	outputPoly.head= new PolyNode(-1,0.0,NULL);

	PolyNode* output_current= outputPoly.head;
	PolyNode* this_current=this->head->next;

	while(this_current != NULL){
		//create new node in outputPoly by passing this_current information
		output_current->next = new PolyNode(this_current->deg,this_current->coeff,NULL);
		//both move to next term
		this_current=this_current->next;
		output_current=output_current->next;
	}
	// TODO
}

int Poly::getDegree()
{
	if(head->next==NULL){
		//dummy header degree is -1
		return -1;
	}
	else{
		return head->next->deg;
	}

	// TODO
//change this after completing this function
}

int Poly::getTermsNo()
{
	int i=0;
	//move to next node until it reach NULL, dummy header do NOT count
	while(head->next != NULL){
		head=head->next;
		i++;
	}
	// TODO
	return i;
}

double Poly::evaluate(double x)
{
	double result=0.0, exponent=1.0;
	PolyNode* current=this->head->next;
	if(current == NULL){
		return 0.0;
	}
	else{
		while(current!=NULL){
			if(current->deg == 0)
				result += current->coeff;
			else{
				//x ^ current->deg
				for(int i=0;i<current->deg;i++)
					exponent *= x;
				//value for each term
				result += current->coeff * exponent;
				//reset exponent
				exponent = 1;
			}
			current=current->next;
		}
	}
	// TODO
	return result;//change this after completing this function
}

std::string Poly::toString()
{
	PolyNode* current=head;
	std::string output="degree=";
	output+= std::to_string(head->next->deg);
	output+="; ";
	while(current != NULL){
		output += "a(";
		output += std::to_string(current->deg);
		output += ")=";
		output += std::to_string(current->coeff);
		output += "; ";
		current=current->next;
	}
	// TODO
	return output;//change this after completing this function
}
