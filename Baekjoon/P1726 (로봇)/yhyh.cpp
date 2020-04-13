#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int M, N;
int board[101][101];
int dp[101][101][4];

int sr, sc, sd, er, ec, ed;

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };

struct Info
{
	int row;
	int col;
	int dir;
};

int changeDir(int dir)
{
	if (dir == 4)return 0;
	else if (dir == 1)return 1;
	else if (dir == 3)return 2;
	return 3;
}
void Solve()
{
	queue<Info>q;
	q.push({ sr,sc,sd });
	dp[sr][sc][sd] = 0;
	while(!q.empty())
	{
		int cr = q.front().row;
		int cc = q.front().col;
		int cd = q.front().dir;
		q.pop();

		//go k(3,2,1)(향하고 있는 방향으로만 움직일 수 있다.)
		for(int k=1;k<=3;k++)
		{
			int nr = cr + dx[cd]*k;
			int nc = cc + dy[cd]*k;
			if (nr <= 0 || nr > M || nc <= 0 || nc > N)continue;
			if (board[nr][nc])break;//1만큼 갈수있으면 저장, 1,2 둘다 가능이면 2 저장, 1,2,3 전부 가능이면 3저장
			if(dp[nr][nc][cd]>dp[cr][cc][cd]+1||dp[nr][nc][cd]==-1)
			{
				dp[nr][nc][cd] = dp[cr][cc][cd] + 1;
				q.push({ nr,nc,cd });
			}
		}
		//turn right
		int nd = (cd + 1) % 4;
		if (dp[cr][cc][nd] > dp[cr][cc][cd] + 1 || dp[cr][cc][nd] == -1)
		{
			dp[cr][cc][nd] = dp[cr][cc][cd] + 1;
			q.push({ cr,cc,nd });
		}
		//turn left
		nd = (cd + 3) % 4;
		if (dp[cr][cc][nd] > dp[cr][cc][cd] + 1 || dp[cr][cc][nd] == -1)
		{
			dp[cr][cc][nd] = dp[cr][cc][cd] + 1;
			q.push({ cr,cc,nd });
		}
	}
}

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	cin >> M >> N;
	for(int i=1;i<=M;i++)
	{
		for(int j=1;j<=N;j++)
		{
			cin >> board[i][j];
		}
	}
	cin >> sr >> sc >> sd;
	cin >> er >> ec >> ed;
	sd = changeDir(sd);
	ed = changeDir(ed);
	memset(dp, -1, sizeof(dp));
	Solve();
	cout << dp[er][ec][ed] << "\n";
}
