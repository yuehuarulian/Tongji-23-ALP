/* ��04 2252941 ������ */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	double a;
	long long int z, x;
    int sy, y, qw, bw, sw, w, q, b, s, yuan, jiao, fen;
	printf( "������[0-100��)֮������֣�\n" );
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
	printf("ʮ��λ : %d\n" ,sy);
	printf("��λ   : %d\n" ,y);
	printf("ǧ��λ : %d\n", qw);
	printf("����λ : %d\n", bw);
	printf("ʮ��λ : %d\n", sw);
	printf("��λ   : %d\n", w);
	printf("ǧλ   : %d\n", q);
	printf("��λ   : %d\n", b);
	printf("ʮλ   : %d\n", s);
	printf("Բ     : %d\n", yuan);
	printf("��     : %d\n", jiao);
	printf("��     : %d\n", fen);

	return 0;
}
