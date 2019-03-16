#include <stdio.h>
#define ARR_LEN 13

void main()
{
	int arr[ARR_LEN][ARR_LEN] = { 0, };
	int number = 1;
	int flag = ARR_LEN;
	for (int i = 0; i<ARR_LEN; i++)
	{
		if (i <(ARR_LEN / 2))
		{
			for (int j = (ARR_LEN - flag); j<flag; j++)arr[i][j] = number++;
			flag--;
		}
		else if (i==(ARR_LEN/2))arr[i][ARR_LEN - flag] = number++;
		else
		{
			flag++;
			for (int j = (ARR_LEN - flag); j<flag; j++)arr[i][j] = number++;

		}
	}
	for (int i = 0; i<ARR_LEN; i++)
	{
		for (int j = 0; j<ARR_LEN; j++)printf("%2d ", arr[i][j]);//글자 맞춰서 출력!
		printf("\n");
	}
}
