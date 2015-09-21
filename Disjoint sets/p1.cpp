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

int rank[1000], parent[1000];

void createset(){
	FRI(i, 0, 1000){
		rank[i]=0;
		parent[i]=i;
	}
}

int find(int x){
	if(parent[x]!=parent[parent[x]]){
		parent[x]=parent[parent[x]];
	}
	return parent[x];
}

bool unioned(int x, int y){
	int xx=find(x);
	int yy=find(y);
	if(xx==yy){
		return false;
	}
	if(rank[xx]>rank[yy]){
		swap(xx, yy);
	}
	if(rank[xx]!=rank[yy]){
		rank[yy]++;
	}
	parent[xx]=yy;
	return true;
} 

int main(){
	ios::sync_with_stdio(0);
}
