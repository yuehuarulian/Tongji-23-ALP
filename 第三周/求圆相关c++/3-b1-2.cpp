/* 信04 2252941 杨瑞灵 */
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	const double pi = 3.14159;
	double r, h;
	cout << "请输入半径和高度" << endl;
	cin >> r >> h;
	double c, s, s_qiu, v_qiu, v_zhu;
	c = 2 * pi * r;
	s = pi * r * r;
	s_qiu = 4 * pi * r * r;
	v_qiu = (double)4 / (double)3 * pi * r * r * r;
	v_zhu = s * h;
	cout << "圆周长    ：" << fixed << setprecision(2) << c << endl;
	cout << "圆面积    ：" << fixed << setprecision(2) << s << endl;
	cout << "圆球表面积：" << fixed << setprecision(2) << s_qiu << endl;
	cout << "圆球体积  ：" << fixed << setprecision(2) << v_qiu << endl;
	cout << "圆柱体积  ：" << fixed << setprecision(2) << v_zhu << endl;

	return 0;
}
