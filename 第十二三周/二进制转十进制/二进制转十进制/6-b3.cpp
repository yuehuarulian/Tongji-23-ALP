/* 2252941 杨瑞灵 信04 */
#include <iostream>
using namespace std;
int main()
{
	char str[33], * p;
	int sum = 0;
	cout << "请输入一个0/1组成的字符串，长度不超过32" << endl;
	cin >> str;
	for (p = str; *p != '\0'; p++)
		sum = sum * 2 + *p - '0';
	cout << sum << endl;
 

}
