//큐를 여러개 두어서 풀어야 하는 문제
//시간초과 많이남 ㅠㅠㅠ 이런 유형 많이 풀어보자
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

int R, C;
char board[1501][1501];
int visited[1501][1501];


int loc[2][2];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
queue<pair<int, int>> swanQ;
queue<pair<int, int>> waterQ;

bool isMelt(int r, int c)
{
	for (int d = 0; d < 4; d++)
	{
		int nr = r + dx[d];
		int nc = c + dy[d];
		if (nr < 0 || nr >= R || nc < 0 || nc >= C)continue;
		if (board[nr][nc] == '.')
		{
			return true;
		}
	}
	return false;
}

bool chk()
{
//	memset(bfsVisited, 0, sizeof(bfsVisited));
	queue<pair<int, int>> q;
	swap(q, swanQ);
	
	while(!q.empty())
	{
		int cr = q.front().first;
		int cc = q.front().second;
		q.pop();
		if (cr == loc[1][0] && cc == loc[1][1])
		{
			return true;
		}
		for(int d=0;d<4;d++)
		{
			int nr = cr + dx[d];
			int nc = cc + dy[d];
			if (nr < 0 || nr >= R || nc < 0 || nc >= C)continue;
			if (visited[nr][nc])continue;
			visited[nr][nc] = 1;
			if (nr == loc[1][0] && nc == loc[1][1])return true;
			if (board[nr][nc] == '.')
			{
				q.push({ nr,nc });
			}
			if(board[nr][nc]=='X')
			{
				swanQ.push({ nr,nc });
			}
		}
	}
	return false;
}

void melt()
{
	queue<pair<int, int >> q;
	swap(q, waterQ);
	
	while (!q.empty())
	{
		int cr = q.front().first;
		int cc = q.front().second;
		q.pop();

		for (int d = 0; d < 4; d++)
		{
			int nr = cr + dx[d];
			int nc = cc + dy[d];
			if (nr < 0 || nr >= R || nc < 0 || nc >= C)continue;
			if(board[nr][nc]=='X')
			{
				board[nr][nc] = '.';
				waterQ.push({ nr,nc });
			}
		}
	}

}
int main()
{
	//freopen("input.txt", "r", stdin);
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	cin >> R >> C;
	
	memset(loc, -1, sizeof(loc));

	for(int i=0;i<R;i++)
	{
		for(int j=0;j<C;j++)
		{
			cin >> board[i][j];
			if(board[i][j]=='L')
			{
				if(loc[0][0]==-1)
				{
					loc[0][0] = i;
					loc[0][1] = j;
					swanQ.push({ i,j });
					visited[i][j] = 1;
				}//start
				else
				{
					loc[1][0] = i;
					loc[1][1] = j;
				}//end
				board[i][j] = '.';
			}
			if (board[i][j] == '.')
			{
				waterQ.push({ i,j });
			}

		}
	}

	int cnt = 0;
	while(true)
	{
		//만나는지 본다
		if (chk())break;
		//현재 빙판을 녹이고 다음 녹을 빙판을 큐에 넣는다
		melt();
		cnt++;
	}
	cout << cnt << "\n";
}
