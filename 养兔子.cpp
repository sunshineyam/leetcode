�����ӣ�
һֻ���������ÿ���ܲ���һ̥���ӡ�ÿֻС���ӵĳ�������һ�졣 ĳ��������һֻС���ӣ����ʵ�N���Ժ�������õ�����ֻ���ӡ�
#include <iostream>
using namespace std;
int main()
{
	int n;
	while (cin >> n)
	{
		long long array[91];
		array[0] = 1;
		array[1] = 2;
		for (int i = 2; i < 91; i++)
		{
			array[i] = array[i - 1] + array[i - 2];
		}
		cout << array[n - 1] << endl;
	}
	return 0;
}