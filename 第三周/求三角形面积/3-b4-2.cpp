/* 信04 2252941 杨瑞灵 */
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
	const float pi = 3.14159f;
	int a, b, r;
	float s;
	cout << "请输入三角形的两边及其夹角（角度）" << endl;
	cin >> a >> b >> r;
	s = float(1) / 2 * a * b * sin(float(r)/180*pi);
	cout << "三角形的面积为 : " << fixed << setprecision(3) << s << endl;

	return 0;
}
