//TC : https://hsin.hr/2009/index.html (plinovod)

//어떻게 풀까 고민했는데 dp로 간단히 풀 수 있다 (이걸 dp라고 할 수 있나?)
//파이프 성공, 실패 여부를 visited에 표시해주면 끝

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

char board[10001][501];
int visited[10001][501];
int R, C;

int ni[3] = { -1,0,1 };

bool Solve(int r,int c)
{
	visited[r][c] = 1;//방문 체크
	if (c == 0)return true;
	for(int d=0;d<3;d++)
	{
		int nr = r + ni[d];
		int nc = c - 1;
		if (nr < 0 || nr >= R)continue;
		if (board[nr][nc] != '.' || visited[nr][nc]!=0)continue;//아예 방문을 하지 않았을 경우에만
		if (Solve(r + ni[d], c - 1))return true;
	}
	visited[r][c] = -1;//현재 인덱스에서는 파이프를 놓을 경우의 수가 존재하지 않음(다시 볼 필요 x)
	return false;
}
int main()
{
	scanf("%d %d", &R, &C);
	for(int i=0;i<R;i++)
	{
		for(int j=0;j<C;j++)
		{
			scanf(" %c", &board[i][j]);
			visited[i][j] = 0;
		}
	}
	int cnt = 0;
	for(int i=0;i<R;i++)
	{
		if(Solve(i, C - 1))cnt++;
	}
	printf("%d\n", cnt);
}
