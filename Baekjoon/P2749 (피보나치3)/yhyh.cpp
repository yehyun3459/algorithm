//내가 푼 문제는 아니지만..... 재밌어서 일단 들고옴!
//https://www.acmicpc.net/blog/view/28
//주기를 이용한 방법이라고 한다
//뭔 소리인지 사실 모르겠다 ㅎㅎ;;
#include <iostream>
using namespace std;

typedef unsigned long long ull;
#define div_num 1000000
const int p = div_num / 10 * 15;
int fibo[p] = { 0,1 };
void Fibo(long long n)
{
	for (int i = 2; i < p; i++)
	{
		fibo[i] = fibo[i - 1] + fibo[i - 2];
		fibo[i] %= div_num;
	}
	cout << fibo[n % p] << '\n';
}
int main()
{
	long long N;
	cin >> N;
	Fibo(N);
	return 0;
}
