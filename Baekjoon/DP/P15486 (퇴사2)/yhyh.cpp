#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX(a,b)(a>b?a:b)
#define MAX_SIZE 1500000
int arr[MAX_SIZE + 2][2];
int dp[MAX_SIZE + 2];
int main()
{
	int N;
	scanf("%d", &N);

	for (int i = 1; i <= N; i++)
	{
		scanf("%d %d", &arr[i][0], &arr[i][1]);
		dp[i] = 0;
	}
	int maxV = 0;
	for (int i = 1; i <= N + 1; i++)
	{
		maxV = MAX(maxV, dp[i]); //지금까지의 누적 최댓값
		if (i + arr[i][0] <= N + 1)
		{
			dp[i + arr[i][0]] = MAX(dp[i + arr[i][0]], maxV + arr[i][1]);//선택하지 않은 경우, 선택한 경우
		}

	}
	printf("%d\n", maxV);
}
