//메모리 줄이려고 생각해본 방식
//현재 visited에 부술 수 있는 벽의 개수를 저장한다(당연히 처음 상태는 visited[0][0]=K)
//그다음 visited에 저장되어 있는 값(부술 수 있는 벽의 개수)보다 현재 부술수 있는 벽의 개수가 더 높으면 갱신해줌
//물론 벽인 경우에는 -1값을 비교해야함
//이렇게 해서 마지막 칸인경우에 min을 갱신했는데 잘 돌아간다 
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

#define MIN(a,b)(a<b?a:b)
int minV = 987654321;
int N, M, K;
bool board[1000][1000];
int visited[1000][1000];

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
struct Info
{
	int r;
	int c;
	int d;//floor
};
queue<Info> q;
void BFS()
{
	while(!q.empty())
	{
		int cr = q.front().r;
		int cc = q.front().c;
		int cd = q.front().d;
		q.pop();
		if (cr == N - 1 && cc == M - 1)
		{
			minV = MIN(minV, cd);
			continue;
		}
		for(int d=0;d<4;d++)
		{
			int nr = cr + dx[d];
			int nc = cc + dy[d];
			if (nr < 0 || nr >= N || nc < 0 || nc >= M)continue;
			if(board[nr][nc]) //이동할수 없는 곳
			{
				if(visited[cr][cc])
				{
					if(visited[nr][nc]<visited[cr][cc]-1)
					{
						visited[nr][nc] = visited[cr][cc] - 1;
						q.push({ nr,nc,cd + 1 });
					}
				}
			}
			else
			{
				if(visited[nr][nc]<visited[cr][cc])
				{
					visited[nr][nc] = visited[cr][cc];
					q.push({ nr,nc,cd + 1 });
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
	visited[0][0] = K;
	q.push({ 0,0,1 });
	BFS();
	if (minV == 987654321)minV = -1;
	cout << minV << "\n";
}
