/* 信04 2252941 杨瑞灵 */
#include <iostream>
using namespace std;

int main()
{
	double a ;
	long long int z, x;
	long long int sy, y, qw, bw, sw, w, q, b, s, yuan, jiao, fen;
	cout << "请输入[0-100亿)之间的数字：" << endl;
	cin >>a;
	z =(long long) a;
	x = (long long)((a - z)*100+0.5);
	sy = z / 1000000000;
	y = z % 1000000000 / 100000000;
	qw = z % 100000000 / 10000000;
	bw = z % 10000000 / 1000000;
	sw = z % 1000000 / 100000;
	w = z % 100000 / 10000;
	q = z % 10000 / 1000;
	b = z % 1000 / 100;
	s = z % 100 / 10;
	yuan = z % 10;
	jiao = x / 10;
	fen = x % 10;
	cout << "十亿位 : " << sy << endl;
	cout << "亿位   : " << y << endl;
	cout << "千万位 : " << qw << endl;
	cout << "百万位 : " << bw << endl; 
	cout << "十万位 : " << sw << endl;
	cout << "万位   : " << w << endl;
	cout << "千位   : " << q << endl;
	cout << "百位   : " << b << endl;
	cout << "十位   : " << s << endl;
	cout << "圆     : " << yuan << endl;
	cout << "角     : " << jiao << endl;
	cout << "分     : " << fen << endl;
	
	return 0;
}
