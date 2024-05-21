/* 2252941 ������ ��04 */
#define _CRT_SECURE_NO_WARNINGS		//ʹ����VS��Ϊunsafe�ĺ���
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <conio.h>
using namespace std;
const int n = 256;
void prize(const struct KFC list[], const struct SPECIAL special[], char order[]);
void f_out2(const char order[], const struct KFC list[]);
struct KFC {
	char code;
	char name[n];
	double prize;
};
struct SPECIAL {
	char name1[n];
	char name2[n];
	double prize;
};
void menu(const struct KFC list[], const struct SPECIAL special[])
{
	cout << setfill('=') << setw(73) << '=' << endl;
	cout << setfill(' ') << setw(45) << resetiosflags(ios::left) << "KFC 2023�����˵�" << endl;
	cout << setfill('=') << setw(73) << '=' << endl;
	for (const struct KFC* p = list; p->code != '\0'; p++) {
		cout << ' ' << p->code << ' ';
		cout << setw(26) << setfill(' ') << setiosflags(ios::left) << p->name;
		cout << setw(7) << p->prize;
		if ((p - list) % 2)
			cout << endl;
		else
			cout << '|';
	}
	cout << "\n���Ż���Ϣ����" << endl;
	for (const struct SPECIAL* p = special; p->prize != 0; p++) {  //p->name1!=NULL???
		cout << p->name2 << '=';
		f_out2(p->name1, list);
		cout << '=' << p->prize << endl;
	}
}
void order(const struct KFC list[], const struct SPECIAL special[])
{
	cout << "\n���������˵������" << endl;
	cout << "ANV = �������ȱ� + ����(С) + ���¿���(С) / akaak = �������ȱ� * 3 + �������� * 2" << endl;
	cout << "��ĸ���ִ�Сд������˳�򣬵�������0���˳�����" << endl;
	cout << "\n��㵥:";
	char order[n] = { 0 };
	cin >> order;
	bool b = 1;
	if (cin.fail()) {
		cin.clear();
		cin.ignore(10000, '\n');
		b = 0;
	}
	for (int i = 0; order[i] != 0; i++) {
		if (order[i] >= 'a' && order[i] <= 'z')
			order[i] += 'A' - 'a';
		else if (order[i] >= 'A' && order[i] <= 'Z')
			;
		else {
			b = 0;
			break;
		}
	}
	if (!b) {
		cout << "������󣬰����������." << endl;
		getchar();
		return;
	}

	move(order);
	cout << "���ĵ��=";
	f_out2(order, list);
	cout << "\n����";
	prize(list, special, order);
}
void prize(const struct KFC list[], const struct SPECIAL special[], char order[])
{
	int spc[n][26] = { 0 };
	for (int spc_num = 0; special[spc_num].prize != 0; spc_num++) {
		for (int zh_code = 0; special[spc_num].name1[zh_code] != 0; zh_code++) {
			spc[spc_num][special[spc_num].name1[zh_code] - 'A']++;
		}
	}
	int ord[26 + n] = { 0 };
	for (int zh_code = 0; order[zh_code] != 0; zh_code++) {
		ord[order[zh_code] - 'A']++;
	}
	double prize = 0;
	int i, j;

	for (i = 0; special[i].prize != 0; i++) {
		while (1) {
			for (j = 0; j < 26 && ord[j] >= spc[i][j]; j++)
				;
			if (j == 26) {
				for (j = 0; j < 26; j++)
					ord[j] -= spc[i][j];
				ord[26 + i] += 1;
			}
			else
				break;
		}
	}

	for (i = 0; i < 26; i++)  //����۸�
		prize += list[i].prize * ord[i];
	for (i = 0; special[i].prize != 0; i++)
		prize += special[i].prize * ord[26 + i];

	cout << prize << endl;
}
void f_out2(const char order[], const struct KFC list[])
{
	int ord[26 + n] = { 0 };
	for (int zh_code = 0; order[zh_code] != 0; zh_code++) {
		ord[order[zh_code] - 'A']++;
	}
	bool b = 0;
	for (int i = 0; i < 26; i++) {
		if (ord[i] == 0)
			continue;
		if (b)
			cout << '+';
		if (ord[i] == 1)
			cout << list[i].name;
		else if (ord[i] >= 2)
			cout << list[i].name << '*' << ord[i];
		b = 1;
	}
}
/* ˵�������Ը������������������Ӧ�Ľṹ�壬Ҳ���Բ�������������ݣ����а��趨�壨�������ݳ�Ա����3���ȣ� */
int main()
{
	const struct KFC list[] = {
		{'A', "�������ȱ�",			19.5},
		{'B', "���༦�ȱ�",			19.5},
		{'C', "�°¶��������ȱ�",		20.0},
		{'D', "�ϱ��������",			18.5},
		{'E', "�ƽ�SPA���ű�(�ٽ���ζ)",	18.0},
		{'F', "������ʽ��ζ��ţ��(����)",	18.0},
		{'G', "˱ָԭζ��(1��)",		12.5},
		{'H', "�ƽ��Ƥ��",			13.5},
		{'I', "�°¶�������(2��)",		13.5},
		{'J', "�������׻�",			12.0},
		{'K', "��������(2��)",			12.5},
		{'L', "������Ǽ�(3��)",		12.5},
		{'M', "֭֭������������ţ��",	55.0},
		{'N', "����(С)",				9.0},
		{'O', "����(��)",				12.5},
		{'P', "����(��)",				14.5},
		{'Q', "ܽ��������",			9.0},
		{'R', "ԭζ��Ͳ������",			6.0},
		{'S', "����������",			7.5},
		{'T', "�ƽ𼦿�",				12.5},
		{'U', "��ʽ��̢",				8.0},
		{'V', "���¿���(С)",			8.5},
		{'W', "���¿���(��)",			10.0},
		{'X', "���¿���(��)",			12.0},
		{'Y', "�����֭",				13.0},
		{'Z', "ѩ������",				14.5},
		{'\0', NULL,				0}
	};
	const struct SPECIAL special[] = {
		//{"AOW", "OK������(�������ȱ�)",		31}, //�������Ҫ���ſ����ע�͵���һ�еġ�COW���Żݣ��۲��Żݲ˵��Ƿ����˱仯
			{"COW", "OK������(�°¶��������ȱ�)",	33.5}, //�������Ҫ���ſ����ע�͵���һ�еġ�AOW���Żݣ��۲��Żݲ˵��Ƿ����˱仯
			{"HHHHHKKKSUWWW", "����ȫ��Ͱ(��Ƥ��)",	101},
			{"APUY", "�����������ļ���(8��)",		44},
			{"GG","˱ָԭζ��(2��)",			21},
			{NULL, NULL, 0}
	};
	while (1) {
		system("cls");
		menu(list, special);
		order(list, special);
		cout << "�㵥��ɣ������������." << endl;
		_getche();
		
	}

	return 0;
}
