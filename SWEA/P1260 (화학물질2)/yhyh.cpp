#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;
#define MAX_SIZE 102
#define MIN(a,b)(a<b?a:b)
 
int T, N;
int board[MAX_SIZE][MAX_SIZE];
int arr[MAX_SIZE][2];
int P[MAX_SIZE];
int M[MAX_SIZE][MAX_SIZE];
int uniI;
 
struct cntInfo
{
    int cnt;
    int ind;
};
cntInfo cntR[MAX_SIZE];
 
void makeSequence(int n) //순서 생성 (약간...스택...?비스무리하게 푼것같은 느낌적인 느낌)
{
    int f = 0;
    int r = n - 1;
     
    P[0] = arr[uniI][0];
    int tmpc = arr[uniI][1];
    f++;
 
 
    arr[uniI][0] = arr[r][0];
    arr[uniI][1] = arr[r][1];
    r--;
    while (f < n)
    {
        for (int i = 0; i <= r; i++)
        {
            if (arr[i][0] == tmpc)
            {
                P[f] = arr[i][0];
                tmpc = arr[i][1];
                f++;
                arr[i][0] = arr[r][0];
                arr[i][1] = arr[r][1];
                r--;
                break;
            }
        }
    }
    P[f] = tmpc;
}
 
void solveMatrix(int n)
{
    int d = 1; //열-행의 차이
    while(d<n)
    {
        for(int i=1;i<=n;i++)
        {
            int j = i + d;
            if (j > n)break;
            M[i][j] = 987654321;
            for (int k = i; k < j; k++)
                M[i][j] = MIN(M[i][j], M[i][k] + M[k + 1][j] + P[i - 1] * P[k] * P[j]); //연속행렬곱
        }
        d++;
    }
    printf(" %d\n", M[1][n]);
 
}
 
void Solve()
{
    int t = 0;
    int maxR = 0;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            if (board[i][j])
            {
                if (!board[i - 1][j] && !board[i][j - 1]) //시작
                {
                    int c = j;
                    int r = i;
                    while (c <= N && board[i][c])c++;
                    while (r <= N && board[r][j])r++;
                   
                    arr[t][0] = r - i;
                    arr[t][1] = c - j;
                    if (maxR < arr[t][0])maxR = arr[t][0];
                    cntR[arr[t][0]].cnt += 1;
                    cntR[arr[t][1]].cnt += 2;
                    cntR[arr[t][0]].ind = t;
                    t++;
                }
            }
        }
    }
    for (int i = 1; i <= maxR; i++) //시작점을 정함
    {
        if (cntR[i].cnt == 1)
        {
            uniI = cntR[i].ind;
            break;
        }
    }
    makeSequence(t); //순서쌍을 만들기 (행렬 P 만들기)
 
    solveMatrix(t);
     
}
 
int main()
{
    scanf("%d", &T);
 
    for (int tc = 1; tc <= T; tc++)
    {
        scanf("%d", &N);
         
        memset(board, 0, sizeof(board));
        memset(arr, 0, sizeof(arr));
        memset(P, 0, sizeof(P));
        memset(M, 0, sizeof(M));
         
        for (int i = 1; i <= N; i++)
        {
            cntR[i] = { 0,0 }; //초기화
            for (int j = 1; j <= N; j++)scanf("%d", &board[i][j]);
        }
 
        printf("#%d", tc);
        Solve();
    }
}
