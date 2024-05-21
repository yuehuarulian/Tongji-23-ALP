/* 信04 2252941 杨瑞灵 */
#include <iostream>
using namespace std;

int main()
{
	int x;
	cout << "请输入x的值[0-100] : ";
	while (1) {
		cin >> x;   //读入x的方式必须是 cin>>int型变量，不允许其他方式
		if (cin.good() && x >= 0 && x <= 100)
			break;
		else if (cin.good() == 0)
		{
			cin.clear();//清除错误标志位
			cin.ignore(10000000000, '\n');//清除缓冲区内数据}
		}
		else
		{
			cin.clear();
			cin.ignore();
		}
		cout << "请输入x的值[0-100] : ";
	}

	cout << "cin.good()=" << cin.good() << " x=" << x << endl; //此句不准动，并且要求输出时good为1

	return 0;
}