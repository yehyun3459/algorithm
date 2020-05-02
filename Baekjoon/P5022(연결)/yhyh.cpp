//input data : https://nordic.icpc.io/ncpc2010/
//이구역의 멍청이는 나야^^
//첫 번째 좌표는 0 이상 N 이하이며 두 번째 좌표는 0 이상 M 이하이다 
//0<=행<=M, 0<=열<=N이라는 의미인데 A, B 좌표인줄 알고 잘못풀어서 거의 1-2시간 삽질! ㅎㅎㅎㅎㅎㅎㅎ ^@^ 아하하하
//문제 접근법은 생각보다는 어렵지 않았다
//첨에 뭔소린가 많이 고민했는데
//그냥 A의 최적 경로 찾고-> B찾고, B찾고 ->A 찾고 이 두개 비교하면 됨
//좌표 visited 처리하는게 좀 많이 짜증났음 ㅇ<-< 에이
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

#define MIN(a,b)(a<b?a:b)
#define INF 987654321

int N, M;
int dist[101][101][2]; //방향을 저장해야 할까..?
int visited[101][101];
int A1r, A1c;
int A2r, A2c;
int B1r, B1c;
int B2r, B2c;

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

void BFS(int sr, int sc,int num)
{
	queue<pair<int, int>> q;
	dist[sr][sc][0] = 0;
	q.push({ sr,sc });
	while(!q.empty())
	{
		int cr = q.front().first;
		int cc = q.front().second;
		q.pop();
		if (num && (cr == A2r && cc == A2c))continue;
		if (!num && (cr == B2r && cc == B2c))continue;
		for(int d=0;d<4;d++)
		{
			int nr = cr + dx[d];
			int nc = cc + dy[d];
			if (nr<0 || nr>M || nc<0 || nc>N)continue; //이거땜에 계속~~틀림 ^^ 하하하
			
			if (visited[nr][nc])continue;//다른 좌표
			if(dist[nr][nc][0]==-1||dist[nr][nc][0]>dist[cr][cc][0]+1)
			{
				dist[nr][nc][0] = dist[cr][cc][0] + 1;
				dist[nr][nc][1] = d;
				q.push({ nr,nc });
			}
		}
	}
}


int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	memset(dist, -1, sizeof(dist));
	memset(visited, 0, sizeof(visited));
	cin >> N >> M;
	cin >> A1c >> A1r;
	cin >> A2c >> A2r;
	cin >> B1c >> B1r;
	cin >> B2c >> B2r;
	//일단 A의 최단거리를 구하고
	visited[B1r][B1c] = 1;
	visited[B2r][B2c] = 1;

	BFS(A1r, A1c, 1);
	int Atmp = dist[A2r][A2c][0];
	int cr, cc;
	int Btmp, ltmp=INF;
	visited[B1r][B1c] = 0;
	visited[B2r][B2c] = 0;
	if (Atmp != -1)
	{
		cr = A2r, cc = A2c;
		visited[A1r][A1c] = 1;
		while (cr != A1r || cc != A1c)//A경로 저장
		{
			visited[cr][cc] = 1;
			int dir = dist[cr][cc][1];
			if (dir == 0 || dir == 1)
			{
				cr = cr + dx[1 - dir];
				cc = cc + dy[1 - dir];
			}
			else
			{
				cr = cr + dx[5 - dir];
				cc = cc + dy[5 - dir];
			}
		}
		memset(dist, -1, sizeof(dist));

		BFS(B1r, B1c,0);
		Btmp = dist[B2r][B2c][0];
		if(Btmp!=-1)
			ltmp = Atmp + Btmp;
	}
	else ltmp = INF;
	//그다음 B의 최단거리를 구함
	
	//그다음에는 뒤집어서 다시 한번
	memset(dist, -1, sizeof(dist));
	memset(visited, 0, sizeof(visited));
	visited[A1r][A1c] = 1;
	visited[A2r][A2c] = 1;
	BFS(B1r, B1c, 0);
	Btmp = dist[B2r][B2c][0];
	visited[A1r][A1c] = 0;
	visited[A2r][A2c] = 0;
	if(Btmp!=-1)
	{
		cr = B2r, cc = B2c;
		visited[B1r][B1c] = 1;
		while (cr != B1r || cc != B1c)//B경로 저장
		{
			visited[cr][cc] = 1;
			int dir = dist[cr][cc][1];
			if (dir == 0 || dir == 1)
			{
				cr = cr + dx[1 - dir];
				cc = cc + dy[1 - dir];
			}
			else
			{
				cr = cr + dx[5 - dir];
				cc = cc + dy[5 - dir];
			}
		}
		//그다음 A의 최단거리를 구함
		memset(dist, -1, sizeof(dist));
		BFS(A1r, A1c,1);
		Atmp = dist[A2r][A2c][0];
		if(Atmp!=-1)
			ltmp = MIN(ltmp, Atmp + Btmp);
	}
	if(ltmp==INF)
	{
		cout << "IMPOSSIBLE\n";
	}
	else cout << ltmp << "\n";
}
