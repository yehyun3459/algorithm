//최소 스패닝 트리 문제
//그래서 그렇게 풀었는데 알고보니 함정문제였다(?) 나는 몰랐음...
//일단 처음 푼 풀이

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int T, N, M;
int graph[1002][1002];
int visited[1002];
void MST()
{
	int cnt = 0;
	queue<int> q;
	q.push(1);
	visited[1] = 0;
	while(!q.empty())
	{
		int cv = q.front();
		q.pop();
		for(int i=1;i<=N;i++)
		{
			if (cv == i || !graph[cv][i])continue;
			if(visited[i]==-1||visited[i]>visited[cv])
			{
				cnt++;
				visited[i] = visited[cv];
				q.push(i);
			}
		}
	}
	cout << cnt << "\n";
}
int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	cin >> T;
	while(T--)
	{
		memset(graph, 0, sizeof(graph));
		memset(visited, -1, sizeof(visited));
		cin >> N >> M;
		while(M--)
		{
			int sv, ev;
			cin >> sv >> ev;
			graph[ev][sv] = graph[sv][ev] = 1;
		}
		MST();
	}
}
