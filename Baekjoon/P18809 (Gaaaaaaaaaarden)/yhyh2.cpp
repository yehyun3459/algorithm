//맨 처음 배양액 예외처리를 안해줌 ㅠ
//큐를 굳이 2개 사용할 필요가 없었음 힝
//시간 처리만 잘 해주면 되는 문제
#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define MAX(a,b)(a>b?a:b)
#define GREEN 1 //헷갈려서...
#define RED 2
#define FLOWER 3

int board[51][51];
int dp[51][51][2]; //퍼지는 시간 표시

vector<pair<int, int>> canG;

queue<pair<int,int>> q;

int num[2]; //배양액
int visited[11];
int Sel[11][3];
int N, M, G, R;
int maxV = 0;

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };


void Spread()
{
	int flo = 0;
	while (!q.empty())
	{

		int cr = q.front().first;
		int cc = q.front().second;
		//int ccol = q.front().color;
		//int ct = q.front().time;
		q.pop();
		if (dp[cr][cc][0] == FLOWER)continue;
		for (int d = 0; d < 4; d++)
		{
			int nr = cr + dx[d];
			int nc = cc + dy[d];
			int nt = dp[cr][cc][1] + 1;
			if (nr < 0 || nr >= N || nc < 0 || nc >= M)continue;
			if (board[nr][nc])
			{
				if(dp[nr][nc][0]==0)
				{
					dp[nr][nc][0] += dp[cr][cc][0];
					dp[nr][nc][1] = nt;
					q.push({ nr,nc });
				}
				else if((dp[nr][nc][0]+dp[cr][cc][0]==FLOWER)&&nt==dp[nr][nc][1])
				{
					dp[nr][nc][0] += dp[cr][cc][0];
					dp[nr][nc][1] = nt;
					flo++;
				}
			}

		}
		
		
	}
	maxV = MAX(flo, maxV);

}
void makeSeq(int cnt, int start)
{
	if (cnt >= (G + R))
	{
		memset(dp, 0, sizeof(dp));
		for (int i = 0; i < G + R; i++)
		{
			dp[Sel[i][1]][Sel[i][2]][0] = Sel[i][0]; //색깔
			dp[Sel[i][1]][Sel[i][2]][1] = 0; //시간
			q.push({ Sel[i][1],Sel[i][2]});
		}
		Spread();
	}
	else
	{
		if (num[0])
		{
			for (unsigned int i = start; i < canG.size(); i++) //초록색 먼저
			{
				if (visited[i])continue;
				visited[i] = 1;
				Sel[cnt][0] = GREEN;
				num[0]--;


				Sel[cnt][1] = canG[i].first;
				Sel[cnt][2] = canG[i].second;
				if (num[0])
					makeSeq(cnt + 1, i + 1);
				else makeSeq(cnt + 1, 0);
				num[0]++;
				visited[i] = 0;
			}
		}
		else
		{
			for (unsigned int i = start; i < canG.size(); i++)
			{
				if (visited[i])continue;
				visited[i] = 1;
				Sel[cnt][0] = RED;
				num[1]--;


				Sel[cnt][1] = canG[i].first;
				Sel[cnt][2] = canG[i].second;
				makeSeq(cnt + 1, i + 1);
				num[1]++;
				visited[i] = 0;
			}
		}

	}
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N >> M >> G >> R;

	num[0] = G;
	num[1] = R;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> board[i][j];
			if (board[i][j] == 2)canG.push_back({ i,j }); //일단 입력 받고...
		}
	}
	//1. 일단 시작점을 만들자
	makeSeq(0, 0);
	cout << maxV << "\n";
}
