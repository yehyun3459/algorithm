//접미사 배열 참고 : 구종만 『알고리즘 문제 해결 전략2』, 671pg
//1. 접미사 배열을 만들고, 문자열에 따라 정렬한다.
//2. 만들어진 접미사를 기준으로 접두사를 만든다. (중첩되는 것들은 LCP 배열을 이용해서 걸러냄)
//2-2. 정렬된 접미사 문자열이기 때문에 앞의 접미사들과 중첩되는 접두사가 있는지 확인하면 된다.
//3. 개수를 카운트 하여 K번째 부분 문자열을 알아낸다.
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX_SIZE 401

int T, K, N; //N : strlen
char buffer[MAX_SIZE];
vector<int> perm;
//int LCP[MAX_SIZE]; //LCP 굳이 필요 없음

//접미사 배열을 계산하는 단순한 알고리즘
struct SuffixComparator {
	const char* s;
	SuffixComparator(const char* s): s(s){}
	bool operator() (int i, int j)
	{
		return strcmp(s + i, s + j) < 0; //문자열 s의 i부터 시작,(i, ...) j부터 시작(j, ...) 부분 문자열들을 비교
	}
};

void getSuffixArrayNaive(const char* s)
{
	for (int i = 0; i < N; i++)perm.push_back(i);
	sort(perm.begin(), perm.end(), SuffixComparator(s));
}

//s[i..]와 s[j..]의 공통 접두사의 최대 길이를 계산함
int commonPrefix(const char* s,int i, int j) 
{
	int k = 0;
	while (i < N&&j<N&&s[i]==s[j])
	{
		++i; ++j; ++k;
	}
	return k;
}

//s의 서로 다른 부분 문자열 세기
void Substrings(const char* s)
{
	getSuffixArrayNaive(s);
	int ret = 0;
	//LCP[0] = 0;
	//ret += N - perm[0] - LCP[0];
	for(int i=0;i<perm.size();i++)
	{
		int cp = 0;
		if(i>0)cp = commonPrefix(s, perm[i - 1], perm[i]); //LCP : 앞에서부터 중첩되는 최대 개수를 구하는 배열
		ret += N - perm[i] - cp;
		if(ret>=K) //현재 접미어 부분 문자열에서 답이 있음
		{
			char tmp[MAX_SIZE];
			strcpy(tmp, s);
			tmp[N - (ret - K)] = '\0';
			
			cout << tmp+perm[i]<<"\n";
			return;
		}


	}
	cout << "none\n";
}

int main()
{
	//freopen("input.txt", "r", stdin);
	cin >> T;
	for(int tc=1;tc<=T;tc++)
	{
		cin >> K;
		cin>>buffer;
		N = strlen(buffer);
		buffer[N] = '\0';
		perm.clear();
		//memset(LCP, 0, sizeof(LCP)); //딱히 LCP 배열을 둘 필요가 없음
		cout << "#" << tc<<" ";
		Substrings(buffer);

	}
}
