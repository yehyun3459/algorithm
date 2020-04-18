//1.브론즈인데 너무 많이 틀려서..흑흑
//2. - 'A'를 해주어야 하는데 -'0'을 해주어서 틀렸다 (자주하는 실수..ㅠㅠ)
//3. 불가능한 경우(0)을 출력하지 않아서 틀림
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

char _str[6][4];
int valid[27][27][27];

int main()
{
	memset(valid, 0, sizeof(valid));
	memset(_str, 0, sizeof(_str));
	for(int i=0;i<6;i++)
	{
		scanf("%s", _str[i]);
		valid[_str[i][0] - 'A'][_str[i][1] - 'A'][_str[i][2] - 'A']++; //카운트 처리(인덱스반환)
	}

	for(int i1=0;i1<6;i1++) //완탐...이라고 생각하면 되려나..?
	{
		valid[_str[i1][0] - 'A'][_str[i1][1] - 'A'][_str[i1][2] - 'A']--;
		for (int i2 = 0; i2 < 6; i2++)
		{
			if (!valid[_str[i2][0] - 'A'][_str[i2][1] - 'A'][_str[i2][2] - 'A'])continue;
			valid[_str[i2][0] - 'A'][_str[i2][1] - 'A'][_str[i2][2] - 'A']--;
			for (int i3 = 0; i3 < 6; i3++)
			{
				if (!valid[_str[i3][0] - 'A'][_str[i3][1] - 'A'][_str[i3][2] - 'A'])continue;
				valid[_str[i3][0] - 'A'][_str[i3][1] - 'A'][_str[i3][2] - 'A']--;
				int j = 0;
				for(;j<3;j++)
				{
					if (!valid[_str[i1][j] - 'A'][_str[i2][j] - 'A'][_str[i3][j] - 'A'])break;
					valid[_str[i1][j] - 'A'][_str[i2][j] - 'A'][_str[i3][j] - 'A']--;
				}
				if(j==3)
				{
					printf("%s\n%s\n%s\n", _str[i1], _str[i2], _str[i3]);
					return 0;
				}
				else
				{
					for(int jj=0;jj<j;jj++)
					{
						valid[_str[i1][jj] - 'A'][_str[i2][jj] - 'A'][_str[i3][jj] - 'A']++;
					}
				}
				valid[_str[i3][0] - 'A'][_str[i3][1] - 'A'][_str[i3][2] - 'A']++;
			}
			valid[_str[i2][0] - 'A'][_str[i2][1] - 'A'][_str[i2][2] - 'A']++;
		}
		valid[_str[i1][0] - 'A'][_str[i1][1] - 'A'][_str[i1][2] - 'A']++;
	}
	printf("%d\n", 0);
	return 0;
}
