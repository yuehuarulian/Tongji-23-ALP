/* 信04 2252941 杨瑞灵 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int year, mon, week, day=1;
	int daym=1;//一个月的总天数
	
	//输入年月并判断正误
	int ret;
	while (1) {
		printf("请输入年份(2000-2030)和月份(1-12) : ");
		ret = scanf("%d %d", &year, &mon); //读入x的方式必须是scanf且格式符为%d，不准用非scanf
		if (ret == 2 && year >= 2000 && year <= 2030 && mon >= 1 && mon <= 12)
			break;
		else
			printf("输入非法，请重新输入\n");
		if (ret != 2)
			while (getchar() != '\n');//用getchar+循环清空缓存区
	}
	//输入星期几并判断正误
	while (1) {
		printf("请输入%d年%d月1日的星期(0-6表示星期日-星期六) : ", year, mon);
		ret = scanf("%d", &week); //读入x的方式必须是scanf且格式符为%d，不准用非scanf
		if (ret == 1 && week >= 0 && week <= 6)
		{
			printf("\n");
			break;
		}
		else
			printf("输入非法，请重新输入\n");
		if (ret != 1)
			while (getchar() != '\n');//用getchar+循环清空缓存区 
	}

	//判断一个月的天数
	if (mon == 4 || mon == 9 || mon == 11 || mon == 6)
		daym = 30;
	else if (mon != 2)
		daym = 31;
	else if (mon == 2)
		daym = 28 + (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0));

	//输出日历
	int n = 8, p = 1;
	printf("%d年%d月的月历为:\n", year, mon);
	printf("星期日  星期一  星期二  星期三  星期四  星期五  星期六\n");
	while (p < week * 8 + 4)
	{
		printf(" ");
		p++;
	}
	printf("1");
	for (day = 2, week += 1; day <= daym; day++, week++)
	{
		if (day <= 9)
			n = 8;
		else
			n = 7;
		if (week == 7)
		{
			printf("\n");
			week -= 7;
			if (day <= 9)
				n = 4;
			else
				n = 3;
		}
		p = 1;
		while (p < n)
		{
			printf(" ");
			p++;
		}
		printf("%d", day);

	}
	if (week == 7)
		printf("\n");
	printf("\n");




	return 0;
}