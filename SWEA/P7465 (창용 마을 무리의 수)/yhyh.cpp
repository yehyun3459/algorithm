#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX_SIZE 101

int T, N, M;
int p[MAX_SIZE];
int cnt[MAX_SIZE];

void make_set(int x)
{
	p[x] = x;
	cnt[x] = 0; //초기화
}
int find_set(int x)
{
	if (p[x] != x)p[x] = find_set(p[x]);
	return p[x];
}
void Union(int x, int y)
{
	p[find_set(y)] = find_set(x);
}

int main()
{
	scanf("%d", &T);
	for(int tc=1;tc<=T;tc++)
	{
		scanf("%d %d", &N, &M);
		for (int i = 1; i <= N; i++)make_set(i);
		int a, b;
		for(int i=0;i<M;i++)
		{
			scanf("%d %d", &a, &b);
			Union(a, b);
		}

		int result = 0;
		for(int i=1;i<=N;i++)
		{
			find_set(i); //한번 더 대표 노드를 가리키도록 
			if(!cnt[p[i]])
			{
				cnt[p[i]] = 1;
				result++;
			}
		}
		printf("#%d %d\n", tc, result);
	}
}
