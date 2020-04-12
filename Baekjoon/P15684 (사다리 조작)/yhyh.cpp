#include <iostream>
#include <vector>
using namespace std;

#define INF 1000000001

int N, M, H;
int minResult = INF;

int ladders[11][31];

int getDst(int src)
{
	int cindex = src;

	for (int i = 1; i <= H; i++)
	{
		if (cindex == 1) //오른쪽만 참조
		{
			if (ladders[cindex][i])cindex++; //오른쪽으로 이동
			else continue;
		}
		else if (cindex == N) //왼쪽만 참조
		{
			if (ladders[cindex - 1][i])cindex--; //왼쪽으로 이동
			else continue;
		}
		else //좌, 우 모두 참조해야함
		{
			if (ladders[cindex - 1][i])cindex--; //왼쪽으로 이동
			else if (ladders[cindex][i])cindex++; //오른쪽으로 이동
			else continue;
		}
	}
	return cindex;
}

void DFS(int count, int size, int sn, int sh)
{
	if (count >= size)
	{
		for (int n = 1; n <= N; n++)
		{
			if (getDst(n) != n)return;
		}
		minResult = size;
		return;
	}
	for (int n = sn; n < N; n++)
	{
		int h = 1;
		//if (n == sn)h = sh + 1; //왜 이렇게 했었지? 이거때문에 틀림
		//else h = 1;
		for (; h <= H; h++)
		{
			if (ladders[n][h])continue;
			else
			{
				if (n == 1 && ladders[n][h])continue; //오른쪽만 검사
				else if (n == N - 1 && ladders[n - 1][h])continue; //왼쪽만 검사
				else
				{
					if (ladders[n][h] || ladders[n - 1][h])continue; //양방향 검사
				}

				ladders[n][h] = 1;
				DFS(count + 1, size, n, h);
				ladders[n][h] = 0;
			}
		}
	}
}


int main()
{

	cin >> N >> M >> H;

	//ladders.resize(N, vector<bool>(H + 1, false)); //(N-1 까지 저장됨 --> 1인덱스부터 시작하더라도....)

	for (int m = 0; m < M; m++)
	{
		int src, height;
		cin >> height >> src;
		ladders[src][height] = 1;
	}

	int n = 1;
	for (; n <= N; n++)
	{
		if (getDst(n) != n)break;
	}
	if (n > N)minResult = 0;

	if (minResult == INF) DFS(0, 1, 1, 1);
	if (minResult == INF) DFS(0, 2, 1, 1);
	if (minResult == INF) DFS(0, 3, 1, 1);

	if (minResult == INF)minResult = -1;
	cout << minResult << '\n';
	return 0;
}
