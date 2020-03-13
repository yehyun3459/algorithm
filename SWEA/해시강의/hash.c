//https://swexpertacademy.com/main/visualcode/main.do#/home/editor//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <memory.h>

#define MAX_KEY 64
#define MAX_DATA 128
#define MAX_TABLE 4096

typedef struct
{
	char key[MAX_KEY + 1];
	char data[MAX_DATA + 1];
}Hash;
Hash tb[MAX_TABLE];

unsigned long hash(const char* str)
{
	unsigned long hash = 5381;
	int c;
	while(c=*str++)
	{
		hash = (((hash << 5) + hash) + c) % MAX_TABLE;
	}
	return hash % MAX_TABLE;
}
int find(const char *key, char* data)
{
	unsigned long h = hash(key);
	int cnt = MAX_TABLE;

	while(tb[h].key[0]!=0&&cnt--) //무한루프 방지
	{
		if(strcmp(tb[h].key,key)==0)
		{
			strcpy(data, tb[h].data);
			return 1; //찾았을 경우
		}
		h = (h + 1) % MAX_TABLE;
	}
	return 0; //찾지 못할 경우
}

//add는 입력값보다 테이블의 크기가 더 크므로
//굳이 cnt값을 둘 필요는 없다.
int add(const char *key, char *data)
{
	unsigned long h = hash(key);

	while(tb[h].key[0]!=0)
	{
		if(strcmp(tb[h].key,key)==0) //중복된 값이라면 에러 체크
		{
			return 0;
		}

		h = (h + 1) % MAX_TABLE; //그 다음 slot(비어있는 slot을 만날때까지)
	}
	strcpy(tb[h].key, key);
	strcpy(tb[h].data, data);
	return 1;
}
int T, N, Q;
int main()
{
	scanf("%d", &T);
	for(int tc=1;tc<=T;tc++)
	{
		scanf("%d", &N);
		
		char k[MAX_KEY + 1];
		char d[MAX_DATA + 1];

		for(int i=0;i<N;i++)
		{
			scanf("%s %s\n", &k, &d);
			add(k, d);
		}

		printf("#%d\n", tc);

		scanf("%d", &Q);
		for(int i=0;i<Q;i++)
		{
			char k[MAX_KEY + 1];
			char d[MAX_DATA + 1];

			scanf("%s\n", &k);

			if(find(k,d))
			{
				printf("%s\n", d);
			}
			else
			{
				printf("not find\n");
			}
		}
	}
}
