#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef long long ll;

//merge sort를 구현해보자
int N;
ll arr[500001];
ll tmp[500001]; //새 공간
ll cnt = 0; //결과값 저장
void merge(ll l,ll m,ll r)
{
	ll i = l;
	ll j = m + 1;

	ll n = l; //새로운 인덱스
	while(i<=m||j<=r)
	{
		if(i>m) //오른쪽만 남음
		{
			tmp[n] = arr[j];
			j++;
		} 
		else if(j>r) //왼쪽만 남음
		{
			tmp[n] = arr[i];
			i++;
		}
		else //둘중에 작은거를 찾자...
		{
			if(arr[j]<arr[i])
			{
				tmp[n] = arr[j];
				cnt = cnt + (j - n);
				j++;
				
			}
			else
			{
				tmp[n] = arr[i];
				i++;
			}
		}
		n++;
	}
	for(ll n=l;n<=r;n++)
	{
		arr[n] = tmp[n];
	}

}
void mergeSort(ll l,ll r)
{
	if(l<r)
	{
		ll m = (l + r) / 2;
		mergeSort(l, m); // [ ]
		mergeSort(m + 1, r);
		merge(l, m, r);
	}
}


int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++)scanf("%lld", &arr[i]);
	mergeSort(0,N-1);
	//for (int i = 0; i < N; i++)printf("%d ", arr[i]);
	printf("%lld\n", cnt);

	return 0;
}
