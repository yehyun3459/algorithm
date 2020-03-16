//문제 접근 : 
//KMP Fail 함수를 구해서,
//접두사 == 접미사 부분의 길이를 빼주는 문제
//문제 파악을 제대로 안했음.. ㅎㅎ
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX_SIZE 1000001
#define MIN(a,b)(a<b?a:b)

int L;
char buffer[MAX_SIZE];
int F[MAX_SIZE + 1];

void make_fail()
{
	int i = 0;
	int j = -1;
	F[0] = -1;
	while(i<L)
	{
		while (j > -1 && buffer[i] != buffer[j])
			j = F[j];
		i++, j++;
		F[i] = j;
		
	}
}

int main()
{
	scanf("%d", &L);
	scanf("%s", buffer);
	buffer[L] = '\0';
	make_fail();

	printf("%d\n", L-F[L]);
}
