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

class myvector{
	public :
	int cap, sze;
	int *data;
	
	myvector(){
		cap=0;
		sze=0;
		data=new int[1];
	}
	
	int capacity(){
		return cap+1;
	}
	
	int size(){
		return sze+1;
	}
	
	void push_back(int value){
		if(cap<sze){
			int *p=new int[cap+10];
			fr(i, 0, sze){
				p[i]=data[i];
			}
			p[sze]=value;
			sze++;
			cap+=10;
			data=p;
		}
		else{
			data[sze]=value;
			sze++;
		}
	}
	
	void modify(int index, int value){
		data[index]=value;
	}
	
	int operator [] (int index){
		return data[index];
	}
	
	void erase(int index){
		int *p=new int[cap];
		fr(i, 0, index){
			p[i]=data[i];
		}
		fr(i, index+1, sze){
			p[i-1]=data[i];
		}
		data=p;
		sze--;
	}
	
	void display(){
		fr(i, 0, sze){
			cout << data[i] << endl;
		}
	}
	
};

int main(){
	myvector v;
	v.pb(3);
	v.pb(5);
	v.pb(1);
	v.pb(10);
	v.erase(0);
	v.display();
}
