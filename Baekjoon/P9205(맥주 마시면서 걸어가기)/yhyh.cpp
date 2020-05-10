//50미터 생각만 하고 visited해주었더니 계속 틀렸는데 훨씬 쉬운 풀이가 있었음...
//왜 이런 생각을 못했지
//그래프를 만들어 주면 된다!
//1000미터 이내에 있는 정점끼리는 이어줌 -> 여기서 BFS,DFS,플로이드 중 하나로 풀이하면 될듯
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cmath>
#include <queue>
#include <cstring>
using namespace std;

int T, N;
int graph[102][102];
int loc[102][2];
int visited[102];
bool BFS()
{
	queue<int> q;
	q.push(0);
	visited[0] = 1;
	while (!q.empty())
	{
		int cv = q.front();
		q.pop();
		for(int i=0;i<=N+1;i++)
		{
			if (cv == i||visited[i]||!graph[cv][i])continue;
			visited[i] = 1;
			q.push(i);
		}
	}
	return visited[N + 1];
}
int main()
{
	//freopen("input.txt", "r", stdin);
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	cin >> T;
	while(T--)
	{
		cin >> N;
		cin >> loc[0][0] >> loc[0][1];
		for(int i=1;i<=N;i++)
		{
			cin >> loc[i][0] >> loc[i][1];
		}
		cin >> loc[N + 1][0] >> loc[N + 1][1]; //도착지

		memset(graph, 0, sizeof(graph));
		for(int i=0;i<=N+1;i++)
		{
			for(int j=0;j<=N+1;j++)
			{
				if (i == j)continue;
				int dist = abs(loc[i][0] - loc[j][0]) + abs(loc[i][1] - loc[j][1]); //1000미터 이내로는 갈 수 있다(간선 이어줌)
				if (dist <= 1000)graph[i][j] = 1; //연결되어있음
			}
		}
		memset(visited, 0, sizeof(visited));
		if (BFS())cout << "happy\n";
		else cout << "sad\n";
	}
}
