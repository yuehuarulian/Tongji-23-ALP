//2252941 ��04 ������
#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

int main()
{
	int i, j;//i,jѭ������
	long double x, y = 1, e;//y=x^n/2! x_n=x^n


	while (1) {
		cout << "������x��ֵ[-10 ~ +65]" << endl;
		cin >> x;
		if (cin.good() && x >= (-10 - 1e-6) && x <= 65.5)
			break;
		else
			cout << "����Ƿ�������������" << endl;
		if (cin.good() == 0)
		{
			cin.clear();//��������־λ
			cin.ignore(10000000000, '\n');//���������������}
		}
		else
		{
			cin.clear();//��������־λ
			cin.ignore();//���������������}
		}

	}

	//��e

	for (i = 1, e = 1; abs(y) >= 1e-6; i++)//��e
	{
		y *= x;
		y /= i;
		e += y;
/*��������һ���Ϊ������жϵ�
* �ĳ�
	for (i = 1,e = 0; abs(y) >= 1e-6; i++)//��e
	{
	    e += y;
		y *= x;
		y /= i;


*/
	}
	cout << "e^" << x << "=" << setprecision(10) << e << endl;
}
