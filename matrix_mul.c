#include <stdio.h>
//#define ARR_LEN 5

void main()
{
	int first_arr[2][4] = { {5,7,-3,4},{2,-5,3,6} };
	int second_arr[4][3] = { {3,0,8},{-5,1,-1},{7,4,4},{2,4,3} };

	int result_arr[2][3] = { 0, }; //행렬의 성질에 의하여 2x3 행렬이 된다.
	for (int row = 0; row < 2; row++) 
	{
		for (int col = 0; col < 3; col++) 
		{
			for (int i = 0; i < 4; i++)result_arr[row][col] += first_arr[row][i] * second_arr[i][col];
		}
	}

	for (int i = 0; i<2; i++)
	{
		for (int j = 0; j<3; j++)printf("%3d ", result_arr[i][j]);//글자 맞춰서 출력!
		printf("\n");
	}
}