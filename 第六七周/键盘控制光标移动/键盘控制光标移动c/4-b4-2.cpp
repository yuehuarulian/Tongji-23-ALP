/* 2252941 杨瑞灵 信04 */
#include <iostream>
#include <cstdio>
#include <conio.h>
#include <time.h>
#include <windows.h>
using namespace std;

const int MAX_X = 69;	//定义*组成的边框的宽度
const int MAX_Y = 17;	//定义*组成的边框的高度


/***************************************************************************
  函数名称：
  功    能：完成与system("cls")一样的功能，但效率高
  输入参数：
  返 回 值：
  说    明：清除整个屏幕缓冲区，不仅仅是可见窗口区域(使用当前颜色)
***************************************************************************/
void cls(const HANDLE hout)
{
	COORD coord = { 0, 0 };
	CONSOLE_SCREEN_BUFFER_INFO binfo; /* to get buffer info */
	DWORD num;

	/* 取当前缓冲区信息 */
	GetConsoleScreenBufferInfo(hout, &binfo);
	/* 填充字符 */
	FillConsoleOutputCharacter(hout, (TCHAR)' ', binfo.dwSize.X * binfo.dwSize.Y, coord, &num);
	/* 填充属性 */
	FillConsoleOutputAttribute(hout, binfo.wAttributes, binfo.dwSize.X * binfo.dwSize.Y, coord, &num);

	/* 光标回到(0,0) */
	SetConsoleCursorPosition(hout, coord);
	return;
}

/***************************************************************************
  函数名称：gotoxy
  功    能：将光标移动到指定位置
  输入参数：HANDLE hout ：输出设备句柄
			int X       ：指定位置的x坐标
			int Y       ：指定位置的y坐标
  返 回 值：无
  说    明：此函数不准修改
***************************************************************************/
void gotoxy(const HANDLE hout, const int X, const int Y)
{
	COORD coord;
	coord.X = X;
	coord.Y = Y;
	SetConsoleCursorPosition(hout, coord);
}

/***************************************************************************
  函数名称：showch
  功    能：在指定位置处打印一个指定的字符
  输入参数：HANDLE hout ：输出设备句柄
			int X       ：指定位置的x坐标
			int Y       ：指定位置的y坐标
			char ch     ：要打印的字符
  返 回 值：无
  说    明：此函数不准修改
***************************************************************************/
void showch(const HANDLE hout, const int X, const int Y, const char ch)
{
	gotoxy(hout, X, Y);
	putchar(ch);
}

/***************************************************************************
  函数名称：init_border
  功    能：显示初始的边框及随机字符
  输入参数：HANDLE hout：输出设备句柄
  返 回 值：无
  说    明：此函数不准修改
***************************************************************************/
void init_border(const HANDLE hout)
{
	gotoxy(hout, 0, 0);	//光标移回左上角(0,0)
	cout << "***********************************************************************" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "***********************************************************************" << endl;

	/* 随机显示20个大写字母，字母的值、XY坐标都随机显示
	   rand()函数的功能：随机生成一个在 0-32767 之间的整数
	   思考：在什么情况下，下面这个循环执行生成后，你看到的实际字母个数不足20个？ */
	int i;
	for (i = 0; i < 20; i++)
		showch(hout, rand() % MAX_X + 1, rand() % MAX_Y + 1, 'A' + rand() % 26);

	return;
}

/* -- 按需增加的若干函数可以放在此处 --*/

/***************************************************************************
  函数名称：menu
  功    能：菜单显示及选择
  输入参数：无
  返 回 值：option
  说    明：自加函数
***************************************************************************/
int menu()
{
	int num;
	cout << "1.用I、J、K、L键控制上下左右(大小写均可，边界停止)\n"
		<< "2.用I、J、K、L键控制上下左右(大小写均可，边界回绕)\n"
		<< "3.用箭头键控制上下左右，边界停止\n"
		<< "4.用箭头键控制上下左右，边界回绕\n"
		<< "5.用箭头键控制上下左右(边界停止，演示大写HPKM可移动的错误，此项不需要实现)\n"
		<< "6.用箭头键控制上下左右(边界回绕，演示大写HPKM可移动的错误，此项不需要实现)\n"
		<< "0.退出"
		<< endl;
	cout << "[请选择0 - 6]";
	while (1)
	{
		num = _getch() - 48;
		if (num >= 0 && num <= 6)
			break;
	}
	return num;
}

/***************************************************************************
  函数名称：move_by_ijkl
  功    能：移动
  输入参数：键盘按键输入值
  返 回 值：无
  说    明：自加函数
***************************************************************************/
int move_by_ijkl(int option, int x, int y, int a)
{
	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE); //取标准输出设备对应的句柄
	int r = 0;
	switch (a)
	{
		case(73):
			y -= 1;
			r = 1;
			break;
		case(105):
			y -= 1;
			r = 2;
			break;
		case(74):
			x -= 1;
			r = 3;
			break;
		case(106):
			x -= 1;
			r = 4;
			break;
		case(75):
			y += 1;
			r = 5;
			break;
		case(107):
			y += 1;
			r = 6;
			break;
		case(76):
			x += 1;
			r = 7;
			break;
		case(108):
			x += 1;
			r = 8;
			break;
		case(32):
			showch(hout, x, y, ' ');
			r = 9;
	}

	if (option == 2 || option == 6)
	{
		if (x == 0)
		{
			x = 69;
			r = 10;
		}
		else if (x == 70)
		{
			x = 1;
			r = 11;
		}
		else if (y == 0)
		{
			y = 17;
			r = 12;
		}
		else if (y == 18)
		{
			y = 1;
			r = 13;
		}
	}
	else(option == 1 || option == 5);
	{
		if (x == 0)
		{
			x = 1;
			r = 14;
		}
		else if (x == 70)
		{
			x = 69;
			r = 15;
		}
		else if (y == 0)
		{
			y = 1;
			r = 16;
		}
		else if (y == 18)
		{
			y = 17;
			r = 17;

		}
	}

	gotoxy(hout, x, y);
	return r;
}

