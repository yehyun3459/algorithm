//자괴감 쩐다...
//아니 걍 이렇게 간단하게 해도 됨 ㅇ<-< 웨 고민한거쥬.....
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

char board[10002][502];
int R, C;

bool Solve(int r,int c)
{
	if (board[r][c] != '.')return false;
	if (c == C)return true;
	board[r][c] = 'v';//visited
	return Solve(r - 1, c + 1) || Solve(r, c + 1) || Solve(r + 1, c + 1);
}
int main()
{
	scanf("%d %d", &R, &C);
	for(int i=1;i<=R;i++)
	{
		for(int j=1;j<=C;j++)
		{
			scanf(" %c", &board[i][j]);
		}
	}
	int cnt = 0;
	for(int i=1;i<=R;i++)
	{
		if(Solve(i, 1))cnt++;
	}
	printf("%d\n", cnt);
}
