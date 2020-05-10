//간만에 dp~~
#include <iostream>
#include <cstring>
using namespace std;

#define MIN(a,b)(a<b?a:b)
int N;
int A[1001];
int dp[1001];
int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	cin >> N;
	for (int i = 0; i < N; i++)cin >> A[i];
	memset(dp, -1, sizeof(dp));
	dp[0] = 0;
	for(int i=0;i<N;i++)
	{
		if (dp[i] == -1)continue;
		int ni = A[i] + i;
		for(int ii=i+1;ii<=ni;ii++)
		{
			if (ii >= N)break;
			if (dp[ii] == -1 || dp[ii] > dp[i] + 1)dp[ii] = dp[i] + 1;
		}

	}
	cout << dp[N - 1] << "\n";
}
