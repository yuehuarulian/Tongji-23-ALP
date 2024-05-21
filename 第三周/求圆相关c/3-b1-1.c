/* 信04 2252941 杨瑞灵 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	const double pi=3.14159;
	double r, h;
	printf("请输入半径和高度\n");
	scanf("%lf %lf", &r, &h);
	double c, s, s_qiu, v_qiu, v_zhu;
	c = 2 * pi * r;
	s = pi * r * r;
	s_qiu = 4 * pi * r * r;
	v_qiu = (double)4 / (double)3 * pi * r * r * r;
	v_zhu = s * h;
	printf("圆周长    ：%.2lf\n", c);
	printf("圆面积    ：%.2lf\n", s);
	printf("圆球表面积：%.2lf\n", s_qiu);
	printf("圆球体积  ：%.2lf\n", v_qiu);
	printf("圆柱体积  ：%.2lf\n", v_zhu);

	return 0;
}
