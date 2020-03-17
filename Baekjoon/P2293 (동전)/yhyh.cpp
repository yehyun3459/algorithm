#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define MIN(a,b)(a<b?a:b)
#define INF 987654321
int d[101]; //동전
int cost[10001];

int main()
{
	int N, K;
	scanf("%d %d", &N, &K);
	
	memset(cost, 0, sizeof(cost));
	
	for (int i = 1; i <= N; i++)
	{
		scanf("%d", &d[i]);
	}
	cost[0] = 1; //아무것도 선택되지 않은 케이스 1?
  //아래의 점화식은 다음과 같음
  //ex 10의 결과값이 있고, 1,2,5의 동전의 합으로 이루어진다면
  //10은 9에서 1이 더해진 값, 또는 8에서 2가 더해진 값, 또는 5에서 5가 더해진 값...
  //cost[N]=cost[N-1]+cost[N-2]+cost[N-5] .... 이렇게 됨
  //따라서 아래와 같이 구현하였다
	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=K;j++)
		{
			if (j >= d[i]) //당연하지만 현재 j값이 동전보다 클때 경우의 수를 더해준다
				cost[j] += cost[j - d[i]];
		}
	}
	printf("%d\n", cost[K]);
}
