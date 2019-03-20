#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_OF_ST 20

void main()
{
	srand((unsigned)time(NULL));
	
	int student[NUM_OF_ST];
	for (int i = 0; i < NUM_OF_ST; i++)student[i] = (rand() % 40) + 60;

	for(int i=0;i<NUM_OF_ST-1;i++)
	{	
		int flag = i+1;
		int min = student[i + 1];
		for (int j = i + 1; j < NUM_OF_ST; j++) 
		{
			if (min > student[j])
			{
				min = student[j];
				flag = j;
			}
		}
		if (min < student[i]) 
		{
			int temp = student[flag];
			student[flag] = student[i];
			student[i] = temp; //swap
		}
	}
	
	for (int i = 0; i < NUM_OF_ST; i++)printf("%dth's score : %d\n", i, student[i]);
}