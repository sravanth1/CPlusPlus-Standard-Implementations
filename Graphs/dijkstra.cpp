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
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
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

int i=0, j=0, k=0, n, s, m;

struct node{
	int vertex, dist;
	node(){vertex=dist=0;}
	node(int a, int b){
		vertex=a;
		dist=b;
	}
};

vector<node> adj[101];

int main(){
	int t, a, b, c, v, length;
	scanf("%d%d%d%d", &n, &s, &t, &m);
	fr(i, 0, m){
		scanf("%d%d%d", &a, &b, &c);
		a--; b--;
		adj[b].pb(node(a, c));
	}
	vi min_dist, prev;
	s--;
	min_dist.resize(n, INT_MAX);
	min_dist[s]=0;
	prev.resize(n, -1);
	set<pair<int, int> > q;
	q.insert(mp(0, s));
	while(!q.empty()){
		a=q.begin()->first;
		b=q.begin()->second;
		q.erase(q.begin());
		fr(i, 0, sz(adj[b])){
			v=adj[b][i].vertex;
			length=adj[b][i].dist;
			if(a+length<min_dist[v]){
				q.erase(mp(min_dist[v], v));
				min_dist[v]=a+length;
				prev[v]=b;
				q.insert(mp(min_dist[v], v));
			}
		}
	}
	int count=0;
	fr(i, 0, n){
		if(min_dist[i]<=t){
			count++;
		}
	}
	printf("%d\n", count);
}
