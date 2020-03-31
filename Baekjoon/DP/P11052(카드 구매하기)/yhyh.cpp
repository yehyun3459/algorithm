//동전문제랑 유형이 똑같당..
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define MAX(a,b)(a>b?a:b)
int P[1001];
int dp[10001];

int main()
{
	int N;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)scanf("%d", &P[i]);
	memset(dp, 0, sizeof(dp));

	for(int i=1;i<=N;i++)
	{
		for(int j=i;j<=N;j++)
		{
			dp[j] = MAX(dp[j], dp[j - i] + P[i]);
		}
	}
	printf("%d\n", dp[N]);
}
