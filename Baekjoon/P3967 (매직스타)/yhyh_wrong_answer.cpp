//!!!!!!!틀린 풀이임!!! 정답 아님!!!!!!!
//처음에 문제를 잘못읽고 푼 버전
//사전순의 의미가 별모양을 한줄로 늘였을때 인줄 알고 푼 풀이.. ㅠㅠㅠ
//DFS 방향 깔쌈하게 했다고 생각했는데 틀려서 아쉽당
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int board[5][9];

int dx[6] = { 1,0,-1,1,-1,0 };
int dy[6] = { -1,2,-1,1,1,-2 };
int visited[13];
bool DFS(int sum,int num,int cnt,int i,int j,int d)
{
	if (sum > 26)return false;
	if(num>=7)
	{
		if (sum == 26)return true;
		else return false;
	}
	if(num==3)
	{
		if (sum == 26) 
		{
			if(DFS(0, 4, 0, 1, 1, 3))return true;
		}
		else return false;
	}
	if(!board[i][j])
	{
		if(cnt==3)
		{
			if (num == 2 || num == 6)
			{
				if (visited[26 - sum])return false;
				board[i][j] = 26 - sum;
				visited[board[i][j]] = 1;
				if (DFS(sum+board[i][j], num + 1, 1, i + dx[d + 1], j + dy[d + 1], d + 1))return true;
				visited[board[i][j]] = 0;
				board[i][j] = 0;
			}
			else
			{
				if (visited[26 - sum])return false;
				board[i][j] = 26 - sum;
				visited[board[i][j]] = 1;
				if (DFS(board[i][j], num + 1, 1, i + dx[d + 1], j + dy[d + 1], d + 1))return true;
				visited[board[i][j]] = 0;
				board[i][j] = 0;
			}
			
		}
		else
		{
			for (int c = 1; c <= 12; c++)
			{
				if (visited[c])continue;
				board[i][j] = c;
				visited[c] = 1;
				if (DFS(sum + c, num, cnt + 1, i + dx[d], j + dy[d], d))return true;
				board[i][j] = 0;
				visited[c] = 0;
			}
		}
		
	}
	else
	{
		if(cnt==3)
		{
			if(num==2||num==6)
			{
				if (sum + board[i][j] != 26)return false;
				if (DFS(sum+board[i][j], num + 1, 1, i + dx[d + 1], j + dy[d + 1], d + 1))return true;
			}
			else
			{
				if (sum + board[i][j] != 26)return false;
				if (DFS(board[i][j], num + 1, 1, i + dx[d + 1], j + dy[d + 1], d + 1))return true;
			}
			
		}
		else
		{
			if (DFS(sum + board[i][j], num, cnt + 1, i + dx[d], j + dy[d], d))return true;
		}
		
	}
	return false;
}
int main()
{
//	freopen("input.txt", "r", stdin);

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

	DFS(0, 0, 0, 0, 4, 0);

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
