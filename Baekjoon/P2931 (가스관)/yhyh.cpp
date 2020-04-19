//이게 대체 뭔 문제람....
//BFS,DFS로 풀 필요도 없이 그냥 4방향 탐색해서 적당히 넣고 끝내면 정답이 나온다(?!?!?!??!)
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

//빈칸을 나타내는 '.'
//블록을 나타내는 '|'(아스키 124), '-', '+', '1', '2', '3', '4'
//모스크바의 위치를 나타내는 'M'과 자그레브를 나타내는 'Z'.두 글자는 한 번만 주어진다.
char board[27][27];
int R, C;

int main()
{
	scanf("%d %d", &R, &C);
	for(int r=0;r<R;r++)
	{
		for(int c=0;c<C;c++)
		{
			scanf(" %c", &board[r][c]);
		}
	}

	for(int r=0;r<R;r++)
	{
		for (int c = 0; c < C; c++) 
		{
			int tmp = 0;
			if(board[r][c]=='.')
			{
				//위
				if (r - 1 >= 0&&(board[r-1][c]=='|'|| board[r - 1][c] == '+'|| 
					board[r - 1][c] == '1'|| board[r - 1][c] == '4'))
				{
					tmp += 8;
				}
				//왼
				if (c - 1 >= 0&&(board[r][c-1]=='-'|| board[r][c - 1] == '+' ||
					board[r][c - 1] == '1' || board[r][c - 1] == '2'))
				{
					tmp += 4;
				}
				
				//오
				if (c + 1 < C&&(board[r][c + 1] == '-' || board[r][c + 1] == '+' ||
					board[r][c + 1] == '3' || board[r][c + 1] == '4')) 
				{
					tmp += 2;
				}
				//아
				if (r + 1 < R && (board[r + 1][c] == '|' || board[r + 1][c] == '+' ||
					board[r + 1][c] == '2' || board[r + 1][c] == '3'))
				{
					tmp += 1;
				}

				if(tmp==9)
				{
					board[r][c] = '|';
				}
				else if(tmp==6)
				{
					board[r][c] = '-';
				}
				else if(tmp==15)
				{
					board[r][c] = '+';
				}
				else if(tmp==3)
				{
					board[r][c] = '1';
				}
				else if(tmp==10)
				{
					board[r][c] = '2';
				}
				else if(tmp==12)
				{
					board[r][c] = '3';
				}
				else if(tmp==5)
				{
					board[r][c] = '4';
				}
				if(board[r][c]!='.')
				{
					printf("%d %d %c", r + 1, c + 1, board[r][c]);
					return 0;
				}
				board[r][c] = '.';
			}
		}
	}
}
