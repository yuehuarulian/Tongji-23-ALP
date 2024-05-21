/* 信04 2252941 杨瑞灵 */
#pragma once
int menu();//菜单
void f_in(char* src, char* tmp, char* dst, int* n,int option);//输入柱子和n
void f_out(int n, char src, char tmp, char dst, int option, int han[][10], int top[]);
//汉诺塔
void hanoi(int n, char src, char tmp, char dst, int option, int han[][10], int top[]);
void tcsz(char src, int n, int ABC[][10], int top[]);
void changesz(char src, char dst, int han[][10], int top[]);
//横向
void out_h(int yd,char src,char dst,int option,int han[][10], int top[],int h);
//纵向
void prime(char src, char dst, int n, int han[][10], int top[],int h);
void out_z(int yd, char src, char dst, int option,  int han[][10], int top[],int h);
//画柱子盘子
void draw_z(int option);
void draw_p(int num, int han[][10], int top[]);
void draw_p_each(int num, int x, int y);
void erase_p_each(int num, int x, int y);
//移动
void move_z(int num, int x1, int y1, int x2, int y2);
//游戏模式
int f_in_I(char* src_I, char* dst_I, int han[][10], int top[]);


/* ------------------------------------------------------------------------------------------------------

     本文件功能：
	1、为了保证 hanoi_main.cpp/hanoi_menu.cpp/hanoi_multiple_solutions.cpp 能相互访问函数的函数声明
	2、一个以上的cpp中用到的宏定义（#define）或全局只读（const）变量，个数不限
	3、可以参考 cmd_console_tools.h 的写法（认真阅读并体会）
   ------------------------------------------------------------------------------------------------------ */