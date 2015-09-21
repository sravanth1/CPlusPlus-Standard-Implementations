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

int uf[1000];
int rank[1000];

void createset(){
	int i=0;
	fr(i, 0, 1000){
		uf[i]=i;
		rank[i]=0;
	}
}

int naivefind(int x){
	if(uf[x]==x){return x;}
	return naivefind(uf[x]);
}

void naiveunion(int a, int b){
	uf[naivefind[x]]=naivefind[y];
}

int optimisedfind(int x){
	if(uf[x]!=uf[uf[x]]){
		uf[x]=optimisedfind(uf[x]);
	}
	return uf[x];
}

bool optimisedunion(int a, int b){
	int xx=optimisedfind(a);
	int yy=optimisedfind(b);
	if(xx==yy){
		return false;
	}
	if(rank[xx]>rank[yy]){
		swap(xx, yy);
	}
	if(rank[xx]==rank[yy]){
		rank[yy]++;
	}
	uf[xx]=yy;
}

int main(){
	
}
