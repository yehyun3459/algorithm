//쉬운 조합 만들기 문제
//오랜만이라 헷갈리넹
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
int sel[6];
int arr[13];

int k;
void DFS(int start,int cnt)
{
	if(cnt>=6)
	{
		printf("%d", sel[0]);
		for(int i=1;i<6;i++)
		{
			printf(" %d", sel[i]);
		}
		printf("\n");
		return;
	}
	for(int i=start;i<k;i++)
	{
		sel[cnt] = arr[i];
		DFS(i + 1, cnt + 1);
	}
}

int main()
{
	while(true)
	{
		scanf("%d", &k);
		if (!k)break;
		for (int i = 0; i < k; i++)scanf("%d", &arr[i]);
		DFS(0, 0);
		printf("\n");
	}
	
	return 0;
}
