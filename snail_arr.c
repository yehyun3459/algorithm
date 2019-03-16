#include <stdio.h>
#define ARR_LEN 15

void main()
{
	int arr[ARR_LEN][ARR_LEN] = { 0, };
	
	int row = 0, column = 0; //행, 열
	int flag = 1; //증감을 계속 스위치 하기 위해
	int number = 1;
	int numOfInput = ARR_LEN - 1; //배열에 들어가는 수가 계속 감소....
	for (column = 0; column < ARR_LEN; column++)arr[0][column] = number++;
	column--; //column이 ARR_LEN-1인 상태에서 다시 시작해야 하므로 하나 빼준다.
	while (numOfInput)
	{
		for (int i = 0; i < numOfInput; i++)
		{
			row += flag;
			arr[row][column] = number++;
		}
		
		flag = -flag; //switch 해줌
		for (int j = 0; j < numOfInput; j++)
		{
			column += flag;
			arr[row][column] = number++;
		}
		numOfInput--;
	}

	for (int i = 0; i<ARR_LEN; i++)
	{
		for (int j = 0; j<ARR_LEN; j++)printf("%3d ", arr[i][j]);//글자 맞춰서 출력!
		printf("\n");
	}

}
