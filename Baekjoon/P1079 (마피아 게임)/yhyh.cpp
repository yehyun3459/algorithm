//문제 잘못봐서 삽질^^ 모든 참가자는 0부터 시작한다!!!!!!!!!!!!!!!!!!!!!!!!!!
//은진이 번호를 제대로 고려하지 못해서 틀림
//초반에 문제를 잘못 읽음
//은진이가 최적의 경우를 고를때 총 몇번의 밤이 지나가는가
//----> 은진이가 최대 얼마나 살아있을 수 
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
using namespace std;
#define MAX_SIZE 16
#define MAX(a,b)(a>b?a:b)

int N;
int guilty[MAX_SIZE];
int R[MAX_SIZE][MAX_SIZE];

int inValid[MAX_SIZE];
int Eunjin;
int retV = 0;

bool flag = false;
//num : 남아있는 사람 수
void makeSequence(int num, int cnt)//은진이가 죽일 사람의 순서를 구한다(n/2)만큼, 사람을 죽여가며(..) 해보자
{
	if (flag)return;
	if (inValid[Eunjin] || num == 1) //잘가~~
	{
		retV = MAX(retV, cnt); //문제를 잘못읽은것 같다...
		if (!inValid[Eunjin] && num == 1)flag = true; //한명남았는데 그게 은진이라면? 더 구할필요 없음(이 부분을 제대로 안하면 시간초과)
		return;
	}
	if (num & 1) //낮
	{
		int maxI = -1;
		for (int i = 0; i < N; i++)
		{
			if (inValid[i])continue; //이미 죽었어!
			if (maxI == -1)maxI = i;
			else if (guilty[maxI] < guilty[i])maxI = i;
		}

		inValid[maxI] = 1; //죽어쒀
		makeSequence(num - 1, cnt); //날짜 추가 x
		if (flag)return;
		inValid[maxI] = 0;

	}
	else //밤
	{
		for (int i = 0; i < N; i++)
		{
			if (inValid[i] || i == Eunjin)continue;
			inValid[i] = 1;
			for (int j = 0; j < N; j++)
			{
				if (inValid[j])continue;
				guilty[j] += R[i][j];
			} //유죄지수를 더함
			makeSequence(num - 1, cnt + 1);
			if (flag)return;

			for (int j = 0; j < N; j++)
			{
				if (inValid[j])continue;
				guilty[j] -= R[i][j];
			} //유죄지수를 다시 빼줌
			inValid[i] = 0;
		}
	}

}
int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &guilty[i]);
		inValid[i] = 0;
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)scanf("%d", &R[i][j]);
	}
	scanf("%d", &Eunjin);
	makeSequence(N, 0);
	printf("%d\n", retV);
}
