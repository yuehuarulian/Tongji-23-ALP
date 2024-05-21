/* ��04 2252941 ������ */
#include <iostream>
#include <stdio.h>
using namespace std;
static const char other[] = "!@#$%^&*-_=+,.?";
const int n = 10;
bool judge(char secret[][128], int len, int upp, int low, int num, int oth)
{
	int jud_upp, jud_low, jud_num, jud_oth;
	for (int i = 0; i < n; i++)
	{
		jud_upp = 0;
		jud_low = 0;
		jud_num = 0;
		jud_oth = 0;
		for (int j = 0; j < 17; j++)
		{
			if (secret[i][j] == '\0')
				break;
			if (secret[i][j] >= 'A' && secret[i][j] <= 'Z')
				jud_upp++;
			else if (secret[i][j] >= 'a' && secret[i][j] <= 'z')
				jud_low++;
			else if (secret[i][j] >= '0' && secret[i][j] <= '9')
			{
				jud_num++;
			}
			else
			{
				for (int k = 0; k < 15; k++)
				{
					if (secret[i][j] == other[k])
					{
						jud_oth++;
						break;
					}
					if (k == 14)
						return 0;
				}
			}
		}
		if (jud_upp < upp || jud_low < low || jud_num < num || jud_oth < oth || (jud_upp + jud_low + jud_num + jud_oth != len))
			return 0;
	}
	return 1;
}
int main()
{
	int len, upp, low, num, oth;
	char secret[n][128] = { 0 };
	while (getchar() != '\n')
		;
	cin >> len >> upp >> low >> num >> oth;
	for (int i = 0; i < n; i++)
		cin >> secret[i];
	if (!cin.good())
	{
		cout << "����" << endl;
		return 0;
	}
	if (len < 12 || len>16)
	{
		cout << "����" << endl;
		return 0;
	}
	if (upp < 2 || upp>len)
	{
		cout << "����" << endl;
		return 0;
	}
	if (low < 2 || low>len)
	{
		cout << "����" << endl;
		return 0;
	}
	if (num < 2 || num>len)
	{
		cout << "����" << endl;
		return 0;
	}
	if (oth < 2 || oth>len)
	{
		cout << "����" << endl;
		return 0;
	}
	if ((upp + low + num + oth) > len)
	{
		cout << "����" << endl;
		return 0;
	}

	if (judge(secret, len, upp, low, num, oth))
		cout << "��ȷ" << endl;
	else
		cout << "����" << endl;


	return 0;
}