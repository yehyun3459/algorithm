#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int M, N;
int board[500][500];
int dp[500][500];

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int Solve(int r, int c)
{
	if (dp[r][c] != -1)return dp[r][c];
	if (r == 0 && c == 0)return 1;

	dp[r][c] = 0;
	for(int d=0;d<4;d++)
	{
		int nr = r + dx[d];
		int nc = c + dy[d];
		if (nr < 0 || nr >= M || nc < 0 || nc >= N)continue;
		if(board[nr][nc]>board[r][c])
		{
			int tmp = Solve(nr, nc);
			dp[r][c] += tmp;
		}
	}
	return dp[r][c];
}
int main()
{
	scanf("%d %d", &M, &N);
	for(int i=0;i<M;i++)
	{
		for(int j=0;j<N;j++)
		{
			scanf("%d", &board[i][j]);
		}
	}
	memset(dp, -1, sizeof(dp));
	printf("%d\n",Solve(M-1, N-1));
}
