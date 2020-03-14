//참고 : https://justicehui.github.io/koi/2019/03/03/BOJ2517/
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

struct segTree
{
	int arr[2020202];
	int bias;
	void init(int n)
	{
		memset(arr, 0, sizeof(arr));
		for (bias = 1; bias < n; bias <<= 1);
		bias = bias - 1;
	}
	void update(int _ind, int _val)
	{
		_ind += bias;
		arr[_ind] = _val;
		while(_ind>>=1) //루트 노드까지
		{
			arr[_ind] = arr[_ind << 1] + arr[_ind<<1|1]; //*2, *2+1 자식노드들의 합을 구해서 저장
		}
	}
	int query(int l, int r)
	{
		l += bias, r += bias;
		int lval = 0, rval = 0;
		while(l<=r)
		{
			if (l & 1) //만약 왼쪽 노드가 홀수라면 오른쪽으로 밀어버린다
			{
				lval += arr[l];
				l++;
			}
			if(!(r&1)) //만약 오른쪽 노드가 짝수라면 왼쪽으로 민다 
			{
				rval += arr[r];
				r--;
			}
			l >>= 1, r >>= 1;

		}
		return lval + rval;
	}
}tree;

struct Info
{
	int ind;
	int val;
};

bool operator<(Info a,Info b)
{
	return a.val < b.val;
}

vector<Info> player;

int ans[505050];

int main()
{
	int n;
	scanf("%d", &n); player.resize(n); tree.init(n);
	for (int i = 0; i < n; i++) {
		int t; 
		scanf("%d", &t);
		player[i] = { i + 1, t };
	}
	sort(player.begin(), player.end());

	for (unsigned int i = 0; i < player.size();i++) {
		int idx = player[i].ind;
		ans[idx] = idx - tree.query(1, idx - 1);// 현재 등수 - 자신보다 앞에 있으면서 실력이 낮은 사람의 수
		tree.update(idx, 1); //업데이트하기
	}
	for (int i = 1; i <= n; i++)printf("%d\n", ans[i]);
}
