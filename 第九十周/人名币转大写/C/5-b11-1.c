//信04 2252941 杨瑞灵
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
const char chnstr[] = "零壹贰叁肆伍陆柒捌玖"; /* 所有输出大写 "零" ~ "玖" 的地方，只允许从这个数组中取值 */
char result[256];  /* 除result外，不再允许定义任何形式的全局变量 */

int main()
{
	double a;
	long long int z, x;
	long long int sy, y, qw, bw, sw, w, q, b, s, yuan, jiao, fen;
	int cn = 0;
	printf("请输入[0-100亿)之间的数字:\n");
	scanf("%lf", &a);
	z = (long long)(a);
	x = (long long)((a - z) * 100 + 0.5);
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
	printf("大写结果是:\n");
	//十亿位输出
	if (sy != 0)
	{
		
		result[cn] = chnstr[sy * 2];
		++cn;
		result[cn] = chnstr[sy * 2 + 1];
		//strncpy(&result[i],&chnstr[sy*2],2);
		++cn;
		strcat(result, "拾");//strcat带着尾零
		//strncpy(&result[i],"拾",2);//最后加尾零
		cn += 2;
	}
	

	//亿位输出
	if (y == 0 && sy != 0)
	{
		strcat(result, "亿");
		cn += 2;
	}
	else if (y != 0)
	{
		result[cn] = chnstr[y * 2];
		++cn;
		result[cn] = chnstr[y * 2 + 1];
		++cn;
		strcat(result, "亿");
		cn += 2;
	}

	//千万位输出
	if (((sy + y) != 0) && ((bw + sw + w) != 0) && qw == 0)
	{
		result[cn] = chnstr[qw * 2];
		++cn;
		result[cn] = chnstr[qw * 2 + 1];
		++cn;
	}
	else if (qw != 0)
	{
		result[cn] = chnstr[qw * 2];
		++cn;
		result[cn] = chnstr[qw * 2 + 1];
		++cn;
		strcat(result, "仟");
		cn += 2;
	}
		
	//百万位输出
	if ((qw != 0 && bw == 0) && (sw != 0 || w != 0) && bw == 0)
	{
		result[cn] = chnstr[bw * 2];
		++cn;
		result[cn] = chnstr[bw * 2 + 1];
		++cn;
	}
	else if (bw != 0)
	{
		result[cn] = chnstr[bw * 2];
		++cn;
		result[cn] = chnstr[bw * 2 + 1];
		++cn;
		strcat(result, "佰");
		cn += 2;
	}
	
	//十万输出
	if ((sw == 0 && bw != 0) && w != 0)
	{
		result[cn] = chnstr[sw * 2];
		++cn;
		result[cn] = chnstr[sw * 2 + 1];
		++cn;
	}
	else if (sw != 0)
	{
		result[cn] = chnstr[sw * 2];
		++cn;
		result[cn] = chnstr[sw * 2 + 1];
		++cn;
		strcat(result, "拾");
		cn += 2;
	}

	//万位输出
	if (w == 0 && (qw != 0 || bw != 0 || sw != 0))
	{
		strcat(result, "万");
		cn += 2;
	}
	else if (w != 0)
	{
		result[cn] = chnstr[w * 2];
		++cn;
		result[cn] = chnstr[w * 2 + 1];
		++cn;
		strcat(result, "万");
		cn += 2;
	}
		
	//千位输出
	if (((sy + y + qw + bw + sw + w) != 0) && ((b + s + yuan) != 0) && q == 0)
	{
		result[cn] = chnstr[q * 2];
		++cn;
		result[cn] = chnstr[q * 2 + 1];
		++cn;
	}
	else if (q != 0)
	{
		result[cn] = chnstr[q * 2];
		++cn;
		result[cn] = chnstr[q * 2 + 1];
		++cn;
		strcat(result, "仟");
		cn += 2;
	}

	//百位输出
	if ((b == 0 && q != 0) && (s != 0 || yuan != 0))
	{
		result[cn] = chnstr[b * 2];
		++cn;
		result[cn] = chnstr[b * 2 + 1];
		++cn;
	}
	else if (b != 0)
	{
		result[cn] = chnstr[b * 2];
		++cn;
		result[cn] = chnstr[b * 2 + 1];
		++cn;
		strcat(result, "佰");
		cn += 2;

	}
	
	//十位输出
	if ((s == 0 && b != 0) && yuan != 0)
	{
		result[cn] = chnstr[s * 2];
		++cn;
		result[cn] = chnstr[s * 2 + 1];
		++cn;
	}
	else if (s != 0)
	{
		result[cn] = chnstr[s * 2];
		++cn;
		result[cn] = chnstr[s * 2 + 1];
		++cn;
		strcat(result, "拾");
		cn += 2;

	}
	
	//个位输出
	if ((yuan == 0) && (sy + y + qw + bw + sw + w + q + b + s) != 0)
	{
		strcat(result, "圆");
		cn += 2;
	}
	else if (yuan != 0)
	{
		result[cn] = chnstr[yuan * 2];
		++cn;
		result[cn] = chnstr[yuan * 2 + 1];
		++cn;
		strcat(result, "圆");
		cn += 2;
	}
	
	//角输出
	if (((jiao + fen) == 0) && (sy + y + qw + bw + sw + w + q + b + s + yuan) != 0)
	{
		strcat(result, "整");
		cn += 2;
	}
	else if ((jiao + fen) == 0)
	{
		result[cn] = chnstr[jiao * 2];
		++cn;
		result[cn] = chnstr[jiao * 2 + 1];
		++cn;
		strcat(result, "圆整");
		cn += 4;
	}
	else if (jiao == 0 && ((sy + y + qw + bw + sw + w + q + b + s + yuan) != 0))
	{
		result[cn] = chnstr[jiao * 2];
		++cn;
		result[cn] = chnstr[jiao * 2 + 1];
		++cn;
	}
	else if (jiao != 0)
	{
		result[cn] = chnstr[jiao * 2];
		++cn;
		result[cn] = chnstr[jiao * 2 + 1];
		++cn;
		strcat(result, "角");
		cn += 2;
	}

	//分输出
	if (fen == 0 && jiao != 0)
	{
		strcat(result, "整");
		cn += 2;
	}
	else if (fen != 0)
	{
		result[cn] = chnstr[fen * 2];
		++cn;
		result[cn] = chnstr[fen * 2 + 1];
		++cn;
		strcat(result, "分");
		cn += 2;
	}
	//for (int i = 0; i < 60; i++)
	//{
	//	int m = result[i];
	//	printf("%d ", m);
	//}
	printf("%s\n", result);  /* 转换得到的大写结果，只允许用本语句输出，其它地方不允许以任何形式对大写结果进行全部/部分输出 */
	return 0;
}