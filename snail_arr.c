#include <stdio.h>
#define ARR_LEN 15

void main()
{
	int arr[ARR_LEN][ARR_LEN] = { 0, };
	
	int row = 0, column = 0; //��, ��
	int flag = 1; //������ ��� ����ġ �ϱ� ����
	int number = 1;
	int numOfInput = ARR_LEN - 1; //�迭�� ���� ���� ��� ����....
	for (column = 0; column < ARR_LEN; column++)arr[0][column] = number++;
	column--; //column�� ARR_LEN-1�� ���¿��� �ٽ� �����ؾ� �ϹǷ� �ϳ� ���ش�.
	while (numOfInput)
	{
		for (int i = 0; i < numOfInput; i++)
		{
			row += flag;
			arr[row][column] = number++;
		}
		
		flag = -flag; //switch ����
		for (int j = 0; j < numOfInput; j++)
		{
			column += flag;
			arr[row][column] = number++;
		}
		numOfInput--;
	}

	for (int i = 0; i<ARR_LEN; i++)
	{
		for (int j = 0; j<ARR_LEN; j++)printf("%3d ", arr[i][j]);//���� ���缭 ���!
		printf("\n");
	}

}
