/* ��04 2252941 ������ */
#include <iostream>
using namespace std;

int main()
{
	int a;
	int wan, qian, bai, shi , ge;
	cout << "������һ��[1..30000]�������:" << endl;
	cin >> a;
	wan = a / 10000;
	qian = (a - 10000 * wan) / 1000;
	bai = a % 1000 / 100;
	shi = a%100 / 10;
	ge = a % 10;
	cout << "��λ : " << wan << endl;
	cout << "ǧλ ; " << qian << endl;
	cout << "��λ ; " << bai << endl;
	cout << "ʮλ ; " << shi << endl;
	cout << "��λ ; " << ge << endl;

	return 0;
}
