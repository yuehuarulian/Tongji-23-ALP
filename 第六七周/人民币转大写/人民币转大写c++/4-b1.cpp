/* 2252941 杨瑞灵 信04 */
#include <iostream>
using namespace std;

/* 可根据需要添加相应的内容 */

/***************************************************************************
  函数名称：
  功    能：输出大写的0~9
  输入参数：
  返 回 值：
  说    明：除本函数外，不允许任何函数中输出“零”-“玖”!!!!!!
***************************************************************************/
void daxie(int num, int flag_of_zero)
{
	/* 不允许对本函数做任何修改 */
	switch (num) {
		case 0:
			if (flag_of_zero)	//此标记什么意思请自行思考
				cout << "零";
			break;
		case 1:
			cout << "壹";
			break;
		case 2:
			cout << "贰";
			break;
		case 3:
			cout << "叁";
			break;
		case 4:
			cout << "肆";
			break;
		case 5:
			cout << "伍";
			break;
		case 6:
			cout << "陆";
			break;
		case 7:
			cout << "柒";
			break;
		case 8:
			cout << "捌";
			break;
		case 9:
			cout << "玖";
			break;
		default:
			cout << "error";
			break;
	}
}

/* 可根据需要自定义其它函数(也可以不定义) */

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int main()
{
	double a;
	long long int z, x;
	long long int sy, y, qw, bw, sw, w, q, b, s, yuan, jiao, fen;
	cout << "请输入[0-100亿)之间的数字:" << endl;
	cin >> a;
	z = (long long int)(a);
	x = (long long int)((a - z) * 100 + 0.5);
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

	//十亿输出
	daxie(sy, 0);
	cout << (sy != 0 ? "拾" : "");

	//亿输出
	daxie(y, 0);
	cout << (sy + y != 0 ? "亿" : "");

	//千万输出
	daxie(qw, ((sy + y) != 0 && bw != 0));
	cout << (qw != 0 ? "仟" : "");

	//百万位输出
	daxie(bw, ((sy + y + qw) != 0 && sw != 0));
	cout << (bw != 0 ? "佰" : "");

	//十万位输出
	daxie(sw, ((sy + y + qw + bw) != 0 && w != 0));
	cout << (sw != 0 ? "拾" : "");

	//万位输出
	daxie(w, 0);
	cout << ((qw + bw + sw + w) != 0 ? "万" : "");

	//千位输出
	daxie(q, (sy + y + qw + bw + w) != 0 && b != 0);
	cout << (q != 0 ? "仟" : "");

	//百位输出
	daxie(b, (sy + y + qw + bw + w + q) != 0 && s != 0);
	cout << (b != 0 ? "佰" : "");

	//十位输出
	daxie(s, (sy + y + qw + bw + sw + w + q + b) != 0 && yuan != 0);
	cout << (s != 0 ? "拾" : "");

	//个位输出
	daxie(yuan, 0);
	cout << ((sy + y + qw + bw + sw + w + q + b + s + yuan) != 0 ? "圆" : "");

	//角输出
	daxie(jiao, (sy + y + qw + bw + w + q + b + s + yuan) != 0 && fen != 0);
	cout << (jiao != 0 ? "角" : "");

	//分输出
	daxie(fen, 0);
	cout << (fen != 0 ? "分" : "");


	//整的输出
	cout << ((sy + y + qw + bw + w + q + b + yuan + jiao + fen) == 0 ? "零圆" : "");
	cout << (fen == 0 ? "整" : "");

	cout << endl;
	/* 按需完成 */
	return 0;
}