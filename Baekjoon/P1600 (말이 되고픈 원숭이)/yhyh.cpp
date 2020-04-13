#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <queue>

#define INF 987654321
#define MIN(a,b)(a<b?a:b)

int K, W, H;
int board[201][201];
int dist[201][201][31];

int dx[12] = { -1,1,0,0,-1,-2,-2,-1,1,2,2,1 };
int dy[12] = { 0,0,-1,1,-2,-1,1,2,-2,-1,1,2 };

int result = INF;

struct Info
{
	int row;
	int col;
	int valid;
};
void Solve()
{
	std::queue<Info> q;
	q.push({ 0,0,K });
	dist[0][0][K] = 0;
	while(!q.empty())
	{
		int cr = q.front().row;
		int cc = q.front().col;
		int cv = q.front().valid;
		q.pop();

		for(int d=0;d<4;d++)
		{
			int nr = cr + dx[d];
			int nc = cc + dy[d];
			if (nr < 0 || nr >= H || nc < 0 || nc >= W)continue;
			if (board[nr][nc])continue;
			if(dist[nr][nc][cv]>dist[cr][cc][cv]+1||dist[nr][nc][cv]==-1)
			{
				dist[nr][nc][cv] = dist[cr][cc][cv] + 1;
				q.push({ nr,nc,cv });
			}
		}
		if(cv>0)
		{
			for (int d = 4; d < 12; d++)
			{
				int nr = cr + dx[d];
				int nc = cc + dy[d];
				if (nr < 0 || nr >= H || nc < 0 || nc >= W)continue;
				if (board[nr][nc])continue;
				if (dist[nr][nc][cv-1] > dist[cr][cc][cv] + 1 || dist[nr][nc][cv-1] == -1)
				{
					dist[nr][nc][cv-1] = dist[cr][cc][cv] + 1;
					q.push({ nr,nc,cv - 1 });
				}
			}
		}
	}
}

int main()
{
	scanf("%d", &K);
	scanf("%d %d", &W, &H);
	for(int i=0;i<H;i++)
	{
		for (int j = 0; j < W; j++)
		{
			scanf("%d", &board[i][j]);
		}
	}
	memset(dist, -1, sizeof(dist));
	Solve();
	int result = INF;
	for(int i=0;i<=K;i++)
	{
		if (dist[H - 1][W - 1][i] == -1)continue;
		result = MIN(result, dist[H - 1][W - 1][i]);
	}
	if (result == INF)result = -1;
	printf("%d\n", result);
}
