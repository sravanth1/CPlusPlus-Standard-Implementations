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

void move(int pos, int size, int A[]){
	FRD(i, size-1, pos+1){
		A[i]=A[i-1];
	}
}

int main(){
	ios::sync_with_stdio(0);
	int A[] = {3, 8, 7, 1, 5, 2};
	int B[] = {INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX};
	FRI(i, 0, 6){
		bool done = 0;
		if(A[i]<=B[0]){
			move(0, 6, B);
			B[0] = A[i];
			done = 1;
		}
		FRI(j, 0, 5){
			if(done){break;}
			if(B[j]<=A[i] && A[i]<=B[j+1]){
				move(j+1, 6, B);
				B[j+1] = A[i];
				done = 1;
			}
		}
		if(!done){B[5]=A[i];}
	}
	FRI(i, 0, 6){
		cout << B[i] << " ";
	}
	cout << endl;
}
