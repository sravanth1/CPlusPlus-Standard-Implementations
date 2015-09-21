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

struct node{
	long best, left, right, sum;
};

int n;
long q[50003];
node tree[200003];

node makeNode(long sum, long best, long left, long right){
	node tmp;
	tmp.sum=sum;
	tmp.best=best;
	tmp.left=left;
	tmp.right=right;
	return tmp;
}

node combine(node l, node r){
	long left=l.left;
	if(l.sum+r.left>left){
		left=l.sum+r.left;
	}
	long right=r.right;
	if(r.sum+l.right>right){
		right=r.sum+l.right;
	}
	long best=max(l.right+r.left, max(l.best, r.best));
	return makeNode(l.sum+r.sum, best, left, right);
}

node build(int from, int to, int index){
	if(from==to){
		tree[index]=makeNode(q[from], q[from], q[from], q[from]);
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

int main(){
	scanf("%d", &n);
	fr(i, 1, n+1){
		scanf("%ld", &q[i]);
	}
	build(1, n, 1);
	int t;
	scanf("%d", &t);
	int a, b;
	fr(i, 0, t){
		scanf("%d%d", &a, &b);
		printf("%ld\n", ans(1, 1, n, a, b).best);
	}
}
