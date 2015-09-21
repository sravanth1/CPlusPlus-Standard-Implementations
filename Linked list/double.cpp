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
	node *next, *prev;
};

class mylist{
	public :
	node *head;
	
	mylist(){
		head=NULL;
	}
	
	void create_list(int value){
		node *s, *temp;
		temp=new node();
		temp->val=value;
		temp->next=NULL;
		temp->prev=NULL;
		head=temp;
	}
	
	void add_begin(int value){
		node *s;
		s=new node();
		s->val=value;
		s->next=head;
		head->prev=s;
		s->prev=NULL;
		head=s;
	}
	
	void add_after(int value, int index){
		node *p, *q, *r;
		q=new node();
		p=new node();
		q=p; p=head;
		i=1;
		if(index==1){
			add_begin(value);
			return;
		}
		while(i!=index){
			q=p;
			p=p->next;
			i++;
		}
		r=new node();
		r->val=value;
		r->next=p;
		r->next->prev=r;
		q->next=r;
		r->prev=q;
	}
	
	void reverse(){
		node *p, *q;
		p=head;
		q=p->next;
		p->next=NULL;
		p->prev=q;
		while(q!=NULL){
			q->prev=q->next;
			q->next=p;
			p=q; q=q->prev;
		}
		head=p;
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
	mylist l;
	l.create_list(2);
	l.add_begin(5);
	l.add_begin(5);
	l.add_after(3, 2);
	l.reverse();
	l.display();
}
