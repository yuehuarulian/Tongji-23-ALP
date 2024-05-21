/* 2252941 杨瑞灵 信04 */
#define _CRT_SECURE_NO_WARNINGS		//使用了VS认为unsafe的函数
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
	cout << setfill(' ') << setw(45) << resetiosflags(ios::left) << "KFC 2023春季菜单" << endl;
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
	cout << "\n【优惠信息】：" << endl;
	for (const struct SPECIAL* p = special; p->prize != 0; p++) {  //p->name1!=NULL???
		cout << p->name2 << '=';
		f_out2(p->name1, list);
		cout << '=' << p->prize << endl;
	}
}
void order(const struct KFC list[], const struct SPECIAL special[])
{
	cout << "\n【输入规则说明】：" << endl;
	cout << "ANV = 香辣鸡腿堡 + 薯条(小) + 百事可乐(小) / akaak = 香辣鸡腿堡 * 3 + 香辣鸡翅 * 2" << endl;
	cout << "字母不分大小写，不限顺序，单独输入0则退出程序" << endl;
	cout << "\n请点单:";
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
		cout << "输入错误，按任意键继续." << endl;
		getchar();
		return;
	}

	move(order);
	cout << "您的点餐=";
	f_out2(order, list);
	cout << "\n共计";
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

	for (i = 0; i < 26; i++)  //计算价格
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
/* 说明：可以根据下面的数据声明对应的结构体，也可以不按照下面的数据，自行按需定义（例如数据成员多余3个等） */
int main()
{
	const struct KFC list[] = {
		{'A', "香辣鸡腿堡",			19.5},
		{'B', "劲脆鸡腿堡",			19.5},
		{'C', "新奥尔良烤鸡腿堡",		20.0},
		{'D', "老北京鸡肉卷",			18.5},
		{'E', "黄金SPA鸡排堡(藤椒风味)",	18.0},
		{'F', "经典美式风味嫩牛堡(单层)",	18.0},
		{'G', "吮指原味鸡(1块)",		12.5},
		{'H', "黄金脆皮鸡",			13.5},
		{'I', "新奥尔良烤翅(2块)",		13.5},
		{'J', "劲爆鸡米花",			12.0},
		{'K', "香辣鸡翅(2块)",			12.5},
		{'L', "热辣香骨鸡(3块)",		12.5},
		{'M', "汁汁厚做培根三层和牛堡",	55.0},
		{'N', "薯条(小)",				9.0},
		{'O', "薯条(中)",				12.5},
		{'P', "薯条(大)",				14.5},
		{'Q', "芙蓉蔬荟汤",			9.0},
		{'R', "原味花筒冰激凌",			6.0},
		{'S', "醇香土豆泥",			7.5},
		{'T', "黄金鸡块",				12.5},
		{'U', "葡式蛋挞",				8.0},
		{'V', "百事可乐(小)",			8.5},
		{'W', "百事可乐(中)",			10.0},
		{'X', "百事可乐(大)",			12.0},
		{'Y', "九珍果汁",				13.0},
		{'Z', "雪顶咖啡",				14.5},
		{'\0', NULL,				0}
	};
	const struct SPECIAL special[] = {
		//{"AOW", "OK三件套(香辣鸡腿堡)",		31}, //如果有需要，放开此项，注释掉下一行的“COW”优惠，观察优惠菜单是否发生了变化
			{"COW", "OK三件套(新奥尔良烤鸡腿堡)",	33.5}, //如果有需要，放开此项，注释掉上一行的“AOW”优惠，观察优惠菜单是否发生了变化
			{"HHHHHKKKSUWWW", "超爆全家桶(脆皮鸡)",	101},
			{"APUY", "人气明星配四件套(8折)",		44},
			{"GG","吮指原味鸡(2块)",			21},
			{NULL, NULL, 0}
	};
	while (1) {
		system("cls");
		menu(list, special);
		order(list, special);
		cout << "点单完成，按任意键继续." << endl;
		_getche();
		
	}

	return 0;
}
