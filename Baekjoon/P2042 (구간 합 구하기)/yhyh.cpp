//참고 : https://justicehui.github.io/koi/2019/03/03/BOJ2517/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

typedef long long ll;
#define MAX_SIZE 4000001 //최대 사이즈 * 4 정도는 해주어야 문제가 발생하지 않는다

struct segTree
{
	ll arr[MAX_SIZE];
	int bias;
	void init(int n)
	{
		memset(arr, 0, sizeof(arr));
		for (bias = 1; bias < n; bias <<= 1);
		for (int i = bias; i < bias + n; i++)
		{
			scanf("%lld", &arr[i]); //리프 노드 입력 받기
			update(i - bias, arr[i]);
		}
		bias = bias - 1;
		
	}
	void update(int x,ll v)
	{
		x += bias;//리프노드로 이동
		arr[x] = v; //현재 노드 갱신
		while(x>>=1) //루트 노드까지 이동(루트 노드 인덱스: 1)
		{
			arr[x] = arr[x << 1] + arr[x << 1 | 1];
		}
	}
	ll query(int l,int r)
	{
		l += bias , r += bias; //리프 노드로 이동
		ll lval = 0, rval = 0;
		while(l<=r)
		{
			if(l&1) //만약에 짝수가 아니라면 오른쪽으로 이동
			{
				lval += arr[l];
				l++;
			}
			if(!(r&1)) //만약에 홀수가 아니라면 왼쪽 이동
			{
				rval += arr[r];
				r--;
			}
			l >>= 1, r >>= 1; //부모 노드로
		}
		return lval + rval;
	}

}tree;

int main()
{
	int N, M, K;
	scanf("%d %d %d", &N, &M, &K);
	tree.init(N);
	int a, b, c;
	for(int i=0;i<M+K;i++)
	{
		scanf("%d %d %d", &a, &b, &c);
		if(a&1)
		{
			tree.update(b, c);
		}
		else
		{
			printf("%lld\n", tree.query(b, c));
		}
	}
}
