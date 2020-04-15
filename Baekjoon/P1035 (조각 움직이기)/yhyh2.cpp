#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
using namespace std;

#define MIN(a,b)((a)<(b)?(a):(b))
#define ABS(a)((a)<0?-1*(a):(a))

char board[5][5];
int chk[5][5];
int visited[5][5];
int sel[5];
int psize = 0;

int q[1000][2];
int piece[5][2];

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

int minV = 987654321;
int tmpv[5] = { 0,0,0,0,0 };
void Solve(int cnt,int diff) //위치 차이 빼기(조합안에 순열이라니 ^^;)
{
	if (diff >= minV)return;
	if(cnt>=psize)
	{
		minV = MIN(minV, diff);
		return;
	}
	for(int i=0;i<psize;i++)
	{
		if (tmpv[i])continue;
		tmpv[i] = 1;
		int d = ABS(piece[cnt][0] - sel[i] / 5) + ABS(piece[cnt][1] - sel[i] % 5);
		Solve(cnt + 1, diff + d);
		tmpv[i] = 0;
	}
}
bool isConnected(int sr,int sc)
{
	int cnt = 0;
	memset(visited, 0, sizeof(visited));
	int f = 0, r = 0;
	q[r][0] = sr;
	q[r][1] = sc;
	r++;
	visited[sr][sc] = 1;
	while(f<r)
	{
		int cr = q[f][0];
		int cc = q[f][1];
		cnt++;
		f++;
		for(int d=0;d<4;d++)
		{
			int nr = cr + dx[d];
			int nc = cc + dy[d];
			if (nr < 0 || nr >= 5 || nc < 0 || nc >= 5)continue;
			if (visited[nr][nc] || !chk[nr][nc])continue;
			visited[nr][nc] = 1;
			q[r][0] = nr;
			q[r][1] = nc;
			r++;
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
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			scanf(" %c", &board[i][j]);
			if (board[i][j] == '*')
			{
				piece[psize][0] = i;
				piece[psize][1] = j;
				psize++;
			}
		}
	}
	DFS(0, 0);
	printf("%d\n", minV);
}
