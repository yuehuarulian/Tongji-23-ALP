/* 信04 2252941 杨瑞灵 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int a;
	int wan, qian, bai, shi, ge;
	printf("请输入一个[1..30000]间的整数:\n");
	scanf("%d", &a);
	wan = a / 10000;
	qian = (a - 10000 * wan) / 1000;
	bai = a % 1000 / 100;
	shi = a % 100 / 10;
	ge = a % 10;
	printf("万位 : %d\n",wan);
	printf("千位 ; %d\n", qian);
	printf("百位 ; %d\n", bai);
	printf("十位 ; %d\n", shi);
	printf("个位 ; %d\n", ge);

	return 0;
}
