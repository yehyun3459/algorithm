//떨어지는거 처리 외에는 크게 어려움이 없는 문제
//떨어지는거 ii!=-1 예외처리를 안해주어서 문제에서 오답이 발생했다 이부분 자주 실수하는 듯 ㅠㅠㅠ
//1. 일단 뭉쳐져 있는거 BFS로 개수 구하고, 4이상이면 지워버림
//2. 떨어뜨림
//1-2를 
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

char board[13][7];
int visited[13][7];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
void Drop()
{
	for(int j=0;j<6;j++)
	{
		for(int i=11;i>=0;i--)
		{
			if(board[i][j]=='.')
			{
				int ii = i - 1;
				for(;ii>=0;ii--)
				{
					if (board[ii][j] != '.')break;
				}
				if(ii!=-1)
				{
					board[i][j] = board[ii][j];
					board[ii][j] = '.';
				}
				
			}
		}
	}
}
bool BFS(int sr,int sc)
{
	int cnt = 0;
	visited[sr][sc] = 1;
	cnt++;
	queue<pair<int, int>> q;
	queue<pair<int, int>> sq;//저장할 큐
	q.push({ sr,sc });
	
	while(!q.empty())
	{
		int cr = q.front().first;
		int cc = q.front().second;
		sq.push({ cr,cc });
		q.pop();
		for(int d=0;d<4;d++)
		{
			int nr = cr + dx[d];
			int nc = cc + dy[d];
			if (nr < 0 || nr >= 12 || nc < 0 || nc >= 6)continue;
			if (board[nr][nc] != board[cr][cc] || visited[nr][nc])continue;
			visited[nr][nc] = 1;
			q.push({ nr,nc });
		}
	}
	if(sq.size()>=4)
	{
		while(!sq.empty())//erase
		{
			board[sq.front().first][sq.front().second] = '.';
			sq.pop();
		}
		return true;
	}
	return false;
}
int main()
{

	for(int i=0;i<12;i++)
	{
		cin >> board[i];
	}
	int num = 0;
	while(true)
	{
		bool flag = false;
		memset(visited, 0, sizeof(visited));
		for (int i = 0; i < 12; i++)
		{
			for (int j = 0; j < 6; j++)
			{
				if (board[i][j] != '.' && !visited[i][j])
				{
					if(BFS(i, j))flag=true;
				}
			}
		}
		if (!flag)break;//지워지는게 하나도없을때 break;
		Drop();
		num++;
	}
	cout << num << "\n";
}
