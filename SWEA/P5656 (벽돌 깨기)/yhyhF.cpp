//함수로 정리

#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int board[15][12];
int tmp[15][12];
int minV = 987654321;

int sel[4]; //구슬 위치
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

struct Info
{
	int row;
	int col;
	int size;
};

int N, W, H;


void blockInit()
{
	for (int r = 0; r < H; r++)
	{
		for (int c = 0; c < W; c++)board[r][c] = tmp[r][c];
	}
}

void blockDrop()
{
	for (int c = 0; c < W; c++)
	{
		for (int r = H - 1; r >= 0; r--)
		{
			if (board[r][c] == 0) {

				for (int i = r - 1; i >= 0; i--)
				{
					if (board[i][c] > 0)
					{
						board[r][c] = board[i][c];
						board[i][c] = 0;
						break;
					}
				}
			}
		}
	}
}

int blockChk()
{
	int result = 0;
	for (int r = 0; r < H; r++)
	{
		for (int c = 0; c < W; c++)
		{
			if (board[r][c] > 0)result++;
		}
	}
	return result;
}

int blockDestroy() 
{
	int result = 0;
	for (int n = 0; n < N; n++)
	{
		int tr = 0;
		for (tr = 0; tr < H; tr++)if (board[tr][sel[n]] > 0)break;
		queue<Info> q;
		q.push({ tr,sel[n],board[tr][sel[n]] }); //현재 맨 위의 위치와 열을 저장

		board[tr][sel[n]] = 0;
		while (!q.empty())
		{
			int cr = q.front().row;
			int cc = q.front().col;
			int cs = q.front().size - 1;
			q.pop();
			for (int d = 0; d < 4; d++)
			{
				for (int s = 1; s <= cs; s++)
				{
					int nr = cr + dx[d] * s;
					int nc = cc + dy[d] * s;
					if (nr < 0 || nr >= H || nc < 0 || nc >= W)break;
					if (!board[nr][nc])continue;
					int ns = board[nr][nc];
					board[nr][nc] = 0; //삭제
					q.push({ nr,nc,ns });
				}
			}
		}
		blockDrop();
		result = blockChk();

		if (result == 0)
		{
			minV = 0;
			return 0;
		}
	}
	return result;
}



void Solve()
{
	for(int b1=0;b1<W;b1++)
	{
		sel[0] = b1;
		for(int b2=0;b2<W;b2++)
		{
			sel[1] = b2;
			for(int b3=0;b3<W;b3++)
			{
				sel[2] = b3;
				for(int b4=0;b4<W;b4++)
				{
					sel[3] = b4;

					blockInit();
					int result = blockDestroy();
					
					if (result == 0)return;

					if (result < minV)
					{
						minV = result;
					}
					if (N < 4)break;
				}
				if (N < 3)break;
			}
			if (N < 2)break;
		}
		
	}
	
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++)
	{
		cin >> N >> W >> H;
		memset(board, 0, sizeof(board));
		minV = 987654321;
		for (int r = 0; r < H; r++)
		{
			for (int c = 0; c < W; c++)
			{
				cin >> board[r][c];
				tmp[r][c] = board[r][c];
			}
		}

		Solve();

		cout << "#" << tc << " " << minV << "\n";
	}
	return 0;
}
