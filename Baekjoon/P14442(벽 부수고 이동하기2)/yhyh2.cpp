//다른 버전
//이게 사실 풀이가 더 쉽긴 한데 K의 범위가 커지면 메모리 초과 날듯
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

#define MIN(a,b)(a<b?a:b)
int minV = 987654321;
int N, M, K;
bool board[1000][1000];
int visited[1000][1000][11];

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
struct Info
{
	int r;
	int c;
	int z;//floor
};
queue<Info> q;
void BFS()
{
	while(!q.empty())
	{
		int cr = q.front().r;
		int cc = q.front().c;
		int cz = q.front().z;
		q.pop();
		if (cr == N - 1 && cc == M - 1)continue;
		for(int d=0;d<4;d++)
		{
			int nr = cr + dx[d];
			int nc = cc + dy[d];
			if (nr < 0 || nr >= N || nc < 0 || nc >= M)continue;
			if(board[nr][nc]) //이동할수 없는 곳
			{
				if(cz)
				{
					if(visited[nr][nc][cz-1]==-1||(visited[nr][nc][cz-1]>visited[cr][cc][cz]+1))
					{
						visited[nr][nc][cz - 1] = visited[cr][cc][cz] + 1;
						q.push({ nr,nc,cz - 1 });
					}
				}
			}
			else
			{
				if(visited[nr][nc][cz]==-1||(visited[nr][nc][cz]>visited[cr][cc][cz]+1))
				{
					visited[nr][nc][cz] = visited[cr][cc][cz] + 1;
					q.push({ nr,nc,cz });
				}
			}
		}
	}
}
int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	cin >> N >> M >> K;
	char tmp;
	for(int i=0;i<N;i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> tmp;
			if (tmp == '0')board[i][j] = 0;
			else board[i][j] = 1;
		}
	}
	memset(visited, -1, sizeof(visited));
	visited[0][0][K] = 1;
	q.push({ 0,0,K });
	BFS();
	for(int i=0;i<=K;i++) //예전에 이거 실수했었음...주의
	{
		if(visited[N-1][M-1][i]!=-1)
		{
			minV = MIN(minV, visited[N - 1][M - 1][i]);
		}
			
	}
	if (minV == 987654321)minV = -1;
	cout << minV << "\n";
}
