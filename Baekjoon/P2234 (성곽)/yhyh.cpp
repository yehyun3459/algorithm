//완탐으로 풀었는데 시간을 줄일수 있을까?
//그냥 모든 제거 가능한 벽을 하나씩 제거해가면서 BFS 돌린듯
//가지치기 안하면 아슬아슬하게 통과... 해도 500ms 정도 걸림
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

#define MAX(a,b)(a>b?a:b)
int board[50][50];
int visited[50][50];
int n, m; //(mxn)임 !!! 헷갈리지 말기

int maxW = 0; //가장 넓은 방
int firstMax = 0; //첫번째로 넓은 방
int secondMax = 0; //두번째로 넓은 방
int maxC = 0;//max count

// 서쪽 1(0), 북쪽 2(1), 동쪽 4(2), 남쪽 8(3)
int dx[4] = { 0,-1,0,1 };
int dy[4] = { -1,0,1,0 };

void getRoomSize(int r,int c,int num)
{
	int cnt = 0;
	visited[r][c] = num;
	queue<pair<int, int>> q;
	q.push({ r,c });
	while(!q.empty())
	{
		int cr = q.front().first;
		int cc = q.front().second;
		cnt++;
		q.pop();
		for(int d=0;d<4;d++)
		{
			int nr = cr + dx[d];
			int nc = cc + dy[d];
			if (nr < 0 || nr >= m || nc < 0 || nc >= n)continue;
			if (visited[nr][nc])continue;
			if ((board[cr][cc]>>d)&1)continue; //벽이다~~~ 비트연산 싫어~~~
			visited[nr][nc] = num;
			q.push({ nr,nc });
		}
	}
	if (cnt > maxW)maxW = cnt;
	else
	{
		if (cnt > secondMax)secondMax = cnt;
	}
}

void getRoomCnt()
{
	memset(visited, 0, sizeof(visited));
	int num = 1;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (!visited[i][j])
			{
				getRoomSize(i, j, num);
				num++;
			}
		}
	}
	maxC = num - 1; //방의 개수
}

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> n >> m;
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin >> board[i][j];
		}
	}
	getRoomCnt();
	cout << maxC << "\n";
	cout << maxW << "\n";
	firstMax = maxW;
	//벽을 하나씩 제거해보자...
	// 서쪽 1(0), 북쪽 2(1), 동쪽 4(2), 남쪽 8(3)
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			for(int d=0;d<4;d++)
			{
				if (i == 0 && d == 1)continue;
				if (i == m - 1 && d == 3)continue;
				if (j == 0 && d == 0)continue;
				if (j == n - 1 && d == 2)continue;
				if ((board[i][j] >> d) & 1)
				{
					board[i][j] -= (1 << d);
					getRoomCnt();
					if(maxW==firstMax+secondMax) //가지치기! 나올 수 있는 제일 최댓값 
					{
						cout << maxW << "\n";
						return 0;
					}
					board[i][j] += (1 << d);
				}
			}
		}
	}
	cout << maxW << "\n";
}
