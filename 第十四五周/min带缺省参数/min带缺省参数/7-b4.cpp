/* 杨瑞灵 2252941 信04 */
#include <iostream>
using namespace std;
#define n 4
int min(int a, int b, int c = 0, int d = 0)
{
	if (c == 0 && d == 0)
		return (a < b ? a : b);
	else if (d == 0)
		return min(a, min(b, c));
	const int t1 = min(a, b);
	const int t2 = min(c, d);
	return min(t1, t2);
}

int main()
{
	int num;
	int m[n] = { 0 };
	while (1) {
		cout << "请输入个数num及num个正整数：" << endl;
		cin >> num;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(1000, '\n');
			continue;
		}
		if (num != 2 && num != 3 && num != 4) {
			cout << "个数输入错误" << endl;
			return 0;
		}
		bool b = 1;
		for (int* p = m; (p - m) < num; p++) {
			cin >> *p;
			if (*p <= 0)
				b = 0;
		}
		if (cin.good() && b)
			break;
		cin.clear();
		cin.ignore(1000, '\n');
	}
	int f;
	if (num == 2)
		f = min(m[0], m[1]);
	else if (num == 3)
		f = min(m[0], m[1], m[2]);
	else if (num == 4)
		f = min(m[0], m[1], m[2], m[3]);
	cout << "min=" << f << endl;
	return 0;
}
