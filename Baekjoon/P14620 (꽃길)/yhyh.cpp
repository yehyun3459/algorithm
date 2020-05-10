//와 울학교 문제다~~ 학교다닐때 이런거 안풀고 뭐했지 ㅎㅎㅎ
//그냥 for문으로 해결 가능 어차피 3개라서...
//100문제 다풀었다~~~~
#include <iostream>
#include <cstring>
using namespace std;

#define MIN(a,b)(a<b?a:b)
int N;
int board[11][11];
int visited[11][11];

int totalSum(int r,int c)
{
	int sum = board[r][c] + board[r - 1][c] + board[r + 1][c] + board[r][c - 1] + board[r][c + 1];
	return sum;
}
int minV = 987654321;
int main()
{
	cin >> N;

	for(int i=0;i<N;i++)
	{
		for (int j = 0; j < N; j++)cin >> board[i][j];
	}
	memset(visited, 0, sizeof(visited));

	for(int fr=1;fr<N-1;fr++)
	{
		for(int fc=1;fc<N-1;fc++)
		{
			visited[fr][fc] = 1;
			visited[fr - 1][fc] = 1;
			visited[fr + 1][fc] = 1;
			visited[fr][fc - 1] = 1;
			visited[fr][fc + 1] = 1;
			for (int sr = 1; sr < N - 1; sr++)
			{
				for (int sc = 1; sc < N - 1; sc++)
				{
					if (visited[sr][sc] || visited[sr - 1][sc] || visited[sr + 1][sc] || visited[sr][sc - 1] || visited[sr][sc + 1])continue;
					visited[sr][sc] = 1;
					visited[sr - 1][sc] = 1;
					visited[sr + 1][sc] = 1;
					visited[sr][sc - 1] = 1;
					visited[sr][sc + 1] = 1;
					for (int tr = 1; tr < N - 1; tr++)
					{
						for (int tc = 1; tc < N - 1; tc++)
						{
							if (visited[tr][tc] || visited[tr - 1][tc] || visited[tr + 1][tc] || visited[tr][tc - 1] || visited[tr][tc + 1])continue;
							minV = MIN(minV, totalSum(fr, fc) + totalSum(sr, sc) + totalSum(tr, tc));
						}
					}
					visited[sr][sc] = 0;
					visited[sr - 1][sc] = 0;
					visited[sr + 1][sc] = 0;
					visited[sr][sc - 1] = 0;
					visited[sr][sc + 1] = 0;
				}
			}
			visited[fr][fc] = 0;
			visited[fr - 1][fc] = 0;
			visited[fr + 1][fc] = 0;
			visited[fr][fc - 1] = 0;
			visited[fr][fc + 1] = 0;
		}
	}
	cout << minV << "\n";
}
