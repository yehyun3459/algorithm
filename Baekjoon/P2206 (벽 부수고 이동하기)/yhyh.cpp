//궁금한점 
//1. 이거 dp로는 못푸는건가?
//2. 큐에 위치정보 하나로 할 수 있을까? (어떻게 한건지 모를..)
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

#define INF 987654321
#define MIN(a,b)((a)<(b)?(a):(b))
int N, M;
char board[1001][1001];
int dp[1001][1001][2]; //벽을 부쉈을때와 아닐때 (이문제에서는 굳이 visited 안써도 됨)

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

struct Info
{
	int row;
	int col;
	int canBreak;
};
void Solve()
{
	queue<Info> q;
	q.push({ 0,0,1 });
	dp[0][0][1] = 1;
	while (!q.empty())
	{
		int cr = q.front().row;
		int cc = q.front().col;
		int cb = q.front().canBreak;
		q.pop();
		for (int d = 0; d < 4; d++)
		{
			int nr = cr + dx[d];
			int nc = cc + dy[d];
			if (nr < 0 || nr >= N || nc < 0 || nc >= M)continue;

			if (board[nr][nc] == '0') //그냥 현재 상태에서 이동하면 됨
			{
				if (dp[cr][cc][cb] + 1 < dp[nr][nc][cb])
				{
					dp[nr][nc][cb] = dp[cr][cc][cb] + 1;
					q.push({ nr,nc,cb });
				}
			}
			else if (cb) //벽인데 부술수 있다면
			{
				if (dp[cr][cc][cb] + 1 < dp[nr][nc][cb - 1])
				{
					dp[nr][nc][cb - 1] = dp[cr][cc][cb] + 1;
					q.push({ nr,nc,cb - 1 });
				}
			}
		}
	}
}
int main()
{
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			scanf(" %c", &board[i][j]);
			dp[i][j][0] = dp[i][j][1] = INF;
		}

	}

	Solve();

	if (dp[N - 1][M - 1][0] == INF && dp[N - 1][M - 1][1] == INF)
	{
		printf("%d\n", -1);
	}
	else printf("%d\n", MIN(dp[N - 1][M - 1][0], dp[N - 1][M - 1][1]));
}
