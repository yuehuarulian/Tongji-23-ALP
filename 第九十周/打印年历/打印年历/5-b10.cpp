/* 杨瑞灵 2252941 信04 */
#include <iostream>
#include <iomanip>
#include <cstdio>
using namespace std;
 
int zeller(int y, int m, int d)
{
	int y_1, m_1, d_1, c_1;
	c_1 = (y - (m == 1 || m == 2)) / 100;
	y_1 = (y - (m == 1 || m == 2)) % 100;
	m_1 = (m == 1 || m == 2 ? m + 12 : m);
	d_1 = d;
	int w;
	w = y_1 + y_1 / 4 + c_1 / 4 - 2 * c_1 + (13 * (m_1 + 1)) / 5 + d_1 - 1;
	if (w < 0)
		w += 7;
	w %= 7;
	return w;
}

int rn(int year)
{
	if ((year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0)))
		return 1;
	else
		return 0;
}

void in_calendar(int calendar[][42], int max_day[], int year)
{
	int day1 = zeller(year, 1, 1);
	for (int i = 1; i <= 12; i++)
	{
		for (int j = 0; j < max_day[i]; j++)
		{
			calendar[i][j + day1] = j + 1;
		}
		day1 = (day1 + max_day[i]) % 7;
	}
	/*for (int i = 0; i < 13; i++)
	{
		for (int j = 0; j < 42; j++)
			cout << calendar[i][j] << ' ';
		cout << endl;
	}*/
	return;
}

void out_calendar(int calendar[][42])
{
	int i, j, k, h;
	for (i = 1; i <= 12; i += 3)
	{
		cout << "           " << setiosflags(ios::right) << setw(2) << i << "月                            "
			<< setw(2) << i + 1 << "月                            " << setw(2) << i + 2 << "月" << endl;
		cout << "Sun Mon Tue Wed Thu Fri Sat     Sun Mon Tue Wed Thu Fri Sat     Sun Mon Tue Wed Thu Fri Sat" << endl;
		for (j = 0; j < 42;j+=7)
		{
			//判断是不是没有输出
			if (calendar[i][j] == 0 && calendar[i][j + 6] == 0 &&
				calendar[i + 1][j] == 0 && calendar[i + 1][j + 6] == 0 &&
				calendar[i + 2][j] == 0 && calendar[i + 2][j + 6] == 0)
				break;
			for(k=0;k<3;k++)
			{
				for (h = 0; h < 7; h++)
				{
					if (calendar[i + k][j + h] != 0)
						cout << resetiosflags(ios::right) << setiosflags(ios::left) << setw(4) << calendar[i + k][j + h];
					else
						cout << "    ";

				}
				cout << "    ";
			}
			cout << endl;
		}
		cout << endl;
	}
	cout << endl;
	return;
}

int main()
{
	int year;
	int i, j;//计数
	int calendar[13][42] = { 0 };
	int max_day[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };

	/* 输入年份 */
	while (1)
	{
		cout << "请输入年份[1900-2100]" << endl;
		cin >> year;

		//判断输入正确
		if (!cin.good())
		{
			cin.clear();
			cin.ignore(10000, '\n');
			continue;
		}
		else if (year < 1900 || year>2100)
		{
			continue;
		}
		break;
	}
	/* 判断闰年 */
	max_day[2] += rn(year);
	/* 填充数组 */
	in_calendar(calendar, max_day, year);
	/* 输出年历 */
	cout << year << "年的日历:" << endl << endl;
	out_calendar(calendar);
	return 0;
}
