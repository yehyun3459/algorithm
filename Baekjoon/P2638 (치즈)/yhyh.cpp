//외부 공기가 테두리와 맞닿아 있는 부분만 잘 체크하면 된다.
//시간을 줄일수 있을까..?
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define AIR 2
int N, M;
int board[100][100];
int nboard[100][100]; //next
int q[20002][2];

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

void BFS()
{
	int f = 0, r = 0;
	q[r][0] = 0;
	q[r][1] = 0;
	r++;
	board[0][0] = AIR;
	while(f<r)
	{
		int cr = q[f][0];
		int cc = q[f][1];
		f++;
		for(int d=0;d<4;d++)
		{
			int nr = cr + dx[d];
			int nc = cc + dy[d];
			if (nr < 0 || nr >= N || nc < 0 || nc >= M)continue;
			if (board[nr][nc] != 0)continue;
			board[nr][nc] = AIR;
			q[r][0] = nr;
			q[r][1] = nc;
			r++;
		}
	}
}

int main()
{
	scanf("%d %d", &N, &M);
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<M;j++)
		{
			scanf("%d", &board[i][j]);
		}
	}
	int result = 0;
	while(true)
	{
		int tmp = 0;
		memset(nboard, 0, sizeof(nboard));
		BFS(); //외부 공기 찾기
		for(int i=0;i<N;i++)
		{
			for (int j = 0; j < M; j++) 
			{
				//외부 공기와 2면 이상 맞닿아 있는 치즈 없애기
				if(board[i][j]==1)
				{
					tmp++;
					nboard[i][j] = 1;
					int cnt = 0;
					for (int d = 0; d < 4; d++)
					{
						int ni = i + dx[d];
						int nj = j + dy[d];
						if (board[ni][nj] == AIR)cnt++;
					}
					if(cnt>=2)
					{
						nboard[i][j] = 0; //지우기!
					}
				}
			}
		}
		if (!tmp)break;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if (nboard[i][j])
				{
					board[i][j] = 1;
				}
				else board[i][j] = 0;//지우기
			}
		}
		result++;
	}
	printf("%d\n", result);
}
