/* 2252941 信04 杨瑞灵 */
#include <iostream>
#include <iomanip>
#include <cstdio>
using namespace std;

/* -----------------------------------------------------------------------------------
		允许   ：1、按需增加一个或多个函数（包括递归函数），但是所有增加的函数中不允许任何形式的循环
				 2、定义符号常量
				 3、定义const型变量

		不允许 ：1、定义全局变量
				 2、除print_tower之外的其他函数中不允许定义静态局部变量
   ----------------------------------------------------------------------------------- */

void letter(int n, int time,int zf);
char width(int w,char ch);

   /***************************************************************************
	 函数名称：
	 功    能：打印字母塔
	 输入参数：order:正序倒序
	           row:总共排数
			   zuhe:是否组合
	 返 回 值：
	 说    明：形参按需设置
			   提示：有一个参数order，指定正序/倒序
			   n:表示输出的是第几排
   ***************************************************************************/
void print_tower(int order, int row, int zuhe)
{
	static int n = 1;
	if (order == 1)//正序
	{
		width(row + 1 - n, ' ');
		letter(n, 0, 1);
		cout << endl;
		if (n == row)
		{
			n = 1;
			return;
		}
		else
		{
			n++;
			print_tower(order, row, zuhe);
			return;
		}
	}
	if (order == 0)//倒序
	{
		width(n + zuhe, ' ');
		letter(row - zuhe + 1 - n, 0, 1);
		if (!(zuhe == 1 && row == 1))//处理输入为A的情况，防止末行多一个空行
			cout << endl;

		if (n >= row - zuhe)
		{
			n = 1;
			return;
		}
		else
		{
			n++;
			print_tower(order, row, zuhe);
			return;
		}
	}
	/* 允许按需定义最多一个静态局部变量（也可以不定义） */
	/* 按需实现，函数中不允许任何形式的循环，函数允许调用其它函数 */
}

/***************************************************************************
	函数名称：letter
	功    能：输出字母ABC...
	输入参数：n:第几排
	          time:用来输出字母
			  zf：表示是ABC...还是CBA...
	返 回 值：无
	说    明：无
  ***************************************************************************/
void letter(int n,int time,int zf)
{
	if (zf == 1)
	{
		if (n == 0)
		{
			letter(time - 1, 0, 0);
			return;
		}
		else
		{
			cout << static_cast<char>(65 + time);
			letter(n - 1, time + 1, 1);
			return;
		}
	}
	else if (zf == 0)
	{
		if (n <= 0)
		{
			return;
		}
		else
		{
			cout << static_cast<char>(64 + n);
			letter(n - 1, time + 1, 0);
			return;
		}
	}
	return;
}
/***************************************************************************
	函数名称：
	功    能：输出宽度=======
	输入参数：
	返 回 值：
	说    明：
  ***************************************************************************/
char width(int w, char ch)
{
	if (w <= 1)
		return ch;
	else
	{
		cout << ch;
		return width(w - 1, ch);
	}
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：main函数中的...允许修改，其余位置不准修改
***************************************************************************/
int main()
{
	char end_ch;

	/* 键盘输入结束字符(仅大写有效，为避免循环出现，不处理输入错误) */
	cout << "请输入结束字符(A~Z)" << endl;
	end_ch = getchar();			//读缓冲区第一个字符
	if (end_ch < 'A' || end_ch > 'Z') {
		cout << "结束字符不是大写字母" << endl;
		return -1;
	}

	/* 正三角字母塔(两边为A) */
	cout << width((static_cast<int>(end_ch) - 64) * 2 - 1, '=') << endl; /* 按字母塔最大宽度输出=(不允许用循环) */
	cout << "正三角字母塔(A->" << end_ch << ")" << endl;
	cout << width((static_cast<int>(end_ch) - 64) * 2 - 1, '=') << endl; /* 按字母塔最大宽度输出=(不允许用循环) */
	print_tower(1, static_cast<int>(end_ch) - 64,0); //正序打印 A~结束字符 
	cout << endl;

	/* 倒三角字母塔(两边为A) */
	cout << width((static_cast<int>(end_ch) - 64) * 2 - 1, '=') << endl; /* 按字母塔最大宽度输出=(不允许用循环) */
	cout << "倒三角字母塔(A->" << end_ch << ")" << endl;
	cout << width((static_cast<int>(end_ch) - 64) * 2 - 1, '=') << endl; /* 按字母塔最大宽度输出=(不允许用循环) */
	print_tower(0, static_cast<int>(end_ch) - 64,0); //逆序打印 A~结束字符 
	cout << endl;

	/* 合起来就是漂亮的菱形（外侧为A） */
	cout << width((static_cast<int>(end_ch) - 64) * 2 - 1, '=') << endl;/* 按字母塔最大宽度输出= */
	cout << "菱形(A->" << end_ch << ")" << endl;
	cout << width((static_cast<int>(end_ch) - 64) * 2 - 1, '=') << endl;/* 按字母塔最大宽度输出= */
	print_tower(1, static_cast<int>(end_ch) - 64,1);   //打印 A~结束字符的正三角 
	print_tower(0, static_cast<int>(end_ch) - 64,1);   //打印 A~结束字符-1的倒三角 
	cout << endl;

	return 0;
}