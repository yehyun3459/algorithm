//투포인터라는 개념을 처음 배움! 잘 써먹어야 겠다..
//나중에 이거랑 관련된 문제를 좀 풀어봐야겠다....
//최솟값과 최댓값을 지정해놓고 탐색할 수 있는가를 체크하며 풀이함
//parametric search로도 풀 수 있는 문제.........(? 잘 모르겠음)
#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAX(a,b)(a>b?a:b)
#define MIN(a,b)(a<b?a:b)
int N;
char board[51][51];
int alt[51][51];//고도

vector<int> tired; //투포인터를 위해...
bool visited[51][51];

int townCnt = 0;
int sr, sc;

int dx[8] = { -1,-1,-1,0,0,1,1,1 };
int dy[8] = { -1,0,1,-1,1,-1,0,1 };

struct Info
{
	int row;
	int col;
};

bool BFS(int minH,int maxH)
{
	int cnt = 0;
	if (alt[sr][sc]<minH || alt[sr][sc]>maxH)return false; //범위에 들어오지 않으므로 false
	memset(visited, 0, sizeof(visited)); 
	queue<Info> q;
	q.push({ sr,sc });
	visited[sr][sc] = 1;
	while (!q.empty())
	{
		int cr = q.front().row;
		int cc = q.front().col;
		if (board[cr][cc] == 'K')cnt++;
		q.pop();
		
		for (int d = 0; d < 8; d++)
		{
			int nr = cr + dx[d];
			int nc = cc + dy[d];
			if (nr < 0 || nr >= N || nc < 0 || nc >= N)continue;
			if (visited[nr][nc])continue;
			visited[nr][nc] = 1;
			if (alt[nr][nc]<minH || alt[nr][nc]>maxH)continue;
			q.push({ nr,nc });
		}
	}
	if (cnt == townCnt)return true;
	return false;
}

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> board[i][j];
			if (board[i][j] == 'P')
			{
				sr = i;
				sc = j;
			}
			else if (board[i][j] == 'K')
			{
				townCnt++;
			}
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> alt[i][j];
			tired.push_back(alt[i][j]);
		}
	}

	sort(tired.begin(), tired.end());
	tired.erase(unique(tired.begin(), tired.end()), tired.end()); //중복된 원소 삭제

	int s=0, e = 0;
	int result = 987654321;
	while(s<tired.size()&&e<tired.size())
	{
		int minV = tired[s], maxV = tired[e];

		if (BFS(minV, maxV))//성공한다면
		{
			result = MIN(result, (maxV - minV));
			s++;
		}
		else e++; //실패한다면
	}
	cout << result << "\n";

}
