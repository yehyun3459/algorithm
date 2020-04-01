//0은 참가자가 들어갈 수 없는! 곳
//1은 참가자가 들어갈 수 있는 곳 (헷갈리지 말자..)
//문제 풀이
//1. 회전
//2. 순열로 순서 정하기
//3. 최단거리 구함
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define INF 987654321

int minValue = 12; //최솟값이 무조건 12이므로 이미 12가 나왔다면 바로 리턴!

int maze[5][5][5]; //기존 배열, 회전 수행
int visited[5][5][5]; //최단경로시 방문 확인
int dist[5][5][5]; //dijkstra
int vis[5]; //순열 visited 배열
int sel[5][5][5];//순서까지 선택됨 -> 최단거리에서 사용
int minV = INF;
int q[1000][3]; //queue
int f, r;

int dx[6] = {0,0,-1,1,0,0};
int dy[6] = {0,0,0,0,-1,1};
int dz[6] = {-1,1,0,0,0,0};

void rotate(int floor) //회전
{
	int k = floor - 1;
	int tmp[5][5];
	for(int i=0;i<5;i++)
	{
		for(int j=0;j<5;j++)
		{
			tmp[i][j] = maze[k][4-j][i];
		}
	}
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			maze[k][i][j] = tmp[i][j];
		}
	}
}

void Solve() //최단경로 구함
{
	if (!sel[0][0][0] || !sel[4][4][4])return; //입구, 출구가 막혀있다면 바로 리턴
	for (int k = 0; k < 5; k++)
	{
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				dist[k][i][j] = INF;
				visited[k][i][j] = 0;
			}
		}
	}

	dist[0][0][0] = 0;
	f = r = 0;
	q[r][0] = 0;
	q[r][1] = 0;
	q[r][2] = 0;
	r++;
	while(f<=r)
	{
		int cf = q[f][0];
		int cr = q[f][1];
		int cc = q[f][2];
		f++;
		if (visited[cf][cr][cc])continue;
		visited[cf][cr][cc] = 1;
		for(int d=0;d<6;d++)
		{
			int nf = cf + dz[d];
			int nr = cr + dx[d];
			int nc = cc + dy[d];
			if (nf < 0 || nf >= 5 || nr < 0 || nr >= 5 || nc < 0 || nc >= 5)continue;
			if(sel[nf][nr][nc]&&dist[cf][cr][cc]+1<dist[nf][nr][nc])
			{
				dist[nf][nr][nc] = dist[cf][cr][cc] + 1;
				q[r][0] = nf;
				q[r][1] = nr;
				q[r][2] = nc;
				r++;
			}
		}
	}
	if (minV > dist[4][4][4])minV = dist[4][4][4];
}



void SelectSeq(int cnt)
{
	if (minV <= minValue)return; //이미 최솟값 나옴
	if(cnt>=5)
	{
		Solve();
		return;
	}
	for(int i=0;i<5;i++)
	{
		if (vis[i])continue;
		vis[i] = 1;
		
		for(int r=0;r<5;r++)
		{
			for(int c=0;c<5;c++)
			{
				sel[cnt][r][c] = maze[i][r][c];
			}
		}
		SelectSeq(cnt + 1);
		vis[i] = 0;
		
	}
}

int main()
{
	for(int k=0;k<5;k++)
	{
		for(int i=0;i<5;i++)
		{
			for (int j = 0; j < 5; j++)scanf("%d", &maze[k][i][j]);
		}
	}
	for(int n1=0;n1<4;n1++)
	{
		for (int n2 = 0; n2 < 4; n2++)
		{
			for (int n3 = 0; n3 < 4; n3++)
			{
				for (int n4 = 0; n4 < 4; n4++)
				{
					for (int n5 = 0; n5 < 4; n5++)
					{
						memset(vis, 0, sizeof(vis));
						SelectSeq(0);
						if(minV<=minValue) //이미 최솟값 나왔으면 출력하고 종료
						{
							printf("%d\n", minV);
							return 0;
						}
						rotate(5);
					}
					rotate(4);
				}
				rotate(3);
			}
			rotate(2);
		}
		rotate(1);
	}

	if (minV == INF)minV = -1;
	printf("%d\n", minV);
}
