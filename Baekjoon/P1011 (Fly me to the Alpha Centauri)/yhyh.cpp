//규칙을 찾아야 하는 문제
//직접 그려서 보면 편하다...
//반복문, 재귀, 큐 등등 다 해봤는데 값의 범위가 너무 커서 그걸로는 해결 불가능함
//(나중에 설명 추가하자...)
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
using namespace std;
typedef long long ll;
int main()
{
	int T;
	scanf("%d", &T);
	while(T--)
	{
		ll x, y;
		scanf("%lld %lld", &x, &y);
		y = y - x;
		
		ll result = 0;
		ll i = 1;
		while (i * i < y)i++;
		
		ll left = (i - 1) * (i - 1);
		ll right = i * i;
		if(y>(left+right)/2)
		{
			result = i * 2 - 1;
		}
		else
		{
			result = i * 2 - 2;
		}
		printf("%lld\n", result);
	}
}
