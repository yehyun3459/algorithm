#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main()
{
	int A[25]; //매출액
	int R[25]; //석차

	srand(time(NULL));

	for (int i = 0; i < 25; i++) 
	{
		//scanf("%d", &A[i]);
		A[i] = (rand() % 10) + 10;
		R[i] = 1;
	}

	for (int i = 0; i < 25; i++) {
		for (int j = 0; j < 25; j++) {
			if (i == j)continue;
			if (A[i] < A[j])R[i]++;
		}
	}

	for (int i = 0; i < 25; i++) {
		printf("%d 대리점 총 매출액 : %d [%d위]\n", i, A[i], R[i]);
	}
}