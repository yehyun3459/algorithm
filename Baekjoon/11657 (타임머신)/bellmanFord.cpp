//벨만포드 공부하자....
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <vector>
using namespace std;

#define MAX_SIZE 501
#define INF 987654321

int N, M;
int A, B, C;
vector<pair<int,int>> adj[MAX_SIZE];

void bellmanFord(int src)
{
	//시작점을 제외한 모든 정점까지의 최단거리 상한을 INF로 둔다.
	vector<int> upper(N+1, INF);
	upper[src] = 0;
	bool updated;
	
	if(adj[src].size()>0) //1번에서 반드시 나가는 간선이 있어야 함!
	{
		for (int n = 1; n <= N; n++)//v번 순회한다
		{
			updated = false;
			for (int s = 1; s <= N; s++) //모든 정점의 간선에 대해 수행한다
			{
				for (int i = 0; i < adj[s].size(); i++) //s정점의 간선 수만큼
				{
					int d = adj[s][i].first;
					int c = adj[s][i].second;

					if (upper[d] > upper[s] + c) //완화를 시도한다.
					{
						upper[d] = upper[s] + c;
						updated = true;
					}
				}
			}
			if (!updated)break; //모든 간선에 대해 완화가 실패한다면 종료 ( 더 수행하여도 완화 안되므로 할 필요 없음 )
		}
		if (updated) //V번째에도 완화가 일어남 -> 음수사이클이 존재
		{
			printf("%d\n", -1);
			return;
		}
	}
	
	
	for(int i=2;i<=N;i++)
	{
		printf("%d\n", upper[i] == INF ? -1 : upper[i]);
	}
	
}

int main()
{
	scanf("%d %d", &N, &M);
	
	for(int i=0;i<M;i++)
	{
		scanf("%d %d %d", &A, &B, &C);
		adj[A].push_back({ B,C }); //도착 정점, 가중치 (1번 정점부터!!!!)
	}
	bellmanFord(1);

	return 0;
}
