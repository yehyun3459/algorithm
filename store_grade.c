#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main()
{
	int A[25]; //�����
	int R[25]; //����

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
		printf("%d �븮�� �� ����� : %d [%d��]\n", i, A[i], R[i]);
	}
}