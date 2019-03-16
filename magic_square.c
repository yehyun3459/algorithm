#include <stdio.h>
#define ARR_LEN 5

void main()
{
	int arr[ARR_LEN][ARR_LEN] = { 0, };
	int number = 1;
	int row = 0, column = 2; //S(1,3)부터 숫자를 할당하기 시작한다.
	int next_row = 0, next_col = 0;
	while (number<=ARR_LEN*ARR_LEN)
	{
		arr[row][column] = number++;
		
		next_row = row - 1;
		next_col = column + 1;
		if (next_row < 0)next_row = ARR_LEN - 1;
		else if (next_col >= ARR_LEN)next_col = 0;

		if (arr[next_row][next_col] == 0)
		{
			row = next_row;
			column = next_col;
		}
		else row++;
	}

	for (int i = 0; i<ARR_LEN; i++)
	{
		for (int j = 0; j<ARR_LEN; j++)printf("%3d ", arr[i][j]);//글자 맞춰서 출력!
		printf("\n");
	}
}