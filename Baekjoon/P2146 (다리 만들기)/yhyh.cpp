//BFS+BFS 문제(DFS로는 도저히 못하겠음)
//1. 그래프 정점 번호 매기기
//2. 최단거리 구하기
//prim이나 다익스트라가 아니어서 각 정점간 최단거리 구해줄 필요없음(이거 때문에 런타임에러+메모리초과나서 많이 틀림)
//목적지를 정해주지 않고 다른 섬을 발견할 경우에 최단거리 갱신해야 시간초과 안남 (목적지 정해주었다가 시간초과 남 ㅎㅎ)

#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

#define INF 987654321
#define MIN(a,b)(a<b?a:b)

bool board[101][101];
bool visited[101][101];

int graph[101][101]; //섬의 번호를 표시해줌

int N;
int minV = INF;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

struct Info
{
	int row;
	int col;
	int _dist;
};

void calDist(int sv,int sr, int sc) //이것도 BFS로 하자
{
	memset(visited, 0, sizeof(visited));
	queue<Info> q;
	visited[sr][sc] = 1;
	q.push({ sr,sc,0 });
	while(!q.empty())
	{
		int cr = q.front().row;
		int cc = q.front().col;
		int cd = q.front()._dist;
		q.pop();
		if (cd >= minV)continue;

		for(int d=0;d<4;d++)
		{
			int nr = cr + dx[d];
			int nc = cc + dy[d];
			if (nr < 0 || nr >= N || nc < 0 || nc >= N)continue;
			if (graph[nr][nc] != sv && graph[nr][nc] != 0)
			{
				if (cd + 1 < minV)
				{
					minV = cd + 1;
				}
			}
			else if (board[nr][nc] || visited[nr][nc])continue;//도착지도 아닌데 섬이네 응 안녕~
			else
			{
				visited[nr][nc] = 1;
				q.push({ nr, nc, cd + 1 });
			}
		}
	}
}

void makeIsland(int sr,int sc,int num)
{
	queue<pair<int, int>> q;
	q.push({ sr,sc });
	graph[sr][sc] = num;
	while(!q.empty())
	{
		int cr = q.front().first;
		int cc = q.front().second;
		q.pop();
		for(int d=0;d<4;d++)
		{
			int nr = cr + dx[d];
			int nc = cc + dy[d];
			if (nr < 0 || nr >= N || nc < 0 || nc >= N)continue;
			if (board[nr][nc] && graph[nr][nc] != num) 
			{
				graph[nr][nc] = num;
				q.push({ nr,nc });
			}
			if(!board[nr][nc])
			{
				calDist(num, nr, nc);
			}
		}
	}
}

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N;
	for(int i=0;i<N;i++)
	{
		for (int j = 0; j < N; j++) 
		{
			cin >> board[i][j];
			graph[i][j] = 0;
		}
	}
	int num = 1;

	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			if(board[i][j]&&!graph[i][j])
			{
				makeIsland(i,j,num);
				num++;
			}
		}
	}
	cout << minV << "\n";
}
