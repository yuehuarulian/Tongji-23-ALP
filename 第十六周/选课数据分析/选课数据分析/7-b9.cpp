/* 2252941 ��04 ������ */

/* ���������ϵͳ�ĺ궨�塢��Ҫ��ͷ�ļ��� */
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstring>
#include "read_stulist.h"
using namespace std;

#define MAX_FILENAME_LEN		512	//�����ļ�������󳤶�

/* stu_metge ����ÿ��ѧ������Ϣ������ѧ�š�������������Ҫ��˽����Ϣ���������ݲ�׼�����ɼ����������Ҫ��������� */
class stu_merge {
private:
	int  stu_no;					//ѧ��
	char stu_name[MAX_NAME_LEN];  //����

	bool stu_1;//�Ƿ��һ��
	bool stu_2;//�Ƿ�ڶ���
	/* ���������private���ݳ�Ա����Ա�����Լ�������Ҫ������ */
	friend class stu_list;

public:
	//���಻�������κεĹ������ݳ�Ա����Ա����
};

/* stu_list ������ѡ����Ϣ���������ݲ�׼�����ɼ����������Ҫ��������� */
class stu_list {
private:
	student list_round_1[MAX_STU_NUM];	//��һ��ѡ�ε�ѧ�������������򡢲�ȥ�أ�
	int list_num_1;						//��һ��ѡ�ε�ѧ������

	student list_round_2[MAX_STU_NUM];	//�ڶ���ѡ�ε�ѧ�������������򡢲�ȥ�أ�
	int list_num_2;						//�ڶ���ѡ�ε�ѧ������

	stu_merge list_merge[MAX_STU_NUM];	//�ϲ����ѧ��������ȥ�أ����������У�
	int list_merge_num;					//�ϲ����ѧ��������Ŀǰ����ӡ�����������ڲ������������Ҫ��Ҳ��Ҫɾ����

	/* ���������private���ݳ�Ա�ͳ�Ա����
	   ע�⣬���������array / set / map / vector��STL���� */

public:
	stu_list();										//���캯����������ɳ�ʼ�����ܣ��������Ҫ�������պ�������
	int read(const char* filename, const int round);	//���ļ��ж���ѡ����Ϣ��roundΪ1/2����ʾѡ���ִ�
	int print(const char* prompt = NULL);				//��ӡ���յ�ѡ������

	/* �������������public��Ա��������ʾ���ϲ���ȥ�ء�����ȣ�
	   �������幫�е����ݳ�Ա
	   �������ڳ�Ա������ʹ��array / set / map / vector��STL���� */
	void sort_list(const int round)
	{
		switch (round) {
			case 1:
				for (int i = 1; i < list_num_1; i++) {
					for (int j = 1; j < list_num_1 - i + 1; j++) {
						if (list_round_1[j - 1].no > list_round_1[j].no) {
							int t = list_round_1[j - 1].no;
							list_round_1[j - 1].no = list_round_1[j].no;
							list_round_1[j].no = t;
							char p[MAX_NAME_LEN];
							strcpy(p, list_round_1[j - 1].name);
							strcpy(list_round_1[j - 1].name, list_round_1[j].name);
							strcpy(list_round_1[j].name, p);
						}
					}
				}
				break;
			case 2:
				for (int i = 1; i < list_num_2; i++) {
					for (int j = 1; j < list_num_2 - i + 1; j++) {
						if (list_round_2[j - 1].no > list_round_2[j].no) {
							int t = list_round_2[j - 1].no;
							list_round_2[j - 1].no = list_round_2[j].no;
							list_round_2[j].no = t;
							char p[MAX_NAME_LEN];
							strcpy(p, list_round_2[j - 1].name);
							strcpy(list_round_2[j - 1].name, list_round_2[j].name);
							strcpy(list_round_2[j].name, p);
						}
					}
				}
				break;
		}
	}
	void remove_duplicates_and_merge()
	{
		list_merge_num = 0;//ָ���һ��û��װ���ݵ�����Ԫ��
		int top_1;
		int top_2;
		for (top_1 = 0, top_2 = 0; top_1 < list_num_1 && top_2 < list_num_2;) {
			if (list_round_1[top_1].no < list_round_2[top_2].no) {
				if (top_1 && list_round_1[top_1].no == list_merge[list_merge_num - 1].stu_no) {
					top_1++;
					continue;
				}
				merge_each(1, top_1);
				top_1++;//round_1_noС,��1
			}
			else if (list_round_1[top_1].no > list_round_2[top_2].no) {
				if (top_2 && list_round_2[top_2].no == list_merge[list_merge_num - 1].stu_no) {
					top_2++;
					continue;
				}
				merge_each(2, top_2);
				top_2++;//round_2_noС,��1
			}
			else {
				if (top_2 && list_round_2[top_2].no == list_merge[list_merge_num - 1].stu_no) {
					top_1++;
					top_2++;
					continue;
				}
				merge_each(3, top_2);
				top_1++;
				top_2++;//��ȶ���
			}
			
			//cout << setiosflags(ios::left) << setw(5) << setfill(' ') << list_merge_num << setw(9) << list_merge[list_merge_num-1].stu_no << list_merge[list_merge_num-1].stu_name;
			//cout << endl;
			//cout << " top_1 " << top_1 << " ѧ�� " << list_round_1[top_1].no << " top_2 " << top_2 << " ѧ�� " << list_round_2[top_2].no << endl;
		}
		for (; top_1 < list_num_1;) {
			if (top_1 && list_round_1[top_1].no == list_merge[list_merge_num - 1].stu_no) {
				top_1++;
				continue;
			}
			merge_each(1,top_1);
			top_1++;
		}
		for (; top_2 < list_num_2; ) {
			if (top_2 && list_round_2[top_2].no == list_merge[list_merge_num - 1].stu_no) {
				top_2++;
				continue;
			}
			merge_each(2,top_2);
			top_2++;
		}

	}
	void merge_each(const int round,const int top)
	{
		switch (round) {
			case 1:
				strcpy(list_merge[list_merge_num].stu_name, list_round_1[top].name);
				list_merge[list_merge_num].stu_no = list_round_1[top].no;
				list_merge[list_merge_num].stu_1 = 1;
				list_merge[list_merge_num].stu_2 = 0;
				list_merge_num++;
				break;
			case 2:
				strcpy(list_merge[list_merge_num].stu_name, list_round_2[top].name);
				list_merge[list_merge_num].stu_no = list_round_2[top].no;
				list_merge[list_merge_num].stu_1 = 0;
				list_merge[list_merge_num].stu_2 = 1;
				list_merge_num++;
				break;
			case 3:
				strcpy(list_merge[list_merge_num].stu_name, list_round_2[top].name);
				list_merge[list_merge_num].stu_no = list_round_2[top].no;
				list_merge[list_merge_num].stu_1 = 1;
				list_merge[list_merge_num].stu_2 = 1;
				list_merge_num++;
				break;
		}
	}
	void rl_1()///////////////////////////////////////��������
	{
		for (int i = 0; i < list_num_1; i++) {
			cout << setiosflags(ios::left) << setw(5) << setfill(' ') << i + 1 << setw(9) << list_round_1[i].no << list_round_1[i].name;
			cout << endl;
		}
		for (int i = 0; i < list_num_2; i++) {
			cout << setiosflags(ios::left) << setw(5) << setfill(' ') << i + 1 << setw(9) << list_round_2[i].no << list_round_2[i].name;
			cout << endl;
		}
	}
};

