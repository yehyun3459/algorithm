//아늬;;;;; 감이 안와서 참고했는데 dp였다니
//그거와 별개로 기억해두면 좋을 문제
//https://sangdo913.tistory.com/116 참고
//음 첨에 for문 돌렸다가 계속 틀렸는데 뭐가 문제였던 걸까
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

#define MIN(a,b)(a<b?a:b)
#define MAX(a,b)(a>b?a:b)
int R, C;
int board[1001][1001];
int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	cin >> R >> C;
	int maxS = 0;
	int tmp;
	for(int i=1;i<=R;i++)
	{
		for (int j = 1; j <= C; j++)
		{
			cin >> tmp;
			if (!tmp)
			{
				board[i][j] = 1;
				board[i][j] = MIN(board[i - 1][j], MIN(board[i][j - 1], board[i - 1][j - 1])) + 1;
				maxS = MAX(maxS, board[i][j]);
			}
		}
	}
	
	cout << maxS << "\n";
}
