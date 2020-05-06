//다른 사람 풀이 참고해서
//잉 근데 난 그래도 3000ms 나오는데...어떻게 
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
int minV = INF;

struct Node
{
	int v;
	int c;
	int d;
};
vector<vector<Node>> graph;
int dist[101][10001]; //거리

bool operator<(Node a,Node b)
{
	return a.d > b.d;
}

void Dijkstra()
{
	for(int i=1;i<=N;i++)
	{
		for (int j = 0; j <= M; j++)dist[i][j] = INF;
	}
	priority_queue<Node> q;
	q.push({ 1,M,0 }); //출발지, 남아있는 돈, 거리
	dist[1][M] = 0;
	while(!q.empty())
	{
		int cv = q.top().v;
		int cc = q.top().c;
		int cd = q.top().d;
		q.pop();
		if (cd > dist[cv][cc])continue;
		if(cv==N)
		{
			minV = MIN(minV, cd); //그리디하게 풀어도 되는 문제라고 한다 음 잘 모르겠음.. ㅇ<-< 
			break;
		}
		for(unsigned int i=0;i<graph[cv].size();i++)//이웃하는 정점을 찾자
		{
			int nv = graph[cv][i].v;
			int nc = cc - graph[cv][i].c;
			int nd = cd + graph[cv][i].d;
			if(nc>=0)
			{
				if (dist[nv][nc] > nd)
				{
					for(int j=nc;j>=0;j--) //!! 이부분 : 미리 거리의 상한선을 저장
					{
						if(dist[nv][j]>nd)
						{
							dist[nv][j] = nd;
						}
					}
					
					q.push({ nv,nc,nd });
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
		minV = INF;
		while(K--)
		{
			cin >> U >> V >> C >> D;
			graph[U].push_back({ V,C,D });
		}

		Dijkstra();
		
		if (minV == INF)cout << "Poor KCM\n";
		else cout << minV << "\n";
	}
}
