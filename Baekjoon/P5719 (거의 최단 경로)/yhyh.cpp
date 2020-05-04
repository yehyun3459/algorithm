//최단거리 경로가 여러개 있는경우가 좀 골치아팠지만 딱히 어렵지는 않은 문제
//으 여러개 있는 경우 때문에 부모노드 배열을 큐 처럼 
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int N, M;
int S, D;//시작점,도착점
int U, V, P;
int graph[501][501]; //그래프(인접행렬)
int dist[501]; //거리 저장
int pre[501][502]; //부모노드번호 저장(같은 거리의 경로 여러개 저장)

void Dijkstra()
{
	dist[S] = 0;
	queue<int> q;
	q.push(S);
	while(!q.empty())
	{
		int cv = q.front();
		q.pop();
		for(int i=0;i<N;i++)
		{
			if (cv == i)continue;
			if(graph[cv][i]!=-1)
			{
				if(dist[i]==-1||dist[i]>dist[cv]+graph[cv][i])
				{
					dist[i] = dist[cv] + graph[cv][i];
					pre[i][0] = 1; //더 작은 경로가 있는 경우 부모 노드들을 초기화한 후 저장함
					pre[i][pre[i][0]] = cv;
					q.push(i);
				}
				else if(dist[i]==dist[cv]+graph[cv][i]) //같은 경로가 있으면 pre배열에 추가
				{
					pre[i][0]++;
					pre[i][pre[i][0]] = cv;
					q.push(i);
				}
			}
		}
	}
}
void eraseEdge() //최단경로 삭제(여러개가 있는 경우를 위해 큐 사용)
{
	queue<int> q;
	q.push(D);
	while(!q.empty())
	{
		int cv = q.front();
		q.pop();
		for(int i=1;i<=pre[cv][0];i++)
		{
			int pv = pre[cv][i];
			if (graph[pv][cv] == -1)continue; //이미 삭제되었으면 넘어감
			graph[pv][cv] = -1; //삭제
			q.push(pv);
		}
	}
	memset(dist, -1, sizeof(dist)); //거리 초기화
}

int main()
{
	//freopen("input.txt", "r", stdin);
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	while(true)
	{
		cin >> N >> M;
		if (!N && !M)break;
		cin >> S >> D;
		memset(graph, -1, sizeof(graph));
		memset(dist, -1, sizeof(dist));
		memset(pre, 0, sizeof(pre));
		for(int i=0;i<M;i++)
		{
			cin >> U >> V >> P;
			graph[U][V] = P;
		}
		Dijkstra();
		//첫번째 최단경로 구함		
		eraseEdge(); //삭제
		Dijkstra(); //다시 구함

		cout << dist[D] << "\n";
	}
}
