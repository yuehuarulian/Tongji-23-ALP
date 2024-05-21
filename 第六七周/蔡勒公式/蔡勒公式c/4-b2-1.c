/* 2252941 杨瑞灵 信04 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

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


int main()
{
	int year, mon, day;
	int w;
	//输入年月日
	while (1)
	{
		int ret;
		printf("请输入年[1900-2100]、月、日：\n");
		ret = scanf("%d %d %d", &year, &mon, &day);
		//计算每个月最大天数
		int day_m;
		if (mon != 2 && mon != 4 && mon != 6 && mon != 9 && mon != 11)
			day_m = 31;
		else if (mon != 2)
			day_m = 30;
		else
			day_m = 28 + (year % 400 == 0 || ((year % 4 == 0) && year % 100 != 0));

		//判断输入正确
		if (ret != 3)
		{
			while (getchar() != '\n')
				continue;
			printf("输入错误，请重新输入\n");
		}
		else if (year < 1900 || year>2100)
		{
			printf("年份不正确，请重新输入\n");
		}
		else if (mon < 1 || mon>12)
		{
			printf("月份不正确，请重新输入\n");
		}
		else if (day<0 || day>day_m)
		{
			printf("日不正确，请重新输入\n");
		}
		else
			break;
	}

	//调用zeller函数计算星期几
	w = zeller(year, mon, day);
	switch (w)
	{
		case(0):
			printf("星期日\n");
			break;
		case(1):
			printf("星期一\n");
			break;
		case(2):
			printf("星期二\n");
			break;
		case(3):
			printf("星期三\n");
			break;
		case(4):
			printf("星期四\n");
			break;
		case(5):
			printf("星期五\n");
			break;
		case(6):
			printf("星期六\n");
			break;

	}
}