//信04 2252941 杨瑞灵
#include <iostream>
using namespace std;

int main()
{
	double mon;
	int a , b ;
	long long z, x;
	cout << "请输入找零值：" << endl;
	cin >> mon;
	z = (long long int)(mon);
	x = (long long int)((mon - z) * 100 + 0.5);
	
	//50 20 10 5 1
	int a0, a1, a2, a3, a4;
	a0 = z / 50;
	a1 = z % 50 / 20;
	a2 = z % 50 % 20 / 10;
	a3 = z % 50 % 20 % 10 / 5;
	a4 = z % 5;

	//5 1 5 2 1
	int b0, b1, b2, b3, b4;
	b0 = x / 50;
	b1 = x % 50 / 10;
	b2 = x % 10 / 5;
	b3 = x % 5 / 2;
	b4 = x % 5 % 2;

	a = a0 + a1 + a2 + a3 + a4 + b0 + b1 + b2 + b3 + b4;

	//输入错误情况
	if (mon>(0.01-1e-6)&&mon<=(100+1e-6))
	{
		b = 1;
		cout << "共" << a << "张找零，具体如下：" << endl;
	}
	else
	{
		b = 0;
		cout << "输入错误，请重新输入" << endl;
	}
	//输入正确情况
	if (a0 !=0&&b==1)
		cout << "50元 : " << a0 << "张" << endl;
	if (a1 !=0&&b==1)
	    cout << "20元 : " << a1 << "张" << endl;
	if (a2 != 0&&b == 1)
		cout << "10元 : " << a2 << "张" << endl;
	if (a3 != 0 && b == 1)
		cout << "5元  : " << a3 << "张" << endl;
	if (a4 != 0 && b == 1)
		cout << "1元  : " << a4 << "张" << endl;
	if (b0 != 0 && b == 1)
	    cout << "5角  : " << b0 << "张" << endl;
	if (b1 != 0 && b == 1)
	    cout << "1角  : " << b1 << "张" << endl;
	if (b2 != 0 && b == 1)
	    cout << "5分  : " << b2 << "张" << endl;
	if (b3 != 0 && b == 1)
	    cout << "2分  : " << b3 << "张" << endl;
	if (b4 != 0 && b == 1)
	    cout << "1分  : " << b4 << "张" << endl;

	return 0;
}