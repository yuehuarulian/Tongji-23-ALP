/* 2252941 杨瑞灵 信04 */
#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	int a[1000] = { 0 };
	int dif[1000] = { 0 };
	int count[1000] = { 0 };
	int n = 0, m = 0;//记录输入个数
	int i, j;//循环计步
	int max;//选择法排序
	int exchange;//交换顺序中间记录

	//输入成绩
	cout << "请输入成绩（最多1000个），负数结束输入" << endl;
	for (i = 0; i < 1000; i++)
	{
		cin >> a[i];
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
		cout << "无有效输入" << endl;
		return 0;
	}

	//输出数组
	cout << "输入的数组为:" << endl;
	for (i = 0; i < n; i++)
	{
		cout << a[i] << ' ';
		if (((i + 1) % 10) == 0)
			cout << endl;
		else
			continue;
	}
	if (i % 10 != 0)
		cout << endl;

	//重新排序和统计
	for (i = 0; i < n - 1; i++)
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

	for (count[0] = 1, j = 1; j < n; j++)//1 1   n=2
	{
		if (a[j] == a[j - 1])
			count[j] = count[j - 1];
		else
			count[j] = j + 1;
	}
	m = i;
	//输出成绩
	cout << "分数与名次的对应关系为:" << endl;
	for (i = 0; i < n; i++)
		cout << a[i] << ' ' << count[i] << endl;

	return 0;
}