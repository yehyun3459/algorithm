#include <stdio.h>

#define ARR_LEN 5
void main()
{
	int arr[ARR_LEN][ARR_LEN] = { 0, };
	int number = 1;
	int flag = ARR_LEN/2;
	for (int i = 0; i<ARR_LEN; i++)
	{
		if (i < (ARR_LEN / 2))
		{
			for (int j = flag; j < (ARR_LEN - flag); j++)
			{
				arr[i][j] = number;
				number += 2;
			}
			flag--;
		}
		else if (i == (ARR_LEN / 2))
			for (int j = flag; j < (ARR_LEN - flag); j++)
			{
				arr[i][j] = number;
				number += 2;
			}
		else
		{
			flag++;
			for (int j = flag; j < (ARR_LEN - flag); j++)
			{
				arr[i][j] = number;
				number += 2;
			}
			
		}
		
	}
	for (int i = 0; i<ARR_LEN; i++)
	{
		for (int j = 0; j<ARR_LEN; j++)printf("%3d ", arr[i][j]);//글자 맞춰서 출력!
		printf("\n");
	}
}
