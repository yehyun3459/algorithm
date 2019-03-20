#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_OF_ST 10

void quick(int *arr,int left,int right)
{
	if (left >= right)return;
	int pivot = arr[left];
	int i = left + 1;
	int j = right;
	while(i<j)
	{
		if(arr[i]>pivot&&arr[j]<pivot)
		{
			int temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
			i++; j--;
		}
		else
		{
			if (arr[i] < pivot)i++;
			if (arr[j] > pivot)j--;
		}
	}
	if (pivot > arr[j]) 
	{
		int temp = pivot;
		arr[left] = arr[j];
		arr[j] = pivot;
	}
	
	quick(arr, left, j - 1);
	quick(arr, j+1, right);
}

void main()
{
	srand((unsigned)time(NULL));

	//int student[NUM_OF_ST] = { 0, };
	//for (int i = 0; i < NUM_OF_ST; i++)student[i] = rand() % 40 + 60;
	int student[NUM_OF_ST] = { 26,14,100,95,22,17,48,20,50,90 };

	quick(student, 0, NUM_OF_ST-1);
	for (int i = 0; i < NUM_OF_ST; i++)printf("%d ", student[i]);
	printf("\n");
}