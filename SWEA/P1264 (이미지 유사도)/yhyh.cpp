//LCS(Longest common sequence) 문제
//참고 : https://www.crocus.co.kr/787
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_SIZE 501
#define MAX(a,b)(a>b?a:b)

char origin[MAX_SIZE];
char comp[MAX_SIZE];
int dp[2][MAX_SIZE];
int T, N;
double result;

void Init()
{
	origin[0] = '0';
	comp[0] = '0';
	for(int i=1;i<=N;i++)
		scanf(" %c", &origin[i]); //이렇게 입력받는게 훨씬 편함
	for (int i = 1; i <= N; i++)
		scanf(" %c", &comp[i]);

	memset(dp, 0, sizeof(dp));
}

int main()
{
	scanf("%d", &T);
	for(int tc=1;tc<=T;tc++)
	{
		scanf("%d", &N);
		Init();

		int n = strlen(origin);
		int m = strlen(comp);

		for (int i = 1; i < m; i++)
		{
			for (int j = 1; j < n; j++)
			{
				if (origin[j] == comp[i]) dp[i % 2][j] = dp[(i - 1) % 2][j - 1] + 1; //이전 문자에서 바로 다음 (+1)
				else dp[i % 2][j] = MAX(dp[(i - 1) % 2][j], dp[i % 2][j - 1]);
				//일치 하지 않은 경우에는 origin 과 comp-1까지 비교했던 경우와, origin-1와 현재 comp까지 비교한 경우 중
				//큰 값을 가져간다
				//
				//RBKBGRBGGG <--- 2번째 문자일때, RB와 B까지 비교했을때 일치하는 경우(1)와, R와 BG까지 비교한 경우(0)중 큰 값
				//BGKRBRKBGB

			}
		}
		result = double(dp[(m - 1) % 2][n - 1]) / N;
		printf("#%d %.2lf\n", tc, result*100);
	}
}
