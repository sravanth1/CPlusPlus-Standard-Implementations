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

struct node{
	int min;
};

int n;
int array[10000];
node tree[210000];

node makeNode(int m){
	node tmp;
	tmp.min = m;
	return tmp;
}

node combine(node l, node r){
	return makeNode(min(l.min, r.min));
}

node build(int from, int to, int index){
	if(from==to){
		tree[index] = makeNode(array[from]);
		return tree[index];
	}
	int mid=(from+to)/2;
	node l=build(from, mid, 2*index);
	node r=build(mid+1, to, 2*index+1);
	tree[index] = combine(l, r);
	return tree[index];
}

node ans(int from, int to, int a, int b, int index){
	if(from==a && to==b){
		return tree[index];
	}
	int mid=(from+to)/2;
	if(a>mid){
		return ans(mid+1, to, a, b, 2*index+1);
	}
	else if(b<=mid){
		return ans(from, mid, a, b, 2*index);
	}
	node l=ans(from, mid, a, mid, 2*index);
	node r=ans(mid+1, to, mid+1, b, 2*index+1);
	return combine(l, r);
}

int main(){
	ios::sync_with_stdio(0);
	FRI(i, 0, 10000){
		array[i]=i;
	}
	build(1, 10000, 1);
	cout << ans(1, 10000, 100, 8000, 1).min << endl;
}
