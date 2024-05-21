/*信18 2252540 金国栋*/
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <windows.h> //取系统时间
using namespace std;

int main()
{
	LARGE_INTEGER tick, begin, end;

	QueryPerformanceFrequency(&tick);	//获得计数器频率
	QueryPerformanceCounter(&begin);	//获得初始硬件计数器计数

	/* 此处是你的程序开始 */
	int num = 1;
	for (int i = 100; i < 1000; i++)
	{
		for (int j = i; j < 1000; j++)
		{
			for (int k = j; k < 1000; k++)
			{
				int a = i / 100;
				int b = i % 100 / 10;
				int c = i % 10;
				int d = j / 100;
				int e = j % 100 / 10;
				int f = j % 10;
				int g = k / 100;
				int h = k % 100 / 10;
				int i1 = k % 10;
				if (a != b && a != c && a != d && a != e && a != f && a != g && a != h && a != i1 &&
					b != c && b != d && b != e && b != f && b != g && b != h && b != i1 &&
					c != d && c != e && c != f && c != g && c != h && c != i1 &&
					d != e && d != f && d != g && d != h && d != i1 &&
					e != f && e != g && e != h && e != i1 &&
					f != g && f != h && f != i1 &&
					g != h && g != i1 &&
					h != i1
					&& i + j + k == 1953
					&& a * b * c * d * e * f * g * h * i1 != 0)
				{
					cout << "No." << setw(3) << num << " : " << i << "+" << j << "+" << k << "=" << 1953 << endl;
					num++;
				}
			}
		}
	}
	cout << "total=" << num - 1 << endl;
	/* 此处是你的程序结束 */

	QueryPerformanceCounter(&end);		//获得终止硬件计数器计数

	cout << "计数器频率 : " << tick.QuadPart << "Hz" << endl;
	cout << "计数器计数 : " << end.QuadPart - begin.QuadPart << endl;
	cout << setiosflags(ios::fixed) << setprecision(6) << double(end.QuadPart - begin.QuadPart) / tick.QuadPart << "秒" << endl;

	return 0;
}
