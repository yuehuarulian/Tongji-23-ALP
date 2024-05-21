/* 信04 2252941 杨瑞灵 */
#pragma once
#define X_prime  0
#define Y_prime  1
#define X_0  4
#define Y_A  3
#define HANG  10
#define LIE  10
#define keycode_Q 81
#define keycode_q 113
#define keycode_r 13
#define keycode_arrow 224
/* main */
char menu();
/* tools 输入输出 小题ABC */
void f_in(int star[][LIE], int* row, int* col, char* row_I, char* col_I, int choose);//输入参数
bool f_out(char option, int star[][LIE], int star_result[][LIE], int row, int col, char& row_I, char& col_I, int& score_each, int& score);//输出调用函数的函数
void f_out_ABC(int star[][LIE], int star_result[][LIE], int row, int col,int choose);
/* base 数组实现和改变 */
void tcsz(int star[][LIE], int row, int col);//填充数组
void initialsz(int star[][LIE]);//初始化数组
int change_star(int star[][LIE], int star_result[][LIE], int row, int col,int choose,int option);//改变星星，数组归零和下落
void change_star_result(int star[][LIE], int star_result[][LIE], char row_I, char col_I,char row,char col);//改变star_result,设置'*'
bool surrounding(int star[][LIE], int star_result[][LIE], char row_I, char col_I, bool color);//判断周围相同星星
bool judge_star(int star[][LIE], int row, int col, int& remain_star);//判断结束条件和剩余星星数量
/* console 画图 */
void erase_star(int star_result[][LIE], int row, int col, char option);
void erase(int x, int y, int len, int high, int color);
void prime(int star[][LIE], int row, int col,char option);//初始界面
bool show_XY(int star[][LIE], int star_result[][LIE], int row, int col, char option, int& score_each, int& score);//鼠标键盘移动和选中
void highlight_star(int row_I, int col_I, int star[][LIE], int star_result[][LIE], int row,int col,int option);//鼠标移动到图标上强调颜色
void move_star(int star[][LIE], int j, int i, int choose,int option);//移动星星
void keycode_224(int keycode2, char& row_I, char& col_I, int row, int col, int star[][LIE]);//键盘移动判断结束位置
