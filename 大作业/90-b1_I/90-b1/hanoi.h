/* ��04 2252941 ������ */
#pragma once
int menu();//�˵�
void f_in(char* src, char* tmp, char* dst, int* n,int option);//�������Ӻ�n
void f_out(int n, char src, char tmp, char dst, int option, int han[][10], int top[]);
//��ŵ��
void hanoi(int n, char src, char tmp, char dst, int option, int han[][10], int top[]);
void tcsz(char src, int n, int ABC[][10], int top[]);
void changesz(char src, char dst, int han[][10], int top[]);
//����
void out_h(int yd,char src,char dst,int option,int han[][10], int top[],int h);
//����
void prime(char src, char dst, int n, int han[][10], int top[],int h);
void out_z(int yd, char src, char dst, int option,  int han[][10], int top[],int h);
//����������
void draw_z(int option);
void draw_p(int num, int han[][10], int top[]);
void draw_p_each(int num, int x, int y);
void erase_p_each(int num, int x, int y);
//�ƶ�
void move_z(int num, int x1, int y1, int x2, int y2);
//��Ϸģʽ
int f_in_I(char* src_I, char* dst_I, int han[][10], int top[]);


/* ------------------------------------------------------------------------------------------------------

     ���ļ����ܣ�
	1��Ϊ�˱�֤ hanoi_main.cpp/hanoi_menu.cpp/hanoi_multiple_solutions.cpp ���໥���ʺ����ĺ�������
	2��һ�����ϵ�cpp���õ��ĺ궨�壨#define����ȫ��ֻ����const����������������
	3�����Բο� cmd_console_tools.h ��д���������Ķ�����ᣩ
   ------------------------------------------------------------------------------------------------------ */