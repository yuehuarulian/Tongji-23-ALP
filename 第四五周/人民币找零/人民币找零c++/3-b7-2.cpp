//��04 2252941 ������
#include <iostream>
using namespace std;

int main()
{
	double mon;
	int a , b ;
	long long z, x;
	cout << "����������ֵ��" << endl;
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

	//����������
	if (mon>(0.01-1e-6)&&mon<=(100+1e-6))
	{
		b = 1;
		cout << "��" << a << "�����㣬�������£�" << endl;
	}
	else
	{
		b = 0;
		cout << "�����������������" << endl;
	}
	//������ȷ���
	if (a0 !=0&&b==1)
		cout << "50Ԫ : " << a0 << "��" << endl;
	if (a1 !=0&&b==1)
	    cout << "20Ԫ : " << a1 << "��" << endl;
	if (a2 != 0&&b == 1)
		cout << "10Ԫ : " << a2 << "��" << endl;
	if (a3 != 0 && b == 1)
		cout << "5Ԫ  : " << a3 << "��" << endl;
	if (a4 != 0 && b == 1)
		cout << "1Ԫ  : " << a4 << "��" << endl;
	if (b0 != 0 && b == 1)
	    cout << "5��  : " << b0 << "��" << endl;
	if (b1 != 0 && b == 1)
	    cout << "1��  : " << b1 << "��" << endl;
	if (b2 != 0 && b == 1)
	    cout << "5��  : " << b2 << "��" << endl;
	if (b3 != 0 && b == 1)
	    cout << "2��  : " << b3 << "��" << endl;
	if (b4 != 0 && b == 1)
	    cout << "1��  : " << b4 << "��" << endl;

	return 0;
}