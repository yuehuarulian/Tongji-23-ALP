//��04 2252941 ������
#include <iostream>
using namespace std;

int main()
{
	double a;
	long long int z, x;
	long long int sy, y, qw, bw, sw, w, q, b, s, yuan, jiao, fen;
	cout << "������[0-100��)֮�������:" << endl;
	cin >> a;
	z = (long long int)(a);
	x = (long long int)((a - z) * 100 + 0.5);
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
	if (sy == 1)
		cout << "Ҽʰ";
	else if (sy == 2)
		cout << "��ʰ";
	else if (sy == 3)
		cout << "��ʰ";
	else if (sy == 4)
		cout << "��ʰ";
	else if (sy == 5)
		cout << "��ʰ";
	else if (sy == 6)
		cout << "½ʰ";
	else if (sy == 7)
		cout << "��ʰ";
	else if (sy == 8)
		cout << "��ʰ";
	else if (sy == 9)
		cout << "��ʰ";

	//��λ���
	if (y == 0 && sy != 0)
		cout << "��";
	else if (y == 1)
		cout << "Ҽ��";
	else if (y == 2)
		cout << "����";
	else if (y == 3)
		cout << "����";
	else if (y == 4)
		cout << "����";
	else if (y == 5)
		cout << "����";
	else if (y == 6)
		cout << "½��";
	else if (y == 7)
		cout << "����";
	else if (y == 8)
		cout << "����";
	else if (y == 9)
		cout << "����";

	//ǧ��λ���
	if (((sy + y) != 0) && ((bw + sw + w) != 0) && qw == 0)
		cout << "��";
	else if (qw == 1)
		cout << "ҼǪ";
	else if (qw == 2)
		cout << "��Ǫ";
	else if (qw == 3)
		cout << "��Ǫ";
	else if (qw == 4)
		cout << "��Ǫ";
	else if (qw == 5)
		cout << "��Ǫ";
	else if (qw == 6)
		cout << "½Ǫ";
	else if (qw == 7)
		cout << "��Ǫ";
	else if (qw == 8)
		cout << "��Ǫ";
	else if (qw == 9)
		cout << "��Ǫ";

	//����λ���
	if ((qw != 0 && bw == 0) && (sw != 0 || w != 0) && bw == 0)
	{
		cout << "��";
	}
	else if (bw == 1)
		cout << "Ҽ��";
	else if (bw == 2)
		cout << "����";
	else if (bw == 3)
		cout << "����";
	else if (bw == 4)
		cout << "����";
	else if (bw == 5)
		cout << "���";
	else if (bw == 6)
		cout << "½��";
	else if (bw == 7)
		cout << "���";
	else if (bw == 8)
		cout << "�ư�";
	else if (bw == 9)
		cout << "����";

	//ʮ�����
	if ((sw == 0 && bw != 0) && w != 0)
	{
		cout << "��";
	}
	else if (sw == 1)
		cout << "Ҽʰ";
	else if (sw == 2)
		cout << "��ʰ";
	else if (sw == 3)
		cout << "��ʰ";
	else if (sw == 4)
		cout << "��ʰ";
	else if (sw == 5)
		cout << "��ʰ";
	else if (sw == 6)
		cout << "½ʰ";
	else if (sw == 7)
		cout << "��ʰ";
	else if (sw == 8)
		cout << "��ʰ";
	else if (sw == 9)
		cout << "��ʰ";

	//��λ���
	if (w == 0 && (qw != 0 || bw != 0 || sw != 0))
	{
		cout << "��";
	}
	else if (w == 1)
		cout << "Ҽ��";
	else if (w == 2)
		cout << "����";
	else if (w == 3)
		cout << "����";
	else if (w == 4)
		cout << "����";
	else if (w == 5)
		cout << "����";
	else if (w == 6)
		cout << "½��";
	else if (w == 7)
		cout << "����";
	else if (w == 8)
		cout << "����";
	else if (w == 9)
		cout << "����";

	//ǧλ���
	if (((sy + y + qw + bw + sw + w) != 0) && ((b + s + yuan) != 0) && q == 0)
		cout << "��";
	else if (q == 1)
		cout << "ҼǪ";
	else if (q == 2)
		cout << "��Ǫ";
	else if (q == 3)
		cout << "��Ǫ";
	else if (q == 4)
		cout << "��Ǫ";
	else if (q == 5)
		cout << "��Ǫ";
	else if (q == 6)
		cout << "½Ǫ";
	else if (q == 7)
		cout << "��Ǫ";
	else if (q == 8)
		cout << "��Ǫ";
	else if (q == 9)
		cout << "��Ǫ";

	//��λ���
	if ((b == 0 && q != 0) && (s != 0 || yuan != 0))
	{
		cout << "��";
	}
	else if (b == 1)
		cout << "Ҽ��";
	else if (b == 2)
		cout << "����";
	else if (b == 3)
		cout << "����";
	else if (b == 4)
		cout << "����";
	else if (b == 5)
		cout << "���";
	else if (b == 6)
		cout << "½��";
	else if (b == 7)
		cout << "���";
	else if (b == 8)
		cout << "�ư�";
	else if (b == 9)
		cout << "����";

	//ʮλ���
	if ((s == 0 && b != 0) && yuan != 0)
	{
		cout << "��";
	}
	else if (s == 1)
		cout << "Ҽʰ";
	else if (s == 2)
		cout << "��ʰ";
	else if (s == 3)
		cout << "��ʰ";
	else if (s == 4)
		cout << "��ʰ";
	else if (s == 5)
		cout << "��ʰ";
	else if (s == 6)
		cout << "½ʰ";
	else if (s == 7)
		cout << "��ʰ";
	else if (s == 8)
		cout << "��ʰ";
	else if (s == 9)
		cout << "��ʰ";


	//��λ���
	if ((yuan == 0) && (sy + y + qw + bw + sw + w + q + b + s) != 0)
	{
		cout << "Բ";
	}
	else if (yuan == 1)
		cout << "ҼԲ";
	else if (yuan == 2)
		cout << "��Բ";
	else if (yuan == 3)
		cout << "��Բ";
	else if (yuan == 4)
		cout << "��Բ";
	else if (yuan == 5)
		cout << "��Բ";
	else if (yuan == 6)
		cout << "½Բ";
	else if (yuan == 7)
		cout << "��Բ";
	else if (yuan == 8)
		cout << "��Բ";
	else if (yuan == 9)
		cout << "��Բ";

	//�����
	if (((jiao + fen) == 0) && (sy + y + qw + bw + sw + w + q + b + s + yuan) != 0)
		cout << "��";
	else if ((jiao + fen) == 0)
		cout << "��Բ��";
	else if (jiao == 0 && ((sy + y + qw + bw + sw + w + q + b + s + yuan) != 0))
		cout << "��";
	else if (jiao == 1)
		cout << "Ҽ��";
	else if (jiao == 2)
		cout << "����";
	else if (jiao == 3)
		cout << "����";
	else if (jiao == 4)
		cout << "����";
	else if (jiao == 5)
		cout << "���";
	else if (jiao == 6)
		cout << "½��";
	else if (jiao == 7)
		cout << "���";
	else if (jiao == 8)
		cout << "�ƽ�";
	else if (jiao == 9)
		cout << "����";

	//�����
	if (fen == 0 && jiao != 0)
		cout << "��";
	else if (fen == 1)
		cout << "Ҽ��";
	else if (fen == 2)
		cout << "����";
	else if (fen == 3)
		cout << "����";
	else if (fen == 4)
		cout << "����";
	else if (fen == 5)
		cout << "���";
	else if (fen == 6)
		cout << "½��";
	else if (fen == 7)
		cout << "���";
	else if (fen == 8)
		cout << "�Ʒ�";
	else if (fen == 9)
		cout << "����";
	cout << endl;

	return 0;
}
