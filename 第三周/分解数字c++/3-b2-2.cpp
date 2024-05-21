/* 信04 2252941 杨瑞灵 */
#include <iostream>
using namespace std;

int main()
{
	int a;
	int wan, qian, bai, shi , ge;
	cout << "请输入一个[1..30000]间的整数:" << endl;
	cin >> a;
	wan = a / 10000;
	qian = (a - 10000 * wan) / 1000;
	bai = a % 1000 / 100;
	shi = a%100 / 10;
	ge = a % 10;
	cout << "万位 : " << wan << endl;
	cout << "千位 ; " << qian << endl;
	cout << "百位 ; " << bai << endl;
	cout << "十位 ; " << shi << endl;
	cout << "个位 ; " << ge << endl;

	return 0;
}
