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

#define PB push_back
#define LB lower_bound
#define UB upper_bound
#define MP make_pair
#define FRI(i, a, b) for(int i=a; i<b; i++)
#define FRD(i, a, b) for(int i=a; i>=b; i--)
#define MSET(a, b) memset(a, b, sizeof(a))
#define MCPY(a, b) memcpy(a, b, sizeof(a))
#define SORTV(a) sort(a.begin(), a.end())
#define SQR(x) ((x) * (x))
#define SZ(x) ((ll)x.size())

#define RI(x) cin >> x
#define RII(x, y) cin >> x >> y
#define RIII(x, y, z) cin >> x >> y >> z
#define DRI(x) int x; cin >> x
#define DRII(x, y) int x, y; cin >> x >> y
#define DRIII(x, y, z) int x, y, z; cin >> x >> y >> z

#define DRL(x) ll x; cin >> x
#define DRLL(x, y) ll x, y; cin >> x >> y
#define DRLLL(x, y, z) ll x, y, z; cin >> x >> y >> z

#define trace1(x)							cerr << #x << ": " << x << endl;
#define trace2(x, y)						cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z)						cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define trace4(a, b, c, d)       			cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;
#define trace5(a, b, c, d, e)    			cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << endl;
#define trace6(a, b, c, d, e, f) 			cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << " | " << #f << ": " << f << endl;

const ll mod=1000000007;

class node{
	public :
	int val;
	node *next;
};

class mylist{
	public :
	node* head;
	
	mylist(){
		head = NULL;
	}
	
	void insert_begin(int value){
		node *naya = new node();
		naya->val = value;
		naya->next = head;
		head = naya;
	}
	
	void insert_end(int value){
		node* naya = new node();
		node *it = new node();
		it = head;
		naya->val = value;
		naya->next = NULL;
		while(it->next!=NULL){
			it = it->next;
		}
		it->next = naya;
	}
	
	void insert_pos(int pos, int value){
		int it_pos = 0;
		pos--;
		node* it = new node();
		it = head;
		node *naya = new node();
		naya->val = value;
		naya->next = NULL;
		while(it_pos!=pos){
			it = it->next;
			it_pos++;
		}
		node *temp = new node();
		temp = it->next;
		it->next = naya;
		naya->next = temp;
	}
	
	void delete_pos(int pos){
		int it_pos = 0;
		pos--;
		node* it = new node();
		it = head;
		while(it_pos!=pos){
			it = it->next;
			it_pos++;
		}
		it->next = it->next->next;
	}
	
	void delete_begin(){
		head = head->next;
	}
	
	void print(){
		node *it = new node();
		it = head;
		while(it->next!=NULL){
			cout << it->val << endl;
			it = it->next;
		}
		cout << it->val << endl;
	}
};

int main(){
	ios::sync_with_stdio(0);
	mylist l;
	l.insert_begin(3);
	l.insert_begin(5);	
	l.insert_begin(5);
	l.insert_end(9);
	l.insert_pos(2, 8);
	l.delete_pos(2);
	l.delete_begin();
	l.print();
}
