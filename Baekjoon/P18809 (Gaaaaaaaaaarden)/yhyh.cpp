//모르겠다.. 잘 짠 코드는 아닌데 일단 백업해둠
//겨우겨우 통과했는데 나중에 시간을 좀 
//맨 처음 배양액 예외처리를 안해줌 ㅠ

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

queue<pair<int, int>> Gq;
queue<pair<int, int>> Rq;
int num[2]; //배양액
int visited[11];
int Sel[11][3];
int N, M, G, R;
int maxV = 0;

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };


void Spread()
{
	int u_time = 0;
	int flo = 0;
	while (!Gq.empty() || !Rq.empty())
	{
		u_time++;
		queue<pair<int, int>> nGq;
		queue<pair<int, int>> nRq;
		//초록색 먼저

		while (!Gq.empty())
		{
			int cr = Gq.front().first;
			int cc = Gq.front().second;

			Gq.pop();
			if (dp[cr][cc][0] == FLOWER)continue;
			for (int d = 0; d < 4; d++)
			{
				int nr = cr + dx[d];
				int nc = cc + dy[d];
				if (nr < 0 || nr >= N || nc < 0 || nc >= M)continue;
				if (board[nr][nc] && dp[nr][nc][0] == 0)
				{
					dp[nr][nc][0] += GREEN;
					dp[nr][nc][1] = u_time;
					nGq.push({ nr,nc });
				}

			}
		}
		swap(Gq, nGq);

		//빨간색 다음
		while (!Rq.empty())
		{
			int cr = Rq.front().first;
			int cc = Rq.front().second;
			Rq.pop();
			if (dp[cr][cc][0] == FLOWER)continue;
			for (int d = 0; d < 4; d++)
			{
				int nr = cr + dx[d];
				int nc = cc + dy[d];
				if (nr < 0 || nr >= N || nc < 0 || nc >= M)continue;
				if (board[nr][nc] && dp[nr][nc][0] == 0)
				{
					dp[nr][nc][0] += RED;
					dp[nr][nc][1] = u_time;
					nRq.push({ nr,nc });
				}
				if(board[nr][nc]&&dp[nr][nc][0]==GREEN&&dp[nr][nc][1]==u_time)
				{
					dp[nr][nc][0] += RED;
					flo++; //그냥 여기서 체크해버리면 됨, 배열 한번 더 탐색할 필요 없음
					dp[nr][nc][1] = u_time;
				}
			}
		}
		swap(Rq, nRq);
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
			dp[Sel[i][1]][Sel[i][2]][1] = 0; //굳이 해줄 필요 없나..?
			if (Sel[i][0] == GREEN)
			{
				dp[Sel[i][1]][Sel[i][2]][0] = GREEN;
				Gq.push({ Sel[i][1],Sel[i][2] });
			}
			else
			{
				dp[Sel[i][1]][Sel[i][2]][0] = RED;
				Rq.push({ Sel[i][1],Sel[i][2] });
			}
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
