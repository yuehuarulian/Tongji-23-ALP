//��04 2252941 ������
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
const char chnstr[] = "��Ҽ��������½��ƾ�"; /* ���������д "��" ~ "��" �ĵط���ֻ��������������ȡֵ */
char result[256];  /* ��result�⣬�����������κ���ʽ��ȫ�ֱ��� */

int main()
{
	double a;
	long long int z, x;
	long long int sy, y, qw, bw, sw, w, q, b, s, yuan, jiao, fen;
	int cn = 0;
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
	if (sy != 0)
	{
		
		result[cn] = chnstr[sy * 2];
		++cn;
		result[cn] = chnstr[sy * 2 + 1];
		//strncpy(&result[i],&chnstr[sy*2],2);
		++cn;
		strcat(result, "ʰ");//strcat����β��
		//strncpy(&result[i],"ʰ",2);//����β��
		cn += 2;
	}
	

	//��λ���
	if (y == 0 && sy != 0)
	{
		strcat(result, "��");
		cn += 2;
	}
	else if (y != 0)
	{
		result[cn] = chnstr[y * 2];
		++cn;
		result[cn] = chnstr[y * 2 + 1];
		++cn;
		strcat(result, "��");
		cn += 2;
	}

	//ǧ��λ���
	if (((sy + y) != 0) && ((bw + sw + w) != 0) && qw == 0)
	{
		result[cn] = chnstr[qw * 2];
		++cn;
		result[cn] = chnstr[qw * 2 + 1];
		++cn;
	}
	else if (qw != 0)
	{
		result[cn] = chnstr[qw * 2];
		++cn;
		result[cn] = chnstr[qw * 2 + 1];
		++cn;
		strcat(result, "Ǫ");
		cn += 2;
	}
		
	//����λ���
	if ((qw != 0 && bw == 0) && (sw != 0 || w != 0) && bw == 0)
	{
		result[cn] = chnstr[bw * 2];
		++cn;
		result[cn] = chnstr[bw * 2 + 1];
		++cn;
	}
	else if (bw != 0)
	{
		result[cn] = chnstr[bw * 2];
		++cn;
		result[cn] = chnstr[bw * 2 + 1];
		++cn;
		strcat(result, "��");
		cn += 2;
	}
	
	//ʮ�����
	if ((sw == 0 && bw != 0) && w != 0)
	{
		result[cn] = chnstr[sw * 2];
		++cn;
		result[cn] = chnstr[sw * 2 + 1];
		++cn;
	}
	else if (sw != 0)
	{
		result[cn] = chnstr[sw * 2];
		++cn;
		result[cn] = chnstr[sw * 2 + 1];
		++cn;
		strcat(result, "ʰ");
		cn += 2;
	}

	//��λ���
	if (w == 0 && (qw != 0 || bw != 0 || sw != 0))
	{
		strcat(result, "��");
		cn += 2;
	}
	else if (w != 0)
	{
		result[cn] = chnstr[w * 2];
		++cn;
		result[cn] = chnstr[w * 2 + 1];
		++cn;
		strcat(result, "��");
		cn += 2;
	}
		
	//ǧλ���
	if (((sy + y + qw + bw + sw + w) != 0) && ((b + s + yuan) != 0) && q == 0)
	{
		result[cn] = chnstr[q * 2];
		++cn;
		result[cn] = chnstr[q * 2 + 1];
		++cn;
	}
	else if (q != 0)
	{
		result[cn] = chnstr[q * 2];
		++cn;
		result[cn] = chnstr[q * 2 + 1];
		++cn;
		strcat(result, "Ǫ");
		cn += 2;
	}

	//��λ���
	if ((b == 0 && q != 0) && (s != 0 || yuan != 0))
	{
		result[cn] = chnstr[b * 2];
		++cn;
		result[cn] = chnstr[b * 2 + 1];
		++cn;
	}
	else if (b != 0)
	{
		result[cn] = chnstr[b * 2];
		++cn;
		result[cn] = chnstr[b * 2 + 1];
		++cn;
		strcat(result, "��");
		cn += 2;

	}
	
	//ʮλ���
	if ((s == 0 && b != 0) && yuan != 0)
	{
		result[cn] = chnstr[s * 2];
		++cn;
		result[cn] = chnstr[s * 2 + 1];
		++cn;
	}
	else if (s != 0)
	{
		result[cn] = chnstr[s * 2];
		++cn;
		result[cn] = chnstr[s * 2 + 1];
		++cn;
		strcat(result, "ʰ");
		cn += 2;

	}
	
	//��λ���
	if ((yuan == 0) && (sy + y + qw + bw + sw + w + q + b + s) != 0)
	{
		strcat(result, "Բ");
		cn += 2;
	}
	else if (yuan != 0)
	{
		result[cn] = chnstr[yuan * 2];
		++cn;
		result[cn] = chnstr[yuan * 2 + 1];
		++cn;
		strcat(result, "Բ");
		cn += 2;
	}
	
	//�����
	if (((jiao + fen) == 0) && (sy + y + qw + bw + sw + w + q + b + s + yuan) != 0)
	{
		strcat(result, "��");
		cn += 2;
	}
	else if ((jiao + fen) == 0)
	{
		result[cn] = chnstr[jiao * 2];
		++cn;
		result[cn] = chnstr[jiao * 2 + 1];
		++cn;
		strcat(result, "Բ��");
		cn += 4;
	}
	else if (jiao == 0 && ((sy + y + qw + bw + sw + w + q + b + s + yuan) != 0))
	{
		result[cn] = chnstr[jiao * 2];
		++cn;
		result[cn] = chnstr[jiao * 2 + 1];
		++cn;
	}
	else if (jiao != 0)
	{
		result[cn] = chnstr[jiao * 2];
		++cn;
		result[cn] = chnstr[jiao * 2 + 1];
		++cn;
		strcat(result, "��");
		cn += 2;
	}

	//�����
	if (fen == 0 && jiao != 0)
	{
		strcat(result, "��");
		cn += 2;
	}
	else if (fen != 0)
	{
		result[cn] = chnstr[fen * 2];
		++cn;
		result[cn] = chnstr[fen * 2 + 1];
		++cn;
		strcat(result, "��");
		cn += 2;
	}
	//for (int i = 0; i < 60; i++)
	//{
	//	int m = result[i];
	//	printf("%d ", m);
	//}
	printf("%s\n", result);  /* ת���õ��Ĵ�д�����ֻ�����ñ��������������ط����������κ���ʽ�Դ�д�������ȫ��/������� */
	return 0;
}