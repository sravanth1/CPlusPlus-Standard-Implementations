#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
	int n, p, i, j, k, output, count=0;
	cin >> n >> p;
	int overlap[p+1], v;
	char given[n+1], match[p+1], current;
	overlap[1]=0;
	for(i=1; i<=n; i++){
		cin >> given[i];
	}
	for(i=1; i<=p; i++){
		cin >> match[i];
	}
	for(i=1; i<p; i++){
		current=match[i+1];
		v=overlap[i];
		while(match[v+1]!=current && v!=0){
			v=overlap[v];
		}
		if(match[v+1]==current){
			overlap[i+1]=v+1;
		}
		else{
			overlap[i+1]=0;
		}
	}
	i=1; j=1; k=1;
	while(n-k>=p){
		while(j<=p && given[i]==match[j]){
			i++;
			j++;
		}
		if(j>p){
			output=k;
			count++;
		}
		if(overlap[j]>0){
			k=i-overlap[j-1];
		}
		else{
			if(i==k){i++;}
			k=i;
		}
		if(j>1){
			j=overlap[j-1]+1;
		}
	}
	cout << count << endl;
}
