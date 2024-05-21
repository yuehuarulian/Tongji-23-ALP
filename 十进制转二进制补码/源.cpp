#include <iostream> //
using namespace std;

int main()
{
	int a;
	int b;
	int c;
	unsigned long long int m = 0, n = 1;
	cout << "输入一个十进制数:" << endl;
	cin >> a;
	c = a;
	a = abs(a); 
	while(a!=0) {
		b = a % 2;
		a = a / 2;
		m = m + n * b;
		n = n * 10;
	}
	cout << c << "绝对值的二进制表示为：" << m << endl;

	
	
	
	return 0;
}
