/* ��04 2252941 ������ */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int ret, x;
	printf("������x��ֵ[0-100] : ");
	while (1) {
		ret = scanf("%d", &x); //����x�ķ�ʽ������scanf�Ҹ�ʽ��Ϊ%d����׼�÷�scanf
		if (ret == 1 && (x >= 0 && x <= 100))
			break;
		else if (ret == 0)
		{
			while (getchar() != '\n')//��getchar+ѭ����ջ�����
				continue;
		}
		else
			getchar();
		printf("�����д�[ret=%d x=%d],����������\n", ret, x); //ȷ��һ�£�ret��ֵ����scanf�ķ���ֵ����ʲô���壿 
		printf("������x��ֵ[0-100] : ");
	}

	printf("ret=%d x=%d\n", ret, x);

	return 0;
}