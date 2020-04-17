#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int M, N, K;
bool board[101][101];
bool visited[101][101];
int q[20002][2];
int result[10001];

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int BFS(int sr,int sc)
{
	int cnt = 0;
	int f =0, r = 0;
	q[r][0] = sr;
	q[r][1] = sc;
	r++;
	visited[sr][sc] = 1;
	while(f<r)
	{
		int cr = q[f][0];
		int cc = q[f][1];
		cnt++;
		f++;
		for(int d=0;d<4;d++)
		{
			int nr = cr + dx[d];
			int nc = cc + dy[d];
			if (nr < 0 || nr >= M || nc < 0 || nc >= N)continue;
			if(!board[nr][nc]&&!visited[nr][nc])
			{
				visited[nr][nc] = 1;
				q[r][0] = nr;
				q[r][1] = nc;
				r++;
			}
		}
	}
	return cnt;
}

int main()
{
	scanf("%d %d %d", &M, &N, &K);

	memset(board, 0, sizeof(board));
	memset(visited, 0, sizeof(visited));
	int x, y, xx, yy;
	for(int k=0;k<K;k++)
	{
		scanf("%d %d %d %d", &x, &y, &xx, &yy);
		for(int i=y;i<yy;i++)
		{
			for(int j=x;j<xx;j++)
			{
				board[i][j] = 1;
			}
		}
	}
	int num = 0;
	for(int i=0;i<M;i++)
	{
		for(int j=0;j<N;j++)
		{
			if(!board[i][j]&&!visited[i][j])
			{
				result[BFS(i, j)]++;
				num++;
			}
		}
	}
	printf("%d\n", num);
	for(int i=0;i<=10000;i++)
	{
		while(result[i]--)
		{
			printf("%d ", i);
		}
	}
	printf("\n");
}
