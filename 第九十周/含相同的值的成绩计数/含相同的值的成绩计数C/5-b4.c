/* 2252941 ������ ��04 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int a[1000] = { 0 };
	int dif[1000] = { 0 };
	int count[1000] = { 0 };
	int n = 0, m = 0;//��¼�������
	int i, j, k;//ѭ���Ʋ�
	int max;//ѡ������
	int exchange;//����˳���м��¼

	//����ɼ�
	printf("������ɼ������1000������������������\n");
	for (i = 0; i < 1000; i++)
	{
		scanf("%d", &a[i]);
		if (a[i] < 0)
		{
			a[i] = 0;
			i--;
			break;
		}
	}
	n = i + 1;
	if (n == 0)
	{
		printf("����Ч����\n");
		return 0;
	}

	//�������
	printf("���������Ϊ:\n");
	for (i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
		if (((i + 1) % 10) == 0)
			printf("\n");
		else
			continue;
	}
	if (i % 10 != 0)
		printf("\n");

	//���������ͳ��
	for (i = 0; i < n-1; i++)
	{
		max = i;
		for (j = i + 1; j < n; j++)
		{
			if (a[j] > a[max])
				max = j;
		}
		exchange = a[max];
		a[max] = a[i];
		a[i] = exchange;
	}

	for (i = 0, j = 0; j < n; i++, j++)//1 1   n=2
	{
		k = 1;
		while (1)
		{
			if (a[j] == a[j + 1] && (j + 1) < n)
			{
				j = j + 1;
				k++;
			}
			else
				break;
		}

		dif[i] = a[j];
		count[i] = k;
	}
	m = i;
	//����ɼ�
	printf("�����������Ķ�Ӧ��ϵΪ:\n");
	for (i = 0; i < m; i++)
		printf("%d %d\n", dif[i], count[i]);




	return 0;
}
