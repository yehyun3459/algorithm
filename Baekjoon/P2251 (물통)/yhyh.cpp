#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int A, B, C;
bool cnt[201];
bool visited[201][201][201];

struct Info
{
	int _A;
	int _B;
	int _C;
};
void Solve()
{
	queue<Info> q;
	q.push({ 0,0,C });
	visited[0][0][C] = 1;
	while (!q.empty())
	{
		int a = q.front()._A;
		int b = q.front()._B;
		int c = q.front()._C;
		q.pop();
		if (!a)cnt[c] = 1;

		//a가 b또는 c에게 붓는다
		if (a && b != B)
		{
			if (a + b > B)
			{
				if (!visited[a - (B - b)][B][c])
				{
					visited[a - (B - b)][B][c] = 1;
					q.push({ a - (B - b),B,c });
				}
			}
			else
			{
				if (!visited[0][a + b][c])
				{
					visited[0][a + b][c] = 1;
					q.push({ 0,a + b,c });
				}
			}

		}
		if (a && c != C)
		{
			if (a + c > C)
			{
				if (!visited[a - (C - c)][b][C])
				{
					visited[a - (C - c)][b][C] = 1;
					q.push({ a - (C - c),b,C });
				}
			}
			else
			{
				if (!visited[0][b][a + c])
				{
					visited[0][b][a + c] = 1;
					q.push({ 0,b,a + c });
				}
			}
		}
		//b
		if (b && a != A)
		{
			if (b + a > A)
			{
				if (!visited[A][b - (A - a)][c])
				{
					visited[A][b - (A - a)][c] = 1;
					q.push({ A,b - (A - a),c });
				}
			}
			else
			{
				if (!visited[a + b][0][c])
				{
					visited[a + b][0][c] = 1;
					q.push({ a + b,0,c });
				}
			}
		}
		if (b && c != C)
		{
			if (b + c > C)
			{
				if (!visited[a][b - (C - c)][C])
				{
					visited[a][b - (C - c)][C] = 1;
					q.push({ a,b - (C - c),C });
				}
			}
			else
			{
				if (!visited[a][0][b + c])
				{
					visited[a][0][b + c] = 1;
					q.push({ a,0,b + c });
				}
			}
		}
		//c
		if (c && a != A)
		{
			if (c + a > A)
			{
				if (!visited[A][b][c - (A - a)])
				{
					visited[A][b][c - (A - a)] = 1;
					q.push({ A,b,c - (A - a) });
				}
			}
			else
			{
				if (!visited[a + c][b][0])
				{
					visited[a + c][b][0] = 1;
					q.push({ a + c,b,0 });
				}
			}
		}
		if (c && b != B)
		{
			if (c + b > B)
			{
				if (!visited[a][B][c - (B - b)])
				{
					visited[a][B][c - (B - b)] = 1;
					q.push({ a,B,c - (B - b) });
				}
			}
			else
			{
				if (!visited[a][b + c][0])
				{
					visited[a][b + c][0] = 1;
					q.push({ a,b + c,0 });
				}
			}
		}
	}
}

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	cin >> A >> B >> C;
	memset(cnt, 0, sizeof(cnt));
	memset(visited, 0, sizeof(visited));
	Solve();
	for (int i = 0; i <= 200; i++)
	{
		if (cnt[i])cout << i << " ";
	}
	cout << "\n";
}
