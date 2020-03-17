//옛날 코드
#include <iostream>
#include <vector>
using namespace std;
 
#define MIN(a,b)(a<b?a:b)
 
int N;
int board[101][101];
int dx[2] = { -1,0 }; //위와 왼쪽을 참조
int dy[2] = { 0,-1 };
 
vector<pair<int,int>> rcInfo;
int p[21];
int matrix[21][21];
int snext[21];
int sprev[21];
 
int makeSequence()//행렬 곱셈의 순서를 만들자
{
    int N = rcInfo.size();
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (i == j)continue;
            if (rcInfo[i].second == rcInfo[j].first)
            {
                snext[i] = j; //다음하고 이전을 이어버림(오...)
                sprev[j] = i;
                break;
            }
        }
    }
    int start = 0;
    for (int i = 0; i < N; i++)
    {
        if (sprev[i] == -1)
        {
            start = i;
            break;
        }
    }
 
    int top = 0;
    while (1) //그래서 순서대로 연결!
    {
        p[top] = rcInfo[start].first;
        top++;
        if(snext[start]==-1)break;
        start = snext[start];
 
    }
    p[top] = rcInfo[start].second;
 
    return top;
}
 
 
int makeMatrix()
{
    int mSize = makeSequence();
     
    for (int i = 1; i <= mSize; i++)matrix[i][i] = 0;
 
    for(int l=2;l<=mSize;l++)
    {
        for(int i=1;i<=mSize-l+1;i++)
        {
            int j = i + l - 1;        
             
            for (int k = i; k < j; k++)
                matrix[i][j] = MIN(matrix[i][j], matrix[i][k] + matrix[k + 1][j] + p[i - 1] * p[k] * p[j]);
        }
    }
     
    return matrix[1][mSize];
}
 
void checkNum(int row, int col) //대체 왜 이렇게 구현했는지 알다가도 모를..?
{
    int rCnt = 0, cCnt = 0;
    int nrow = row, ncol = col;
    while (true)
    {
        nrow = nrow + 1;
        if (nrow >= N)break;
        if (board[nrow][col] == 0)break;
        rCnt++;
    }
    while (true)
    {
        ncol = ncol + 1;
        if (ncol >= N)break;
        if (board[row][ncol] == 0)break;
        cCnt++;
    }
    rCnt += 1;
    cCnt += 1;
    rcInfo.push_back({ rCnt,cCnt });
}
 
void Init()
{
    rcInfo.clear();
    for (int i = 0; i <= 20; i++)
    {
        snext[i] = -1;
        sprev[i] = -1;
        p[i] = 0;
        for (int j = i; j <= 20; j++)matrix[i][j] = 987654321;
    }
}
 
int main()
{
    int T;
    cin >> T;
    for (int tc = 1; tc <= T; tc++)
    {
        Init(); //초기화
        cin >> N;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)cin >> board[i][j];
        }
 
        for (int i = 0; i < N; i++) //이렇게 하기 귀찮아서 두번째 코드에서는 상하좌우 + 1 해서 감싸버림
        {
            for (int j = 0; j < N; j++)
            {
                if (board[i][j] == 0)continue;
                if (i == 0 && j == 0)//맨 위,왼쪽에있음
                {
                    checkNum(i, j);
                }
                else if (i == 0)//맨 위에 있음(왼쪽만 검사)
                {
                    if (board[i][j - 1] == 0)checkNum(i, j);
                    else continue;
                }
                else if (j == 0)//맨 왼쪽 (위에만 검사)
                {
                    if (board[i - 1][j] == 0)checkNum(i, j);
                    else continue;
                }
                else //위, 왼쪽 검사
                {
                    if (board[i - 1][j] == 0 && board[i][j - 1] == 0)checkNum(i, j);
                    else continue;
                }
            }
        }
        cout<<"#"<<tc<<" "<<makeMatrix()<<"\n";
    }
    return 0;
}
