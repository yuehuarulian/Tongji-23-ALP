//��04 2252941 ������
#include <iostream>
#include <cstdio>
#include <string>
//�ɰ���������Ҫ��ͷ�ļ�
using namespace std;

const char chnstr[] = "��Ҽ��������½��ƾ�"; /* ���������д "��" ~ "��" �ĵط���ֻ��������������ȡֵ */
string result;  /* ��result�⣬�����������κ���ʽ��ȫ�ֱ��� */

int main()
{
	double a;
	long long int z, x;
	long long int sy, y, qw, bw, sw, w, q, b, s, yuan, jiao, fen;
	cout << "������[0-100��)֮�������:" << endl;
	cin >> a;
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
	cout << "��д�����:" << endl;
	//ʮ��λ���
	if (sy != 0)
	{
		result+= chnstr[sy * 2];
		result+= chnstr[sy * 2 + 1];
		result += "ʰ";
	}

	//��λ���
	if (y == 0 && sy != 0)
		result += "��";
	else if (y != 0)
	{
		result+=chnstr[y * 2];
		result+= chnstr[y * 2 + 1];
		result += "��";
	}

	//ǧ��λ���
	if (((sy + y) != 0) && ((bw + sw + w) != 0) && qw == 0)
	{
		result+= chnstr[qw * 2];
		result+= chnstr[qw * 2 + 1];
	}
	else if (qw != 0)
	{
		result+=chnstr[qw * 2];
		result+=chnstr[qw * 2 + 1];
		result += "Ǫ";
	}

	//����λ���
	if ((qw != 0 && bw == 0) && (sw != 0 || w != 0) && bw == 0)
	{
		result+=chnstr[bw * 2];
		result += chnstr[bw * 2 + 1];
	}
	else if (bw != 0)
	{
		result += chnstr[bw * 2];
		result +=  chnstr[bw * 2 + 1];
		result += "��";
	}

	//ʮ�����
	if ((sw == 0 && bw != 0) && w != 0)
	{
		result += chnstr[sw * 2];
		result += chnstr[sw * 2 + 1];
	}
	else if (sw != 0)
	{
		result += chnstr[sw * 2];
		result += chnstr[sw * 2 + 1];
		result += "ʰ";
	}

	//��λ���
	if (w == 0 && (qw != 0 || bw != 0 || sw != 0))
		result += "��";
	else if (w != 0)
	{
		result += chnstr[w * 2];
		result += chnstr[w * 2 + 1];
		result += "��";
	}

	//ǧλ���
	if (((sy + y + qw + bw + sw + w) != 0) && ((b + s + yuan) != 0) && q == 0)
	{
		result += chnstr[q * 2];
		result += chnstr[q * 2 + 1];
	}
	else if (q != 0)
	{
		result += chnstr[q * 2];
		result += chnstr[q * 2 + 1];
		result += "Ǫ";
	}

	//��λ���
	if ((b == 0 && q != 0) && (s != 0 || yuan != 0))
	{
		result+= chnstr[b * 2];
		result += chnstr[b * 2 + 1];
	}
	else if (b != 0)
	{
		result += chnstr[b * 2];
		result += chnstr[b * 2 + 1];
		result += "��";
	}

	//ʮλ���
	if ((s == 0 && b != 0) && yuan != 0)
	{
		result += chnstr[s * 2];
		result += chnstr[s * 2 + 1];
	}
	else if (s != 0)
	{
		result += chnstr[s * 2];
		result += chnstr[s * 2 + 1];
		result += "ʰ";
	}

	//��λ���
	if ((yuan == 0) && (sy + y + qw + bw + sw + w + q + b + s) != 0)
		result += "Բ";
	else if (yuan != 0)
	{
		result += chnstr[yuan * 2];
		result += chnstr[yuan * 2 + 1];
		result += "Բ";
	}

	//�����
	if (((jiao + fen) == 0) && (sy + y + qw + bw + sw + w + q + b + s + yuan) != 0)
		result += "��";
	else if ((jiao + fen) == 0)
	{
		result += chnstr[jiao * 2];
		result += chnstr[jiao * 2 + 1];
		result += "Բ��";
	}
	else if (jiao == 0 && ((sy + y + qw + bw + sw + w + q + b + s + yuan) != 0))
	{
		result += chnstr[jiao * 2];
		result += chnstr[jiao * 2 + 1];
	}
	else if (jiao != 0)
	{
		result += chnstr[jiao * 2];
		result += chnstr[jiao * 2 + 1];
		result += "��";
	}

	//�����
	if (fen == 0 && jiao != 0)
	{
		result += "��";
	}
	else if (fen != 0)
	{
		result += chnstr[fen * 2];
		result += chnstr[fen * 2 + 1];
		result += "��";
	}
	cout << result << endl;  /* ת���õ��Ĵ�д�����ֻ�����ñ��������������ط����������κ���ʽ�Դ�д�������ȫ��/������� */
	return 0;
}