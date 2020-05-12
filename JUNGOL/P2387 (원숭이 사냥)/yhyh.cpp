//정올에서는 잘 돌아가는 소스
//백준에서는 시간초과로 틀림 --> 따라서 수정한 코드는 백준 카테고리 밑에 따로 

//특이한 문제...
//문제 푼 사람들 코드를 다 봤는데 모두 모든 나무에 원숭이를 넣고 죽여가면서(...) 0이 되는 지점을 찾아서 풀었다
//개중에 넘나 멋있는 코드 참고함
//출처 : http://www.cppblog.com/y346491470/articles/159298.html 천재인가
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
 
#define MAXN 22
int N, M;
int adj[MAXN]; //인접한 간선들을 전부 비트 처리함
int visited[1 << MAXN];//헷갈려... 현재 원숭이가 살아있는 상태
int pre[1 << MAXN][2]; //이전 상태와 인덱스 참조
 
bool BFS()
{
    queue<int> q;
    q.push((1 << N) - 1);
    visited[(1 << N) - 1] = 0;
    while(!q.empty())
    {
        int cs = q.front();//현재 살아있는 원숭이
        q.pop();
        for(int i=0;i<N;i++)//모든 나무들을 뒤져보자!
        {
            if(cs&(1<<i))//i번째 나무에 원숭이가 존재함
            {
                int ks = cs ^ (1 << i); //i번째 원숭이를 죽여버림
                int ns = 0;
                for(int j=0;j<N;j++) //현재 상태(i번째 원숭이 죽음)에서 원숭이들이 인접한 곳으로 이동함
                {
                    //현재 상태에서 j번째 나무에 원숭이가 존재할때 j나무의 인접한 나무로 이동한다
                    //따라서 모든 가능한 상태를 ns에 넣어버리는거! (아 헷갈려)
                    if (ks & (1 << j))ns |= adj[j]; 
                }
                if (visited[ns]!=-1)continue; //이미 방문했음
                visited[ns] = visited[cs] + 1;
                pre[ns][0] = cs; //이전 원숭이들 상태를 저장함
                pre[ns][1] = i; //이전에 쏘았던 나무 인덱스 저장
                q.push(ns);
                if (!ns)return true;
 
            }
        }
    }
    return false;
}
 
void printResult(int state) //백트래킹으로 경로 출력함
{
    if (state == ((1 << N) - 1))return;
    printResult(pre[state][0]);
    cout << pre[state][1] << " ";
}
 
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    while(true)
    {
        cin >> N >> M;
        if (!N && !M)break;
        int a, b;
        memset(adj, 0, sizeof(adj));
        memset(visited, -1, sizeof(visited));
        memset(pre, 0, sizeof(pre));
 
        while(M--)
        {
            cin >> a >> b;
            adj[a] |= (1 << b);
            adj[b] |= (1 << a);
        }
        if (BFS())
        {
            cout << visited[0] << ": ";
            printResult(0);
            cout << "\n";
        }
        else cout << "Impossible\n";
    }
 
}
