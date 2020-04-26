//간단한 BFS문제 좋아~~
#include <iostream>
#include <queue>
using namespace std;

int R, C;
char board[251][251];
bool visited[251][251];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int sheepCnt = 0;
int wolfCnt = 0;

void BFS(int sr, int sc)
{
	int sheep = 0;
	int wolf = 0;
	queue<pair<int, int>> q; 
	q.push({ sr,sc });
	visited[sr][sc] = 1;
	if (board[sr][sc] == 'o')sheep++;
	else if (board[sr][sc] == 'v')wolf++;

	while(!q.empty())
	{
		int cr = q.front().first;
		int cc = q.front().second;
		q.pop();
		for(int d=0;d<4;d++)
		{
			int nr = cr + dx[d];
			int nc = cc + dy[d];
			if (nr < 0 || nr >= R || nc < 0 || nc >= C)continue;
			if (visited[nr][nc] || board[nr][nc] == '#')continue;
			visited[nr][nc] = 1;
			if (board[nr][nc] == 'o')sheep++;
			if (board[nr][nc] == 'v')wolf++;
			q.push({ nr,nc });
		}
	}
	if (sheep > wolf)sheepCnt += sheep;
	else wolfCnt += wolf;
}

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> R >> C;
	for(int r=0;r<R;r++)
	{
		for(int c=0;c<C;c++)
		{
			cin >> board[r][c];
			visited[r][c] = 0;
		}
	}

	for(int r=0;r<R;r++)
	{
		for(int c=0;c<C;c++)
		{
			if((board[r][c]=='o'||board[r][c]=='v')&&!visited[r][c])
			{
				BFS(r,c);
			}
		}
	}
	cout << sheepCnt << " " << wolfCnt << "\n";
}
