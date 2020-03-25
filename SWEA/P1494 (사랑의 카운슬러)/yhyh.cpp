#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <math.h>
typedef long long ll;

ll INF = 2e15;
int T, N;

ll vertex[21][2];
int idx[11][2];
int visited[21];

ll dist[21][21][2];
ll minV = INF;

void Solve(int cnt,int start)//N/2만 선택하고(조합 nCn/2) 선택되지 않은 값들과 각각 매칭해줌
{
	if (cnt >= N/2)
	{
		int ltop = 0, rtop = 0;
		for(int i=0;i<N;i++)
		{
			if (visited[i]) 
			{
				idx[ltop][0] = i;
				ltop++;
			}
			else 
			{
				idx[rtop][1] = i;
				rtop++;
			}
		}
		ll tmp[2] = { 0,0 };
		for (int i = 0; i < N / 2; i++)
		{
			tmp[0] += vertex[idx[i][0]][0]-vertex[idx[i][1]][0];
			tmp[1] += vertex[idx[i][0]][1] - vertex[idx[i][1]][1];
		}
		ll cmp = tmp[0] * tmp[0] + tmp[1] * tmp[1];
		if (cmp < minV)minV = cmp;
		return;
	}

	for(int i=start;i<N;i++)
	{
		if (visited[i])continue;
		visited[i] = 1;
		Solve(cnt + 1, i + 1);
		visited[i] = 0;
	}
	
	
}
int main()
{
	//freopen("input.txt", "r", stdin);
	scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++)
	{
		scanf("%d", &N);
		minV = INF;
		memset(visited, 0, sizeof(visited));
		memset(idx, 0, sizeof(idx));
		for (int i = 0; i < N; i++)
		{
			scanf("%lld %lld", &vertex[i][0], &vertex[i][1]);

		}

		Solve(0,0);
		printf("#%d %lld\n", tc, minV);
	}
}
