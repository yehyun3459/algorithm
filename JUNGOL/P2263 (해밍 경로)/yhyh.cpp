//문제 어려운데?ㅠㅠㅠㅠ
//그래프는 그냥 Dijkstra로 풀리는 쉬운문제이긴 한데
//간선을 잇는 부분이 어렵다 그래서 이부분은 참고함...
//결론적으로는, hash를 만들어야함(key : 코드의 10진수값, value : 인덱스)
//비트 하나씩 바꿔가면서 이에 해당되는 key값이 존재하는지 검색함. 있다면 간선을 이어준다
//비트 연산 너무 어려움 맨날 까먹음 
#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
#include <cmath>
#include <map>
using namespace std;

char code[100001][30];
map<int, int> h;
vector<vector<int>> graph; //인접리스트로 구현
int value[100001];
int result[100001];
int dist[100001];
int pre[100001];
int N, K, M;

void Dijkstra()
{
	dist[1] = 0;
	queue<int> q;
	q.push(1);
	while(!q.empty())
	{
		int cv = q.front();
		q.pop();
		for(unsigned int i=0;i<graph[cv].size();i++)
		{
			int nv = graph[cv][i];
			if(dist[nv]==-1||dist[nv]>dist[cv]+1)
			{
				dist[nv] = dist[cv] + 1;
				pre[nv] = cv;//부모 저장
				q.push(nv);
			}
		}
	}
}
int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	cin >> N >> K;
	graph.resize(N + 1);
	memset(value, 0, sizeof(value));
	for(int i=1;i<=N;i++)
	{
		cin >> code[i];
		int num = 1;
		for(int j=K-1;j>=0;j--)//10진수로 변환해서 저장하는 부분
		{
			value[i] += (code[i][j]-'0') * num;
			num *= 2; 
		}
		h[value[i]] = i;
		for(int j=0;j<K;j++) //비트 하나씩 바꿔가면서 찾아봄
		{
			if (h.find(value[i] ^ (1 << j)) == h.end())continue; //xor 연산으로 찾는다
			else
			{
				int ni = h[value[i] ^ (1 << j)];
				graph[i].push_back(ni);
				graph[ni].push_back(i);
			}
		}
	}//입력 및 그래프 만들기
	memset(dist, -1, sizeof(dist));
	memset(pre, 0, sizeof(pre));
	Dijkstra();
	cin >> M;
	int j;
	while(M--)
	{
		cin >> j;
		if (dist[j] != -1)
		{
			int cnt = 0;
			result[cnt] = j;
			cnt++;
			while(pre[j])
			{
				result[cnt] = pre[j];
				cnt++;
				j = pre[j];
			}
			for(int p=cnt-1;p>=0;p--)
			{
				cout << result[p] << " ";
			}
			cout << "\n";
		}
		else cout << -1 << "\n";
	}
}
