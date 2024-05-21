/* 信04 2252941 杨瑞灵 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main()
{
	const float pi = 3.14159f;
	int a, b, r;
	float s;
	printf("请输入三角形的两边及其夹角（角度）\n");
	scanf("%d %d %d", &a,&b,&r);
	s = (float)1 / 2 * a * b * sin((float)r / 180 * pi);
	printf("三角形的面积为 : %.3f\n", s);

	return 0;
}
