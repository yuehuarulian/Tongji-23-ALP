/* ��04 2252941 ������ */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main()
{
	const float pi = 3.14159f;
	int a, b, r;
	float s;
	printf("�����������ε����߼���нǣ��Ƕȣ�\n");
	scanf("%d %d %d", &a,&b,&r);
	s = (float)1 / 2 * a * b * sin((float)r / 180 * pi);
	printf("�����ε����Ϊ : %.3f\n", s);

	return 0;
}
