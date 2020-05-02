//visited 숫자의 체크만 잘 해주면 되는 BFS 문제
//근데 문제보고 한참 멍때림..
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

#define MIN(a,b)(a<b?a:b)

int minV = 987654321;
char board[1001][1001];
char visited[1001][1001];
int H, W, N;
int sr, sc;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

struct Info
{
	int row;
	int col;
	int dist;
};
void BFS()
{
	visited[sr][sc] = '0';
	queue<Info> q;
	q.push({ sr,sc });
	while(!q.empty())
	{
		int cr = q.front().row;
		int cc = q.front().col;
		int cd = q.front().dist;
		q.pop();
		if(visited[cr][cc]==N+'0')
		{
			minV = MIN(minV, cd);
			continue;
		}
		for(int d=0;d<4;d++)
		{
			int nr = cr + dx[d];
			int nc = cc + dy[d];
			if (nr < 0 || nr >= H || nc < 0 || nc >= W)continue;
			if (visited[nr][nc] >= visited[cr][cc])continue;
			if (board[nr][nc] == 'X')continue;
			if (board[nr][nc] == visited[cr][cc] + 1)
			{
				visited[nr][nc] = visited[cr][cc] + 1;
				q.push({ nr,nc,cd + 1 });
			}
			else
			{
				visited[nr][nc] = visited[cr][cc];
				q.push({ nr,nc,cd + 1 });
			}
		}
	}

}

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	cin >> H >> W >> N;

	for(int i=0;i<H;i++)
	{
		for(int j=0;j<W;j++)
		{
			cin >> board[i][j];
			if (board[i][j] == 'S')
			{
				sr = i;
				sc = j;
				board[i][j] = '.';
			}
			visited[i][j] = 47;
		}
	}

	BFS();
	cout << minV << "\n";
}
