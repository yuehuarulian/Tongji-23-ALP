/* 2252941 ������ ��04 */
#include <iostream>
#include <cstdio>
#include <conio.h>
#include <time.h>
#include <windows.h>
using namespace std;

const int MAX_X = 69;	//����*��ɵı߿�Ŀ��
const int MAX_Y = 17;	//����*��ɵı߿�ĸ߶�


/***************************************************************************
  �������ƣ�
  ��    �ܣ������system("cls")һ���Ĺ��ܣ���Ч�ʸ�
  ���������
  �� �� ֵ��
  ˵    �������������Ļ���������������ǿɼ���������(ʹ�õ�ǰ��ɫ)
***************************************************************************/
void cls(const HANDLE hout)
{
	COORD coord = { 0, 0 };
	CONSOLE_SCREEN_BUFFER_INFO binfo; /* to get buffer info */
	DWORD num;

	/* ȡ��ǰ��������Ϣ */
	GetConsoleScreenBufferInfo(hout, &binfo);
	/* ����ַ� */
	FillConsoleOutputCharacter(hout, (TCHAR)' ', binfo.dwSize.X * binfo.dwSize.Y, coord, &num);
	/* ������� */
	FillConsoleOutputAttribute(hout, binfo.wAttributes, binfo.dwSize.X * binfo.dwSize.Y, coord, &num);

	/* ���ص�(0,0) */
	SetConsoleCursorPosition(hout, coord);
	return;
}

/***************************************************************************
  �������ƣ�gotoxy
  ��    �ܣ�������ƶ���ָ��λ��
  ���������HANDLE hout ������豸���
			int X       ��ָ��λ�õ�x����
			int Y       ��ָ��λ�õ�y����
  �� �� ֵ����
  ˵    �����˺�����׼�޸�
***************************************************************************/
void gotoxy(const HANDLE hout, const int X, const int Y)
{
	COORD coord;
	coord.X = X;
	coord.Y = Y;
	SetConsoleCursorPosition(hout, coord);
}

/***************************************************************************
  �������ƣ�showch
  ��    �ܣ���ָ��λ�ô���ӡһ��ָ�����ַ�
  ���������HANDLE hout ������豸���
			int X       ��ָ��λ�õ�x����
			int Y       ��ָ��λ�õ�y����
			char ch     ��Ҫ��ӡ���ַ�
  �� �� ֵ����
  ˵    �����˺�����׼�޸�
***************************************************************************/
void showch(const HANDLE hout, const int X, const int Y, const char ch)
{
	gotoxy(hout, X, Y);
	putchar(ch);
}

/***************************************************************************
  �������ƣ�init_border
  ��    �ܣ���ʾ��ʼ�ı߿�����ַ�
  ���������HANDLE hout������豸���
  �� �� ֵ����
  ˵    �����˺�����׼�޸�
***************************************************************************/
void init_border(const HANDLE hout)
{
	gotoxy(hout, 0, 0);	//����ƻ����Ͻ�(0,0)
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

	/* �����ʾ20����д��ĸ����ĸ��ֵ��XY���궼�����ʾ
	   rand()�����Ĺ��ܣ��������һ���� 0-32767 ֮�������
	   ˼������ʲô����£��������ѭ��ִ�����ɺ��㿴����ʵ����ĸ��������20���� */
	int i;
	for (i = 0; i < 20; i++)
		showch(hout, rand() % MAX_X + 1, rand() % MAX_Y + 1, 'A' + rand() % 26);

	return;
}

/* -- �������ӵ����ɺ������Է��ڴ˴� --*/

/***************************************************************************
  �������ƣ�menu
  ��    �ܣ��˵���ʾ��ѡ��
  �����������
  �� �� ֵ��option
  ˵    �����ԼӺ���
***************************************************************************/
int menu()
{
	int num;
	cout << "1.��I��J��K��L��������������(��Сд���ɣ��߽�ֹͣ)\n"
		<< "2.��I��J��K��L��������������(��Сд���ɣ��߽����)\n"
		<< "3.�ü�ͷ�������������ң��߽�ֹͣ\n"
		<< "4.�ü�ͷ�������������ң��߽����\n"
		<< "5.�ü�ͷ��������������(�߽�ֹͣ����ʾ��дHPKM���ƶ��Ĵ��󣬴����Ҫʵ��)\n"
		<< "6.�ü�ͷ��������������(�߽���ƣ���ʾ��дHPKM���ƶ��Ĵ��󣬴����Ҫʵ��)\n"
		<< "0.�˳�"
		<< endl;
	cout << "[��ѡ��0 - 6]";
	while (1)
	{
		num = _getch() - 48;
		if (num >= 0 && num <= 6)
			break;
	}
	return num;
}

/***************************************************************************
  �������ƣ�move_by_ijkl
  ��    �ܣ��ƶ�
  ������������̰�������ֵ
  �� �� ֵ����
  ˵    �����ԼӺ���
***************************************************************************/
int move_by_ijkl(int option, int x, int y, int a)
{
	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE); //ȡ��׼����豸��Ӧ�ľ��
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
  �������ƣ�move_by_errow
  ��    �ܣ��ƶ�
  ������������̰�������ֵ
  �� �� ֵ����
  ˵    �����ԼӺ���
***************************************************************************/
int move_by_errow(int option,int x,int y,int a)
{
	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE); //ȡ��׼����豸��Ӧ�ľ��
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
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����main���������ڳ�ʼ��ʾ�����԰���ĿҪ��ȫ���Ʒ���д
***************************************************************************/

int main()
{
	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE); //ȡ��׼����豸��Ӧ�ľ��

	/* ����α����������ӣ�ֻ���ڳ���ʼʱִ��һ�μ��� */
	srand((unsigned int)(time(0)));


	int option;  //�˵���ѡ��
	int  x = 35, y = 9;  //�������λ��
	int a;  //ÿ�ζ���ļ��̰���
	int r;

	while (1)
	{
		/* �˾�������ǵ���ϵͳ��cls�������� */
		cls(hout);

		/*����menu����*/
		option = menu();

		/* �˾�������ǵ���ϵͳ��cls�������� */
		cls(hout);

		//�ж�option�Ƿ�Ϊ0�˳�
		if (!option)
			break;

		/* ��ʾ��ʼ�ı߿����е�����ַ� */
		init_border(hout);
		gotoxy(hout, x, y);

		//option=1 2���ƶ�
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

		//option=3 4 ���ƶ�
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

		//option=5 6 ���ƶ�
		while (option == 5 || option == 6)
		{
			char m = _getch();  // ��ȡ����������ַ�
			if (m == '\xE0')  // ����������ַ�(���ͷ��)
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

		//����
		gotoxy(hout, 0, 23);
		cout << "��Ϸ���������س����˳�." << endl;
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