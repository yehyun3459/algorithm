#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define MAX_SIZE 100001
#define MAX(a,b)(a>b?a:b)
typedef long long ll;

int N;
int arr[MAX_SIZE];

struct segTree
{
	int tree[MAX_SIZE * 4]; //인덱스만 담아보자
	int base;
	void init(int N) //트리 초기화, 리프노드의 위치 갱신
	{
		memset(tree, 0, sizeof(tree));
		for (base = 1; base < N; base <<= 1);
		base -= 1;
	}
	void update(int idx, int val)
	{
		int i = idx + base;
		tree[i] = idx;
		while (i >>= 1)
		{
			//둘중 최솟값으로 갱신함
			if (arr[tree[i << 1]] < arr[tree[i << 1 | 1]])
			{
				tree[i] = tree[i << 1];
			}
			else tree[i] = tree[i << 1 | 1];
		}
	}
	int query(int l, int r) //l부터 r까지의 구간 중 최소 높이를 가진 인덱스를 반환함
	{
		int i = l + base;
		int j = r + base;
		int lval = 0, rval = 0;
		while (i <= j)
		{
			if (i & 1)
			{
				if (arr[lval] > arr[tree[i]])
				{
					lval = tree[i];
				}
				i++;
			}
			if (!(j & 1))
			{
				if (arr[rval] > arr[tree[j]])
				{
					rval = tree[j];
				}
				j--;
			}
			i >>= 1, j >>= 1;
		}
		if (arr[lval] < arr[rval])return lval;
		else return rval;
	}
};
segTree tr;

ll Solve(int start, int end)
{
	//현재 구간에서 최솟값과 최소 인덱스를 찾음
	if (start == end)return arr[start];
	int current = tr.query(start, end);

	ll result = (ll)arr[current] * ((ll)end - (ll)start + 1); //넓이

  //놀랍게도 tmp 변수를 두었을때와 두지 않았을때의 시간 차이는 10배라고 한다 (왜???????????????????????)
	if (start <= current - 1)
	{
		ll tmp = Solve(start, current - 1); //이 부분 빼면 시간초과 남(대체 왜???? 대체 왜>??>/????????????)
		result = MAX(result, tmp);

	}
	if (current + 1 <= end)
	{
		ll tmp = Solve(current + 1, end);
		result = MAX(result, tmp);
	}

	return result;
}

int main()
{
	while (true)
	{
		scanf("%d", &N);
		if (!N)break;
		tr.init(N);

		arr[0] = 1000000001; //트리 update할 때 INF값으로 사용함
		for (int i = 1; i <= N; i++)
		{
			scanf("%d", &arr[i]);
			tr.update(i, arr[i]); //미리 업데이트
		}

		printf("%lld\n", Solve(1, N));
	}
}
