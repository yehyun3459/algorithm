//함정문제... 이게 가능한 이유는
//간선 간에 가중치가 없고, 연결 그래프인경우에는 무조건 N-1이 최소값이 된다는 MST의 특징때문이다
//나는 몰랐다 바보다 ㅎ하하ㅏ하ㅏ하하하
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int T, N, M;

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	cin >> T;
	while(T--)
	{
		cin >> N >> M;
		while(M--)
		{
			int sv, ev;
			cin >> sv >> ev;
		}
		cout << N - 1 << "\n";
	}
}
