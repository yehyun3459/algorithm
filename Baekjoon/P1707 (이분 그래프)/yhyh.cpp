//인접리스트로 구현함
//인접행렬로 구현시, 메모리 초과 
#include <iostream>
#include <vector>
#include <queue>
using namespace std;


vector<int> color;
vector<vector<int>> graph;
int V, E;

bool isBipartite()
{
	for(int sv=1;sv<=V;sv++)
	{
		for(unsigned int v=0;v<graph[sv].size();v++)
		{
			int dv = graph[sv][v];
			if (color[sv] == color[dv])return false; //만약 인접한데 색깔이 같은경우 false 반환
		}
	}
	return true; //그런 경우가 한번도 없다면 true
}

void setColor(int sV)
{
	vector<bool> visited(V + 1, false);
	color[sV] = 1;
	visited[sV] = 1;
	queue<int> q;
	q.push(sV);
	while(!q.empty())
	{
		int cV = q.front();
		visited[cV] = 1;
		q.pop();
		for(unsigned int v=0;v<graph[cV].size();v++)
		{
			int nV = graph[cV][v];
			if (visited[nV])continue;

			color[nV] = !color[cV]; //인접한 정점을 자신과 반대 색으로 색칠
			q.push(nV);
		}
	}
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int K;
	cin >> K;
	for(int tc=1;tc<=K;tc++)
	{
		cin >> V >> E;
		graph.clear(); //테스트케이스마다 꼭 초기화!
		color.clear();
		graph.resize(V + 1);
		color.resize(V + 1, -1);
		for(int e=0;e<E;e++)
		{
			int src, dst;
			cin >> src >> dst;
			graph[src].push_back(dst); //인접리스트로 구현
			graph[dst].push_back(src);
		}

		for(int i=1;i<=V;i++)
		{
			if (color[i] == -1)setColor(i); //비연결 그래프인 경우 색칠이 안되어 있을 수 있으므로 모든 정점에서 
		}

		if (isBipartite())cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}
