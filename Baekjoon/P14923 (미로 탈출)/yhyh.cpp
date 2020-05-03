//벽 부수고 이동하기랑 유형은 똑같은데
//출발지와 도착지가 지정되어 있다는게 다르다
//놀랍게도 위의 조건때문에 여러번 틀림..ㅎㅎ 무조건 1,1 ~ N,M 인줄 알고 풀다가 잘못 
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

#define INF 987654321
#define MIN(a,b)(a<b?a:b)
int N, M;
int sr, sc, er, ec;

bool board[1001][1001];
int visited[1001][1001][2];

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
struct Info
{
	int r;
	int c;
	int z;
};
void BFS()
{
	queue<Info> q;
	q.push({ sr,sc,1 });
	visited[sr][sc][1] = 0;
	while (!q.empty())
	{
		int cr = q.front().r;
		int cc = q.front().c;
		int cz = q.front().z;
		q.pop();
		if (cr == er && cc == ec)continue; //여기서도 처음에 N,M으로 잘못했는데 딱히 오답의 원인이 되지는 않음
		for (int d = 0; d < 4; d++)
		{
			int nr = cr + dx[d];
			int nc = cc + dy[d];
			if (nr <= 0 || nr > N || nc <= 0 || nc > M)continue;
			if (board[nr][nc])//벽인경우
			{
				if (cz)
				{
					if (visited[nr][nc][cz - 1] > visited[cr][cc][cz] + 1)
					{
						visited[nr][nc][cz - 1] = visited[cr][cc][cz] + 1;
						q.push({ nr,nc,cz - 1 });
					}
				}
			}
			else
			{
				if (visited[nr][nc][cz] > visited[cr][cc][cz] + 1)
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
	cin >> N >> M;
	cin >> sr >> sc;
	cin >> er >> ec;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			cin >> board[i][j];
			visited[i][j][0] = visited[i][j][1] = INF;
		}
	}
	BFS();
	int result = MIN(visited[er][ec][0], visited[er][ec][1]); //이거때문에 계속 틀림 ㅋㅋㅋㅋ아놔
	if (result == INF)result = -1;
	cout << result << "\n";
}
