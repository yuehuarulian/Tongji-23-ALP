//��04 2252941 ������
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	double a;
	long long int z, x;
	long long int sy, y, qw, bw, sw, w, q, b, s, yuan, jiao, fen;
	printf("������[0-100��)֮�������:\n");
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
	printf("��д�����:\n");

	//ʮ��λ���
	if (sy == 1)
		printf ("Ҽʰ");
	else if (sy == 2)
		printf ("��ʰ");
	else if (sy == 3)
		printf("��ʰ");
	else if (sy == 4)
		printf("��ʰ");
	else if (sy == 5)
		printf("��ʰ");
	else if (sy == 6)
		printf("½ʰ");
	else if (sy == 7)
		printf("��ʰ");
	else if (sy == 8)
		printf("��ʰ");
	else if (sy == 9)
		printf("��ʰ");

	//��λ���
	if (y == 0 && sy != 0)
		printf("��");
	else if (y == 1)
		printf("Ҽ��");
	else if (y == 2)
		printf("����");
	else if (y == 3)
		printf("����");
	else if (y == 4)
		printf("����");
	else if (y == 5)
		printf("����");
	else if (y == 6)
		printf("½��");
	else if (y == 7)
		printf("����");
	else if (y == 8)
		printf("����");
	else if (y == 9)
		printf("����");

	//ǧ��λ���
	if (((sy +y) != 0) && ((bw +sw +w) != 0)&&qw==0)
		printf("��");
	else if (qw == 1)
		printf("ҼǪ");
	else if (qw == 2)
		printf("��Ǫ");
	else if (qw == 3)
		printf("��Ǫ");
	else if (qw == 4)
		printf("��Ǫ");
	else if (qw == 5)
		printf("��Ǫ");
	else if (qw == 6)
		printf("½Ǫ");
	else if (qw == 7)
		printf("��Ǫ");
	else if (qw == 8)
		printf("��Ǫ");
	else if (qw == 9)
		printf("��Ǫ");

	//����λ���
	if ((qw != 0 && bw == 0) && (sw != 0 || w != 0)&&bw==0)
	{
		printf("��");
	}
	else if (bw == 1)
		printf("Ҽ��");
	else if (bw == 2)
		printf("����");
	else if (bw == 3)
		printf("����");
	else if (bw == 4)
		printf("����");
	else if (bw == 5)
		printf("���");
	else if (bw == 6)
		printf("½��");
	else if (bw == 7)
		printf("���");
	else if (bw == 8)
		printf("�ư�");
	else if (bw == 9)
		printf("����");

	//ʮ�����
	if ((sw == 0 && bw != 0) && w != 0)
	{
		printf("��");
	}
	else if (sw == 1)
		printf("Ҽʰ");
	else if (sw == 2)
		printf("��ʰ");
	else if (sw == 3)
		printf("��ʰ");
	else if (sw == 4)
		printf("��ʰ");
	else if (sw == 5)
		printf("��ʰ");
	else if (sw == 6)
		printf("½ʰ");
	else if (sw == 7)
		printf("��ʰ");
	else if (sw == 8)
		printf("��ʰ");
	else if (sw == 9)
		printf("��ʰ");

	//��λ���
	if (w == 0 && (qw != 0 || bw != 0 || sw != 0))
	{
		printf("��");
	}
	else if (w == 1)
		printf("Ҽ��");
	else if (w == 2)
		printf("����");
	else if (w == 3)
		printf("����");
	else if (w == 4)
		printf("����");
	else if (w == 5)
		printf("����");
	else if (w == 6)
		printf("½��");
	else if (w == 7)
		printf("����");
	else if (w == 8)
		printf("����");
	else if (w == 9)
		printf("����");

	//ǧλ���
	if (((sy + y + qw + bw + sw + w) != 0) && ((b + s + yuan) != 0)&&q==0)
		printf("��");
	else if (q == 1)
		printf("ҼǪ");
	else if (q == 2)
		printf("��Ǫ");
	else if (q == 3)
		printf("��Ǫ");
	else if (q == 4)
		printf("��Ǫ");
	else if (q == 5)
		printf("��Ǫ");
	else if (q == 6)
		printf("½Ǫ");
	else if (q == 7)
		printf("��Ǫ");
	else if (q == 8)
		printf("��Ǫ");
	else if (q == 9)
		printf("��Ǫ");

	//��λ���
	if ((b == 0 && q != 0) && (s != 0 || yuan != 0))
	{
		printf("��");
	}
	else if (b == 1)
		printf("Ҽ��");
	else if (b == 2)
		printf("����");
	else if (b == 3)
		printf("����");
	else if (b == 4)
		printf("����");
	else if (b == 5)
		printf("���");
	else if (b == 6)
		printf("½��");
	else if (b == 7)
		printf("���");
	else if (b == 8)
		printf("�ư�");
	else if (b == 9)
		printf("����");

	//ʮλ���
	if ((s == 0 && b != 0) && yuan != 0)
	{
		printf("��");
	}
	else if (s == 1)
		printf("Ҽʰ");
	else if (s == 2)
		printf("��ʰ");
	else if (s == 3)
		printf("��ʰ");
	else if (s == 4)
		printf("��ʰ");
	else if (s == 5)
		printf("��ʰ");
	else if (s == 6)
		printf("½ʰ");
	else if (s == 7)
		printf("��ʰ");
	else if (s == 8)
		printf("��ʰ");
	else if (s == 9)
		printf("��ʰ");


	//��λ���
	if ((yuan == 0) && (sy + y + qw + bw + sw + w + q + b + s) != 0)
	{
		printf("Բ");
	}
	else if (yuan == 1)
		printf("ҼԲ");
	else if (yuan == 2)
		printf("��Բ");
	else if (yuan == 3)
		printf("��Բ");
	else if (yuan == 4)
		printf("��Բ");
	else if (yuan == 5)
		printf("��Բ");
	else if (yuan == 6)
		printf("½Բ");
	else if (yuan == 7)
		printf("��Բ");
	else if (yuan == 8)
		printf("��Բ");
	else if (yuan == 9)
		printf("��Բ");

	//�����
	if (((jiao + fen) == 0) && (sy + y + qw + bw + sw + w + q + b + s + yuan) != 0)
		printf("��");
	else if ((jiao + fen) == 0)
		printf("��Բ��");
	else if (jiao == 0 && ((sy + y + qw + bw + sw + w + q + b + s + yuan) != 0))
		printf("��");
	else if (jiao == 1)
	    printf("Ҽ��");
	else if (jiao == 2)
		printf("����");
	else if (jiao == 3)
		printf("����");
	else if (jiao == 4)
		printf("����");
	else if (jiao == 5)
		printf("���");
	else if (jiao == 6)
		printf("½��");
	else if (jiao == 7)
		printf("���");
	else if (jiao == 8)
		printf("�ƽ�");
	else if (jiao == 9)
		printf("����");

	//�����
	if (fen == 0 && jiao != 0)
    	printf ("��");
	else if (fen == 1)
		printf("Ҽ��");
	else if (fen == 2)
	    printf("����");
	else if (fen == 3)
	    printf("����");
	else if (fen == 4)
		printf("����");
	else if (fen == 5)
		printf("���");
	else if (fen == 6)
		printf("½��");
	else if (fen == 7)
		printf("���");
	else if (fen == 8)
		printf("�Ʒ�");
	else if (fen == 9)
		printf("����");
	printf("\n");

	return 0;
}