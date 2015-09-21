#include <iostream>
using namespace std;

class node{
	int val;
	public :
	node* next;
	node(){
		val = 0;
		next = NULL;
	}
	node(int v){
		val = v;
		next = NULL;
	}
	int getVal(){
		return val;
	}
	void setVal(int v){
		val = v;
	}
};

class stack{
	private :

	node* head;
	int height;

	public :

	stack(){
		head = NULL;
		height = 0;
	}

	int size(){
		return height;
	}

	bool empty(){
		return height==0;
	}

	void push(int v){
		node *n = new node();
		n->setVal(v);
		n->next = NULL;
		if(height == 0){
			head = n;
			height++;
		}
		else{
			node* temp = head;
			n->next = temp;
			head = n;
			height++;
		}
	}

	void print(){
		node* temp = new node();
		temp = head;
		for(int i = 0; i < height; i++){
			cout << temp->getVal() << " ";
			temp = temp->next;
		}
		cout << endl;
	}

	int pop(){
		node* temp = new node();
		temp = head;
		head = head->next;
		return temp->getVal();
	}
};

int main(){
	stack s;
	s.push(1);
	s.push(2);
	s.print();
	cout << s.pop() << endl;
	cout << s.pop() << endl;
}
