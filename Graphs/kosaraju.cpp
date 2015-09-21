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

class Graph{
	public :
	int V, sc;
	list<int> *adj;
	void fillOrder(int v, bool visited[], stack<int> &St);
	void DFSUtil(int v, bool visited[]);
	Graph(int V);
	void addEdge(int v, int w);
	void printSCCs();
	Graph getTranspose();
};

Graph::Graph(int V){
	this->V=V; sc=0;
	adj=new list<int>[V];
}

void Graph::DFSUtil(int v, bool visited[]){
	visited[v]=true;
	list<int>::iterator it;
	for(it=adj[v].begin(); it!=adj[v].end(); ++it){
		if(!visited[*it]){
			DFSUtil(*it, visited);
		}
	}
}

Graph Graph::getTranspose(){
	Graph g(V);
	fr(i, 0, V){
		list<int>::iterator it;
		for(it=adj[i].begin(); it!=adj[i].end(); ++it){
			g.adj[*it].pb(i);
		}
	}
	return g;
}

void Graph::addEdge(int v, int w){
	adj[v].pb(w);
}

void Graph::fillOrder(int v, bool visited[], stack<int> &St){
	visited[v]=true;
	list<int>::iterator it;
	for(it=adj[v].begin(); it!=adj[v].end(); ++it){
		if(!visited[*it]){
			fillOrder(*it, visited, St);
		}
	}
	St.push(v);
}

void Graph::printSCCs(){
	stack<int> Stack;
	bool *visited=new bool[V];
	fr(i, 0, V){
		visited[i]=false;
	}
	fr(i, 0, V){
		if(!visited[i]){
			fillOrder(i, visited, Stack);
		}
	}
	Graph gr=getTranspose();
	fr(i, 0, V){
		visited[i]=false;
	}
	while(!Stack.empty()){
		int v=Stack.top();
		Stack.pop();
		if(!visited[v]){
			gr.DFSUtil(v, visited);
			sc++;
		}
	}
	printf("%d\n", sc);
}

int main(){
	int t, n;
	scanf("%d", &t);
	string s;
	while(t--){
		scanf("%d", &n);
		char k;
		Graph g(n);
		fr(i, 0, n){
			getline(cin, s);
			fr(j, 0, n){
				scanf("%c", &k);
				if(k=='Y'){
					g.addEdge(i, j);
				}
			}
		}
		g.printSCCs();
	}
}
