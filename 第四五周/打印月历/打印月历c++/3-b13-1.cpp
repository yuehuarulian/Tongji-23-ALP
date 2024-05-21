/* 信04 2252941 杨瑞灵 */
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	int year, mon, week, day;
	int daym;//一个月的总天数
	//输入年月并判断正误
	while (1) {
		cout << "请输入年份(2000-2030)和月份(1-12) : ";
		cin >> year >> mon; 
		if (cin.good() && year >= 2000 && year <= 2030 && mon >= 1 && mon <= 12)
			break;
		else
			cout << "输入非法，请重新输入" << endl;

		if (cin.good() == 0)
		{
			cin.clear();//清除错误标志位
			cin.ignore(10000000000, '\n');//清除缓冲区内数据}
		}
		else
		{
			cin.clear();//清除错误标志位
			cin.ignore();//清除缓冲区内数据}
		}
	}

	//输入星期几并判断正误
	while (1) {
		cout << "请输入" << year << "年" << mon << "月1日的星期(0-6表示星期日-星期六) : " ;
		cin >> week;
		if (cin.good() && week >= 0 && week <= 6)
		{
			cout << endl;
			break;
		}
		else
			cout << "输入非法，请重新输入" << endl;

		if (cin.good() == 0)
		{
			cin.clear();//清除错误标志位
			cin.ignore(10000000000, '\n');//清除缓冲区内数据}
		}
		else
		{
			cin.clear();//清除错误标志位
			cin.ignore();//清除缓冲区内数据}
		}
	}
	//判断一个月的天数
	if (mon == 4 || mon == 9 || mon == 11 || mon == 6)
		daym = 30;
	else if (mon != 2)
		daym = 31;
	else if (mon == 2)
		daym = 28 + (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0));


	//输出日历
	int n = 8;
	cout << year << "年" << mon << "月的月历为:" << endl;
	cout << "星期日  星期一  星期二  星期三  星期四  星期五  星期六" << endl;
	cout << setw(week * 8 + 4) << 1;
	for (day = 2, week += 1; day <= daym; day++, week++)
	{
		n = 8;
		if (week == 7)
		{
			cout << endl;
			week -= 7;
			n = 4;
		}
		cout << setw(n) << day;

	}
	if (week == 7)
		cout << endl;
	cout << endl;



	return 0;
}