/* 2252941 ������ ��04 */
#include <iostream>
using namespace std;

/* 1�����������κ����͵�ȫ�ֱ������������������궨���
   2������������κ���ʽ��ȫ�ֺ���
*/

/* --- ����Ķ��岹������ --- */
class Days {
private:
	int year;
	int month;
	int day;
	//�����������private���ݳ�Ա�⣬������������κ����͵����ݳ�Ա

	/* ������Բ�����Ҫ�����Ա�����Ķ��壨���ṩ����磬���������������Ա�������ã��������Ϊ˽�У��������ޣ��������壩 */
	bool runnian(int year);
	int unswer(int month, int day, int rili[][31], int top[12]);

public:
	int calc_days();     //�����ǵ���ĵڼ���

	/* ������Բ���������Ҫ�����Ա�����Ķ���(����ʵ��)���������ޣ��������� */
	Days(int y, int m, int d);
};

/* --- �˴��������Ա����������ʵ�� --- */
bool Days::runnian(int year)//�ж�����
{
	if ((year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0)))
		return true;
	else
		return false;
}
int Days::unswer(int month, int day, int rili[][31], int top[12])
{
	int i, j;
	int day_sum = 0;
	for (i = 0; i < 12; i++){
		for (j = 0; j < top[i]; j++){
			day_sum++;
			rili[i][j] = day_sum;
		}
	}
	return rili[month - 1][day - 1];
}
Days::Days(int y, int m, int d) :year(y), month(m), day(d)
{

}
int Days::calc_days()
{
	int rili[12][31];
	int top[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	//�Ƿ�����
	top[1] += runnian(year);
	if (month < 1 || month > 12)
		return -1;
	if (day<1 || day>top[month - 1])
		return -1;
	//��ʼ����rili
	return unswer(month, day, rili, top);
}
/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����main������׼��
 ***************************************************************************/
int main()
{
	if (1) {
		Days d1(2020, 3, 18);
		cout << "Ӧ�����78�� ʵ���ǣ�" << d1.calc_days() << endl;
	}

	if (1) {
		Days d1(2023, 3, 18);
		cout << "Ӧ�����77�� ʵ���ǣ�" << d1.calc_days() << endl;
	}

	if (1) {
		Days d1(2020, 12, 31);
		cout << "Ӧ�����366��ʵ���ǣ�" << d1.calc_days() << endl;
	}

	if (1) {
		Days d1(2023, 12, 31);
		cout << "Ӧ�����365��ʵ���ǣ�" << d1.calc_days() << endl;
	}

	if (1) {
		Days d1(2020, 2, 29);
		cout << "Ӧ�����60�� ʵ���ǣ�" << d1.calc_days() << endl;
	}

	if (1) {
		Days d1(2023, 2, 29);
		cout << "Ӧ�����-1�� ʵ���ǣ�" << d1.calc_days() << endl;
	}

	return 0;
}
