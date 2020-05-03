//옛날에 풀던 방식으로 풀려다가 삽질했다 ㅠㅠ
//그냥 음...이게 가능한가 싶었는데
//열쇠 찾을때마다 visited 0으로 초기화 하고, 같은 열쇠, 열쇠로 열리는 문을 전부 열어버리면 쉽게 해결이 가능하다
//왜 간단한 해결법을 생각하지 못했지? 특히 열쇠 찾을때마다 visited 0으로 초기화 부분...
//그리고 string 으로 키를 입력받으니까 0인 경우에 진짜 "0"으로 입력받아서(그냥 '\0'으로 받을줄..) keys[key[s]-'a'] 이부분에서 런타임 에러 났음
//위와 같은 오류가 나지 않도록 조심해야할것같다
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <string>
#include <cstring>
using namespace std;

int T, H, W;
char board[102][102];
int visited[102][102];
int keys[27];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

int dcnt = 0;
queue<pair<int, int>> q;

void openDoors(char door,char key)
{
	for(int i=1;i<=H;i++)
	{
		for(int j=1;j<=W;j++)
		{
			if(board[i][j]==door||board[i][j]==key)
			{
				board[i][j] = '.';
			}
		}
	}
	memset(visited, 0, sizeof(visited));
}

void BFS()
{
	q.push({ 0,0 });
	visited[0][0] = 1;
	while(!q.empty())
	{
		int cr = q.front().first;
		int cc = q.front().second;
		q.pop();
		for(int d=0;d<4;d++)
		{
			int nr = cr + dx[d];
			int nc = cc + dy[d];
			if (nr < 0 || nr > H+1 || nc < 0 || nc > W+1)continue;
			if (visited[nr][nc])continue;
			if (board[nr][nc] == '*'||(board[nr][nc] >= 'A' && board[nr][nc] <= 'Z'))continue;
			else if(board[nr][nc]=='.')
			{
				visited[nr][nc] = 1;
				q.push({ nr,nc });
			}
			else if(board[nr][nc]>='a'&&board[nr][nc]<='z')
			{
				keys[board[nr][nc] - 'a'] = 1;
				openDoors(board[nr][nc] - 32,board[nr][nc]); //문 전부 열어버리기
				visited[nr][nc] = 1;
				board[nr][nc] = '.';
				q.push({ nr,nc });
			}
			else //문서
			{
				board[nr][nc] = '.';
				dcnt++;
				visited[nr][nc] = 1;
				q.push({ nr,nc });
			}
		}
	}
}
int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	cin >> T;
	while(T--)
	{
		cin >> H >> W;
		
		for(int i=1;i<=H;i++)
		{
			for(int j=1;j<=W;j++)
			{
				cin >> board[i][j];
			}
		}
		memset(visited, 0, sizeof(visited));
		memset(keys, 0, sizeof(keys));
		string key;
		cin >> key;
		if(key!="0")
		{
			for (int s = 0; s < key.length(); s++)
			{
				keys[key[s] - 'a'] = 1;
			}
		}
		
		for (int i = 0; i <= H + 1; i++)
		{
			for (int j = 0; j <= W + 1; j++)
			{
				if(i==0||i==H+1||j==0||j==W+1)
				{
					board[i][j] = '.';
				}
				else
				{
					if(board[i][j]>='A'&&board[i][j]<='Z'&&keys[board[i][j]-'A'])//미리 문 열어버리기
					{
						board[i][j] = '.';
					}
				}
			}
		}


		BFS();
		cout << dcnt << "\n";
		dcnt = 0;
	}
}
