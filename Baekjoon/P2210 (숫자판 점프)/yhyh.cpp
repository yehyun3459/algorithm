//ㅎㅎ 어려운 문제는 아닌데 그냥 기록을 남기고 싶다....
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

bool chk[1000001];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int result = 0;
int board[5][5];

void DFS(int r, int c, int cnt,int num)
{
	if(cnt>=5)
	{
		if (!chk[num])
		{
			chk[num] = 1;
			result++;
		}
		return;
	}
	for(int d=0;d<4;d++)
	{
		int nr = r + dx[d];
		int nc = c + dy[d];
		if (nr < 0 || nr >= 5 || nc < 0 || nc >= 5)continue;
		DFS(nr, nc, cnt + 1, num * 10 + board[nr][nc]);
	}
}
int main()
{
	for(int i=0;i<5;i++)
	{
		for (int j = 0; j < 5; j++)
		{
			scanf("%d", &board[i][j]);
		}
	}
	memset(chk, 0, sizeof(chk));
	for(int i=0;i<5;i++)
	{
		for(int j=0;j<5;j++)
		{
			DFS(i, j, 0,board[i][j]);
		}
	}
	printf("%d\n", result);
}
