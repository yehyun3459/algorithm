#include <iostream>
#include <queue>
#include <vector>
#include <stack>
#include <cstring>
using namespace std;

#define INF 987654321

int N;
int board[502][1002][2];
int dx[2] = { 1,0 };
int dy[2] = { 0,1 };
vector<vector<int>> graph;
vector<int> dist;
vector<int> visited;
vector<int> preV;
stack<int> st;
void make_graph()
{
	for (int r = 1; r <= N; r++)
	{
		for (int c = 1; c <= N * 2; c++)
		{
			if (!board[r][c][0])continue;
			for (int d = 0; d < 2; d++)
			{
				int nr = r + dx[d];
				int nc = c + dy[d];
				if (!board[nr][nc][1])continue;
				if (board[nr][nc][1] != board[r][c][1] && board[nr][nc][0] == board[r][c][0])
				{
					graph[board[r][c][1]].push_back(board[nr][nc][1]);
					graph[board[nr][nc][1]].push_back(board[r][c][1]); //인접!
				}
			}
		}
	}
}

void dijkstra()
{
	queue<int> q;
	q.push(1);
	dist[1] = 1;
	preV[1] = -1;
	while (!q.empty())
	{
		int cv = q.front();
		q.pop();
		if (visited[cv])continue;
		visited[cv] = 1;
		for (unsigned int i = 0; i < graph[cv].size(); i++)
		{
			int nv = graph[cv][i];
			if (!visited[nv] && dist[nv] > dist[cv] + 1)
			{
				dist[nv] = dist[cv] + 1;
				preV[nv] = cv;
				q.push(nv);
			}
		}
	}

}

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	cin >> N;

	memset(board, 0, sizeof(board));
	graph.resize(N * N - (N / 2) + 1);
	dist.resize(N * N - (N / 2) + 1, INF);
	visited.resize(N * N - (N / 2) + 1, 0);
	preV.resize(N * N - (N / 2) + 1, -1);
	int num = 1;
	int cnt = 0;
	for (int r = 1; r <= N; r++)
	{
		if (r & 1)
		{
			for (int c = 1; c <= N * 2; c++)
			{
				if (cnt == 2)
				{
					num++;
					cnt = 0;
				}
				cnt++;
				cin >> board[r][c][0];
				board[r][c][1] = num;
			}
		}
		else
		{
			for (int c = 2; c <= N * 2 - 1; c++)
			{
				if (cnt == 2)
				{
					num++;
					cnt = 0;
				}
				cnt++;
				cin >> board[r][c][0];
				board[r][c][1] = num;
			}
		}
	}
	make_graph();
	dijkstra();
	int dest = N * N - (N / 2);
	for (; dest >= 1; dest--)
	{
		if (dist[dest] != INF)break; //번호가 가장 큰 타일로 이동!
	}
	st.push(dest);
	int nv = preV[dest];
	while (nv != -1)
	{
		st.push(nv);
		nv = preV[nv];
	}
	cout << dist[dest] << "\n";
	while (!st.empty())
	{
		cout << st.top() << " ";
		st.pop();
	}
	cout << "\n";
}
