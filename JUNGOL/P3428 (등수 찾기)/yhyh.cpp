//어려운 문제라고 생각했는데 stl로 하니까 생각보다 쉽게 해결되는 문제...
//그냥 트리 그려서 풀 수 있는 문제였다
//근데 그냥 구현하려면 좀 골치아플듯(특히 메모리가..)
#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

int N, M, X;
vector<vector<int>> p;
vector<vector<int>> c;
int visited[100001];
int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	cin >> N >> M >> X;
	p.resize(N + 1);
	c.resize(N + 1);
	int A, B;
	while(M--)
	{
		cin >> A >> B;
		p[B].push_back(A); //부모를 가리킴
		c[A].push_back(B);//자식을 가리킴
	}
	int pSize = 0, cSize = 0;
	queue<int> pq;
	queue<int> cq;
	pq.push(X);
	cq.push(X);
	memset(visited, 0, sizeof(visited));
	visited[X] = 1;
	while(!pq.empty()) //상위 level의 노드 개수를 찾음
	{
		int cs = pq.front();
		pq.pop();
		for(unsigned int i=0;i<p[cs].size();i++)
		{
			if (visited[p[cs][i]])continue;
			visited[p[cs][i]] = 1;
			pq.push(p[cs][i]);
			pSize++;
		}
	}
	memset(visited, 0, sizeof(visited));
	visited[X] = 1;
	while (!cq.empty()) //하위 level의 노드 개수를 찾음
	{
		int cs = cq.front();
		cq.pop();
		for (unsigned int i = 0; i < c[cs].size(); i++)
		{
			if (visited[c[cs][i]])continue;
			visited[c[cs][i]] = 1;
			cq.push(c[cs][i]);
			cSize++;
		}
	}
	cout << 1 + pSize << " " << N - cSize << "\n";
}
