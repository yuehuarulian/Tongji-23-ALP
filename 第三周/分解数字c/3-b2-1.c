/* ��04 2252941 ������ */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int a;
	int wan, qian, bai, shi, ge;
	printf("������һ��[1..30000]�������:\n");
	scanf("%d", &a);
	wan = a / 10000;
	qian = (a - 10000 * wan) / 1000;
	bai = a % 1000 / 100;
	shi = a % 100 / 10;
	ge = a % 10;
	printf("��λ : %d\n",wan);
	printf("ǧλ ; %d\n", qian);
	printf("��λ ; %d\n", bai);
	printf("ʮλ ; %d\n", shi);
	printf("��λ ; %d\n", ge);

	return 0;
}
