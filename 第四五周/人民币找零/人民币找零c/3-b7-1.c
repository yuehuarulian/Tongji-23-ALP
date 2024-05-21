//信04 2252941 杨瑞灵
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	double mon;
	int a, b;
	long long z, x;
	printf("请输入找零值：\n");
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

	//输入错误情况
	if (mon > (0.01 - 1e-6) && mon <= (100 + 1e-6))
	{
		b = 1;
		printf("共%d张找零，具体如下：\n", a);
	}
	else
	{
		b = 0;
		printf("输入错误，请重新输入\n");
	}

	//输入正确情况
	if (a0 != 0 && b == 1)
		printf("50元 : %d张\n", a0);
	if (a1 != 0 && b == 1)
		printf("20元 : %d张\n", a1);
	if (a2 != 0 && b == 1)
		printf("10元 : %d张\n", a2);
	if (a3 != 0 && b == 1)
		printf("5元  : %d张\n", a3);
	if (a4 != 0 && b == 1)
		printf("1元  : %d张\n", a4);
	if (b0 != 0 && b == 1)
		printf("5角  : %d张\n", b0);
	if (b1 != 0 && b == 1)
		printf("1角  : %d张\n", b1);
	if (b2 != 0 && b == 1)
		printf("5分  : %d张\n", b2);
	if (b3 != 0 && b == 1)
		printf("2分  : %d张\n", b3);
	if (b4 != 0 && b == 1)
		printf("1分  : %d张\n", b4);

	return 0;
}
