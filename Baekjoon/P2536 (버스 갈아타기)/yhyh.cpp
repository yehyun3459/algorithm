//문제 해결법을 빨리 파악하지 못해서 엄청 오래 품...
//그냥 다익스트라 문제였다 ㅎ
//한 좌표에서 다음 좌표(버스 갈아타는거) 하는게 좀 힘들었다...
//수직 선분과 수평 선분의 교차점이 범위에 들어가는지, 기울기가 같은 경우라면 구간이 겹치는지를 체크해서 다익스트라 돌리면 됨
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MIN(a,b)(a<b?a:b)
int M, N, K;
int buses[5001][5]; //x1,y1,x2,y2, 0=v,1=h
int busDist[5001]; //아 다익스트라였어요..... ㅇ<-< 이런 멍청이...(현재 거쳐간 버스 개수)
int sx, sy, dx, dy; //방문처리는 못하나..?어떻게 하지.. <---할 필요가 없었다~~~
int minV;
bool isGoToDst[5001]; //목적지로 가는 

int q[20002];//버스 번호

void Solve()
{
    int f = 0, r = 0;
    for (int i = 1; i <= K; i++)//출발지를 거쳐가는 버스 찾기
    {
        if (!buses[i][4])//vertical
        {
            if (buses[i][0] == dx && buses[i][1] <= dy && buses[i][3] >= dy)
            {
                isGoToDst[i] = 1;
            }

            if (buses[i][0] == sx && buses[i][1] <= sy && buses[i][3] >= sy)
            {
                if (isGoToDst[i])
                {
                    minV = 1;
                    return;
                }
                busDist[i] = 1;
                q[r] = i;
                r++;
            }
        }
        else //horizontal
        {
            if (buses[i][1] == dy && buses[i][0] <= dx && buses[i][2] >= dx)
            {
                isGoToDst[i] = 1;
            }

            if (buses[i][1] == sy && buses[i][0] <= sx && buses[i][2] >= sx)
            {
                if (isGoToDst[i])
                {
                    minV = 1;
                    return;
                }
                busDist[i] = 1;
                q[r] = i;
                r++;
            }
        }
    }
    while (f<r)
    {
        int cb = q[f];
        f++;
        
        int t1, t2;
        t1 = 0, t2 = 1;
        if (buses[cb][4])
        {
            t1 = 1, t2 = 0;
        }
        for (int i = 1; i <= K; i++)//현재 지점을 거쳐가는 버스 찾기..?
        {
            if (i == cb)continue;
            if (buses[cb][4] == buses[i][4]) //같은 수평선(혹은 수직선)인데 범위가 겹칠경우
            {
                if (buses[i][t1] != buses[cb][t1])continue;
                if ((buses[i][t2] <= buses[cb][t2] && buses[cb][t2] <= buses[i][t2 + 2])
                    || (buses[i][t2] <= buses[cb][t2 + 2] && buses[cb][t2 + 2] <= buses[i][t2 + 2])) //겹치는 구간이 있는가?
                {
                    if (isGoToDst[i])
                    {
                        minV = MIN(minV, busDist[cb] + 1);
                    }
                    else
                    {
                        if(busDist[i]> busDist[cb] + 1)
                        {
                            busDist[i] = busDist[cb] + 1;
                            q[r]= i;
                            r++;
                        }
                    }
                }
            }
            else
            {
                int i1 = buses[cb][t1], i2 = buses[i][t2];
                if ((buses[cb][t2] <= i2 && i2 <= buses[cb][t2 + 2])
                    && (buses[i][t1] <= i1 && i1 <= buses[i][t1 + 2])) //교차점이 두 선분 안에 포함되어 있어야 함
                {
                    if (isGoToDst[i])
                    {
                        minV = MIN(minV, busDist[cb] + 1);
                    }
                    if (busDist[i] > busDist[cb] + 1)
                    {
                        busDist[i] = busDist[cb] + 1;
                        q[r] = i;
                        r++;
                    }
                }
            }
        }
    }
}
int main()
{
    scanf("%d %d", &M, &N);
    scanf("%d", &K);

    int b, x1, y1, x2, y2;
    for (int k = 1; k <= K; k++)
    {
        scanf("%d %d %d %d %d", &b, &x1, &y1, &x2, &y2);
        if (x1 == x2)
        {
            if (y1 > y2) //무조건 오름차순으로
            {
                buses[b][1] = y2, buses[b][3] = y1;
            }
            else
            {
                buses[b][1] = y1, buses[b][3] = y2;
            }
            buses[b][0] = x1, buses[b][2] = x2;
            buses[b][4] = 0; //vertical
        }
        else
        {
            if (x1 > x2)
            {
                buses[b][0] = x2, buses[b][2] = x1;
            }
            else
            {
                buses[b][0] = x1, buses[b][2] = x2;
            }
            buses[b][1] = y1, buses[b][3] = y2;
            buses[b][4] = 1; //horizontal
        }

        isGoToDst[b] = 0;
        busDist[b] = K;
    }
    scanf("%d %d %d %d", &sx, &sy, &dx, &dy);
    minV = K; //최댓값 : 모든 버스의 수(출발지-목적지 경로가 있음을 보장하므로)
    Solve();
    printf("%d\n", minV);
}
