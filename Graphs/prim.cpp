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

struct node{
	int v, d;
	node(int a, int b){
		v=a; d=b;
	}
};

vector<node> adj[1001];
set<pair<int, int> > q;
int ans, n, m;
int key[1001];

void prim(){
	si done; key[0]=0;
	int u, v, dist, length;
	ans=0; j=0;
	while(!q.empty() && j<n){
		u=q.begin()->second;
		done.insert(u);
		dist=q.begin()->first;
		ans+=dist;
		q.erase(q.begin());
		fr(i, 0, sz(adj[u])){
			v=adj[u][i].v;
			length=adj[u][i].d;
			if(!done.count(v) && length<key[v]){
				q.erase(mp(key[v], v));
				key[v]=length;
				q.insert(mp(key[v], v));
			}
		}
		j++;
	}
}

int main(){
	int p, t, a, b, c;
	scanf("%d", &t);
	while(t--){
		q.clear();
		scanf("%d%d%d", &p, &n, &m);
		fr(i, 0, n){
			adj[i].clear();
			key[i]=INT_MAX;
		}
		fr(i, 0, m){
			scanf("%d%d%d", &a, &b, &c);
			a--; b--;
			adj[a].pb(node(b, c));
			adj[b].pb(node(a, c));
		}
		q.insert(mp(0, 0));
		fr(i, 1, n){q.insert(mp(INT_MAX, i));}
		prim();
		printf("%d\n", ans*p);
	}
}
