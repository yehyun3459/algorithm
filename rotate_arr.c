#include <stdio.h>
//#define ARR_LEN 5

void main()
{
	char arr[5][5] =
	{ 
	{'A','B','C','D','E'},
	{'F','G','H','I','J'},
	{'K','L','M','N','O'},
	{'P','Q','R','S','T'},
	{'U','V','W','X','Y'}
	};
	
	char new_arr[5][5];
	for(int row=0;row<5;row++)
	{
		for (int col = 0; col < 5; col++)new_arr[row][col] = arr[4 - col][row];
	}

	for (int i = 0; i<5; i++)
	{
		for (int j = 0; j<5; j++)printf("%c ", new_arr[i][j]);//글자 맞춰서 출력!
		printf("\n");
	}
}