/* ������ 2252941 ��04 */
#include <iostream>
using namespace std;
#define n 4

int max(int a, int b)
{
	if (a >= b)
		return a;
	else
		return b;
}

int max(int a, int b, int c)
{
	int t = max(a, b);
	t = max(t, c);
	return t;
}

int max(int a, int b, int c, int d)
{
	const int t1 = max(a, b);
	const int t2 = max(c, d);
	return max(t1, t2);
}

int main()
{
	int num;
	int m[n] = { 0 };
	while(1){
		cout << "���������num��num����������" << endl;
		cin >> num;
		if (cin.fail()){
			cin.clear();
			cin.ignore(1000, '\n');
			continue;
		}
		if (num != 2 && num != 3 && num != 4) {
			cout << "�����������" << endl;
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
		f = max(m[0], m[1]);
	else if (num == 3)
		f = max(m[0], m[1], m[2]);
	else if (num == 4)
		f = max(m[0], m[1], m[2], m[3]);
	cout << "max=" << f << endl;
	return 0;
}
