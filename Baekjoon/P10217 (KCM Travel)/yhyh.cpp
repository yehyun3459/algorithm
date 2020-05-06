//맨 처음에 푼 풀이, 한 6000ms정도 
//그냥 평범하게? 거리 dp배열을 이용해서 다익스트라로 
//주의! 출발지-목적지가 같은 경로가 여러개 있을 수 있음 (인접행렬로 구현하기 힘들당)
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

#define MIN(a,b)(a<b?a:b)
#define INF 987654321
int T;
int N, M, K; //공항 수(정점), 비용, 티켓정보(간선정보)
int U, V, C, D;//출발지,도착지,비용,거리

struct Node
{
	int v;
	int c;
	int d;
};
vector<vector<Node>> graph;
int dist[101][10001]; //거리

void Dijkstra()
{
	queue<pair<int,int>> q;
	q.push({ 1,M }); //출발지, 남아있는 돈, 거리
	dist[1][M] = 0;
	while(!q.empty())
	{
		int cv = q.front().first;
		int cc = q.front().second;
		q.pop();

		for(unsigned int i=0;i<graph[cv].size();i++)//이웃하는 정점을 찾자
		{
			int nv = graph[cv][i].v;
			int nc = cc - graph[cv][i].c;
			int nd = graph[cv][i].d;
			if(nc>=0)
			{
				if (dist[nv][nc] == -1 || dist[nv][nc] > dist[cv][cc] + nd)
				{
					dist[nv][nc] = dist[cv][cc] + nd;
					q.push({ nv,nc });
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
	while(T--)
	{
		cin >> N >> M >> K;
		graph.clear();
		graph.resize(N + 1);
		while(K--)
		{
			cin >> U >> V >> C >> D;
			graph[U].push_back({ V,C,D });
		}
		memset(dist, -1, sizeof(dist));
		Dijkstra();
		int minV = INF;
		for(int i=0;i<=M;i++)
		{
			if (dist[N][i] == -1)continue;
			minV = MIN(minV, dist[N][i]);
		}
		if (minV == INF)cout << "Poor KCM\n";
		else cout << minV << "\n";
	}
}
