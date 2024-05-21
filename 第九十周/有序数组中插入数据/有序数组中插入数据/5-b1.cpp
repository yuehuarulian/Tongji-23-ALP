/* 2252941 杨瑞灵 信04 */
#include <iostream>
using namespace std;

int main()
{
	int a[40] = { 0 };
	int i, j, t;
	cout << "请输入任意个正整数（升序，最多20个），0或负数结束输入" << endl;
	for (i = 0; i < 20; i++)
	{
		while (1)
		{
			cin >> a[i];
			if (cin.good())
				break;
			else
			{
				cin.clear();
				cin.ignore(10000, '\n');
			}
		}
		if (a[i] <= 0)
		{
			a[i] = 0;
			i--;
			break;
		}
	}
	if (i < 0)
	{
		cout << "无有效输入" << endl;
		return 0;
	}
	cin.clear();
	cin.ignore(10000, '\n');
	cout << "原数组为：" << endl;
	for (j = 0; j <= i; j++)
		cout << a[j] << ' ';
	cout << endl;
	cout << "请输入要插入的正整数" << endl;
	while (1)
	{
		i++;
		cin >> a[i];
		if (cin.good())
			break;
		else
		{
			cin.clear();
			cin.ignore(10000, '\n');
		}
	}
	for (j = i; j > 0; j--)
	{
		if (a[j] < a[j - 1])
		{
			t = a[j];
			a[j] = a[j - 1];
			a[j - 1] = t;

		}
	}
	cout << "插入后的数组为：" << endl;
	for (j = 0; j <= i; j++)
		cout << a[j] << ' ';
	cout << endl;
	return 0;
}
