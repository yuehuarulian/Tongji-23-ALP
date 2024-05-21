/* 信04 2252941 杨瑞灵 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define people 10
#define pass_grade 60
int f_in(char name[][9], char num[][8],int grade[])
{
	int jg, bjg = 0;
	for (jg = 0; jg < people - bjg; jg++)
	{
		printf("请输入第%d个人的学号、姓名、成绩\n", jg + 1+bjg);
		scanf("%s",num[jg]);
		scanf("%s",name[jg]);
		scanf("%d",&grade[jg]);
		if (grade[jg] < pass_grade)
		{
			jg--;
			bjg++;
		}
	}
	return jg;
}
void sort(char name[][9], char num[][8], int grade[], int jg)
{
	char f_num[128] = { 0 };
	char f_name[128] = { 0 };
	int t;
	int i, j, max;
	for (i = 0; i < jg; i++)
	{
		strcpy(f_num, num[i]);
		max = i;
		for (j = i + 1; j < jg; j++)
		{
			if (strcmp(f_num, num[j]) == -1)
			{
		
				strcpy(f_num, num[j]);
				max = j;
			}
		}
		strcpy(num[max], num[i]);
		strcpy(num[i], f_num);
		strcpy(f_name, name[max]);
		strcpy(name[max], name[i]);
		strcpy(name[i], f_name);
		t = grade[max];
		grade[max] = grade[i];
		grade[i] = t;
	}
	return;
}
void f_out(char name[][9], char num[][8], int grade[], int jg)
{
	printf("\n及格名单(学号降序):\n");
	for (int i = 0; i < jg; i++)
		printf("%s %s %d\n", name[i], num[i], grade[i]);

	return;
}
int main()
{
	char name[people][9] = { 0 };
	char num[people][8] = { 0 };
	int grade[people] = { 0 };
	int jg;
	jg = f_in(name, num,grade);
	sort(name, num, grade,jg);
	f_out(name, num,grade, jg);
	return 0;
}
