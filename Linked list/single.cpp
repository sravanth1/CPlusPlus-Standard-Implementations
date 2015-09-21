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
};

class mylist{
	public :
	node* head;
	
	mylist(){
		head=NULL;
	}
	
	node* create_node(int value){
		node *temp;
		temp=new node();
		temp->val=value;
		temp->next=NULL;
		return temp;
	}
	
	void insert_begin(int value){
		node *temp, *p;
		temp=create_node(value);
		if(head==NULL){
			head=temp;
			head->next=NULL;
		}
		else{
			p=head;
			head=temp;
			head->next=p;
		}
	}
	
	void insert_end(int value){
		node *temp, *p;
		temp=create_node(value);
		p=head;
		while(p->next != NULL){
			p=p->next;
		}
		p->next=temp;
		temp->next=NULL;
	}
	
	void insert_pos(int value, int index){
		node *temp, *p, *q;
		temp=create_node(value);
		i=1;
		p=head;
		while(i!=index){
			p=p->next;
			i++;
		}
		q=p->next;
		p->next=temp;
		temp->next=q;
	}
	
	void delete_pos(int index){
		i=1;
		node *p, *q;
		p=head;
		while(i!=index){
			p=p->next;
			i++;
		}
		q=p->next;
		p->next=q->next;
	}
	
	void update(int index, int value){
		i=0;
		node *p, *q;
		p=head;
		while(i!=index){
			p=p->next;
			i++;
		}
		p->val=value;
	}
	
	void reverse(){
		node *p, *q, *r;
		p=head;
		q=p->next;
		r=q->next;
		p->next=NULL;
		q->next=p;
		while(r!=NULL){
			p=q;
			q=r;
			r=r->next;
			q->next=p;
		}
		head=q;
	}
	
	void display(){
		node *p;
		p=head;
		if(head!=NULL){
			cout << p->val << endl;
		}
		while(p->next!=NULL){
			p=p->next;
			cout << p->val << endl;
		}
	}
	
};

int main(){
	mylist l;
	l.insert_begin(2);
	l.insert_end(5);
	l.insert_pos(3, 1);
	l.delete_pos(1);
	l.insert_begin(2);
	l.update(1, 3);
	l.reverse();
	l.display();
}
