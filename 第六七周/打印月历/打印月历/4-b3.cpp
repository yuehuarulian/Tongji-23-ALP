/* 2252941 杨瑞灵 信04 */
#include <iostream>
#include <iomanip>
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

//输出月历
void calendar(int w, int mon, int year)
{
	//计算每个月最大天数
	int day_m;
	if (mon != 2 && mon != 4 && mon != 6 && mon != 9 && mon != 11)
		day_m = 31;
	else if (mon != 2)
		day_m = 30;
	else
		day_m = 28 + (year % 400 == 0 || ((year % 4 == 0) && year % 100 != 0));

	//打印日历
	cout << "======================================================\n"
		<< "星期日  星期一  星期二  星期三  星期四  星期五  星期六\n"
		<< "======================================================"
		<< endl;
	cout << setw(w * 8 + 4) << 1;
	int day,n;
	for (day = 2, w += 1; day <= day_m; day++, w++)
	{
		n = 8;
		if (w == 7)
		{
			cout << endl;
			w -= 7;
			n = 4;
		}
		cout << setw(n) << day;

	}
	if (w == 7)
		cout << endl;
	cout << endl;

	return;
}

int main()
{
	int year, mon;
	int w;

	//输入年月日
	while (1)
	{
		cout << "请输入年[1900-2100]、月" << endl;
		cin >> year >> mon ;
		

		//判断输入正确
		if (!cin.good())
		{
			cin.clear();
			cin.ignore(10000, '\n');
			cout << "输入错误，请重新输入" << endl;
			continue;
		}
		else if (year < 1900 || year>2100)
		{
			cout << "年份不正确，请重新输入" << endl;
			continue;
		}
		else if (mon < 1 || mon>12)
		{
			cout << "月份不正确，请重新输入" << endl;
			continue;
		}
		else
		{
			cout << endl;
			break;
		}
	}

	//调用zeller函数计算星期几
	w = zeller(year, mon, 1);
	//调用calendar打印日历
	calendar(w, mon, year);
return 0;
}
