/* 信04 2252941 杨瑞灵 */
#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;
#define people 10
#define pass_grade 60
int f_in(string name[], string num[], int grade[])
{
	int jg = 0, bjg = 0;
	for (bjg = 0; bjg < people - jg; bjg++)
	{
		cout << "请输入第" << bjg + jg+1 << "个人的学号、姓名、成绩" << endl;
		cin >> num[bjg];
		cin >> name[bjg];
		cin >> grade[bjg];
		if (grade[bjg] >= pass_grade)
		{
			bjg--;
			jg++;
		}
	}
	return bjg;
}
void sort(string name[], string num[], int grade[], int bjg)
{
	string f_num;
	string f_name;
	int f_grade;
	int i, j, min;
	for (i = 0; i < bjg; i++)
	{
		f_grade = grade[i];
		min = i;
		for (j = i + 1; j < bjg; j++)
		{
			if (f_grade > grade[j])
			{
				f_grade = grade[j];
				min = j;
			}
		}
		grade[min] = grade[i];
		grade[i] = f_grade;
		f_name = name[min];
		name[min] = name[i];
		name[i] = f_name;
		f_num = num[min];
		num[min] = num[i];
		num[i] = f_num;
	}
	return;
}
void f_out(string name[], string num[], int grade[], int jg)
{
	cout << endl;
	cout << "不及格名单(成绩升序):" << endl;
	for (int i = 0; i < jg; i++)
		cout << name[i] << " " << num[i] << ' ' << grade[i] << endl;
	return;
}
int main()
{
	string name[people];
	string num[people];
	int grade[people] = { 0 };
	int bjg;
	bjg = f_in(name, num, grade);
	sort(name, num, grade, bjg);
	f_out(name, num, grade, bjg);
	return 0;
}
