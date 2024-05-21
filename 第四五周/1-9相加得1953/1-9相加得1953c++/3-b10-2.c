/* 班级 学号 姓名*/
#include <stdio.h>
#include <windows.h> //取系统时间

int main()
{
	LARGE_INTEGER tick, begin, end;

	QueryPerformanceFrequency(&tick);	//获得计数器频率
	QueryPerformanceCounter(&begin);	//获得初始硬件计数器计数

	/* 此处是你的程序开始 */
	int a1, a2, a3, a4, a5, a6, a7, a8, a9;//循环
	int num1, num2, num3;
	int x = 0;//计数
	for (a1 = 1; a1 <= 6; a1++)//1
	{
		num1 = 100 * a1;

		for (a2 = 1; a2 <= 9; a2++)//2
		{
			if (a2 != a1)
				num1 = 100 * a1 + 10 * a2;
			else
			{

				continue;
			}

			for (a3 = 1; a3 <= 9; a3++)//3
			{
				if (a3 != a1 && a3 != a2)
					num1 = 100 * a1 + 10 * a2 + a3;
				else
				{

					continue;
				}

				for (a4 = 5; a4 <= 8; a4++)//4
				{
					if (a4 != a1 && a4 != a2 && a4 != a3)
						num2 = 100 * a4;
					else
						continue;

					for (a5 = 1; a5 <= 9; a5++)//5
					{
						if (a5 != a1 && a5 != a2 && a5 != a3 && a5 != a4)
							num2 = 100 * a4 + 10 * a5;
						else
							continue;

						for (a6 = 1; a6 <= 9; a6++)//6
						{
							if (a6 != a1 && a6 != a2 && a6 != a3 && a6 != a4 && a6 != a5)
								num2 = 100 * a4 + 10 * a5 + a6;
							else
								continue;

							for (a7 = 7; a7 <= 9; a7++)//7
							{
								if (a7 != a1 && a7 != a2 && a7 != a3 && a7 != a4 && a7 != a5 && a7 != a6)
									num3 = 100 * a7;
								else
									continue;

								for (a8 = 1; a8 <= 9; a8++)//8
								{
									if (a8 != a1 && a8 != a2 && a8 != a3 && a8 != a4 && a8 != a5 && a8 != a6 && a8 != a7)
										num3 = 100 * a7 + 10 * a8;
									else
										continue;

									for (a9 = 1; a9 <= 9; a9++)//9
									{
										num3 += a9;
										if (a9 != a1 && a9 != a2 && a9 != a3 && a9 != a4 && a9 != a5 && a9 != a6 && a9 != a7 && a9 != a8)
											num3 = 100 * a7 + 10 * a8 + a9;
										else
											continue;

										if (num1 + num2 + num3 == 1953 && num1 < num2 && num2 < num3)
										{
											x += 1;
											printf("No.%3d : %d+%d+%d=1953\n", x, num1, num2, num3);
										}

									}

								}
							}

						}

					}
				}
			}
		}
	}

	printf("total=%d\n", x);


	/* 此处是你的程序结束 */

	QueryPerformanceCounter(&end);		//获得终止硬件计数器计数

	printf("计数器频率 : %lldHz\n", tick.QuadPart);
	printf("计数器计数 : %lld\n", end.QuadPart - begin.QuadPart);
	printf("%.6f秒\n", (double)(end.QuadPart - begin.QuadPart) / tick.QuadPart);

	return 0;
}