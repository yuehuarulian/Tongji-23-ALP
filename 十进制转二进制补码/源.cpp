#include <iostream> //
using namespace std;

int main()
{
	int a;
	int b;
	int c;
	unsigned long long int m = 0, n = 1;
	cout << "����һ��ʮ������:" << endl;
	cin >> a;
	c = a;
	a = abs(a); 
	while(a!=0) {
		b = a % 2;
		a = a / 2;
		m = m + n * b;
		n = n * 10;
	}
	cout << c << "����ֵ�Ķ����Ʊ�ʾΪ��" << m << endl;

	
	
	
	return 0;
}
