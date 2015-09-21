#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
typedef vector<ll> vl;
typedef queue<ll> ql;
typedef set<ll> sl;
typedef vector<int> vi;
typedef queue<int> qi;
typedef set<int> si;

#define pb push_back
#define fr(i, a, b) for(i=a; i<b; i++)
#define mset(a, b) memset(a, b, sizeof(a))
#define mcpy(a, b) memcpy(a, b, sizeof(a))
#define sortv(a) sort(a.begin(), a.end())
#define max(x, y) ((x) > (y) ? (x) : (y))
#define min(x, y) ((x) < (y) ? (x) : (y))
#define sqr(x) ((x) * (x))
#define sz(x) ((ll)x.size())

#define trace1(x)							cerr << #x << ": " << x << endl;
#define trace2(x, y)						cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z)						cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define trace4(a, b, c, d)       			cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;
#define trace5(a, b, c, d, e)    			cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << endl;
#define trace6(a, b, c, d, e, f) 			cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << " | " << #f << ": " << f << endl;

int i=0, j=0;

class node{
	public :
	int val;
	node *next;
	
	node(){
		next=NULL;
	}
};

class mystack{
	public :
	node *root;
	int elements;
	
	mystack(){
		root=NULL;
		elements=0;
	}
	
	bool empty(){
		if(root==NULL){
			return true;
		}
		return false;
	}
	
	int size(){
		return elements;
	}
	
	void push(int value){
		if(empty()){
			root=new node();
			root->val=value;
			root->next=NULL;
			elements++;
		}
		else{
			node *p=new node();
			*p=*root;
			root->next=p;
			root->val=value;
			elements++;
		}
	}
	
	void pop(){
		if(elements==1){
			root=NULL;
			elements=0;
		}
		if(elements>1){
			node *p=new node();
			p=root;
			root=p->next;
			elements--;
		}
	}
	
	int top(){
		return root->val;
	}
	
	void print(){
		node *p=new node;
		p=root;
		fr(i, 0, elements){
			cout << p->val << endl;
			p=p->next;
		}
	}
	
};

int main(){
	mystack s;
	s.push(3);
	s.push(8);
	cout << s.top() << endl;
	s.push(2);
	s.push(9);
	s.pop();
	s.print();
}
