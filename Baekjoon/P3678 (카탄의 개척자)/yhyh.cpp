//음 메모리가 간당간당하게 가능
//이렇게 풀면 안될것 같은데..ㅋㅋㅋㅋ
//풀리긴 하지만 다른 방법을 좀 알아보자
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

char board[10001][10001];

int dx[6] = { -1,-2,-1,1,2,1 };
int dy[6] = { 1,0,-1,-1,0,1 };
int cnt[6] = { 0,0,0,0,0,0 };
int xx[6] = { -1,-2,-1,1,2,1 };
int yy[6] = { 1,0,-1,-1,0,1 };
int solution[10001];
int Q[201];
int main()
{
	//freopen("input.txt", "r", stdin);
	int c;
	scanf("%d", &c);
	for (int i = 0; i < c; i++)scanf("%d",&Q[i]);
	int rotateN = 1;
	int rn = 1;
	board[5000][5000] = 1;
	int cr = 5000;
	int cc = 5000;
	int dir = 0;
	for(int i=1;i<=10000;i++)
	{
		int chk[6] = { 0,0,0,0,0,0 };
		int minV = 987654321;
		for(int d=0;d<6;d++) //보드에 가장 적게 나타난 자원을 골라야 함!
		{
			int tr = cr + xx[d];
			int tc = cc + yy[d];
			if (!board[tr][tc])continue;
			chk[board[tr][tc]] = 1;
		}
		int num = 1;
		for(int n=1;n<=5;n++)
		{
			if(!chk[n]&&minV>cnt[n])
			{
				num = n;
				minV = cnt[n];
			}
		}
		board[cr][cc] = num;
		cnt[num]++;
		solution[i] = num;

		cr = cr + dx[dir];
		cc = cc + dy[dir];
		
		rn--;
		if(!rn)
		{
			rn = rotateN;
			dir = dir + 1;
			if (dir == 1 && rotateN == 1)dir = 2;
			else if (dir == 1)rn = rn - 1;
			else if(dir==6)
			{
				dir = 0;
				rotateN++;
				rn = rotateN;
			}
		}
		
	}
	for(int i=0;i<c;i++)
	{
		printf("%d\n", solution[Q[i]]);
	}
}
