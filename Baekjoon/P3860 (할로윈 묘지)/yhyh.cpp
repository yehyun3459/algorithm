//벨만포드 개꿀~~ 했다가 울면서 푼 문제 ㅇ<-<
//조건이 까다로워서 많이 실수했다 ㅠㅠ 그래도 혼자 풀었으니 된거야... 흑긓긓
//test data : http://pc.fdi.ucm.es/swerc/swerc09/problems.php
//문제 풀이 :
//1. 일단 그래프를 생성한다. 
// - 먼저 각 잔디들에 정점 번호를 부여함(묘비는 빼야함)
// - 귀신구멍인 경우에 먼저 그래프의 간선을 부여함 (귀신구멍인 경우에는 4방향에 있는 정점과 이웃 정점이 아님)
// - 귀신구멍이 아니면 잔디에서 인접한 잔디들과 이어줌(간선 1)
// ****이때 마지막 노드에는 간선을 주지 않는다 (아니 마지막 노드에 간선줬다가 계속 답이 안나왔음)
// ---> 문제 조건 : 출구에 도달하면 뒤도 돌아보지 않고 그 즉시 묘지를 빠져나갈 생각이다 (따라서 출구에서 또 이동하면 안됨)
//2. 벨만포드 알고리즘으로 문제 해결
//**주의해야 할 점
//(1) 위에도 적었지만, 마지막 노드에서 움직이면 안됨. 즉 그래프 만들면서 마지막 노드에 이웃 정점 추가하면 안됨
//(2) 행 순서**** 이거 짜증... 근데 그냥 board[R][C]가 아니라 board[H-1-R][C]로 입력받으면 해결됨
//(3) 벨만포드는 음수사이클이 발생할 수 있기 때문에 언더플로를 조심해야함 (타임머신 문제 이거때문에 틀림)
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
using namespace std;

#define INF 987654321
typedef long long ll; //벨만포드는 음수 사이클 경우에 언더플로 날 수가있음 ㅠㅠ
vector<vector<pair<int, ll>>> graph;
int board[31][31];
int W, H;
int G;
int C, R;
int E;
int C1, R1, C2, R2, T; //이름 헷갈려
int vSize = 0; //정점 개수
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

void BellmanFord()
{
	vector<ll> upper(vSize, INF);
	upper[0] = 0;
	ll minV = INF;
	if(graph[0].size()>0)//혹시 모르니까
	{
		bool updated = false;
		for(int n=0;n<vSize;n++)//모든 정점의 개수만큼 업데이트
		{
			updated = false;
			for(int v=0;v<vSize;v++)
			{
				if (upper[v] == INF)continue; //현재 정점은 출발지로부터의 경로가 존재하지 않으므로 여기서 뻗어나가면 안됨(이것도 실수했음)
				for(unsigned int i=0;i<graph[v].size();i++)
				{
					int nv = graph[v][i].first;
					ll dist = graph[v][i].second;
					if(upper[nv]>upper[v]+dist)
					{
						upper[nv] = upper[v] + dist;
						updated = true;
					}
				}
			}
			if (!updated)break;
		}
		if(updated)//음수 사이클 존재
		{
			cout << "Never\n";
			return;
		}
	}
	if (upper[vSize - 1] == INF)cout << "Impossible\n";
	else cout << upper[vSize - 1] << "\n";
}
int main()
{
	//freopen("input.txt", "r", stdin);
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	while(true)
	{
		memset(board, 0, sizeof(board));
		graph.clear();
		cin >> W >> H;
		if (!W && !H)break;
		graph.resize(W*H);
		cin >> G;
		while(G--)
		{
			cin >> C >> R;
			board[H-1-R][C] = -1; //으 행 순서 진심...
		}
		vSize = 0;
		for (int i = H-1; i >= 0; i--)
		{
			for (int j = 0; j < W; j++)
			{
				if (board[i][j] == -1)continue;
				board[i][j] = vSize;
				vSize++; //그래프 정점 개수
			}
		}
		cin >> E;
		while(E--)
		{
			cin >> C1 >> R1 >> C2 >> R2 >> T;
			graph[board[H-1-R1][C1]].push_back({ board[H-1-R2][C2],T }); //귀신 구멍인 경우 이어줌(유향)
		}
		//그래프 만들기
		for (int i = 0; i < H; i++)
		{
			for (int j = 0; j < W; j++)
			{
				if (board[i][j] == -1)continue;
				if (graph[board[i][j]].size() > 0)continue;//귀신구멍인 경우 패스 (귀신구멍인 경우 목적지로만 감)
				if (board[i][j] == vSize - 1)continue;//마지막 노드에서는 더 움직이지 않는다
				for(int d=0;d<4;d++)
				{
					int ni = i + dx[d];
					int nj = j + dy[d];
					if (ni < 0 || ni >= H || nj < 0 || nj >= W)continue;
					if (board[ni][nj] == -1)continue;
					graph[board[i][j]].push_back({ board[ni][nj],1 });
				}
			}
		}
		BellmanFord();
	}
}
