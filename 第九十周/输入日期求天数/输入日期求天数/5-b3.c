/* 2252941 杨瑞灵 信04 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int runnian(int year)
{
	if ((year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0)))
		return 29;
	else
		return 28;
}

int unswer(int month, int day, int rili[][31], int top[12])
{
	int i, j;
	int day_sum = 0;
	for (i = 0; i < 12; i++)
	{
		for (j = 0; j < top[i]; j++)
		{
			day_sum++;
			rili[i][j] = day_sum;
		}
	}
	return rili[month - 1][day - 1];
}

int main()
{
	int year, month, day;
	int uns;
	int rili[12][31];
	int top[12] = { 31,0,31,30,31,30,31,31,30,31,30,31 };
	printf("请输入年，月，日\n");
	scanf("%d %d %d", &year, &month, &day);
	//是否闰年
	top[1] = runnian(year);
	//初始化表rili
	uns = unswer(month, day, rili, top);

	if ((month >= 1 && month <= 12) && (day >= 1 && day <= top[month - 1]))
		printf("%d-%d-%d是%d年的第%d天\n", year, month, day, year, uns);
	else if (month < 1 || month > 12)
		printf("输入错误-月份不正确\n");
	else if (day<1 || day>top[month - 1])
		printf("输入错误-日与月的关系非法\n");
}