/* --- ������Ը���stu_merge/stu_list������ĳ�Ա����������ʵ�� --- */


/***************************************************************************
  �������ƣ�
  ��    �ܣ����ļ��ж���ѡ����Ϣ��roundΪ1/2����ʾѡ���ִ�
  ���������
  �� �� ֵ��
  ˵    �������캯����������ɳ�ʼ�����ܣ��������Ҫ�������պ�������
***************************************************************************/
stu_list::stu_list()
{
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ���ʾ��̬���ӿ��ʹ�ã��������е��þ�̬���ӿ��е�Ԥ�ú���
  ���������
  �� �� ֵ��
  ˵    ��������������Ҫ�޸� 
***************************************************************************/
int stu_list::read(const char* filename, const int round)
{
	int ret = 0;
	/* ��ȡ��1/2�ֵ�ѡ����������ӡ */
	switch (round) {
		case 1:
			this->list_num_1 = read_stulist(filename, this->list_round_1, MAX_STU_NUM);
			if (this->list_num_1 > 0)
				print_stulist("��һ��ѡ��������", this->list_round_1, this->list_num_1);
			else
				ret = -1;
			break;
		case 2:
			this->list_num_2 = read_stulist(filename, this->list_round_2, MAX_STU_NUM);
			if (this->list_num_2 > 0)
				print_stulist("�ڶ���ѡ��������", this->list_round_2, this->list_num_2);
			else
				ret = -1;
			break;
		default:
			ret = -1;
			break;
	}

	return ret;
}


/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ������ӡ���յ�ѡ������
***************************************************************************/
int stu_list::print(const char* prompt)
{
	cout << prompt << endl;
	cout << setw(60) << setfill('=') << '=' << endl;
	cout << "��� ѧ��     ����                            ��һ�� �ڶ���" << endl;
	cout << setw(60) << '=' << endl;
	for (int i = 0; i < list_merge_num; i++) {
		cout << setiosflags(ios::left) << setw(5) << setfill(' ') << i + 1 << setw(9) << list_merge[i].stu_no <<setw(32)<< list_merge[i].stu_name;
		cout << setw(7) << (list_merge[i].stu_1 == 1 ? 'Y' : '/');
		if (list_merge[i].stu_1 == 1 && list_merge[i].stu_2 == 1)
			cout << 'Y' << endl;
		else if (list_merge[i].stu_1 == 1 && list_merge[i].stu_2 == 0)
			cout << "�˿�" << endl;
		else if (list_merge[i].stu_1 == 0 && list_merge[i].stu_2 == 1)
			cout << "��ѡ" << endl;
	}
	cout << setw(60) << setfill('=') << '=' << endl;
	return 0;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int main(int argc, char** argv)
{
	char file1[MAX_FILENAME_LEN], file2[MAX_FILENAME_LEN];

	cout << "������ǰһ��ѡ�ε������ļ� : ";
	gets_s(file1); //cin���ܶ��пո���ļ�

	cout << "�������һ��ѡ�ε������ļ� : ";
	gets_s(file2);

	stu_list list;

	/* �������� */
	if (list.read(file1, 1) < 0)
		return -1;
	if (list.read(file2, 2) < 0)
		return -1;

	/* �������� */
	list.sort_list(1);
	list.sort_list(2);
	list.remove_duplicates_and_merge();

	/* ��ӡ */
	list.print("����ѡ������");///////////////////

	return 0;
}

