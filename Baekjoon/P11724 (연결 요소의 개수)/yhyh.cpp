//연결 요소 : 연결 그래프가 총 몇개 있는지
//그냥 visited 체크해주면서 풀면 풀리는 문제
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int N, M;
bool graph[1001][1001];
bool visited[1001];
int u, v;

void BFS(int sv)
{
	queue<int> q;
	q.push(sv);
	visited[sv] = 1;
	while(!q.empty())
	{
		int cv = q.front();
		q.pop();
		for(int i=1;i<=N;i++)
		{
			if (visited[i] || !graph[cv][i])continue;
			visited[i] = 1;
			q.push(i);
		}
	}
}
int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	cin >> N >> M;
	while (M--)
	{
		cin >> u >> v;
		graph[v][u] = graph[u][v] = 1;
	}
	memset(visited, 0, sizeof(visited));

	int cnt = 0;
	for(int i=1;i<=N;i++)
	{
		if (visited[i])continue;
		BFS(i);
		cnt++;
	}
	cout << cnt << "\n";
}