/***************************************************************************
  函数名称：move_by_errow
  功    能：移动
  输入参数：键盘按键输入值
  返 回 值：无
  说    明：自加函数
***************************************************************************/
int move_by_errow(int option,int x,int y,int a)
{
	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE); //取标准输出设备对应的句柄
	int r = 0;
	switch (a)
	{
		case(72):
			y -= 1;
			r = 1;
			break;
		case(75):
			x -= 1;
			r = 3;
			break;
		case(80):
			y += 1;
			r = 5;
			break;
		case(77):
			x += 1;
			r = 7;
			break;
		case(32):
			showch(hout, x, y, ' ');
			r = 9;
	}

	if (option == 4)
	{
		if (x == 0)
		{
			x = 69;
			r = 10;
		}
		else if (x == 70)
		{
			x = 1;
			r = 11;
		}
		else if (y == 0)
		{
			y = 17;
			r = 12;
		}
		else if (y == 18)
		{
			y = 1;
			r = 13;
		}
	}
	else(option == 3);
	{
		if (x == 0)
		{
			x = 1;
			r = 14;
		}
		else if (x == 70)
		{
			x = 69;
			r = 15;
		}
		else if (y == 0)
		{
			y = 1;
			r = 16;
		}
		else if (y == 18)
		{
			y = 17;
			r = 17;

		}
	}

	gotoxy(hout, x, y);
	return r;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：main函数仅用于初始演示，可以按题目要求全部推翻重写
***************************************************************************/

int main()
{
	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE); //取标准输出设备对应的句柄

	/* 生成伪随机数的种子，只需在程序开始时执行一次即可 */
	srand((unsigned int)(time(0)));


	int option;  //菜单的选择
	int  x = 35, y = 9;  //光标坐标位置
	int a;  //每次读入的键盘按键
	int r;

	while (1)
	{
		/* 此句的作用是调用系统的cls命令清屏 */
		cls(hout);

		/*调用menu函数*/
		option = menu();

		/* 此句的作用是调用系统的cls命令清屏 */
		cls(hout);

		//判断option是否为0退出
		if (!option)
			break;

		/* 显示初始的边框及其中的随机字符 */
		init_border(hout);
		gotoxy(hout, x, y);

		//option=1 2的移动
		while (option == 1 || option == 2)
		{
			a = _getch();
			if (a == 81 || a == 113)
				break;
			else
				r=move_by_ijkl(option,x,y,a);
			switch (r)
			{
				case(1):
					y -= 1;
					break;
				case(2):
					y -= 1;
					break;
				case(3):
					x -= 1;
					break;
				case(4):
					x -= 1;
					break;
				case(5):
					y += 1;
					break;
				case(6):
					y += 1;
					break;
				case(7):
					x += 1;
					break;
				case(8):
					x += 1;
					break;
				case(9):
					break;
				case(10):
					x = 69;
					break;
				case(11):
					x = 1;
					break;
				case(12):
					y = 17;
					break;
				case(13):
					y = 1;
					break;
				case(14):
					x = 1;
					break;
				case(15):
					x = 69;
					break;
				case(16):
					y = 1;
					break;
				case(17):
					y = 17;
					break;
			}
		}

		//option=3 4 的移动
		while (option == 3 || option == 4)
		{
			a = _getch();
			if (a == 81 || a == 113)
				break;
			else
				r = move_by_errow(option, x, y, a);
			switch (r)
			{
				case(1):
					y -= 1;
					break;
				case(3):
					x -= 1;
					break;
				case(5):
					y += 1;
					break;
				case(7):
					x += 1;
					break;
				case(9):
					break;
				case(10):
					x = 69;
					break;
				case(11):
					x = 1;
					break;
				case(12):
					y = 17;
					break;
				case(13):
					y = 1;
					break;
				case(14):
					x = 1;
					break;
				case(15):
					x = 69;
					break;
				case(16):
					y = 1;
					break;
				case(17):
					y = 17;
					break;
			}
		}

		//option=5 6 的移动
		while (option == 5 || option == 6)
		{
			char m = _getch();  // 读取键盘输入的字符
			if (m == '\xE0')  // 如果是特殊字符(如箭头键)
			{
				m = _getch();
				a = 0;
			}
			else
				a = m;
			if (a == 81 || a == 113)
				break;
			else
				r = move_by_ijkl(option, x, y, a);
			switch (r)
			{
				case(1):
					y -= 1;
					break;
				case(2):
					y -= 1;
					break;
				case(3):
					x -= 1;
					break;
				case(4):
					x -= 1;
					break;
				case(5):
					y += 1;
					break;
				case(6):
					y += 1;
					break;
				case(7):
					x += 1;
					break;
				case(8):
					x += 1;
					break;
				case(9):
					break;
				case(10):
					x = 69;
					break;
				case(11):
					x = 1;
					break;
				case(12):
					y = 17;
					break;
				case(13):
					y = 1;
					break;
				case(14):
					x = 1;
					break;
				case(15):
					x = 69;
					break;
				case(16):
					y = 1;
					break;
				case(17):
					y = 17;
					break;
			}
		}

		//结束
		gotoxy(hout, 0, 23);
		cout << "游戏结束，按回车键退出." << endl;
		x = 35;
		y = 9;

		while (1)
		{
			if (_getch() == 13)
				break;
		}

	}

	return 0;
}