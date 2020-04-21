//이런 문제 싫어 ㅠㅠ
#include <iostream>
#include <queue>
using namespace std;

#define INF 987654321
#define MIN(a,b)(a<b?a:b)

struct Info
{
	int row;
	int col;
	int isFire;
};

char board[1001][1001];
int dist[1001][1001];
int R, C;
queue<Info> q;
int sr = 0, sc = 0;

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int Solve()
{
	int minV = 987654321;
	while(!q.empty())
	{
		int cr = q.front().row;
		int cc = q.front().col;
		int cf = q.front().isFire;
		
		q.pop();
		if ((cr==0||cr==R-1||cc==0||cc==C-1)&&!cf)
		{
			minV = MIN(minV, dist[cr][cc]);
			continue;
		}
		for(int d=0;d<4;d++)
		{
			int nr = cr + dx[d];
			int nc = cc + dy[d];
			if (nr < 0 || nr >= R || nc < 0 || nc >= C)continue;
			if (board[nr][nc] == '#' || board[nr][nc] == 'F')continue;
		
			if(cf)
			{
				board[nr][nc] = 'F';
				q.push({ nr,nc,1 });
			}
			else
			{
				if(dist[nr][nc]>dist[cr][cc]+1)
				{
					dist[nr][nc] = dist[cr][cc] + 1;
					if ((nr == 0 || nr == R - 1 || nc == 0 || nc == C - 1))
					{
						minV = MIN(minV, dist[nr][nc]);
					}
					else q.push({ nr,nc,0 });
				}
			}
		}
	}
	return minV;
}
int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	cin >> R >> C;

	for(int i=0;i<R;i++)
	{
		for(int j=0;j<C;j++)
		{
			cin >> board[i][j];
			dist[i][j] = INF;
			if (board[i][j] == 'J')
			{
				dist[i][j] = 0;
				board[i][j] = '.';
				sr = i;
				sc = j;
			}

			if(board[i][j]=='F')
			{
				q.push({ i,j,1 });
			}
			
		}
	}
	q.push({ sr,sc,0 });
	int result = Solve();
	if (result == INF)cout << "IMPOSSIBLE\n";
	else cout << result + 1 << "\n";
}
