//그냥 DFS로 했는데 잘 된다
//처음에는 마지막 더 갈곳이 없을때 모든 배열의 원소가 visited되었는지 일일이 비교해주었는데 그랬더니 시간이 한 1000ms가 나서...
//조금 수정해서 미리 빈 공간의 개수를 세어놓고 개수로 비교해주었더니 시간이 확실히 줄었다
//이 문제는
//1. 빈공간 찾기
//2. 무조건 한방향으로 뻗어나가서(일단 4방향 전부 시작) 장애물 만나면 나머지 3방향으로 depth 늘려나가기
//3. 조건에 맞으면 min값 갱신하기
//이렇게 풀었는데 input값이 작아서 그런지 시간초과 안나고 잘 돌아감
//좀 골치아픈 부분이 있었는데 아예 이동을 안하는 경우에 cnt 처리가 좀 짜증났다
//이 경우에는 아예 DFS 호출을 안하고 0 
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

#define MIN(a,b)(a<b?a:b)
int R, C;
char board[31][31];
int visited[31][31];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int minV = 987654321;
int tCnt = 0;

void DFS(int cnt,int r, int c,int d,int num)//d: 방향
{
	if (cnt >= minV)return;
	int nr = r + dx[d];
	int nc = c + dy[d];
	if(nr>=0&&nr<R&&nc>=0&&nc<C)
	{
		if (board[nr][nc] != '*' && !visited[nr][nc]) 
		{
			visited[nr][nc] = 1;
			DFS(cnt, nr, nc, d, num + 1);
			visited[nr][nc] = 0;
		}
		else//방향을 바꿔야 하는데...
		{
			for(int nd=0;nd<4;nd++)
			{
				if (nd == d)continue;
				nr = r + dx[nd];
				nc = c + dy[nd];
				if (nr < 0 || nr >= R || nc < 0 || nc >= C)continue;
				if (board[nr][nc] == '*' || visited[nr][nc])continue;
				visited[nr][nc] = 1;
				DFS(cnt + 1, nr, nc, nd, num + 1);
				visited[nr][nc] = 0;
			}
		}
	}
	else //방향을 바꿔야하는데...
	{
		for (int nd = 0; nd < 4; nd++)
		{
			if (nd == d)continue;
			nr = r + dx[nd];
			nc = c + dy[nd];
			if (nr < 0 || nr >= R || nc < 0 || nc >= C)continue;
			if (board[nr][nc] == '*' || visited[nr][nc])continue;
			visited[nr][nc] = 1;
			DFS(cnt + 1, nr, nc, nd, num + 1);
			visited[nr][nc] = 0;
		}
	}
	//만약 전부 실패하면 여기로 오겠지?
	if (num==tCnt) 
	{
		minV = MIN(minV, cnt);
		return;
	}
}

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	freopen("input.txt", "r", stdin);
	int num = 1;
	while(true)
	{
		cin >> R >> C;
		if(cin.eof()==true)
		{
			break;
		}
		for(int i=0;i<R;i++)
		{
			for (int j = 0; j < C; j++)
			{
				cin >> board[i][j];
				if (board[i][j] == '.')tCnt++;
			}
		}
		minV = 987654321;
		
		for(int i=0;i<R;i++)
		{
			for(int j=0;j<C;j++)
			{
				if(board[i][j]=='.')
				{
					for(int d=0;d<4;d++)
					{
						memset(visited, 0, sizeof(visited));
						visited[i][j] = 1;
						if(tCnt==1)
						{
							minV = 0;
							goto EXIT;
						}

						DFS(1, i, j, d, 1);
					}
					
				}
			}
		}
	EXIT:
		if (minV == 987654321)minV = -1;
		cout << "Case " << num << ": " << minV << "\n";
		
		num++;
		tCnt = 0;
	}
}
