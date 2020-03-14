//disjoint-set으로 풀었는데 플로이드 문제인가..?

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX_SIZE 101

int p[MAX_SIZE];

void make_set(int x)
{
	p[x] = x;
}

int find_set(int x)
{
	if (p[x] != x)p[x] = find_set(p[x]);
	return p[x];
}
void Union(int x,int y)
{
	p[find_set(y)] = find_set(x);
}
int main()
{
	int N, M;
	scanf("%d", &N);
	scanf("%d", &M);

	for (int i = 1; i <= N; i++)make_set(i);
	
	int a, b;
	for(int i=0;i<M;i++)
	{
		scanf("%d %d", &a, &b);
		Union(a, b);
	}
	int cnt = 0;
	find_set(1); //한번 더 갱신
	int flag = p[1]; //1번 노드가 속한 집합의 대표를 가리킴
	for(int i=2;i<=N;i++)
	{
		find_set(i); //한번 더 갱신
		if (p[i] == flag)cnt++;
	}
	printf("%d\n", cnt); //1번 컴퓨터는 제외하고 출력

	return 0;
}
