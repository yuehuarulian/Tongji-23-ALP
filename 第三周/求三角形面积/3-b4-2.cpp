/* ��04 2252941 ������ */
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
	const float pi = 3.14159f;
	int a, b, r;
	float s;
	cout << "�����������ε����߼���нǣ��Ƕȣ�" << endl;
	cin >> a >> b >> r;
	s = float(1) / 2 * a * b * sin(float(r)/180*pi);
	cout << "�����ε����Ϊ : " << fixed << setprecision(3) << s << endl;

	return 0;
}
