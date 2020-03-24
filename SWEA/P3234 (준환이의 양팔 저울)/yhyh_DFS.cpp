//시간초과나서 가지치기 참조함!
//아이디어 신기해서 백업
//전역변수 인자로 넘겨도 초과남 <-- 자바만 가능한가?

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
 
int T, N;
int arr[10];
int visited[10];
int fact[] = { 0, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880 };
int exp[] = { 1, 2, 4, 8, 16, 32, 64, 128, 256, 512 };
int total_v;
int maxV;
void makeSequence(int cnt, int left, int right)
{
    if (cnt >= N)
    {
        total_v++;
        return;
    }
    //신기하당
    if (left >= maxV - left) { 
        //왼쪽저울의 무게가 이미 총 합의 중간값을 넘겼을 경우
        //그 다음 추들은 왼쪽 저울에 오건, 오른쪽 저울에 오건, 순서 전부 상관없음
        //남아있는 추의 수 = x라면
        //2^x*x!을 구해주어서 더함
        total_v += exp[N - cnt] * fact[N - cnt];
        return;
    }
     
    for (int i = 0; i < N; i++)
    {
        if (visited[i])continue;
        visited[i] = 1;
 
        makeSequence(cnt + 1, left + arr[i], right); //왼쪽에다가 달아보자!
        if (right + arr[i] <= left) //왼쪽보다 크지 않을때만
            makeSequence(cnt + 1, left, right + arr[i]); //오른쪽!
        visited[i] = 0;
    }
     
}
 
int main()
{
    scanf("%d", &T);
    for (int tc = 1; tc <= T; tc++)
    {
        scanf("%d", &N);
        total_v = 0;
        maxV = 0;
        memset(visited, 0, sizeof(visited));
        for (int i = 0; i < N; i++)
        {
            scanf("%d", &arr[i]);
            maxV += arr[i];
        }
 
        makeSequence(0, 0, 0);
        printf("#%d %d\n", tc, total_v);
    }
}
