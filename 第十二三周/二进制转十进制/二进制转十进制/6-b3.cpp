/* 2252941 ������ ��04 */
#include <iostream>
using namespace std;
int main()
{
	char str[33], * p;
	int sum = 0;
	cout << "������һ��0/1��ɵ��ַ��������Ȳ�����32" << endl;
	cin >> str;
	for (p = str; *p != '\0'; p++)
		sum = sum * 2 + *p - '0';
	cout << sum << endl;
 

}
