//대체 문제 해결법이 뭔가 궁금했었는데
//kmp를 이용해서 dp로 푸는거였다..
//그러니까 fail function을 이용해서 그 이전 인덱스를 계속 참조해서 접미사==접두사인 최소 길이를 찾음

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define MIN(a,b)((a)<(b)?(a):(b))
#define INF 987654321
typedef long long ll;

char buffer[1000001];
int fail[1000001];
int dp[1000001];
ll sum = 0;
int sLen;

void make_fail()//fail function
{
	int j = 0;
	int i = 1;
	while(i<sLen)
	{
		if(buffer[j]==buffer[i])
		{
			fail[i] = j + 1;
			j++;
			i++;
		}
		else if(j>0)
		{
			j = fail[j - 1];
		}
		else
		{
			fail[i] = 0;
			i++;
		}
	}	
}

int Solve(int idx) //반복되는 경우에 그 부분을 다시 참조한다
{
	if (idx < 0)return INF;
	if (fail[idx] == 0)return INF;
	if (dp[idx] != -1)return dp[idx];
	dp[idx] = 0;

	dp[idx] = MIN(fail[idx], Solve(fail[idx] - 1));
	return dp[idx];
}

int main()
{
	memset(buffer, 0, sizeof(buffer));
	memset(fail, 0, sizeof(fail));
	memset(dp, -1, sizeof(dp));
	scanf("%d", &sLen);
	scanf("%s", buffer);

	make_fail();
	//prefix와 suffix가 같음을 이용하자 못해먹겠네
	for(int i=1;i<sLen;i++)
	{
		int ret = Solve(i);
		if(ret!=INF)
		{
			sum += (ll)(i + 1 - ret);
		}
		
	}
	printf("%lld",sum);
	
}
