//정줄 놓고 풀었다가 풀이가 산으로 날아가서 계속 틀림
//이걸로 틀린다고..?를 4번이나 반복함
//어이없어서 저장
#include <iostream>
#include <cstring>
using namespace std;

int R, C, K;
bool board[1001][1001];
bool visited[1001][1001];
int br, bc, sr, sc;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int seq[4];//순서

int main()
{
	cin >> R >> C;
	cin >> K;
	while(K--)
	{
		cin >> br >> bc;
		board[br][bc] = 1;
	}
	cin >> sr >> sc;
	for (int i = 0; i < 4; i++)
	{
		cin >> seq[i];
		seq[i]--;
	}
	int cr = sr, cc = sc;
	int d_idx = 0; //얘때문에 계속 틀림
	visited[cr][cc] = 1;
	while(true)
	{
		int nr = cr + dx[seq[d_idx]];
		int nc = cc + dy[seq[d_idx]];
		if((nr<0||nr>=R||nc<0||nc>=C)||board[nr][nc]||visited[nr][nc])//방향 바꾸기
		{
			bool flag = false;
			for(int d=1;d<=4;d++)
			{
				d_idx = (d_idx + 1) % 4; //이걸로 계속 틀림(바본가?)
				int nnr = cr + dx[seq[d_idx]];
				int nnc = cc + dy[seq[d_idx]];
				if ((nnr < 0 || nnr >= R || nnc < 0 || nnc >= C) || board[nnr][nnc] || visited[nnr][nnc])continue;
				else
				{
					visited[nnr][nnc] = 1;
					cr = nnr;
					cc = nnc;
					flag = true;
					break;
				}
				
			}
			if (!flag)break;
		}
		else
		{
			visited[nr][nc] = 1;
			cr = nr;
			cc = nc;
		}

	}
	cout << cr << " " << cc << "\n";
}
