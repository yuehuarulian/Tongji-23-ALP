/* ��04 2252941 ������ */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	const double pi=3.14159;
	double r, h;
	printf("������뾶�͸߶�\n");
	scanf("%lf %lf", &r, &h);
	double c, s, s_qiu, v_qiu, v_zhu;
	c = 2 * pi * r;
	s = pi * r * r;
	s_qiu = 4 * pi * r * r;
	v_qiu = (double)4 / (double)3 * pi * r * r * r;
	v_zhu = s * h;
	printf("Բ�ܳ�    ��%.2lf\n", c);
	printf("Բ���    ��%.2lf\n", s);
	printf("Բ��������%.2lf\n", s_qiu);
	printf("Բ�����  ��%.2lf\n", v_qiu);
	printf("Բ�����  ��%.2lf\n", v_zhu);

	return 0;
}
