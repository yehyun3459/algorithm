//엄...큐로 하려 했는데 굳이 그렇게 할 필요가 없었다...? ㅇ_ㅇ
//그냥 계속 반복문 돌려주면서 오른쪽으로 나가는 개미들만 생각해주면 되는 문제였음
//큐로 하면 왜 틀리는걸까
//가끔 틀에서 벗어난 생각을 하는게 좋은것같다
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int chk[27];
char ant[27];
int N1, N2, T;

int main()
{
	memset(chk, 0, sizeof(chk));
	memset(ant, 0, sizeof(ant));
	scanf("%d %d", &N1, &N2);
	for (int i = N1 - 1; i >= 0; i--)
	{
		scanf(" %c", &ant[i]);
		chk[ant[i] - 'A'] = 1;
	}
	for(int i=N1;i<N1+N2;i++)
	{
		scanf(" %c", &ant[i]);
		chk[ant[i] - 'A'] = 2;
	}
	scanf("%d", &T);
	
	for(int t=0;t<T;t++)
	{
		for(int i=0;i<N1+N2-1;i++)
		{
			if((chk[ant[i]-'A']!=chk[ant[i+1]-'A'])&&chk[ant[i]-'A']==1)//하나만 바꿔야
			{
				char tmp = ant[i];
				ant[i] = ant[i + 1];
				ant[i + 1] = tmp;
				i++;
			}
		}
	}

	printf("%s\n", ant);
}
