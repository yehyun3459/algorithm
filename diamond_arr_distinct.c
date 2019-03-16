#include <stdio.h>

#define ARR_LEN 13
void main()
{
	int arr[ARR_LEN][ARR_LEN] = { 0, };
	int number = 1;
	int flag = ARR_LEN/2;
	for (int i = 0; i<ARR_LEN; i++)
	{
		for (int j = flag; j < (ARR_LEN - flag); j++)
		{
				arr[i][j] = number;
				number += 2;
		}

		
		if (i < (ARR_LEN / 2)) flag--;
		else flag++;
		
	}
	for (int i = 0; i<ARR_LEN; i++)
	{
		for (int j = 0; j<ARR_LEN; j++)printf("%3d ", arr[i][j]);//글자 맞춰서 출력!
		printf("\n");
	}
}
