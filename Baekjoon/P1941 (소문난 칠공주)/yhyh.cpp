#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

char board[5][5];
int chk[5][5];
int tmp[5][5];

int sel[7]; //일차 배열로 해서....모르겠다 젠장
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

int result = 0;

void Solve(int r, int c)
{
	memset(tmp, 0, sizeof(tmp));
	queue<pair<int, int>> q;
	q.push({ r,c });
	int cnt = 0;
	tmp[r][c] = 1;
	while (!q.empty())
	{
		int cr = q.front().first;
		int cc = q.front().second;
		cnt++;
		q.pop();
		for (int d = 0; d < 4; d++)
		{
			int nr = cr + dx[d];
			int nc = cc + dy[d];
			if (nr < 0 || nr >= 5 || nc < 0 || nc >= 5)continue;
			if (tmp[nr][nc])continue;
			tmp[nr][nc] = 1;
			if (chk[nr][nc])q.push({ nr,nc });
		}
	}
	if (cnt == 7)result++;
}

void DFS(int start, int cnt, int scnt, int ycnt)
{
	if (ycnt >= 4)return;
	if (cnt >= 7)
	{
		Solve(sel[0] / 5, sel[0] % 5);
		return;
	}
	for (int i = start; i < 25; i++)
	{
		sel[cnt] = i;
		chk[i / 5][i % 5] = 1;
		if (board[i / 5][i % 5] == 'S')DFS(i + 1, cnt + 1, scnt + 1, ycnt);
		else DFS(i + 1, cnt + 1, scnt, ycnt + 1);
		chk[i / 5][i % 5] = 0;
	}
}

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)cin >> board[i][j];
	}
	memset(chk, 0, sizeof(chk));

	DFS(0, 0, 0, 0);

	cout << result << "\n";
}
