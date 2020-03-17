//이걸 이렇게도 짤수 있다니 싱긔방긔
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define ABS(X) (((X) > 0) ? (X) : (X) * -1) //define으로 설정할때는 항상 조심 ㅠ 이것때문에 계속 틀렸다
#define CALDIST(x, y, xx, yy)(ABS(x-xx)+ABS(y-yy))
#define MAX_SIZE 12
#define INF 987654321
#define MIN(a,b)(a<b?a:b)

int T, N;
int adj[MAX_SIZE][MAX_SIZE];
int vertex[MAX_SIZE][2];
int dp[MAX_SIZE][1<<MAX_SIZE];//현재 노드, 방문상태 (max가 총 12개라 비트마스킹이 가능한건가?)

int Solve(int cur,int v) //v : 방문 상태
{
	if (dp[cur][v] != -1)return dp[cur][v];
	dp[cur][v] = INF;
	if (v == (1 << (N + 1)) - 1)
	{
		dp[cur][v] = adj[cur][N + 1];
		return dp[cur][v];
	}

	for(int i=1;i<=N;i++)
	{
		if (v & (1 << i))continue; //이미 방문했다면
		Solve(i, v | (1 << i));
		dp[cur][v] = MIN(dp[cur][v], dp[i][v|(1<<i)]+ adj[cur][i]);
	}
	return dp[cur][v];
}

int main()
{
	scanf("%d", &T);
	for(int tc=1;tc<=T;tc++)
	{
		memset(dp, -1, sizeof(dp));
		scanf("%d", &N);
		scanf("%d %d", &vertex[0][0], &vertex[0][1]);
		scanf("%d %d", &vertex[N+1][0], &vertex[N+1][1]);
		for(int i=1;i<=N;i++)
		{
			scanf("%d %d", &vertex[i][0], &vertex[i][1]);
		}
		
		for(int i=0;i<N+1;i++)
		{
			for(int j=i+1;j<=N+1;j++)
			{
				adj[i][j] = CALDIST(vertex[i][0], vertex[i][1], vertex[j][0], vertex[j][1]);
				adj[j][i] = adj[i][j];

			}
		}
		
		printf("#%d %d\n", tc, Solve(0,1));
	}
}
