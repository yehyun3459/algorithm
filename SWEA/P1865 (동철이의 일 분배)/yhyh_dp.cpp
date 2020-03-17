#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define MAX(a,b)(a>b?a:b)
int T, N;
double P[17][17]; //16+1을 해주어야 오류가 안남..(visual에서는 잘 돌아가는데..? 이래서 리눅스를 써야한다)

double dp[17][1 << 17];

double Solve(int c,int v)
{
	if (dp[c][v] > 0)return dp[c][v];
	if(c>=N) //전부 선택 했을 때! (v==(1<<N)-1)해주어도 상관없음
	{
		return 1;
	}
	dp[c][v] = 0;
	for(int i=0;i<N;i++)
	{
		if (v & (1 << i))continue;
		//c번째 직원이 선택 완료했으니까 그 다음은 c+1이 되어야겠지...?
		dp[c][v] = MAX(dp[c][v], Solve(c + 1, (v | (1 << i))) * P[c][i]); //헷갈리지 말자 ㅠㅠㅠ
	}
	return dp[c][v];
}

int main()
{
	scanf("%d", &T);
	for(int tc=1;tc<=T;tc++)
	{
		scanf("%d", &N);
		memset(dp, 0, sizeof(dp));
		double tmp;
		for(int i=0;i<N;i++)
		{
			for(int j=0;j<N;j++)
			{
				scanf("%lf", &tmp);
				P[i][j] = tmp / 100;
			}
		}
		printf("#%d %.6lf\n", tc,Solve(0, 0)*100);
	}
}
