#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_OF_ST 20

void main()
{
	srand((unsigned)time(NULL));

	int student[NUM_OF_ST];
	for (int i = 0; i < NUM_OF_ST; i++)student[i] = (rand() % 40) + 60;

	for (int i = 1; i < NUM_OF_ST; i++)
	{
		int j;
		int temp = student[i];

		for (j = i - 1; j >= 0; j--)
		{
			if (student[j] <= temp)break;	
			student[j + 1] = student[j];
			
		}
		student[j+1] = temp;
	}

	for (int i = 0; i < NUM_OF_ST; i++)printf("%dth's score : %d\n", i, student[i]);
}