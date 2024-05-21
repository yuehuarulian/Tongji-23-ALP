//2252941 信04 杨瑞灵
#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

int main()
{
	int i, j;//i,j循环计数
	long double x, y = 1, e;//y=x^n/2! x_n=x^n


	while (1) {
		cout << "请输入x的值[-10 ~ +65]" << endl;
		cin >> x;
		if (cin.good() && x >= (-10 - 1e-6) && x <= 65.5)
			break;
		else
			cout << "输入非法，请重新输入" << endl;
		if (cin.good() == 0)
		{
			cin.clear();//清除错误标志位
			cin.ignore(10000000000, '\n');//清除缓冲区内数据}
		}
		else
		{
			cin.clear();//清除错误标志位
			cin.ignore();//清除缓冲区内数据}
		}

	}

	//求e

	for (i = 1, e = 1; abs(y) >= 1e-6; i++)//算e
	{
		y *= x;
		y /= i;
		e += y;
/*这里多加了一项，因为加完才判断的
* 改成
	for (i = 1,e = 0; abs(y) >= 1e-6; i++)//算e
	{
	    e += y;
		y *= x;
		y /= i;


*/
	}
	cout << "e^" << x << "=" << setprecision(10) << e << endl;
}
