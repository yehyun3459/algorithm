#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX_SIZE 60

int N;
int tree[MAX_SIZE][MAX_SIZE]; //1. 부모노드 2.자식 개수 3~N-1. 자식들
int que[200];

int main()
{
	scanf("%d", &N);
	int tmp;
	int rootN = 0;
	for(int i=0;i<N;i++)
	{
		scanf("%d", &tmp);
		tree[i][0] = tmp; //부모
		if (tmp != -1)
		{
			int cind = tree[tmp][1];
			tree[tmp][cind + 2] = i;
			tree[tmp][1]++;
			//첫번째 자식 인덱스 : 2
		}
		else rootN = i;
	}
	int delNode;
	scanf("%d", &delNode);
	tree[delNode][1] = 0;
	
	int pd = tree[delNode][0];
	if (pd == -1) //만약 루트 노드가 삭제된다면? 안녕~
	{
		printf("%d\n", 0);
		return 0;
	}

	tree[pd][1]--; //부모노드의 자식 하나 삭제

	
	if(!tree[rootN][1]) //만약 루트 노드의 자식이 없다면? 루트 노드가 유일한 리프 노드
	{
		printf("%d\n", 1);
		return 0;
	}

	int result = 0;
	int f, r;
	f = r = 0;
	que[r] = rootN; //루트 노드부터 시작!
	r++;
	while(f<r) //큐에 넣어서 리프 노드를 찾아주자.
	{
		int cn = que[f];
		f++;
		
		int cnt = tree[cn][1];
		int i = 0;
		while(cnt--)
		{
			int nn = tree[cn][i + 2];
			i++;
			if(nn==delNode) //만약 자식 노드가 삭제된 노드라면 패스
			{
				cnt++;
				continue;
			}
			if (!tree[nn][1])result++; //자식 노드에 자식이 없다면 개수 추가
			else //자식 있다면 큐에 추가
			{
				que[r] = nn;
				r++;
			}
		}
	}
	printf("%d\n", result);

	return 0;
}
