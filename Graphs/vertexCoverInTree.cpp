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

vi adj[100001];
bool visited[100001];
int dp[100001][2];

void dfs(int i){
	visited[i]=true;
	int a, b;
	a=b=0;
	for(int j=0; j<sz(adj[i]); j++){
		if(!visited[adj[i][j]]){
			dfs(adj[i][j]);
			a+=dp[adj[i][j]][0];
			b+=max(dp[adj[i][j]][0], dp[adj[i][j]][1]);
		}
	}
	dp[i][0]=b;
	dp[i][1]=1+a;
}

int main(){
	int t, n, e, a, b;
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &e);
		fr(i, 0, n){
			adj[i].clear();
			visited[i]=false;
		}
		fr(i, 0, e){
			scanf("%d%d", &a, &b);
			adj[a].pb(b);
			adj[b].pb(a);
		}
		a=0;
		mset(dp, 0);
		dfs(0);
		printf("%d\n", n-max(dp[0][0], dp[0][1]));
	}
}
