/* ��04 2252941 ������ */
#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;
#define people 10
#define pass_grade 60
int f_in(string name[], string num[], int grade[])
{
	int i;
	for (i = 0; i < people ; i++)
	{
		cout << "�������" << i+1 << "���˵�ѧ�š��������ɼ�" << endl;
		cin >> num[i];
		cin >> name[i];
		cin >> grade[i];
	}
	return 0;
}
void sort(string name[], string num[], int grade[])
{
	string f_num;
	string f_name;
	int f_grade;
	int i, j, min;
	for (i = 0; i < people; i++)
	{
		f_num = num[i];
		min = i;
		for (j = i + 1; j < people; j++)
		{
			if (f_num > num[j])
			{
				f_num = num[j];
				min = j;
			}
		}
		num[min] = num[i];
		num[i] = f_num;
		f_name = name[min];
		name[min] = name[i];
		name[i] = f_name;
		f_grade = grade[min];
		grade[min] = grade[i];
		grade[i] = f_grade;
	}
	return;
}
void f_out(string name[], string num[], int grade[])
{
	cout << endl;
	cout << "ȫ��ѧ��(ѧ������):" << endl;
	for (int i = 0; i < people; i++)
		cout << name[i] << " " << num[i] << ' ' << grade[i] << endl;
	return;
}
int main()
{
	string name[people];
	string num[people];
	int grade[people] = { 0 };
	f_in(name, num, grade);
	sort(name, num, grade);
	f_out(name, num, grade);
	return 0;
}
