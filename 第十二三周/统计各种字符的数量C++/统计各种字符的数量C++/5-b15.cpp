/* ��04 2252941 ������ */
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
	int upp = 0, low = 0, num = 0, va = 0, other = 0;
	char str[3][128] = { 0 };
	cout << "�������1��" << endl;
	cin.getline(str[0], 128, '\n');
	cout << "�������2��" << endl;
	cin.getline(str[1], 128, '\n');
	cout << "�������3��" << endl;
	cin.getline(str[2], 128, '\n');
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 128; j++)
		{
			if (str[i][j] == '\0')
				break;
			if (str[i][j] >= 'A' && str[i][j] <= 'Z')
				upp++;
			else if (str[i][j] >= 'a' && str[i][j] <= 'z')
				low++;
			else if (str[i][j] >= '0' && str[i][j] <= '9')
				num++;
			else if (str[i][j] == ' ')
				va++;
			else
				other++;
		}
	}
	cout << "��д : " << upp << endl;
	cout << "Сд : " << low << endl;
	cout << "���� : " << num << endl;
	cout << "�ո� : " << va << endl;
	cout << "���� : " << other << endl;


	return 0;
}
