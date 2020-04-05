//참고 : https://cooling.tistory.com/4
//요새 문제 너무 안풀림 ㅠㅠㅠ 화이팅하자..

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define MAX_SIZE 1000
#define MIN(a,b)(a<b?a:b)

int dp[MAX_SIZE][3];
int arr[MAX_SIZE][3];
int main()
{
	int N;
	scanf("%d", &N);

	memset(dp, 0, sizeof(dp));

	int minV = 987654321;
	for(int i=0;i<N;i++)
	{
		for (int j = 0; j < 3; j++)
		{
			scanf("%d", &arr[i][j]);
		}
	}

	for (int k = 0; k < 3; k++) //무조건 0번째 집은 k 색깔을 선택함
	{
		for (int i = 0; i < 3; i++) 
		{
			if (i == k) dp[0][i] = arr[0][i];//첫번째는 고정함
			else dp[0][i] = 987654321; //무조건 0번째는 i를 선택하도록
		}
		for (int i = 1; i < N; i++)
		{
			dp[i][0] = MIN(dp[i - 1][1], dp[i - 1][2]) + arr[i][0];
			dp[i][1] = MIN(dp[i - 1][0], dp[i - 1][2]) + arr[i][1];
			dp[i][2] = MIN(dp[i - 1][0], dp[i - 1][1]) + arr[i][2];

		}
		for (int i = 0; i < 3; i++) { //N-1이 0과 같으면 continue
			if (i == k) continue; 
			minV = MIN(minV, dp[N - 1][i]);
		}
	}
	
	printf("%d\n", minV);
}
