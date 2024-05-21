/* 信04 2252941 杨瑞灵 */
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
	int upp = 0, low = 0, num = 0, va = 0, other = 0;
	char str[3][128] = { 0 };
	cout << "请输入第1行" << endl;
	cin.getline(str[0], 128, '\n');
	cout << "请输入第2行" << endl;
	cin.getline(str[1], 128, '\n');
	cout << "请输入第3行" << endl;
	cin.getline(str[2], 128, '\n');
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 128; j++)
		{
			if (str[i][j] == '\0')
				break;
			if (str[i][j] >= 'A' && str[i][j] <= 'Z')
				upp++;
			else if (str[i][j] >= 'a' && str[i][j] <= 'z')
				low++;
			else if (str[i][j] >= '0' && str[i][j] <= '9')
				num++;
			else if (str[i][j] == ' ')
				va++;
			else
				other++;
		}
	}
	cout << "大写 : " << upp << endl;
	cout << "小写 : " << low << endl;
	cout << "数字 : " << num << endl;
	cout << "空格 : " << va << endl;
	cout << "其它 : " << other << endl;


	return 0;
}
