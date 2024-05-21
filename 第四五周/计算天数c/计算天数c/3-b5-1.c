//信04 2252941 杨瑞灵
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>

int main()
{
	int year, month, day;
	int a, b;
	bool c, d;
	printf("请输入年，月，日\n");
	scanf("%d %d %d", &year, &month, &day);

	if ((year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0)))
		b = 29;
	else
		b = 28;

	if (month >= 1)
	{
		a = day;
		if (day >= 1 && day <= 31)
			d = true;
		else
			d = false;
	}
	if (month >= 2)
	{
		a += 31;
		if (day >= 1 && day <= b)
			d = true;
		else
			d = false;
	}
	if (month >= 3)
	{
		a += b;
		if (day >= 1 && day <= 31)
			d = true;
		else
			d = false;
	}
	if (month >= 4)
	{
		a += 31;
		if (day >= 1 && day <= 30)
			d = true;
		else
			d = false;
	}
	if (month >= 5)
	{
		a += 30;
		if (day >= 1 && day <= 31)
			d = true;
		else
			d = false;
	}
	if (month >= 6)
	{
		a += 31;
		if (day >= 1 && day <= 31)
			d = true;
		else
			d = false;
	}
	if (month >= 7)
	{
		a += 30;
		if (day >= 1 && day <= 31)
			d = true;
		else
			d = false;
	}
	if (month >= 8)
	{
		a += 31;
		if (day >= 1 && day <= 31)
			d = true;
		else
			d = false;
	}
	if (month >= 9)
	{
		a += 31;
		if (day >= 1 && day <= 30)
			d = true;
		else
			d = false;
	}
	if (month >= 10)
	{
		a += 30;
		if (day >= 1 && day <= 31)
			d = true;
		else
			d = false;
	}
	if (month >= 11)
	{
		a += 31;
		if (day >= 1 && day <= 30)
			d = true;
		else
			d = false;
	}
	if (month >= 12)
	{
		a += 30;
		if (day >= 1 && day <= 31)
			d = true;
		else
			d = false;
	}

	if (month >= 1 && month <= 12)
		c = true;
	else
		c = false;

	if ((c == true) && (d == true))
		printf("%d-%d-%d是%d年的第%d天\n", year, month, day, year, a);
	else if (c == false)
		printf("输入错误-月份不正确\n");
	else if (d == false)
		printf("输入错误-日与月的关系非法\n");
}