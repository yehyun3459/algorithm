//문제를 제대로 안봐서 한참 헤맴..
//1. 지우 순서 정함(순열)
//2. 가위바위보 시뮬레이션 후 이기는지 확인
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int N, K;
int A[10][10];

int rps[3][20];

int visited[10];

int win[3]; //승리한 횟수
bool isValid = false;

bool Solve()
{
	memset(win, 0, sizeof(win));
	int p1 = 0, p2 = 1; //초기 플레이어
	int tops[3] = { 0,0,0 };

	int cmp1, cmp2;
	while(true)
	{
		if(win[0]==K||win[1]==K||win[2]==K||tops[0]>=N)break; //더이상 수행할 필요 없음
		
		cmp1 = rps[p1][tops[p1]];
		cmp2 = rps[p2][tops[p2]];
		tops[p1]++;
		tops[p2]++;
		if(A[cmp1][cmp2]==2||(A[cmp1][cmp2]==1&&p1>p2))//p1이 이김
		{
			win[p1]++;
			p2 = 3 - (p1 + p2);
		}
		else //p2가 이김
		{
			win[p2]++;
			p1 = 3 - (p1 + p2);
		}
		
	}
	if (win[0] >= K)return true;
	else return false;
}

void makeSequence(int cnt)//지우의 순서 정하기
{
	if (isValid)return;
	if(cnt>=N)
	{
		if (Solve())isValid = true;
		return;
	}
	for(int i=1;i<=N;i++)
	{
		if (visited[i])continue;
		visited[i] = 1;
		rps[0][cnt] = i;
		makeSequence(cnt + 1);
		visited[i] = 0;
	}
}

int main()
{

	scanf("%d %d", &N, &K);
	for(int i=1;i<=N;i++)
	{
		for (int j = 1; j <= N; j++)scanf("%d", &A[i][j]);
	}
	memset(rps, 0, sizeof(rps));
	for (int i = 0; i < 20; i++)scanf("%d", &rps[1][i]);
	for (int i = 0; i < 20; i++)scanf("%d", &rps[2][i]);
	makeSequence(0);

	if (isValid)printf("%d\n", 1);
	else printf("%d\n", 0);
}
