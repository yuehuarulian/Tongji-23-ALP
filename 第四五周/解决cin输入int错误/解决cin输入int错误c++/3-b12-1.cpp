/* ��04 2252941 ������ */
#include <iostream>
using namespace std;

int main()
{
	int x;
	cout << "������x��ֵ[0-100] : ";
	while (1) {
		cin >> x;   //����x�ķ�ʽ������ cin>>int�ͱ�����������������ʽ
		if (cin.good() && x >= 0 && x <= 100)
			break;
		else if (cin.good() == 0)
		{
			cin.clear();//��������־λ
			cin.ignore(10000000000, '\n');//���������������}
		}
		else
		{
			cin.clear();
			cin.ignore();
		}
		cout << "������x��ֵ[0-100] : ";
	}

	cout << "cin.good()=" << cin.good() << " x=" << x << endl; //�˾䲻׼��������Ҫ�����ʱgoodΪ1

	return 0;
}