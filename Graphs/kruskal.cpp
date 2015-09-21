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
#define lb lower_bound
#define ub upper_bound
#define mp make_pair
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

int i=0, j=0, k=0;

vector<pair<int, pair<int, int> > > graph;
int parent[1001], rank[1001], ans, n, m;

int findset(int x){
	if(x!=parent[x]){
		parent[x]=findset(parent[x]);
	}
	return parent[x];
}

void unionsets(int a, int b){
	int x=findset(a);
	int y=findset(b);
	if(rank[x]>rank[y]){
		swap(x, y);
	}
	if(rank[x]==rank[y]){
		rank[y]++;
	}
	parent[x]=y;
}

void reset(){
	graph.clear();
	ans=0;
	fr(i, 0, n){
		parent[i]=i;
		rank[i]=0;
	}
}

void kruskal(){
	sortv(graph);
	int pu, pv;
	ans=0;
	for(i=0; i<m; i++){
		pu=findset(graph[i].second.first);
		pv=findset(graph[i].second.second);
		if(pu!=pv){
			ans+=graph[i].first;
			unionsets(pu, pv);
		}
	}
}

int main(){
	int p, t, a, b, c;
	scanf("%d", &t);
	while(t--){
		scanf("%d%d%d", &p, &n, &m);
		reset();
		fr(i, 0, m){
			a--; b--;
			scanf("%d%d%d", &a, &b, &c);
			graph.pb(mp(c, mp(a, b)));
		}
		kruskal();
		printf("%d\n", ans*p);
	}
}
