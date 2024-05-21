//–≈04 2252941 —Ó»¡È
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int a, b, c;
	for (a = 1; a <= 9; a++)
	{
		for (b = 1; b <= a; b++)
		{
			c = b * a;
			printf("%dx%d=%-4d", b, a, c);
		}
		printf("\n");
	}
}