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

struct node{
	int i, j;
};

int n;
int q[100003];
node tree[2000006];

node makeNode(int i, int j){
	node tmp;
	tmp.i=i;
	tmp.j=j;
	return tmp;
}

node combine(node l, node r){
	int i, j;
	if(q[l.i]>q[l.j]){i=l.i;}
	else{i=l.j;}
	if(q[r.i]>q[r.j]){j=r.i;}
	else{j=r.j;}
	if(q[l.i]+q[l.j]>q[i]+q[j] && l.i!=l.j){
		i=l.i; j=l.j;
	}
	if(q[r.i]+q[r.j]>q[i]+q[j] && r.i!=r.j){
		i=r.i; j=r.j;
	}
	return makeNode(i, j);
}

node build(int from, int to, int index){
	if(from==to){
		tree[index]=makeNode(from, from);
		return tree[index];
	}
	int mid=(from+to)/2;
	node l=build(from, mid, 2*index);
	node r=build(mid+1, to, 2*index+1);
	tree[index]=combine(l, r);
	return tree[index];
}

node ans(int index, int from, int to, int a, int b){
	if(from==a && to==b){
		return tree[index];
	}
	int mid=(from+to)/2;
	if(a>mid){
		return ans(2*index+1, mid+1, to, a, b);
	}
	else if(b<=mid){
		return ans(2*index, from, mid, a, b);
	}
	node l=ans(2*index, from, mid, a, mid);
	node r=ans(2*index+1, mid+1, to, mid+1, b);
	return combine(l, r);
}

void update(int index, int pos, int val, int a, int b){
	if(a==b && a==pos){
		tree[index]=makeNode(pos, pos);
		return;
	}
	int mid=(a+b)/2;
	if(pos<=mid){
		update(index*2, pos, val, a, mid);
	}
	else if(pos>mid){
		update(2*index+1, pos, val, mid+1, b);
	}
	node left=tree[index*2];
	node right=tree[index*2+1];
	tree[index]=combine(left, right);
}

int main(){
	scanf("%d", &n);
	for(int i=1; i<n+1; i++){
		scanf("%d", &q[i]);
	}
	build(1, n, 1);
	int t;
	scanf("%d", &t);
	int a, b;
	char dir;
	string s;
	for(int i=0; i<t; i++){
		getline(cin, s);
		scanf("%c", &dir);
		scanf("%d%d", &a, &b);
		if(dir=='Q'){
			node temp=ans(1, 1, n, a, b);
			printf("%d\n", q[temp.i]+q[temp.j]);
		}
		else if(dir=='U'){
			q[a]=b;
			update(1, a, b, 1, n);
		}
	}
}
