//불하고 상근이랑 같이 처리 안해줌
#include <iostream>
#include <queue>
#include <cstring>
#define MIN(a,b)((a)<(b)?(a):(b))
using namespace std;

#define SPACE 0
#define WALL 1
#define FIRE 2
#define SAN 3
#define END 4

#define MAX_SIZE 1001
#define INF 987654321

int T, W, H;
int board[MAX_SIZE][MAX_SIZE];
int dp[MAX_SIZE][MAX_SIZE][2];

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

queue<pair<int, int>> q;


int Solve()
{
	int minV = INF;
	while (!q.empty())
	{
		int cr = q.front().first;
		int cc = q.front().second;

		q.pop();
		if (dp[cr][cc][0] == SAN && board[cr][cc] == END)minV = MIN(minV, dp[cr][cc][1]);
		int nt = dp[cr][cc][1] + 1; //갈때의 시간
		for (int d = 0; d < 4; d++)
		{
			int nr = cr + dx[d];
			int nc = cc + dy[d];
			if (nr < 0 || nr >= H || nc < 0 || nc >= W)continue;
			if(board[nr][nc]!=WALL)
			{
				if(!dp[nr][nc][0])
				{
					dp[nr][nc][0] = dp[cr][cc][0];
					dp[nr][nc][1] = nt;
					q.push({ nr,nc });
				}
				
				else if(dp[cr][cc][0]==FIRE&&nt<=dp[nr][nc][1]) //시간 잘 체크!!
				{
					dp[nr][nc][0] = dp[cr][cc][0];
					dp[nr][nc][1] = nt;
					q.push({ nr,nc });
				}
			}
		}
	}
	return minV;
}


int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> T;
	while (T--)
	{
		cin >> W >> H;
		memset(dp, 0, sizeof(dp));
		int result = 1;
		char tmp;
		for (int i = 0; i < H; i++)
		{
			for (int j = 0; j < W; j++)
			{
				cin >> tmp;
				if (tmp == '.')
				{
					if (i == 0 || j == 0 || i == H - 1 || j == W - 1)board[i][j] = END;
					else board[i][j] = SPACE;
				}
				else if (tmp == '#')
				{
					board[i][j] = WALL;
				}
				else
				{
					if (tmp == '@' && (i == 0 || j == 0 || i == H - 1 || j == W - 1))result = 0;
					if (tmp == '@')dp[i][j][0] = SAN;
					else dp[i][j][0] = FIRE;
					dp[i][j][1] = 0; //초기상태
					q.push({ i,j });
				}
			}
		}
		if (result)
			result = Solve();
		if (result == INF) cout << "IMPOSSIBLE\n";

		else
			cout << result + 1 << "\n";
	}

}
