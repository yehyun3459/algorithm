//내가 푼 코드 아니다....
//참고용으로 일단 업로드
//참고1 : https://privatedevelopnote.tistory.com/82
//참고2 : https://jaimemin.tistory.com/1022

//1. 마지막 아이까지 탑승한 시간을 구함 = time
//2. time-1분까지 탑승한 아이들을 구함
//3. time분 째에 탑승하는 아이들 중에서 마지막 아이가 탑승하는
//   놀이기구를 구함

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX 10001
typedef long long ll;

int N, M;
int ride[MAX];

ll binarySearch() //마지막 아이가 탑승한 시간을 구한다.
{
	ll l = 0, r = 60000000000;
	ll result = -1;
	while(l<=r)
	{
		ll m = (l + r) / 2;
		ll c = M; //children

		for(int i=0;i<M;i++)
		{
			c += m / ride[i];
		}

		if (c >= N) 
		{
			//탑승한 아이가 이미 N보다 많다면
			//좀더 적은 시간
			result = m;
			r = m - 1;
		}
		else l = m + 1; //아니라면 오른쪽
	}
	return result;
}

int main()
{
	scanf("%d %d", &N, &M);

	for (int i = 0; i < M; i++)scanf("%d", &ride[i]);

	if (N <= M)printf("%d\n", N);
	else //마지막 아이가 탑승한 시간을 구함!
	{
		ll time = binarySearch();
		ll c = M; //0분에는 이미 M개의 놀이기구에 전부 탑승
		//time-1 까지 탑승한 아이들을 전부 더함
		for (int i = 0; i < M; i++)
			c += (time - 1) / ride[i];
		//ex) tc 기준 
		//time - 1 : 7
		//7/1 = 7명, 7/2 = 3명 , 7/3 = 2명, 7/4 = 1명 , 7/5 = 1명
		// 총 5+7+3+2+1+1 = 19명
		
		//time에 탑승한 아이를 확인
		for(int i=0;i<M;i++)
		{
			if (!(time % ride[i]))c++; //c번째 아이가 탑승
			if (c == N)//마지막 아이라면 출력
			{
				printf("%d\n", i + 1);
				break;
			}
		}
	}
	return 0;
}
