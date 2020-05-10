//오랜만에 쉬운 플로이드~~
#include <iostream>
#include <cstring>
using namespace std;

int N;
int graph[101][101];

void Solve()
{
	for(int v=1;v<=N;v++)
	{
		for(int i=1;i<=N;i++)
		{
			for(int j=1;j<=N;j++)
			{
				if (graph[i][j])continue; //이미 연결되어있으면 볼 필요 없음
				graph[i][j] = graph[i][v] && graph[v][j];
			}
		}
	}
}
int main() 
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	cin >> N;
	for(int i=1;i<=N;i++)
	{
		for (int j = 1; j <= N; j++)cin >> graph[i][j];
	}

	Solve();
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)cout<< graph[i][j]<<" ";
		cout << "\n";
	}
}
