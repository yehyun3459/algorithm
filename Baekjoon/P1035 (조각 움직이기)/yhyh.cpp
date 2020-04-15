//조각 움직이기 옛날에 못풀었던 문제!
//1. 새로 움직일 위치를 지정한다(조합)
//2. 연결되어있는지 확인(BFS)
//3. 최소 이동거리 확인(이거는 순열로 했는데....)
#include <iostream>
#include <queue>
#include <vector> //벡터 조아~~
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

char board[5][5];
int chk[5][5];
int visited[5][5];
int sel[5];
int psize = 0;

vector<pair<int, int>> piece;

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

int minV = 987654321;
int tmpv[5] = { 0,0,0,0,0 };
void Solve(int cnt,int diff) //위치 차이 빼기(조합안에 순열이라니 ^^;)
{
	if(cnt>=psize)
	{
		minV = min(minV, diff);
		return;
	}
	for(int i=0;i<psize;i++)
	{
		if (tmpv[i])continue;
		tmpv[i] = 1;
		int d = abs(piece[cnt].first - sel[i] / 5) + abs(piece[cnt].second - sel[i] % 5);
		Solve(cnt + 1, diff + d);
		tmpv[i] = 0;
	}
}
bool isConnected(int sr,int sc)
{
	int cnt = 0;
	memset(visited, 0, sizeof(visited));
	queue<pair<int, int>> q;
	q.push({ sr,sc });
	visited[sr][sc] = 1;
	while(!q.empty())
	{
		int cr = q.front().first;
		int cc = q.front().second;
		cnt++;
		q.pop();
		for(int d=0;d<4;d++)
		{
			int nr = cr + dx[d];
			int nc = cc + dy[d];
			if (nr < 0 || nr >= 5 || nc < 0 || nc >= 5)continue;
			if (visited[nr][nc] || !chk[nr][nc])continue;
			visited[nr][nc] = 1;
			q.push({ nr,nc });
		}
	}
	if (cnt == psize)return true;
	return false;
}
void DFS(int cnt,int start)
{
	if(cnt>=psize)
	{
		if(isConnected(sel[0]/5,sel[0]%5))
		{
			Solve(0,0);
		}
		return;
	}
	for(int i=start;i<25;i++)
	{
		chk[i / 5][i % 5] = 1;
		sel[cnt] = i;
		DFS(cnt + 1, i + 1);
		chk[i / 5][i % 5] = 0;
	}
}
int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	for(int i=0;i<5;i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cin >> board[i][j];
			if(board[i][j]=='*')
				piece.push_back({ i,j }); //원래 조각 위치 저장
		}
	}
	psize = piece.size();
	DFS(0,0);
	cout << minV << "\n";
}
