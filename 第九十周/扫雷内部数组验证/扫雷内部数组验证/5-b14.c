/* 2252941 杨瑞灵 信04 */
/* 2253692 龚佳灿 2251924 晏景豪 2252707 陈艺天 2252540 金国栋 2153393 胡峻玮*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	char sl[10][26] = { 0 };
	char judge[10][26]; 
	int i, j;
	int cnt = 0;
	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 26; j++)
			judge[i][j] = '0';
	}
	//输入
	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 26; j++)
		{
			while (1)
			{
				sl[i][j] = getchar();
				if (sl[i][j] == '*')
				{
					cnt++;
					judge[i][j] = '*';
					break;
				}
				if ((sl[i][j] >= '0' && sl[i][j] <= '8'))
					break;
			}

		}
	}
	//*个数
	if (cnt != 50)
	{
		printf("错误一\n");
		return 0;
	}

	//雷数
	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 26; j++)
		{
			if (judge[i][j] == '*')
			{
				if (i - 1 >= 0)
				{
					if (judge[i - 1][j] != '*')
						judge[i - 1][j]++;
				}
				if (i + 1 < 10)
				{
					if(judge[i + 1][j]!='*')
					judge[i + 1][j]++;
				}
				if (j - 1 >= 0)
				{
					if (judge[i][j-1] != '*')
						judge[i][j-1]++;
				}
				if (j + 1 < 26)
				{
					if (judge[i][j + 1] != '*')
						judge[i][j + 1]++;
				}
				if (i - 1 >= 0 && j - 1 >= 0)
				{
					if (judge[i-1][j - 1] != '*')
						judge[i-1][j - 1]++;
				}
				if (i - 1 >= 0 && j + 1 < 26)
				{
					if (judge[i - 1][j + 1] != '*')
						judge[i - 1][j + 1]++;
				}
				if (i + 1 < 10 && j - 1 >= 0)
				{
					if (judge[i + 1][j - 1] != '*')
						judge[i + 1][j - 1]++;
				}
				if (i + 1 < 10 && j + 1 < 26)
				{
					if (judge[i + 1][j + 1] != '*')
						judge[i + 1][j + 1]++;
				}
			}
		}
	}

	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 26; j++)
		{
			if (judge[i][j] != sl[i][j])
			{
				printf("错误二\n");
				return 0;
			}
		}
	}
	printf("正确\n");
	return 0;
}