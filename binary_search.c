#include <stdio.h>
#define ARR_LEN 10
int binarySearch(int *arr,int key)
{
	int r_index = -99;
	int start = 0, end = ARR_LEN - 1;
	
	while(1)
	{
		int mid = (start + end) / 2;

		if (arr[mid] == key) return mid;
		else if (arr[mid] > key)end = mid;
		else start = mid + 1;

		if (start == end&&arr[start] != key)break;
	}
	return r_index;
}

void main()
{
	int _arr[] = { 14,17,20,22,26,48,50,90,95,100 };
	int key;
	while (EOF)
	{
		printf("ã���� �ϴ� ���� �Է��ϼ���\n[14,17,20,22,26,48,50,90,95,100]�߿���*^^*\n");
		scanf("%d", &key);
		int index = binarySearch(_arr, key);
		if(index!=-99)
			printf("%d is stored in %dth index in arr\n", key, index + 1);
		else printf("���� ���� �Է��ϼ̳׿� ^////^");
	}
}