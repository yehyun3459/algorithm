//내가 직접 구현하긴 했는데 뭔 코드인지 모르겠음
//1. 일단 segTree로 구현함
//2. 구간 합을 구하는 것이 아니라 구간 중 최댓값을 구함, 당연히 update도 자식중(리프노드중) 최댓값
//3. 전부 갱신 후에 1번 노드(루트 노드)의 값이 총 최장 길이 이다.
//4. dp에 이전 인덱스를 참조해서 tracking 가능하도록 만듬
//5. tracking해서 전부 카운트 하고, 카운트 되지 않은 값들 출력함

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX(a,b)(a>b?a:b)
#define MAX_SIZE 100001 
typedef unsigned long long ull;

struct Info
{
	int ind;
	int f;
	int s;
};

bool fcmp(Info a,Info b){
	return a.f < b.f;
}
bool scmp(Info a,Info b)
{
	return a.s < b.s;
}

vector<Info> arr;
int origin[MAX_SIZE];

struct ReInfo
{
	ull val = 0;
	int tind = -1;
	int chk = 0;
};

ReInfo dp[MAX_SIZE];

struct segTree {
	ReInfo tree[MAX_SIZE * 4];
	int base;
	void init(int N)
	{
		for (base = 1; base < N; base <<= 1);
		base -= 1; //leaf 노드의 위치를 찾는다
	}
	void update(int idx, int val) //idx 부분을 val로 바꿈
	{
		int i = idx + base;
		tree[i].val = val;
		tree[i].tind = idx;
		while (i >>= 1)
		{
			if(tree[i<<1].val>=tree[i<<1|1].val)
			{
				tree[i] = tree[i << 1];
			}
			else
			{
				tree[i] = tree[i << 1 | 1];
			}
		}
	}
	ReInfo query(int l, int r) //l부터 r까지의 구간합을 구함 
	{
		int left = l + base; //리프 노드부터 올라오면서 값을 구함
		int right = r + base;
		ReInfo lval, rval;
		while (left <= right) //최댓값을 구함
		{
			if (left & 1) {
				if(lval.val<tree[left].val)
					lval = tree[left];
				left++;
			}
			if (!(right & 1))
			{
				if(rval.val<tree[right].val)
					rval = tree[right];
				right--;
			}
			left >>= 1; right >>= 1;
		}
		if (lval.val >= rval.val)
			return lval;
		else return rval;
	}
};

segTree stree;

int main()
{
	int N;
	scanf("%d", &N);

	stree.init(N);
	arr.resize(N);

	for (int i = 0; i < N; i++)
	{
		scanf("%d %d", &arr[i].f, &arr[i].s);
	}

	sort(arr.begin(), arr.end(), fcmp);
	for(int i=0;i<N;i++)
	{
		arr[i].ind = i + 1;
		origin[i+1] = arr[i].f;
	}
	sort(arr.begin(), arr.end(), scmp);
	
	for (int i = 0; i < N; i++)
	{
		int idx = arr[i].ind;
		dp[idx] = stree.query(1, idx - 1);
		dp[idx].val += 1;
		stree.update(idx, dp[idx].val);
	}
	
	//이게 뭔 코드여
	int flag = stree.tree[1].tind; //tracking
	while(flag!=-1)
	{
		dp[flag].chk = 1;
		flag = dp[flag].tind;
	}

	int result = N - stree.tree[1].val;
	printf("%d\n", result);
	for(int i=1;i<=N;i++)
	{
		if (dp[i].chk == 0)printf("%d\n", origin[i]);
	}
}
