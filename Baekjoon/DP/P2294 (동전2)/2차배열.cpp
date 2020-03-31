#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define MIN(a,b)(a<b?a:b)
#define INF 987654321
int d[101]; //동전
int cost[101][10001]; //아 헷갈려..

int main()
{
	int N, K;
	scanf("%d %d", &N, &K);
	
	memset(cost, 0, sizeof(cost));
	
	for (int i = 1; i <= N; i++)
	{
		scanf("%d", &d[i]);
	}
	for (int i = 1; i <= K; i++)cost[0][i] = INF;

	for(int i=1;i<=N;i++) //생각하기 귀찮으니까 감싸주자
	{
		for(int j=1;j<=K;j++)
		{
			if (j < d[i]) cost[i][j] = cost[i - 1][j]; //현재 동전이 j값보다 크다면 이전 값(개수)을 그대로 가져감
			else cost[i][j] = MIN(cost[i - 1][j], cost[i][j - d[i]] + 1);
		}
	}
	printf("%d\n", cost[N][K]==INF?-1:cost[N][K]);
}
