/* ��04 2252941 ������ */
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	const double pi = 3.14159;
	double r, h;
	cout << "������뾶�͸߶�" << endl;
	cin >> r >> h;
	double c, s, s_qiu, v_qiu, v_zhu;
	c = 2 * pi * r;
	s = pi * r * r;
	s_qiu = 4 * pi * r * r;
	v_qiu = (double)4 / (double)3 * pi * r * r * r;
	v_zhu = s * h;
	cout << "Բ�ܳ�    ��" << fixed << setprecision(2) << c << endl;
	cout << "Բ���    ��" << fixed << setprecision(2) << s << endl;
	cout << "Բ��������" << fixed << setprecision(2) << s_qiu << endl;
	cout << "Բ�����  ��" << fixed << setprecision(2) << v_qiu << endl;
	cout << "Բ�����  ��" << fixed << setprecision(2) << v_zhu << endl;

	return 0;
}
