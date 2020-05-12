//정올 원숭이 사냥 문제
//정올에서는 돌아가는 소스가 백준에서는 계속 시간초과가 나서 아래와 같이 수정함 ㅠㅠㅠ 이유는 모르겠음

#include <iostream>
#include <queue>
#include <cstring>
#include <stack>
using namespace std;

#define MAXN 21 //22로 하면 백준에서 시초남 (왜???;;;)
int N, M;
int adj[MAXN]; //인접한 간선들을 전부 비트 처리함
bool visited[1 << MAXN];//헷갈려... 현재 원숭이가 살아있는 상태
int pre[1 << MAXN][2]; //이전 상태와 인덱스 참조

bool BFS()
{
	queue<int> q;
	q.push((1 << N) - 1);
	visited[(1 << N) - 1] = 1;
	while(!q.empty())
	{
		int cs = q.front();//현재 살아있는 원숭이
		q.pop();
		for(int i=0;i<N;i++)//모든 나무들을 뒤져보자!
		{
			if(cs&(1<<i))//i번째 나무에 원숭이가 존재함
			{
				int ns = 0;
				for(int j=0;j<N;j++) //현재 상태(i번째 원숭이 죽음)에서 원숭이들이 인접한 곳으로 이동함
				{
					//현재 상태에서 j번째 나무에 원숭이가 존재할때 j나무의 인접한 나무로 이동한다
					//따라서 모든 가능한 상태를 ns에 넣어버리는거! (아 헷갈려)
					if (cs & (1 << j)&&(i!=j))ns |= adj[j]; 
				}
				if (visited[ns])continue; //이미 방문했음
				visited[ns] = 1;
				pre[ns][0] = cs; //이전 원숭이들 상태를 저장함
				pre[ns][1] = i; //이전에 쏘았던 나무 인덱스 저장
				q.push(ns);
				if (!ns)return true;

			}
		}
	}
	return false;
}


int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	while(true)
	{
		cin >> N >> M;
		if (!N && !M)break;
		int a, b;
		memset(adj, 0, sizeof(adj));
		memset(visited, 0, sizeof(visited));
		memset(pre, 0, sizeof(pre));
		
		while(M--)
		{
			cin >> a >> b;
			adj[a] |= (1 << b);
			adj[b] |= (1 << a);
		}

		if (M > N - 1)
		{
			cout<<"Impossible\n";
			continue;
		}
		if (BFS())
		{
			stack<int> result; //재귀로 출력하면 시초남 ㅠㅠㅠㅠ 승질나아앜
			int state = 0;
			while(state!=((1<<N)-1))
			{
				result.push(pre[state][1]);
				state = pre[state][0];
			}
			cout << result.size() << ": ";
			while(!result.empty())
			{
				cout << result.top() << " ";
				result.pop();
			}
			cout << "\n";
		}
		else cout << "Impossible\n";
	}

}
