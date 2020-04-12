#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;

#define MIN(a,b)(a<b?a:b)
int N, M;
char board[51][51];
int visited[50][50][1<<7];//키의 유무를 비트연산으로 저장
int minV = 987654321;

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int sr,sc;
//BFS로 다시 짜보자(DFS로는 잘 안되넹)

struct Info
{
	int row;
	int col;
	int key;
	int dist;
};

void BFS()
{
	queue<Info> q;
	q.push({ sr,sc,0,0 });
	while(!q.empty())
	{
		int cr = q.front().row;
		int cc = q.front().col;
		int ck = q.front().key;
		int cd = q.front().dist;
		q.pop();

		if (board[cr][cc] == '1') //도달했을 때 최솟값 저장
		{
			minV = MIN(minV, cd);
			continue;
		}

		for(int d=0;d<4;d++)
		{
			int nr = cr + dx[d];
			int nc = cc + dy[d];
			if (nr < 0 || nr >= N || nc < 0 || nc >= M)continue;
			if (visited[nr][nc][ck])continue;
			if (board[nr][nc] == '.' || board[nr][nc] == '1')
			{
				visited[nr][nc][ck] = 1;
				q.push({ nr,nc,ck,cd + 1 });
			}
			else if (board[nr][nc] >= 'A' && board[nr][nc] <= 'F' && (ck & (1 << (board[nr][nc] - 'A')))) //문에 도달했는데 키가 있다면
			{
				visited[nr][nc][ck] = 1;
				q.push({ nr,nc,ck,cd + 1 });
			}
			else if (board[nr][nc] >= 'a' && board[nr][nc] <= 'f') //키를 발견했당 키 줍줍
			{
				visited[nr][nc][ck] = 1;
				q.push({ nr, nc,  ck | (1 << (board[nr][nc] - 'a')),cd + 1 }); //비트연산 할때 괄호 조심..
			}
		}
	}
}

int main()
{
	scanf("%d %d", &N, &M);

	for(int i=0;i<N;i++)
	{
		for(int j=0;j<M;j++)
		{
			scanf(" %c", &board[i][j]);
			if(board[i][j]=='0')
			{
				sr = i, sc = j; //시작점
				board[i][j] = '.';
			}
		}
	}
	memset(visited, 0, sizeof(visited));
	BFS();
	
	if (minV == 987654321)minV = -1;
	printf("%d\n", minV);
}
