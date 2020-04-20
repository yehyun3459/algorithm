//18500번 (미네랄2)에서도 정답이 나온다
//미네랄2에는 
//'클러스터가 떨어질 때, 그 클러스터 각 열의 맨 아래 부분 중 하나가 바닥 또는 미네랄 위로 떨어지는 입력만 주어진다.'
//조건이 없음(근데 저게 뭔소리인지 모르겠다)

//반례
/*
5 1
x
x
x
x
x
2
2 3
*/

//1. 음...일단 해당 높이의 미네랄을 지운다.
//2. 공중에 떠있는 미네랄을 찾고, 1씩 내려준다(중간에 걸려서 움직이지 않는 클러스터도 있어서..) ((visited 배열 사용해서 품))
//3. 반복하면 끝끟끗
//4. BFS할때 제발 맨 처음 인덱스 visited좀 표시해주자 ㅠㅠㅠ 이것때문에 틀림! 이 실수 자주함
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int R, C, N;
char board[101][101];

int harr[101]; //바닥의 높이 항상 저장
int q[20002][2];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int visited[101][101];

void BFS(int sr, int sc,int num)
{
	int f = 0, r = 0;
	q[r][0] = sr;
	q[r][1] = sc;
	visited[sr][sc] = num; //이거 안해줘서 20분간 헤맴 (바보니?)
	r++;
	while(f<r)
	{
		int cr = q[f][0];
		int cc = q[f][1];
		f++;
		for(int d=0;d<4;d++)
		{
			int nr = cr + dx[d];
			int nc = cc + dy[d];
			if (nr < 0 || nr >= R || nc < 0 || nc >= C)continue;
			if(board[nr][nc]=='x'&&!visited[nr][nc])
			{
				visited[nr][nc] = num;
				q[r][0] = nr;
				q[r][1] = nc;
				r++;
			}
		}
	}
}

int main()
{
	scanf("%d %d", &R, &C);
	for(int i=0;i<R;i++)
	{
		scanf("%s", board[i]);
	}

	scanf("%d", &N);
	int dir = 0;//0 왼쪽, 1 오른쪽
	while(N--)
	{
		int height;
		scanf("%d", &height);
		//1.없앤다.
		if(!dir)
		{
			for (int j = 0; j < C; j++)
			{
				if (board[R - height][j] == 'x')
				{
					board[R - height][j]='.';
					break;
				}
			}
		}else{
			for (int j = C-1; j >= 0; j--)
			{
				if (board[R - height][j] == 'x')
				{
					board[R - height][j] = '.';
					break;
				}
			}
		}
		
		//2.떠있는 곳이 있다면 내린다
		//2-1.바닥과 붙어있는 미네랄들을 보자꾸나...
		memset(visited, 0, sizeof(visited));

		int aircnt = 0;
		int num = 1;
		for(int i=R-1;i>=0;i--)
		{
			for (int j = 0; j < C; j++)
			{
				if (i == R - 1)
				{
					int cnt = 0;
					for (int r = R - 1; r >= 0; r--)
					{
						if (board[r][j] == 'x')cnt++;
						else break;
					}
					harr[j] = cnt;
				}
				if (board[i][j] == 'x'&&!visited[i][j])
				{
					if (i == R - 1)
					{
						BFS(R - 1, j, 1);
					}
					else
					{
						aircnt++;
						BFS(i, j, 2); //공중에 떠있는 클러스터
					}
				}
			}
		}
		int drop = 0;
		if(aircnt>0)
		{
			for (int i = R - 1; i >= 0; i--)
			{
				for (int j = 0; j < C; j++)
				{
					if(visited[i][j]==2)
					{
						drop = (R - harr[j] - 1) - i;
						i = -1;
						break;	
					}
					
				}
			}
			while(drop--)
			{
				bool flag = false;
				for (int i=R-1;i>=0;i--)
				{
					for (int j = 0; j < C; j++)
					{
						if (visited[i][j] == 2)
						{
							if(!visited[i+1][j])
							{
								visited[i + 1][j] = 2;
								visited[i][j] = 0;
							}
							else
							{
								flag = true;
								break;

							}
						}

					}
					if (flag)break;
				}
				if (flag)break;
				
				for (int i = R - 1; i >= 0; i--)
				{
					for (int j = 0; j < C; j++)
					{
						if (visited[i][j] > 0)board[i][j] = 'x';
						else board[i][j] = '.';
					}
				}
			}
			
		}
		dir = (dir + 1) % 2;
	}
	for(int i=0;i<R;i++)
	{
		for(int j=0;j<C;j++)
		{
			printf("%c", board[i][j]);
		}
		printf("\n");
	}
}
