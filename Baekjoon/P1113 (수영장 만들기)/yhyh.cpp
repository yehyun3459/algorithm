//문제보고 3시간 멍때림....
//풀이방법은 다음과 같다.
//1. BFS로 높이가 같은 공간을 구함(약간 섬 개수 구하기 문제처럼)
//2. 같은 구역의 공간(같은 높이)의 테두리가 다 높거나 같을때 체크한 후, 기존 높이 + 1을 해준다.
//3. 더이상 높이가 높아지지 않을때까지 1-2를 반복한다.

#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
#define MAX_SIZE 52
#define MAX(a,b)(a>b?a:b)

int N, M;
int board[MAX_SIZE][MAX_SIZE];
int chk[MAX_SIZE][MAX_SIZE];

int invalid[2501];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

void checkNum(int maxN)
{
	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=M;j++)
		{
			if (invalid[chk[i][j]])continue;
			for(int d=0;d<4;d++)
			{
				int ni = i + dx[d];
				int nj = j + dy[d];
				if (chk[ni][nj] == chk[i][j] || board[ni][nj] >= board[i][j]) continue;
				else invalid[chk[i][j]] = 1;
			}
		}
	}
}

void setNum(int r,int c,int num) //BFS로 연결된 섬을 구함
{
	queue<pair<int, int>> q;
	q.push({ r,c });
	chk[r][c] = num;
	while(!q.empty())
	{
		int cr = q.front().first;
		int cc = q.front().second;
		q.pop();
		for(int d=0;d<4;d++)
		{
			int nr = cr + dx[d];
			int nc = cc + dy[d];
			if (board[nr][nc]==board[cr][cc]&&chk[nr][nc]==0)
			{
				chk[nr][nc] = num;
				q.push({ nr,nc });
			}
			
		}
	}

}

int main()
{
	scanf("%d %d", &N, &M);
	memset(board, 0, sizeof(board));
	char tmp;
	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=M;j++)
		{
			scanf(" %c", &tmp);
			board[i][j] = tmp - '0';
		}
	}
	int result = 0;
	
	while(true)
	{
		int tsum = 0;
		memset(chk, 0, sizeof(chk));
		int num = 1;
		for(int i=1;i<=N;i++)
		{
			for(int j=1;j<=M;j++)
			{
				if(!chk[i][j])
				{
					setNum(i,j,num);
					num++;
				}
			}
		}
		memset(invalid, 0, sizeof(invalid));
		checkNum(num - 1);
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= M; j++)
			{
				if(!invalid[chk[i][j]])
				{
					board[i][j]++;
					tsum++;
				}
			}
		}
		if (!tsum)break;
		result += tsum;
	}
	
	printf("%d\n", result);

	return 0;
}
