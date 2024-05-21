/* 2252941 杨瑞灵 信04 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int a[1000] = { 0 };
	int dif[1000] = { 0 };
	int count[1000] = { 0 };
	int n = 0, m = 0;//记录输入个数
	int i, j, k;//循环计步
	int max;//选择法排序
	int exchange;//交换顺序中间记录

	//输入成绩
	printf("请输入成绩（最多1000个），负数结束输入\n");
	for (i = 0; i < 1000; i++)
	{
		scanf("%d", &a[i]);
		if (a[i] < 0)
		{
			a[i] = 0;
			i--;
			break;
		}
	}
	n = i + 1;
	if (n == 0)
	{
		printf("无有效输入\n");
		return 0;
	}

	//输出数组
	printf("输入的数组为:\n");
	for (i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
		if (((i + 1) % 10) == 0)
			printf("\n");
		else
			continue;
	}
	if (i % 10 != 0)
		printf("\n");

	//重新排序和统计
	for (i = 0; i < n-1; i++)
	{
		max = i;
		for (j = i + 1; j < n; j++)
		{
			if (a[j] > a[max])
				max = j;
		}
		exchange = a[max];
		a[max] = a[i];
		a[i] = exchange;
	}

	for (i = 0, j = 0; j < n; i++, j++)//1 1   n=2
	{
		k = 1;
		while (1)
		{
			if (a[j] == a[j + 1] && (j + 1) < n)
			{
				j = j + 1;
				k++;
			}
			else
				break;
		}

		dif[i] = a[j];
		count[i] = k;
	}
	m = i;
	//输出成绩
	printf("分数与人数的对应关系为:\n");
	for (i = 0; i < m; i++)
		printf("%d %d\n", dif[i], count[i]);




	return 0;
}
