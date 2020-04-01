#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define MAX_SIZE 33

typedef long long ll;
//가로 -> 가로, 대각선
//대각선 -> 가로, 세로, 대각선
//세로 -> 세로, 대각선

int board[MAX_SIZE][MAX_SIZE]; //가로, 대각선, 세로
ll dp[MAX_SIZE][MAX_SIZE][3];

int main()
{
	int N;
	scanf("%d", &N);
	memset(board, 0, sizeof(board));
	memset(dp, 0, sizeof(dp));
	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=N;j++)
		{
			scanf("%d", &board[i][j]);
		}
	}

	dp[1][2][0] = 1;
	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=N;j++)
		{
			if(!board[i][j]) //벽이 아닐때
			{
				//가로일때
				dp[i][j][0] += (dp[i][j - 1][0] + dp[i][j - 1][1]);
				//세로일때
				dp[i][j][2] += (dp[i - 1][j][1] + dp[i - 1][j][2]);
				//대각선
				if(!board[i-1][j]&&!board[i][j-1])
				{
					dp[i][j][1] += (dp[i - 1][j-1][0]+dp[i-1][j-1][1]+dp[i-1][j-1][2]);

				}
			}
		}
	}
	long long result = dp[N][N][0] + dp[N][N][1] + dp[N][N][2];
	printf("%lld\n", result);
}
