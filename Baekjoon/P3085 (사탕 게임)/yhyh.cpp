//잉 어려웡 
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define MAX(a,b)(a>b?a:b)

char board[51][51];
int N;

int chkMax()
{
	int cnt = 0;
	int maxV = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cnt = 1;
			for (int k = j + 1; k < N; k++)
			{
				if (board[i][j] == board[i][k])cnt++;
				else break;
			}
			maxV = MAX(maxV, cnt);
		}
	}
	for (int j = 0; j < N; j++)
	{
		for (int i = 0; i < N; i++)
		{
			cnt = 1;
			for (int k = i + 1; k < N; k++)
			{
				if (board[i][j] == board[k][j])cnt++;
				else break;
			}
			maxV = MAX(maxV, cnt);
		}
	}
	return maxV;
}

int main()
{

	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			scanf(" %c", &board[i][j]);
		}
	}
	int result = chkMax();
	for (int i = 0; i < N; i++) // 이부분에서 실수했다... 둘다 N - 1까지만 검사해서 배열 끝부분은 swap을 안함
	{
		for (int j = 0; j < N; j++)//그리고 다를때만 swap한다는 조건 없음 인접한 경우 swap가능
		{
			char tmp;
			if (j < N - 1)
			{
				tmp = board[i][j];
				board[i][j] = board[i][j + 1];
				board[i][j + 1] = tmp;
				//swap후 check
				result = MAX(result, chkMax());
				//check하고 나서 다시 swap..
				tmp = board[i][j];
				board[i][j] = board[i][j + 1];
				board[i][j + 1] = tmp;
			}


			if (i < N - 1)
			{
				tmp = board[i][j];
				board[i][j] = board[i + 1][j];
				board[i + 1][j] = tmp;
				//swap후 check
				result = MAX(result, chkMax());
				//check하고 나서 다시 swap..
				tmp = board[i][j];
				board[i][j] = board[i + 1][j];
				board[i + 1][j] = tmp;
			}


		}
	}
	printf("%d\n", result);
}
