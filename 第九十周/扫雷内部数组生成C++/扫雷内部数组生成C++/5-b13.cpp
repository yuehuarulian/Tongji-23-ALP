/* ������ 2252941 ��04 */
#include <iostream>
#include <cstdio>
#include <windows.h> 
#include <time.h>

using namespace std;

int main()
{
	srand((unsigned int)(time(0)));
	char sl[10][26];                    //д��sl[12][28],�������Ҳ��ܣ��������ֵ�ʱ��������
	int i, j, t;
	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 26; j++)
			sl[i][j] = '0';
	}
	for (i = 0; i < 50; i++)
	{
		t = rand() % 260;
		if (sl[t / 26][t % 26] == '*')
		{
			--i;
			continue;
		}
		sl[t / 26][t % 26] = '*';
		if (t / 26 - 1 >= 0)
		{
			if (sl[t / 26 - 1][t % 26] != '*')
				sl[t / 26 - 1][t % 26]++;
		}
		if (t / 26 + 1 < 10)
		{
			if (sl[t / 26 + 1][t % 26] != '*')
				sl[t / 26 + 1][t % 26]++;
		}
		if (t % 26 - 1 >= 0)
		{
			if (sl[t / 26][t % 26 - 1] != '*')
				sl[t / 26][t % 26 - 1]++;
		}
		if (t % 26 + 1 < 26)
		{
			if (sl[t / 26][t % 26 + 1] != '*')
				sl[t / 26][t % 26 + 1]++;
		}
		if (t / 26 - 1 >= 0 && t % 26 - 1 >= 0)
		{
			if (sl[t / 26 - 1][t % 26 - 1] != '*')
				sl[t / 26 - 1][t % 26 - 1]++;
		}
		if (t / 26 - 1 >= 0 && t % 26 + 1 < 26)
		{
			if (sl[t / 26 - 1][t % 26 + 1] != '*')
				sl[t / 26 - 1][t % 26 + 1]++;
		}
		if (t / 26 + 1 < 10 && t % 26 - 1 >= 0)
		{
			if (sl[t / 26 + 1][t % 26 - 1] != '*')
				sl[t / 26 + 1][t % 26 - 1]++;
		}
		if (t / 26 + 1 < 10 && t % 26 + 1 < 26)
		{
			if (sl[t / 26 + 1][t % 26 + 1] != '*')
				sl[t / 26 + 1][t % 26 + 1]++;
		}
	}
	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 26; j++)
			cout << sl[i][j] << ' ';
		cout << endl;
	}
	return 0;
}
