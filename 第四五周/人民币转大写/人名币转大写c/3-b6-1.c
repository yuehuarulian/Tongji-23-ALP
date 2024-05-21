//ĞÅ04 2252941 ÑîÈğÁé
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	double a;
	long long int z, x;
	long long int sy, y, qw, bw, sw, w, q, b, s, yuan, jiao, fen;
	printf("ÇëÊäÈë[0-100ÒÚ)Ö®¼äµÄÊı×Ö:\n");
	scanf("%lf", &a);
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
	printf("´óĞ´½á¹ûÊÇ:\n");

	//Ê®ÒÚÎ»Êä³ö
	if (sy == 1)
		printf ("Ò¼Ê°");
	else if (sy == 2)
		printf ("·¡Ê°");
	else if (sy == 3)
		printf("ÈşÊ°");
	else if (sy == 4)
		printf("ËÁÊ°");
	else if (sy == 5)
		printf("ÎéÊ°");
	else if (sy == 6)
		printf("Â½Ê°");
	else if (sy == 7)
		printf("ÆâÊ°");
	else if (sy == 8)
		printf("°ÆÊ°");
	else if (sy == 9)
		printf("¾ÁÊ°");

	//ÒÚÎ»Êä³ö
	if (y == 0 && sy != 0)
		printf("ÒÚ");
	else if (y == 1)
		printf("Ò¼ÒÚ");
	else if (y == 2)
		printf("·¡ÒÚ");
	else if (y == 3)
		printf("ÈşÒÚ");
	else if (y == 4)
		printf("ËÁÒÚ");
	else if (y == 5)
		printf("ÎéÒÚ");
	else if (y == 6)
		printf("Â½ÒÚ");
	else if (y == 7)
		printf("ÆâÒÚ");
	else if (y == 8)
		printf("°ÆÒÚ");
	else if (y == 9)
		printf("¾ÁÒÚ");

	//Ç§ÍòÎ»Êä³ö
	if (((sy +y) != 0) && ((bw +sw +w) != 0)&&qw==0)
		printf("Áã");
	else if (qw == 1)
		printf("Ò¼Çª");
	else if (qw == 2)
		printf("·¡Çª");
	else if (qw == 3)
		printf("ÈşÇª");
	else if (qw == 4)
		printf("ËÁÇª");
	else if (qw == 5)
		printf("ÎéÇª");
	else if (qw == 6)
		printf("Â½Çª");
	else if (qw == 7)
		printf("ÆâÇª");
	else if (qw == 8)
		printf("°ÆÇª");
	else if (qw == 9)
		printf("¾ÁÇª");

	//°ÙÍòÎ»Êä³ö
	if ((qw != 0 && bw == 0) && (sw != 0 || w != 0)&&bw==0)
	{
		printf("Áã");
	}
	else if (bw == 1)
		printf("Ò¼°Û");
	else if (bw == 2)
		printf("·¡°Û");
	else if (bw == 3)
		printf("Èş°Û");
	else if (bw == 4)
		printf("ËÁ°Û");
	else if (bw == 5)
		printf("Îé°Û");
	else if (bw == 6)
		printf("Â½°Û");
	else if (bw == 7)
		printf("Æâ°Û");
	else if (bw == 8)
		printf("°Æ°Û");
	else if (bw == 9)
		printf("¾Á°Û");

	//Ê®ÍòÊä³ö
	if ((sw == 0 && bw != 0) && w != 0)
	{
		printf("Áã");
	}
	else if (sw == 1)
		printf("Ò¼Ê°");
	else if (sw == 2)
		printf("·¡Ê°");
	else if (sw == 3)
		printf("ÈşÊ°");
	else if (sw == 4)
		printf("ËÁÊ°");
	else if (sw == 5)
		printf("ÎéÊ°");
	else if (sw == 6)
		printf("Â½Ê°");
	else if (sw == 7)
		printf("ÆâÊ°");
	else if (sw == 8)
		printf("°ÆÊ°");
	else if (sw == 9)
		printf("¾ÁÊ°");

	//ÍòÎ»Êä³ö
	if (w == 0 && (qw != 0 || bw != 0 || sw != 0))
	{
		printf("Íò");
	}
	else if (w == 1)
		printf("Ò¼Íò");
	else if (w == 2)
		printf("·¡Íò");
	else if (w == 3)
		printf("ÈşÍò");
	else if (w == 4)
		printf("ËÁÍò");
	else if (w == 5)
		printf("ÎéÍò");
	else if (w == 6)
		printf("Â½Íò");
	else if (w == 7)
		printf("ÆâÍò");
	else if (w == 8)
		printf("°ÆÍò");
	else if (w == 9)
		printf("¾ÁÍò");

	//Ç§Î»Êä³ö
	if (((sy + y + qw + bw + sw + w) != 0) && ((b + s + yuan) != 0)&&q==0)
		printf("Áã");
	else if (q == 1)
		printf("Ò¼Çª");
	else if (q == 2)
		printf("·¡Çª");
	else if (q == 3)
		printf("ÈşÇª");
	else if (q == 4)
		printf("ËÁÇª");
	else if (q == 5)
		printf("ÎéÇª");
	else if (q == 6)
		printf("Â½Çª");
	else if (q == 7)
		printf("ÆâÇª");
	else if (q == 8)
		printf("°ÆÇª");
	else if (q == 9)
		printf("¾ÁÇª");

	//°ÙÎ»Êä³ö
	if ((b == 0 && q != 0) && (s != 0 || yuan != 0))
	{
		printf("Áã");
	}
	else if (b == 1)
		printf("Ò¼°Û");
	else if (b == 2)
		printf("·¡°Û");
	else if (b == 3)
		printf("Èş°Û");
	else if (b == 4)
		printf("ËÁ°Û");
	else if (b == 5)
		printf("Îé°Û");
	else if (b == 6)
		printf("Â½°Û");
	else if (b == 7)
		printf("Æâ°Û");
	else if (b == 8)
		printf("°Æ°Û");
	else if (b == 9)
		printf("¾Á°Û");

	//Ê®Î»Êä³ö
	if ((s == 0 && b != 0) && yuan != 0)
	{
		printf("Áã");
	}
	else if (s == 1)
		printf("Ò¼Ê°");
	else if (s == 2)
		printf("·¡Ê°");
	else if (s == 3)
		printf("ÈşÊ°");
	else if (s == 4)
		printf("ËÁÊ°");
	else if (s == 5)
		printf("ÎéÊ°");
	else if (s == 6)
		printf("Â½Ê°");
	else if (s == 7)
		printf("ÆâÊ°");
	else if (s == 8)
		printf("°ÆÊ°");
	else if (s == 9)
		printf("¾ÁÊ°");


	//¸öÎ»Êä³ö
	if ((yuan == 0) && (sy + y + qw + bw + sw + w + q + b + s) != 0)
	{
		printf("Ô²");
	}
	else if (yuan == 1)
		printf("Ò¼Ô²");
	else if (yuan == 2)
		printf("·¡Ô²");
	else if (yuan == 3)
		printf("ÈşÔ²");
	else if (yuan == 4)
		printf("ËÁÔ²");
	else if (yuan == 5)
		printf("ÎéÔ²");
	else if (yuan == 6)
		printf("Â½Ô²");
	else if (yuan == 7)
		printf("ÆâÔ²");
	else if (yuan == 8)
		printf("°ÆÔ²");
	else if (yuan == 9)
		printf("¾ÁÔ²");

	//½ÇÊä³ö
	if (((jiao + fen) == 0) && (sy + y + qw + bw + sw + w + q + b + s + yuan) != 0)
		printf("Õû");
	else if ((jiao + fen) == 0)
		printf("ÁãÔ²Õû");
	else if (jiao == 0 && ((sy + y + qw + bw + sw + w + q + b + s + yuan) != 0))
		printf("Áã");
	else if (jiao == 1)
	    printf("Ò¼½Ç");
	else if (jiao == 2)
		printf("·¡½Ç");
	else if (jiao == 3)
		printf("Èş½Ç");
	else if (jiao == 4)
		printf("ËÁ½Ç");
	else if (jiao == 5)
		printf("Îé½Ç");
	else if (jiao == 6)
		printf("Â½½Ç");
	else if (jiao == 7)
		printf("Æâ½Ç");
	else if (jiao == 8)
		printf("°Æ½Ç");
	else if (jiao == 9)
		printf("¾Á½Ç");

	//·ÖÊä³ö
	if (fen == 0 && jiao != 0)
    	printf ("Õû");
	else if (fen == 1)
		printf("Ò¼·Ö");
	else if (fen == 2)
	    printf("·¡·Ö");
	else if (fen == 3)
	    printf("Èş·Ö");
	else if (fen == 4)
		printf("ËÁ·Ö");
	else if (fen == 5)
		printf("Îé·Ö");
	else if (fen == 6)
		printf("Â½·Ö");
	else if (fen == 7)
		printf("Æâ·Ö");
	else if (fen == 8)
		printf("°Æ·Ö");
	else if (fen == 9)
		printf("¾Á·Ö");
	printf("\n");

	return 0;
}