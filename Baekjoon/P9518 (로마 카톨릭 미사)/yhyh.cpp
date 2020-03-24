//코딩 처음할때 못풀었던 문제 ㅋㅋㅋ
//생각보다 간단한 문제
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int R, S;
char board[51][51];

int dx[8] = { -1,-1,-1,0,0,1,1,1 };
int dy[8] = { -1,0,1,-1,1,-1,0,1 };
int maxV = 0;
int maxI[2];
int main()
{
	scanf("%d %d", &R, &S);
	for(int i=0;i<R;i++)
	{
		for (int j = 0; j < S; j++)scanf(" %c", &board[i][j]);
	}

	for(int i=0;i<R;i++)
	{
		for(int j=0;j<S;j++)
		{
			int cnt = 0;
			if(board[i][j]=='.')
			{
				for(int d=0;d<8;d++)
				{
					int ni = i + dx[d];
					int nj = j + dy[d];
					if (ni < 0 || ni >= R || nj < 0 || nj >= S)continue;
					if (board[ni][nj] == 'o') cnt++;
				}
			}
			if(maxV<cnt)
			{
				maxV = cnt;
				maxI[0] = i;
				maxI[1] = j;
			}
		}
	}
	board[maxI[0]][maxI[1]] = 'o'; //악수 제일 많이 할수 있는 곳에 상근이 배치
	
	int result = 0;
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < S; j++)
		{
			if (board[i][j] == 'o')
			{
				for (int d = 0; d < 8; d++)
				{
					int ni = i + dx[d];
					int nj = j + dy[d];
					if (ni < 0 || ni >= R || nj < 0 || nj >= S)continue;
					if (board[ni][nj] == 'o') result++;
				}
			}
		}
	}
	printf("%d\n", result / 2);
}
