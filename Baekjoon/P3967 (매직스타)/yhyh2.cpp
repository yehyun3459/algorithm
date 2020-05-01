//가지치기x
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int board[5][9];
int seq[13][2] = { {0,4},{1,1},{1,3},{1,5},{1,7},{2,2},{2,6},{3,1},{3,3},{3,5},{3,7},{4,4} };
int visited[13];
bool DFS(int cnt)
{
	if(cnt>=12)
	{
		if(board[0][4]+board[1][3]+board[2][2]+board[3][1]==26&&
			board[3][1]+board[3][3]+board[3][5]+board[3][7]==26&&
			board[3][7]+board[2][6]+board[1][5]+board[0][4]==26&&
			board[1][1]+board[2][2]+board[3][3]+board[4][4]==26&&
			board[4][4]+board[3][5]+board[2][6]+board[1][7]==26&&
			board[1][7]+board[1][5]+board[1][3]+board[1][1]==26)
		{
			return true;
		}
		return false;
	}
	if(!board[seq[cnt][0]][seq[cnt][1]])
	{
		for (int i = 1; i <= 12; i++)
		{
			if (visited[i])continue;
			board[seq[cnt][0]][seq[cnt][1]] = i;
			visited[i] = 1;
			if(DFS(cnt + 1))return true;
			board[seq[cnt][0]][seq[cnt][1]] = 0;
			visited[i] = 0;
		}
	}
	else
	{
		if (DFS(cnt + 1))return true;
	}
	return false;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	
	char tmp;
	memset(visited, 0, sizeof(visited));
	visited[0] = 1;
	for (int i = 0; i <= 4; i++)
	{
		for (int j = 0; j <= 8; j++)
		{
			scanf(" %c", &tmp);
			if (tmp >= 'A' && tmp <= 'L')
			{
				board[i][j] = tmp - 64;
				visited[board[i][j]] = 1;
			}

			else board[i][j] = 0;
		}
	}

	DFS(0);

	for (int i = 0; i <= 4; i++)
	{
		for (int j = 0; j <= 8; j++)
		{
			if (!board[i][j])printf(".");
			else printf("%c", board[i][j] + 64);
		}
		printf("\n");
	}
}
