#include <cstdio>
#include <algorithm>
using namespace std;
 
int N,M;
double pct[100][100];
 
int main()
{
	int i,j,k,a,b,c;
	scanf("%d", &N);
	while(N != 0)
	{
		scanf("%d", &M);
		for(i = 0; i < N; i++)
			for(j = 0; j < N; j++)
				pct[i][j] = 0.0;
		while(M--)
		{
			scanf("%d %d %d", &a, &b, &c);
			a--;
			b--;
			pct[a][b] = pct[b][a] = c/100.0;
		}
		
		for(k = 0; k < N; k++)
			for(i = 0; i < N; i++)
				for(j = 0; j < N; j++)
					if(i != j && i != k && j != k && pct[i][k]*pct[k][j] > pct[i][j])
						pct[i][j] = pct[i][k] * pct[k][j];
		
		printf("%.6llf percent\n", pct[0][N-1]*100.0);
		scanf("%d", &N);
	}
	return 0;
}
