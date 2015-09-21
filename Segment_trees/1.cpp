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

#define RANGE_SUM 0
#define RANGE_MIN 1
#define RANGE_MAX 2

vi segment_tree;

void init_segment_tree(int n){
	int length=(int)(2*pow(2.0, floor((log((double)n)/log(2.0))+1)));
	segment_tree.resize(length, 0);
}

void build_segment_tree(int code, int A[], int node, int b, int e){
	if(b==e){
		if(code==RANGE_SUM){segment_tree[node]=A[b];}
		else{segment_tree[node]=b;}
	}
	else{
		int leftIdx=2*node, rightIdx=2*node+1;
		build_segment_tree(code, A, leftIdx, b, (b+e)/2);
		build_segment_tree(code, A, rightIdx, ((b+e)/2)+1, e);
		int lContent=segment_tree[leftIdx], rContent=segment_tree[rightIdx];
		if(code==RANGE_SUM){
			segment_tree[node]=lContent+rContent;
		}
		else{
			int lValue=A[lContent], rValue=A[rContent];
			if(code==RANGE_MIN){
				segment_tree[node]=(lValue<=rValue)?lContent:rContent;
			}
			else{
				segment_tree[node]=(lValue>=rValue)?lContent:rContent;
			}
		}
	}
}

int query(int code, int A[], int node, int b, int e, int i, int j){
	if(i>e || j<b){
		return -1;
	}
	if(b>=i && e<=j){
		return segment_tree[node];
	}
	int p1=query(code, A, 2*node, b, (b+e)/2, i, j);
	int p2=query(code, A, 2*node+1, ((b+e)/2)+1, e, i, j);
	if(p1==-1){return p2;}
	if(p2==-1){return p1;}
	if(code==RANGE_SUM){
		return p1+p2;
	}
	else if(code==RANGE_MIN){
		return (A[p1]<=A[p2])?p1:p2;
	}
	else{
		return (A[p1]>=A[p2])?p1:p2;
	}
}

int main(){
	int A[]={8, 7, 3, 9, 5, 1, 10};
	init_segment_tree(7);
	build_segment_tree(RANGE_MIN, A, 1, 0, 6);
	cout << query(RANGE_MIN, A, 1, 0, 6, 1, 3) << endl;
}
