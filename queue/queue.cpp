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
		val=0;
		next=NULL;
	}
};

class myqueue{
	public :
	node *head;
	node *tail;
	int elements;
	
	myqueue(){
		head=NULL;
		tail=NULL;
		elements=0;
	}
	
	bool empty(){
		if(elements==0){
			return true;
		}
		return false;
	}
	
	int size(){
		return elements;
	}
	
	int front(){
		return head->val;
	}
	
	int back(){
		return tail->val;
	}
	
	void push(int value){
		if(elements==0){
			head=new node();
			tail=new node();
			head->val=value;
			tail->val=value;
			head->next=NULL;
			tail->next=NULL;
		}
		else if(elements==1){
			node *p;
			p=new node();
			p->val=value;
			p->next=NULL;
			tail->next=p;
			tail=p;
			head->next=tail;
		}
		else{
			node *p;
			p=new node();
			p->val=value;
			p->next=NULL;
			tail->next=p;
			tail=p;
		}
		elements++;
	}
	
	void pop(){
		node *p;
		p=head;
		p=p->next;
		head=p;
		elements--;
	}
	
	void display(){
		node *p;
		p=head;
		while(p!=NULL){
			cout << p->val << endl;
			p=p->next;
		}
	}
	
};

int main(){
	myqueue q;
	q.push(3);
	q.push(5);
	q.push(1);
	cout << q.front() << " " << q.back() << endl;
	q.pop();
	q.display();
}
