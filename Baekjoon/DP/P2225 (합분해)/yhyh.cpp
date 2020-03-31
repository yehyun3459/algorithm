//점화식은 다음과 같다.
//0은 무조건 한가지 경우 dp[0][k]=1
//1은 k의 경우를 가짐 ex) k=2, 0 1, 1 0 // dp[1][k]=k
//2이상은 다음과 같음
//k=0 dp[n][0]=1
//k>0 dp[n][k] = sum(dp[i][k-1]) {0<=i<=n}
//-->ex) n = 4, k = 4
// 0 + dp[4][3]
// 1 + dp[3][3]
// 2 + dp[2][3]
// 3 + dp[1][3]
// 4 + dp[0][3]

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

typedef long long ll;
#define MOD 1000000000

ll dp[201][201];

int N, K;
void Init()
{
	//base case 초기화
	dp[1][1] = 1; 
	for(int i=2;i<=K;i++)
	{
		dp[0][i] = 1;
		dp[1][i] = i;
	}
	for (int i = 2; i <= N; i++)
	{
		dp[i][1] = 1;
		dp[i][2] = ((ll)i%MOD + 1)%MOD;
	}
}

ll Solve(int n, int k)
{
	if (dp[n][k] != -1)return dp[n][k];
	dp[n][k] = 0;
	for(int i=0;i<=n;i++)
	{
		ll tmp = Solve(i, k-1);
		dp[n][k] = (dp[n][k]%MOD + tmp%MOD) % MOD;
	}
	return dp[n][k];
}
int main() 
{
	scanf("%d %d", &N, &K);
	memset(dp, -1, sizeof(dp));
	Init();
	printf("%lld\n", Solve(N, K));
}
