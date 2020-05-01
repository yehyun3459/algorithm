//이잉ㅠㅠ 혼자 해결못함
//deque가 필요하다고는 하는데 사실 잘 모르겠다 pq안쓰고 그냥 queue써도 다익스트라로만 잘 구현하면 해결됨
//세 구역에서 BFS돌려서 해결하는 방법 신기하다 생각못함 ㅠㅠ 
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;

#define MIN(a,b)(a<b?a:b)
int T;
int H, W;
vector<vector<char>> board;
int visited[103][103][3];
vector<pair<int, int>> prisoners;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };


struct Info
{
	int row;
	int col;
};
//bool operator<(Info a,Info b)
//{
//	return a.doors > b.doors;
//}

void BFS(int _case,int sr,int sc)//탈출 가능?
{
	int _c = _case;
	visited[sr][sc][_c] = 0;
	queue<Info> q;
	q.push({ sr,sc});
	while(!q.empty())
	{
		int cr = q.front().row;
		int cc = q.front().col;
		q.pop();
		for(int d=0;d<4;d++)
		{
			int nr = cr + dx[d];
			int nc = cc + dy[d];
			if (nr<0 || nr>H + 1 || nc < 0 || nc > W + 1)continue;
			if (board[nr][nc] == '*')continue;
			else if(board[nr][nc]=='.')
			{
				if(visited[nr][nc][_c]==-1||visited[nr][nc][_c]>visited[cr][cc][_c])
				{
					visited[nr][nc][_c] = visited[cr][cc][_c];
					q.push({ nr,nc });
				}
			}
			else if(board[nr][nc]=='#')
			{
				if (visited[nr][nc][_c] == -1 || visited[nr][nc][_c] > visited[cr][cc][_c]+1)
				{
					visited[nr][nc][_c] = visited[cr][cc][_c] + 1;
					q.push({ nr,nc });
				}
			}
			else
			{
				if (visited[nr][nc][_c] == -1 || visited[nr][nc][_c] > visited[cr][cc][_c])
				{
					visited[nr][nc][_c] = visited[cr][cc][_c];
					q.push({ nr,nc });
				}
			}
		}
	}
}

int main()
{
	//freopen("input.txt", "r", stdin);
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	cin >> T;
	int num = 1;
	while (T--)
	{
		cin >> H >> W;
		board.clear();
		board.resize(H + 2, vector<char>(W + 2, '.'));
		prisoners.clear();
		for (int i = 1; i <= H; i++)
		{
			for (int j = 1; j <= W; j++)
			{
				cin >> board[i][j];
				if (board[i][j] == '$')prisoners.push_back({ i,j });
			}
		}
		memset(visited, -1, sizeof(visited));
		BFS(0,0,0);
		BFS(1,prisoners[0].first,prisoners[0].second);
		BFS(2,prisoners[1].first, prisoners[1].second);

		int minV = 987654321;
		for(int i=1;i<=H;i++)
		{
			for(int j=1;j<=W;j++)
			{
				if (board[i][j] == '*')continue;
				int tmp = visited[i][j][0] + visited[i][j][1] + visited[i][j][2];
				if (board[i][j] == '#')tmp -= 2;
				minV = MIN(minV, tmp);
			}
		}
		cout << minV << "\n";
	}

}
