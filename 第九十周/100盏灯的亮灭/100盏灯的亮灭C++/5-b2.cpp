/* 2252941 ������ ��04 */
#include <iostream>
using namespace std;
const int n = 100;
int main()
{
	bool lamp[n] = { 0 };
	int i, j;
	for (i = 1; i <= n; i++)//iΪ�˵ı���
	{
		for (j = i; j <= n; j++)//jΪ�Ƶı���
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