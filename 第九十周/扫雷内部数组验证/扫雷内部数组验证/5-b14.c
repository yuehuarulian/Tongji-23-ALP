/* 2252941 ������ ��04 */
/* 2253692 ���Ѳ� 2251924 �̾��� 2252707 ������ 2252540 ����� 2153393 ������*/
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
	//����
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
	//*����
	if (cnt != 50)
	{
		printf("����һ\n");
		return 0;
	}

	//����
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
				printf("�����\n");
				return 0;
			}
		}
	}
	printf("��ȷ\n");
	return 0;
}