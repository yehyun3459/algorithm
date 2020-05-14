//다익스트라~~ 좋아~~
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int L, R, C;
int er, ec, el;
char board[31][31][31];
int dist[31][31][31];
int dl[6] = { -1,1,0,0,0,0 };
int dr[6] = { 0,0,-1,1,0,0 };
int dc[6] = { 0,0,0,0,-1,1 };

struct Info
{
	int l;
	int r;
	int c;
};

queue<Info> q;

void BFS()//다익~~~
{
	while(!q.empty())
	{
		int cl = q.front().l;
		int cr = q.front().r;
		int cc = q.front().c;
		q.pop();
		for(int d=0;d<6;d++)
		{
			int nl = cl + dl[d];
			int nr = cr + dr[d];
			int nc = cc + dc[d];
			if (nl < 0 || nl >= L || nr < 0 || nr >= R || nc < 0 || nc >= C)continue;
			if (board[nl][nr][nc] == '#')continue;
			if(dist[nl][nr][nc]==-1||dist[nl][nr][nc]>dist[cl][cr][cc]+1)
			{
				dist[nl][nr][nc] = dist[cl][cr][cc] + 1;
				q.push({ nl,nr,nc });
			}
		}
	}
}
int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	while(1)
	{
		cin >> L >> R >> C;
		if (!L && !R && !C)break;
		memset(dist, -1, sizeof(dist));
		for (int l = 0; l < L; l++)
		{
			for (int r = 0; r < R; r++)
			{
				for (int c = 0; c < C; c++)
				{
					cin >> board[l][r][c];
					if (board[l][r][c] == 'S')
					{
						q.push({ l,r,c });
						dist[l][r][c] = 0;
						board[l][r][c] = '.';
					}
					else if(board[l][r][c]=='E')
					{
						el = l;
						er = r;
						ec = c;
						board[l][r][c] = '.';
					}
				}
			}
		}
		BFS();
		if(dist[el][er][ec]==-1)
		{
			cout << "Trapped!\n";
		}
		else
		{
			cout << "Escaped in "<<dist[el][er][ec]<<" minute(s).\n";
		}
	}
	
}
