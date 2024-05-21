/* 2252941 杨瑞灵 信04 */
#include <iostream>
using namespace std;
int main()
{
	char str[256];
	char* p = str;
	char* q = str;
	fgets(str, 255, stdin);
	cout << "请输入一个长度小于80的字符串（回文串）" << endl;
	for (; *p != '\0'; p++)
	{
		if (*p == '\n')
			*p = '\0';
	}
	for (p-=2; p > q; p--, q++)
	{
		if (*p != *q)
		{
			cout << "no" << endl;
			return 0;
		}
	}
	cout << "yes" << endl;


	return 0;
}
