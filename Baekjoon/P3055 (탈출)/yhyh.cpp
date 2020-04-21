//아 이런 문제 왜케 머리아프지...

#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

#define MIN(a,b)(a<b?a:b)
int R, C;
char board[51][51];
int dist[51][51];

struct Info
{
	int row;
	int col;
	int isWater;
};
queue<Info> q;

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int sr = 0, sc = 0;

int minV = 987654321;
void Solve()
{
	while(!q.empty())
	{
		int cr = q.front().row;
		int cc = q.front().col;
		int cw = q.front().isWater;
		q.pop();

		if(board[cr][cc]=='D')
		{
			if (cw)continue;
			else
			{
				minV = MIN(minV, dist[cr][cc]);
			}
		}

		for(int d=0;d<4;d++)
		{
			int nr = cr + dx[d];
			int nc = cc + dy[d];
			if (nr < 0 || nr >= R || nc < 0 || nc >= C)continue;
			if (board[nr][nc] == 'X' || board[nr][nc] == '*')continue;

			if(cw)
			{
				if (board[nr][nc] == 'D')continue;
				board[nr][nc] = '*';
				q.push({ nr,nc,1 });
			}
			else 
			{
				if(dist[nr][nc] == -1 || dist[nr][nc] > dist[cr][cc] + 1)
				{
					dist[nr][nc] = dist[cr][cc] + 1;
					q.push({ nr,nc,0 });
				}

			}
		}
	}
}

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	cin >> R >> C;
	memset(dist, -1, sizeof(dist));
	for(int i=0;i<R;i++)
	{
		for(int j=0;j<C;j++)
		{
			cin >> board[i][j];
			if(board[i][j]=='*')
			{
				q.push({ i,j,1 });
			}
			else if(board[i][j]=='S')
			{
				board[i][j] = '.';
				dist[i][j] = 0;
				sr = i;
				sc = j;
			}
		}
	}
	q.push({ sr,sc,0 }); //일부러 고슴도치를 제일 나중에 큐에 
	Solve();
	if(minV==987654321)
	{
		cout << "KAKTUS\n";
	}
	else cout << minV << "\n";

}
