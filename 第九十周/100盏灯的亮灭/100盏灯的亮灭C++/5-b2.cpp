/* 2252941 杨瑞灵 信04 */
#include <iostream>
using namespace std;
const int n = 100;
int main()
{
	bool lamp[n] = { 0 };
	int i, j;
	for (i = 1; i <= n; i++)//i为人的编码
	{
		for (j = i; j <= n; j++)//j为灯的编码
		{
			if (j % i == 0)
				lamp[j - 1] = !lamp[j - 1];
			else
				continue;
		}
	}
	int max;
	for (j = 1; j <= n; j++)
	{
		if (lamp[j - 1])
			max = j;
	}
	for (j = 1; j <= n; j++)
	{
		if (lamp[j - 1])
		{
			cout << j;
			if (j < max)
				cout << ' ';
		}
		else
			continue;
	}
	cout << endl;
	return 0;
}