//접미사 배열을 이용하여 해결
//접미사 배열 참고 : 구종만 『알고리즘 문제 해결 전략2』, 671pg
//이 문제와 K번째 문자열 전부 맨버-마이어스로도 풀어보았는데 딱히 실행시간에 큰 차이는 없다.
//입력값이 엄청 크지는 않은듯..?

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

#define MAX_SIZE 401

int T, K, N;
char buffer[MAX_SIZE];
vector<int> perm; //접미사 배열

struct Comparator {
	const char* s;
	Comparator(const char* s):s(s){}
	bool operator()(int i,int j)
	{
		return strcmp(s + i, s + j) < 0; //접미사를 문자열 비교로 정렬
	}
};


int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	cin >> T;
	for(int tc=1;tc<=T;tc++)
	{
		cin >> K;
		cin >> buffer;
		N = strlen(buffer);
		
		cout << "#" << tc << " ";
		if (K > N) //총 N개의 접미어 집합이 발생한다. 따라서 K가 N보다 크면 바로 none 출력 후 종료
		{
			cout << "none\n";
			continue;
		}
		perm.clear();
		perm.resize(N);
		for (int i = 0; i < N; i++)perm[i] = i;
		sort(perm.begin(), perm.end(), Comparator(buffer)); //sort를 직접 구현해 볼 수 있을까?

		
		cout<<buffer + perm[K - 1] << "\n"; //0번째부터 저장하므로 K-1번째를 사용
	}
	return 0;
}
