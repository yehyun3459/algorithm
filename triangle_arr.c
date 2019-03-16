#include <stdio.h>
#define ARR_LEN 5

void main()
{
	int arr[ARR_LEN][ARR_LEN] = { 0, };
	int number = 1;
	for (int i = 0; i<ARR_LEN; i++)
	{
		for (int j = i; j<ARR_LEN; j++)arr[i][j] = number++;
	}
	for (int i = 0; i<ARR_LEN; i++)
	{
		for (int j = 0; j<ARR_LEN; j++)printf("%2d ", arr[i][j]);
		printf("\n");
	}
}