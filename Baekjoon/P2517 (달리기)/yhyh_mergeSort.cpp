//1. merge sort로 해결해본다

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

typedef long long ll;
#define MAX_SIZE 500001

struct Info
{
	ll pr; //priority
	int ind;
};

Info arr[MAX_SIZE];
Info tmp[MAX_SIZE]; //merge sort에서 사용할거임
int rank[MAX_SIZE];

//헷갈리면 안됨! 내림차순 정렬임!
//2. 왼쪽 등수는 그대로, 오른쪽 등수는 왼쪽과의 비교 수
void merge(int l,int m,int r)
{
	int i = l;
	int j = m + 1;
	int t = l; //top
	while(i<=m||j<=r)
	{
		if(i>m)
		{
			tmp[t] = arr[j];
			rank[arr[j].ind] = rank[arr[j].ind] + (i - l);
			t++;
			j++;
		}
		else if(j>r)
		{
			tmp[t] = arr[i];
			t++;
			i++;
		}
		else
		{
			if(arr[j].pr>arr[i].pr)
			{
				tmp[t] = arr[j];
				rank[arr[j].ind] = rank[arr[j].ind] + (i - l);
				t++;
				j++;
			}
			else
			{
				tmp[t] = arr[i];
				t++;
				i++;
			}
		}
	}
	for(int t=l;t<=r;t++)
	{
		arr[t] = tmp[t];
	}
}

void mergeSort(int l, int r) //둘다 닫힌 괄호
{
	if(l<r)
	{
		int m = (l + r) / 2;
		mergeSort(l, m);
		mergeSort(m + 1, r);
		merge(l, m, r);
	}
}

int main()
{
	int N;
	scanf("%d", &N);
	for(int i=0;i<N;i++)
	{
		scanf("%lld", &arr[i].pr);
		arr[i].ind = i;
		rank[i] = 1; //다 1등으로 초기화
	}
	mergeSort(0,N-1);
	for(int i=0;i<N;i++)
	{
		printf("%d\n", rank[i]);
	}

}
