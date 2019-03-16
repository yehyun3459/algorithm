#include <stdio.h>
#define ARR_LEN 13

void main()
{
	int arr[ARR_LEN][ARR_LEN] = { 0, };
	int row = 0, column = 0,number=1;
	for (row = 0; row<ARR_LEN; row++)
	{
		if (row % 2 == 0)for (column = 0; column < ARR_LEN; column++)arr[row][column]=number++;
		else for (column = ARR_LEN - 1; column >= 0; column--)arr[row][column]=number++;
	}
	for (int i = 0; i<ARR_LEN; i++)
	{
		for (int j = 0; j<ARR_LEN; j++)printf("%3d ", arr[i][j]);//글자 맞춰서 출력!
		printf("\n");
	}
}