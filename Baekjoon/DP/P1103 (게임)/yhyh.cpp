//메모이제이션 dp(BFS로 하려다가 계~~~속 틀림) 정석대로 풀자

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define MAX_SIZE 50
#define MAX(a,b)(a>b?a:b)

int N, M;
int arr[MAX_SIZE][MAX_SIZE];
int dp[MAX_SIZE][MAX_SIZE];
int visited[MAX_SIZE][MAX_SIZE];

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

int Solve(int x,int y)
{
	if (x < 0 || x >= N || y < 0 || y >= M)return 0;
	if (arr[x][y] == -1)return 0;
	if (visited[x][y]) return -1; //가는 길목에 사이클을 체크해 주어야 하니까... 그래서 BFS로 하기에는 힘든듯
	if (dp[x][y])return dp[x][y];
	visited[x][y] = 1;
	for(int d=0;d<4;d++)
	{
		int tmp = Solve(x + dx[d] * arr[x][y], y + dy[d] * arr[x][y]);
		if (tmp == -1)return -1; //응 사이클~
		dp[x][y] = MAX(dp[x][y], tmp + 1);
	}
	visited[x][y] = 0;
	return dp[x][y];
}
int main()
{ 
	char tmp;
	scanf("%d %d", &N, &M);
	for(int i=0;i<N;i++)
	{
		for (int j = 0; j < M; j++)
		{
			scanf(" %c", &tmp);
			if (tmp == 'H')arr[i][j] = -1;
			else arr[i][j] = tmp - '0';
		}
	}
	memset(visited, 0, sizeof(visited));
	memset(dp, 0, sizeof(dp));
	printf("%d\n",Solve(0,0));
	
}
