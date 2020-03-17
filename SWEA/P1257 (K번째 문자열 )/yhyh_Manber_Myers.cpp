//아직 이해 못함 ㅠ
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
int group[MAX_SIZE + 1];
int newGroup[MAX_SIZE + 1];
 
//1.접미사 배열을 계산하는 맨버-마이어스 알고리즘
//첫번째 문자 정렬 -> 2번째까지 정렬 -> 4번째 까지 정렬 ...
struct Comparator {
    int* group;
    int t;
    Comparator(int *_group, int _t): group(_group),t(_t)
    {
        group = _group; t = _t;
    }
    bool operator() (int a, int b)
    {
        if (group[a] != group[b])return group[a] < group[b];
        return group[a + t] < group[b + t];
    }
};
 
void getSuffixArray(const char* s)
{
    int t = 1;
 
    for (int i = 0; i < N; i++)
    {
        group[i] = s[i];
        perm[i] = i;
    }
    group[N] = -1;
     
    while(t<N)
    {
        Comparator compareUsing2T(group, t);
        sort(perm.begin(), perm.end(), compareUsing2T);
 
        t *= 2;
        if (t >= N)break;
 
        newGroup[N] = -1;
        newGroup[perm[0]] = 0;
        for (int i = 1; i < N; i++)
        {
            if (compareUsing2T(perm[i - 1], perm[i]))
                newGroup[perm[i]] = newGroup[perm[i - 1]] + 1;
            else
                newGroup[perm[i]] = newGroup[perm[i - 1]];
        }
        for(int i=0;i<N;i++)
        {
            group[i] = newGroup[i];
        }
         
    }
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
    getSuffixArray(s);
    int ret = 0;
    //LCP[0] = 0;
    //ret += N - perm[0] - LCP[0];
    for(int i=0;i<perm.size();i++)
    {
        int cp = 0;
        if(i>0)cp = commonPrefix(s, perm[i - 1], perm[i]); //LCP : 앞에서부터 중첩되는 최대 개수를 구하는 배열
        ret += N - perm[i] - cp;
        if(ret>=K)
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
    cin >> T;
    for(int tc=1;tc<=T;tc++)
    {
        cin >> K;
        cin>>buffer;
        N = strlen(buffer);
        buffer[N] = '\0';
        perm.clear();
        perm.resize(N);
        memset(group, 0, sizeof(group));
        memset(newGroup, 0, sizeof(newGroup));
        cout << "#" << tc<<" ";
        Substrings(buffer);
 
    }
}
