/* 信04 2252941 杨瑞灵 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define people 10
#define pass_grade 60
int f_in(char name[][9], char num[][8], int grade[])
{
	int i;
	for (i = 0; i < people ; i++)
	{
		printf("请输入第%d个人的学号、姓名、成绩\n", i+1);
		scanf("%s", num[i]);
		scanf("%s", name[i]);
		scanf("%d", &grade[i]);
	}
	return 0;
}
void sort(char name[][9], char num[][8], int grade[])
{
	char f_num[8] = { 0 };
	char f_name[9] = { 0 };
	int f_grade;
	int i, j, max;
	for (i = 0; i < people; i++)
	{
		f_grade = grade[i];
		max = i;
		for (j = i + 1; j < people; j++)
		{
			if (f_grade < grade[j])
			{
				f_grade = grade[j];
				max = j;
			}
		}
		grade[max] = grade[i];
		grade[i] = f_grade;
		strcpy(f_num, num[max]);
		strcpy(num[max], num[i]);
		strcpy(num[i], f_num);
		strcpy(f_name, name[max]);
		strcpy(name[max], name[i]);
		strcpy(name[i], f_name);
	}
	return;
}
void f_out(char name[][9], char num[][8], int grade[])
{
	printf("\n全部学生(成绩降序):\n");
	for (int i = 0; i < people; i++)
		printf("%s %s %d\n", name[i], num[i], grade[i]);

	return;
}
int main()
{
	char name[people][9] = { 0 };
	char num[people][8] = { 0 };
	int grade[people] = { 0 };
	f_in(name, num, grade);
	sort(name, num, grade);
	f_out(name, num, grade);
	return 0;
}
