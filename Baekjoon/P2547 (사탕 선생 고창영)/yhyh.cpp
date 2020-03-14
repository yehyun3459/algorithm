//3년전에 틀린 문제 와아^0^
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef long long ll;
int T, N;

int main()
{
	scanf("%d", &T);
	for(int tc=1;tc<=T;tc++)
	{
		scanf("%d", &N);
		ll total = 0;
		ll tmp = 0;
		for(int i=0;i<N;i++)
		{
			scanf("%lld", &tmp); //scanf에서 long long으로 받을때는 lld란다....
			tmp = tmp % N; //입력 받을때도 한번 %연산 해주어야 더하기 연산에서 오버플로 발생 안함
			total = (total + tmp) % N; //물론 더하고 나서도 나눠주어야 겠징
		}
		if (total % N==0)
		{
			printf("YES\n"); //3년전에 yes로 출력을 해서 틀렸던 거였음 ㅋㅋㅋㅋ 왜 몰랐던 거야...
		}
		else printf("NO\n");
	}
	return 0;
}
