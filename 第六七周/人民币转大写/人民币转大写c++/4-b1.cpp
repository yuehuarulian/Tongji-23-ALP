/* 2252941 ������ ��04 */
#include <iostream>
using namespace std;

/* �ɸ�����Ҫ�����Ӧ������ */

/***************************************************************************
  �������ƣ�
  ��    �ܣ������д��0~9
  ���������
  �� �� ֵ��
  ˵    �������������⣬�������κκ�����������㡱-������!!!!!!
***************************************************************************/
void daxie(int num, int flag_of_zero)
{
	/* ������Ա��������κ��޸� */
	switch (num) {
		case 0:
			if (flag_of_zero)	//�˱��ʲô��˼������˼��
				cout << "��";
			break;
		case 1:
			cout << "Ҽ";
			break;
		case 2:
			cout << "��";
			break;
		case 3:
			cout << "��";
			break;
		case 4:
			cout << "��";
			break;
		case 5:
			cout << "��";
			break;
		case 6:
			cout << "½";
			break;
		case 7:
			cout << "��";
			break;
		case 8:
			cout << "��";
			break;
		case 9:
			cout << "��";
			break;
		default:
			cout << "error";
			break;
	}
}

/* �ɸ�����Ҫ�Զ�����������(Ҳ���Բ�����) */

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
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

	//ʮ�����
	daxie(sy, 0);
	cout << (sy != 0 ? "ʰ" : "");

	//�����
	daxie(y, 0);
	cout << (sy + y != 0 ? "��" : "");

	//ǧ�����
	daxie(qw, ((sy + y) != 0 && bw != 0));
	cout << (qw != 0 ? "Ǫ" : "");

	//����λ���
	daxie(bw, ((sy + y + qw) != 0 && sw != 0));
	cout << (bw != 0 ? "��" : "");

	//ʮ��λ���
	daxie(sw, ((sy + y + qw + bw) != 0 && w != 0));
	cout << (sw != 0 ? "ʰ" : "");

	//��λ���
	daxie(w, 0);
	cout << ((qw + bw + sw + w) != 0 ? "��" : "");

	//ǧλ���
	daxie(q, (sy + y + qw + bw + w) != 0 && b != 0);
	cout << (q != 0 ? "Ǫ" : "");

	//��λ���
	daxie(b, (sy + y + qw + bw + w + q) != 0 && s != 0);
	cout << (b != 0 ? "��" : "");

	//ʮλ���
	daxie(s, (sy + y + qw + bw + sw + w + q + b) != 0 && yuan != 0);
	cout << (s != 0 ? "ʰ" : "");

	//��λ���
	daxie(yuan, 0);
	cout << ((sy + y + qw + bw + sw + w + q + b + s + yuan) != 0 ? "Բ" : "");

	//�����
	daxie(jiao, (sy + y + qw + bw + w + q + b + s + yuan) != 0 && fen != 0);
	cout << (jiao != 0 ? "��" : "");

	//�����
	daxie(fen, 0);
	cout << (fen != 0 ? "��" : "");


	//�������
	cout << ((sy + y + qw + bw + w + q + b + yuan + jiao + fen) == 0 ? "��Բ" : "");
	cout << (fen == 0 ? "��" : "");

	cout << endl;
	/* ������� */
	return 0;
}