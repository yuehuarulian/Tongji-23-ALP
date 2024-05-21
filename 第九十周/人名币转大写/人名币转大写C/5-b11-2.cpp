//信04 2252941 杨瑞灵
#include <iostream>
#include <cstdio>
#include <string>
//可按需增加需要的头文件
using namespace std;

const char chnstr[] = "零壹贰叁肆伍陆柒捌玖"; /* 所有输出大写 "零" ~ "玖" 的地方，只允许从这个数组中取值 */
string result;  /* 除result外，不再允许定义任何形式的全局变量 */

int main()
{
	double a;
	long long int z, x;
	long long int sy, y, qw, bw, sw, w, q, b, s, yuan, jiao, fen;
	cout << "请输入[0-100亿)之间的数字:" << endl;
	cin >> a;
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
	cout << "大写结果是:" << endl;
	//十亿位输出
	if (sy != 0)
	{
		result+= chnstr[sy * 2];
		result+= chnstr[sy * 2 + 1];
		result += "拾";
	}

	//亿位输出
	if (y == 0 && sy != 0)
		result += "亿";
	else if (y != 0)
	{
		result+=chnstr[y * 2];
		result+= chnstr[y * 2 + 1];
		result += "亿";
	}

	//千万位输出
	if (((sy + y) != 0) && ((bw + sw + w) != 0) && qw == 0)
	{
		result+= chnstr[qw * 2];
		result+= chnstr[qw * 2 + 1];
	}
	else if (qw != 0)
	{
		result+=chnstr[qw * 2];
		result+=chnstr[qw * 2 + 1];
		result += "仟";
	}

	//百万位输出
	if ((qw != 0 && bw == 0) && (sw != 0 || w != 0) && bw == 0)
	{
		result+=chnstr[bw * 2];
		result += chnstr[bw * 2 + 1];
	}
	else if (bw != 0)
	{
		result += chnstr[bw * 2];
		result +=  chnstr[bw * 2 + 1];
		result += "佰";
	}

	//十万输出
	if ((sw == 0 && bw != 0) && w != 0)
	{
		result += chnstr[sw * 2];
		result += chnstr[sw * 2 + 1];
	}
	else if (sw != 0)
	{
		result += chnstr[sw * 2];
		result += chnstr[sw * 2 + 1];
		result += "拾";
	}

	//万位输出
	if (w == 0 && (qw != 0 || bw != 0 || sw != 0))
		result += "万";
	else if (w != 0)
	{
		result += chnstr[w * 2];
		result += chnstr[w * 2 + 1];
		result += "万";
	}

	//千位输出
	if (((sy + y + qw + bw + sw + w) != 0) && ((b + s + yuan) != 0) && q == 0)
	{
		result += chnstr[q * 2];
		result += chnstr[q * 2 + 1];
	}
	else if (q != 0)
	{
		result += chnstr[q * 2];
		result += chnstr[q * 2 + 1];
		result += "仟";
	}

	//百位输出
	if ((b == 0 && q != 0) && (s != 0 || yuan != 0))
	{
		result+= chnstr[b * 2];
		result += chnstr[b * 2 + 1];
	}
	else if (b != 0)
	{
		result += chnstr[b * 2];
		result += chnstr[b * 2 + 1];
		result += "佰";
	}

	//十位输出
	if ((s == 0 && b != 0) && yuan != 0)
	{
		result += chnstr[s * 2];
		result += chnstr[s * 2 + 1];
	}
	else if (s != 0)
	{
		result += chnstr[s * 2];
		result += chnstr[s * 2 + 1];
		result += "拾";
	}

	//个位输出
	if ((yuan == 0) && (sy + y + qw + bw + sw + w + q + b + s) != 0)
		result += "圆";
	else if (yuan != 0)
	{
		result += chnstr[yuan * 2];
		result += chnstr[yuan * 2 + 1];
		result += "圆";
	}

	//角输出
	if (((jiao + fen) == 0) && (sy + y + qw + bw + sw + w + q + b + s + yuan) != 0)
		result += "整";
	else if ((jiao + fen) == 0)
	{
		result += chnstr[jiao * 2];
		result += chnstr[jiao * 2 + 1];
		result += "圆整";
	}
	else if (jiao == 0 && ((sy + y + qw + bw + sw + w + q + b + s + yuan) != 0))
	{
		result += chnstr[jiao * 2];
		result += chnstr[jiao * 2 + 1];
	}
	else if (jiao != 0)
	{
		result += chnstr[jiao * 2];
		result += chnstr[jiao * 2 + 1];
		result += "角";
	}

	//分输出
	if (fen == 0 && jiao != 0)
	{
		result += "整";
	}
	else if (fen != 0)
	{
		result += chnstr[fen * 2];
		result += chnstr[fen * 2 + 1];
		result += "分";
	}
	cout << result << endl;  /* 转换得到的大写结果，只允许用本语句输出，其它地方不允许以任何形式对大写结果进行全部/部分输出 */
	return 0;
}