/* ��04 2252941 ������ */
#include <iostream>
using namespace std;

int main()
{
	double a ;
	long long int z, x;
	long long int sy, y, qw, bw, sw, w, q, b, s, yuan, jiao, fen;
	cout << "������[0-100��)֮������֣�" << endl;
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
	cout << "ʮ��λ : " << sy << endl;
	cout << "��λ   : " << y << endl;
	cout << "ǧ��λ : " << qw << endl;
	cout << "����λ : " << bw << endl; 
	cout << "ʮ��λ : " << sw << endl;
	cout << "��λ   : " << w << endl;
	cout << "ǧλ   : " << q << endl;
	cout << "��λ   : " << b << endl;
	cout << "ʮλ   : " << s << endl;
	cout << "Բ     : " << yuan << endl;
	cout << "��     : " << jiao << endl;
	cout << "��     : " << fen << endl;
	
	return 0;
}
