//실버 1인 이유를 모르겠다 넘 어렵다 ㅠ
//0X...90, 900 <-- 이런 데이터를 조심하자..
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
typedef long long ll;

#define MOD 1000000

char uStr[5001] = "";
ll dp[5001];


ll Solve(int idx)
{
	if (idx < 0)return 1;//두자리 숫자가 하나의 글자일때
	if (uStr[idx]!='0'&&idx == 0)return 1;//한자리 숫자가 하나의 글자일때
	if (dp[idx] != -1)return dp[idx]%MOD;
	dp[idx] = 0;
	ll tmp;

	if(uStr[idx]=='0') //'0'일 경우
	{
		if (idx == 0)return -1; //0은 존재하지 않으므로 -1
		else if (uStr[idx - 1] > '2'||uStr[idx-1]=='0')return -1; //존재하지 않으므로 -1
		tmp = Solve(idx - 2) % MOD;//10, 20의 두자리-한글자만 가능
		if (tmp == -1)return -1;
		dp[idx] = (dp[idx] % MOD + tmp) % MOD;
		return dp[idx];
	}

	if(uStr[idx-1]=='1'||(uStr[idx-1]=='2'&&(uStr[idx]>'0'&&uStr[idx]<='6'))) //두자리-한글자
	{
		tmp = Solve(idx - 2)%MOD;
		if (tmp == -1)return -1;
		dp[idx] = (dp[idx] % MOD + tmp) % MOD;
	}

	tmp = Solve(idx - 1) % MOD; //한자리-한글자인 경우
	if (tmp == -1)return -1;
	dp[idx] = (dp[idx] % MOD + tmp) % MOD;
	
	

	return dp[idx] % MOD;
}

int main()
{

	int slen;

	scanf("%s", &uStr);
	slen = strlen(uStr);
	memset(dp, -1, sizeof(dp));
	ll result = Solve(slen - 1);
	if (result == -1)result = 0;
	printf("%lld\n",result);
}
