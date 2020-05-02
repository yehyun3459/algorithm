//최소 개수가 같을 때도 유념해주어야 하는 문제...
//(거리가 같은 경우에도 큐에 넣어주어야 함) 왜냐하면 방향 바뀌기 전, 바뀐 후 인 경우가 있어서...
//아래와 같은 반례의 경우가 위에 해당함
//4 4
//C...
//....
//**..
//**.C

//그 이외에는 방향 바뀔때만 거리(거울 개수) +1을 해주어서 다익스트라(라고 해도되나?)로 풀면 됨

#include <iostream>
#include <queue>
using namespace std;

int W, H;
char board[101][101];
int visited[101][101];
int sr, sc, er, ec;

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

struct Info
{
	int row;
	int col;
	int dir;
};
queue<Info> q;
void BFS()
{
	visited[sr][sc] = 0;
	for(int d=0;d<4;d++)
	{
		int nr = sr + dx[d];
		int nc = sc + dy[d];
		if (nr < 0 || nr >= H || nc < 0 || nc >= W)continue;
		if (board[nr][nc] == '*')continue;
		visited[nr][nc] = 0;
		q.push({ nr,nc,d });
	}
	while(!q.empty())
	{
		int cr = q.front().row;
		int cc = q.front().col;
		int cd = q.front().dir;
		q.pop();
		int nr = cr + dx[cd];
		int nc = cc + dy[cd];
		if (nr >= 0 && nr < H && nc >= 0 && nc < W)
		{
			if(board[nr][nc]!='*'&&(visited[nr][nc]==-1||visited[nr][nc]>=visited[cr][cc]))
			{
				visited[nr][nc] = visited[cr][cc];
				q.push({ nr,nc,cd });
			}
		}
		
		if(cd==0||cd==1)
		{
			for(int d=2;d<=3;d++)
			{
				nr = cr + dx[d];
				nc = cc + dy[d];
				if (nr >= 0 && nr < H && nc >= 0 && nc < W)
				{
					if (board[nr][nc] != '*' && (visited[nr][nc] == -1 || visited[nr][nc] >= visited[cr][cc]+1))
					{
						visited[nr][nc] = visited[cr][cc] + 1;
						q.push({ nr,nc,d});
					}
				}
			}
		}
		else
		{
			for (int d = 0; d <= 1; d++)
			{
				nr = cr + dx[d];
				nc = cc + dy[d];
				if (nr >= 0 && nr < H && nc >= 0 && nc < W)
				{
					if (board[nr][nc] != '*' && (visited[nr][nc] == -1 || visited[nr][nc] >= visited[cr][cc]+1))
					{
						visited[nr][nc] = visited[cr][cc] + 1;
						q.push({ nr,nc,d });
					}
				}
			}
		}
	}
}
int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	cin >> W >> H;
	sr = sc = -1;
	er = ec = 0;
	for(int i=0;i<H;i++)
	{
		for (int j = 0; j < W; j++)
		{
			cin >> board[i][j];
			if (board[i][j] == 'C')
			{
				if(sr!=-1)
				{
					er = i;
					ec = j;
				}
				else
				{
					sr = i;
					sc = j;
				}
				board[i][j] = '.';
			}
			visited[i][j] = -1;
		}
	}
	BFS();
	cout << visited[er][ec]<<"\n";
}
