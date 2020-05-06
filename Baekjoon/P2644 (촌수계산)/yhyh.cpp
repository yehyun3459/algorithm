//단순한 다익스트라 최고 ㅠㅠㅠㅠ
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int dist[101];
int graph[101][101];
int N, M;
void Dijkstra(int sv)
{
	queue<int> q;
	q.push(sv);
	dist[sv] = 0;
	while(!q.empty())
	{
		int cv = q.front();
		q.pop();
		for(int i=1;i<=N;i++)
		{
			if(graph[cv][i])
			{
				if(dist[i]==-1||dist[i]>dist[cv]+1)
				{
					dist[i] = dist[cv] + 1;
					q.push(i);
				}
			}
		}
	}
}
int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	cin >> N;
	memset(graph, 0, sizeof(graph));
	memset(dist, -1, sizeof(dist));
	int src = 0, dst = 0;
	cin >> src >> dst;
	cin >> M;
	while(M--)
	{
		int a, b;
		cin >> a >> b;
		graph[b][a] = graph[a][b] = 1;
	}

	Dijkstra(src);
	cout << dist[dst] << "\n";
}
