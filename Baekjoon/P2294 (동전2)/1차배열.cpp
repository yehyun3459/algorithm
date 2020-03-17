//어려운 문제는 아니지만...

//1차 배열이 가능한 이유 :
//잔돈을 만들 수 있는 최솟값을 갱신할 때 이전 동전의 경우에만 확인함.
//즉 이전값만 cost에 저장해두고 계속 갱신해나가면 됨
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define MIN(a,b)(a<b?a:b)
#define INF 987654321
int d[101]; //동전
int cost[10001]; //아 헷갈려..

int main()
{
	int N, K;
	scanf("%d %d", &N, &K);
	
	memset(cost, 0, sizeof(cost));
	
	for (int i = 1; i <= N; i++)
	{
		scanf("%d", &d[i]);
	}
	cost[0] = 0;
	for (int i = 1; i <= K; i++)cost[i] = INF; //제일 큰 값으로 초기화

	for(int i=1;i<=N;i++) //생각하기 귀찮으니까 감싸주자
	{
		for(int j=1;j<=K;j++)
		{
			if (j >= d[i])
				cost[j] = MIN(cost[j], cost[j - d[i]] + 1);
		}
	}
	printf("%d\n", cost[K]==INF?-1:cost[K]); //동전으로 만들수 없는 경우
}
