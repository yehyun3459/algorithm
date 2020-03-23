#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
typedef unsigned long long ull;
int T, N, M;
int arr[100001];

ull Solve()
{
    ull l = 0;
    ull r = 100000000000000;
    ull c;
    ull result = 0;
    while (l <= r) //모든 사람들이 처리되는 시간을 구하자!
    {
        ull m = (l + r) / 2;
        c = 0;
        //이건 완료시간이므로 처음에는(0초) 0으로 초기화 해주어야 함 ㅠ(m초에 완료된 사람 수임!!!)
        for (int i = 0; i < N; i++)
        {
            c += m / arr[i]; //현재 시간에 i번째 심사대에서 처리되는 사람 수
        }
        if (c >= M)
        {
            result = m; //현재 시간 저장
            r = m - 1;
        }
        else
        {
            l = m + 1;
        }
    }
    return result;
}

int main()
{
    scanf("%d", &T);
    for (int tc = 1; tc <= T; tc++)
    {
        scanf("%d %d", &N, &M);
        for (int i = 0; i < N; i++)
        {
            scanf("%d", &arr[i]);
        }
        printf("#%d %lld\n", tc, Solve());
    }
}
