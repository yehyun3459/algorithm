//test data : https://gcpc.nwerc.eu/german-collegiate-programming-contest-2013 F번
//하.....ㅎ...
//미리 위치를 지정한 후에 했는데 계속 틀렸음 ㅠㅜ
//결국 배열 전부 탐색해서 o인경우로 돌렸는데 시간 넉넉해서 ????했음
//그리고 8개라 그런가 딱히 가지치기 안해도 수월하게 통과해서 2차 ?????함
//뭐지 이문제 왜 난 바보지
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

#define MIN(a,b)(a<b?a:b)
#define INF 987654321
int N;
char board[5][10];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int minM, minP;

int chk()
{
	int cnt = 0;
	for(int i=0;i<5;i++)
	{
		for(int j=0;j<9;j++)
		{
			if (board[i][j] == 'o')cnt++;
		}
	}
	return cnt;
}
void DFS(int cnt)
{
	int num = chk();
	if(minP>num)
	{
		minP = num;
		minM = cnt;
	}
	for(int i=0;i<5;i++)
	{
		for(int j=0;j<9;j++)
		{
			if(board[i][j]=='o')
			{
				for (int d = 0; d < 4; d++)
				{
					int nr = i + dx[d];
					int nc = j + dy[d];
					int nnr = i + 2 * dx[d];
					int nnc = j + 2 * dy[d];
					if (nr < 0 || nr >= 5 || nc < 0 || nc >= 9)continue;
					if (nnr < 0 || nnr >= 5 || nnc < 0 || nnc >= 9)continue;
					if (board[nr][nc] != 'o' || board[nnr][nnc] != '.')continue;
					board[nnr][nnc] = 'o';
					board[nr][nc] = '.';
					board[i][j] = '.';
					DFS(cnt + 1);
					board[i][j] = 'o';
					board[nr][nc] = 'o';
					board[nnr][nnc] = '.';
				}
			}
		}
	}
}

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	freopen("input.txt", "r", stdin);
	cin >> N;
	while (N--)
	{
		minM = INF;
		minP = INF;
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				cin >> board[i][j];
			}
		}

		DFS(0);
		cout << minP << " " << minM << "\n";
	}
}
