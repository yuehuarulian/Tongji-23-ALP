//��04 2252941 ������
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	double mon;
	int a, b;
	long long z, x;
	printf("����������ֵ��\n");
	scanf("%lf", &mon);
	z = (long long int)(mon);
	x = (long long int)((mon - z) * 100 + 0.5);

	//50 20 10 5 1
	int a0, a1, a2, a3, a4;
	a0 = z / 50;
	a1 = z % 50 / 20;
	a2 = z % 50 % 20 / 10;
	a3 = z % 50 % 20 % 10 / 5;
	a4 = z % 5;

	//5 1 5 2 1
	int b0, b1, b2, b3, b4;
	b0 = x / 50;
	b1 = x % 50 / 10;
	b2 = x % 10 / 5;
	b3 = x % 5 / 2;
	b4 = x % 5 % 2;

	a = a0 + a1 + a2 + a3 + a4 + b0 + b1 + b2 + b3 + b4;

	//����������
	if (mon > (0.01 - 1e-6) && mon <= (100 + 1e-6))
	{
		b = 1;
		printf("��%d�����㣬�������£�\n", a);
	}
	else
	{
		b = 0;
		printf("�����������������\n");
	}

	//������ȷ���
	if (a0 != 0 && b == 1)
		printf("50Ԫ : %d��\n", a0);
	if (a1 != 0 && b == 1)
		printf("20Ԫ : %d��\n", a1);
	if (a2 != 0 && b == 1)
		printf("10Ԫ : %d��\n", a2);
	if (a3 != 0 && b == 1)
		printf("5Ԫ  : %d��\n", a3);
	if (a4 != 0 && b == 1)
		printf("1Ԫ  : %d��\n", a4);
	if (b0 != 0 && b == 1)
		printf("5��  : %d��\n", b0);
	if (b1 != 0 && b == 1)
		printf("1��  : %d��\n", b1);
	if (b2 != 0 && b == 1)
		printf("5��  : %d��\n", b2);
	if (b3 != 0 && b == 1)
		printf("2��  : %d��\n", b3);
	if (b4 != 0 && b == 1)
		printf("1��  : %d��\n", b4);

	return 0;
}
