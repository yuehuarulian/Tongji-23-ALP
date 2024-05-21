/* 信04 2252941 杨瑞灵 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	double a;
	long long int z, x;
    int sy, y, qw, bw, sw, w, q, b, s, yuan, jiao, fen;
	printf( "请输入[0-100亿)之间的数字：\n" );
	scanf("%lf",&a);
	z = (long long)(a);
	x = (long long)((a - z) * 100 + 0.5);
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
	printf("十亿位 : %d\n" ,sy);
	printf("亿位   : %d\n" ,y);
	printf("千万位 : %d\n", qw);
	printf("百万位 : %d\n", bw);
	printf("十万位 : %d\n", sw);
	printf("万位   : %d\n", w);
	printf("千位   : %d\n", q);
	printf("百位   : %d\n", b);
	printf("十位   : %d\n", s);
	printf("圆     : %d\n", yuan);
	printf("角     : %d\n", jiao);
	printf("分     : %d\n", fen);

	return 0;
}
