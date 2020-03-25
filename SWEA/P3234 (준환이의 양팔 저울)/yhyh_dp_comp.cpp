//시간과 메모리를 줄여보았습니다.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int T, N;
int total_v;
int arr[10];
//단순히 visited로만 처리하면 왼쪽 저울에 놓았을 경우와 오른쪽 저울에 놓았을 경우를 처리해주지 못함
//그래서....왼쪽에 놓았을 경우에는 1<<(i+10) 으로 처리함 (어차피 N < 10) ---> i+N으로 변경
//오른쪽 : 0~8, 왼쪽 0+N ~ 8+N (최대......16..?)
int dp[10][1<<17]; //적당히 처리하니까 시간과 메모리가 절약됨

int Solve(int cnt,int state,int left, int right)
{
	if (left < right)return 0;
	if (cnt == N)
	{
		return 1;
	}
	if (dp[cnt][state] != -1)return dp[cnt][state];

	dp[cnt][state] = 0;
	for (int i = 0; i < N; i++)
	{
		if (state&(1<<i)||state&(1<<(i+N)))continue; 
		dp[cnt][state] += Solve(cnt + 1, (state| (1<<(i+N))),left + arr[i], right); //왼쪽에다가 달아보자!
		if (right + arr[i] <= left) //왼쪽보다 크지 않을때만
		{
			dp[cnt][state] += Solve(cnt + 1, (state| (1<<i)),left, right + arr[i]); //오른쪽
		}
	}
	return dp[cnt][state];
}

int main()
{
	scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++)
	{
		scanf("%d", &N);
		total_v = 0;
		memset(dp, -1, sizeof(dp));
		for (int i = 0; i < N; i++)
		{
			scanf("%d", &arr[i]);
		}

		total_v = Solve(0, 0, 0, 0);
		printf("#%d %d\n", tc, total_v);
	}
}
