养兔子：
一只成熟的兔子每天能产下一胎兔子。每只小兔子的成熟期是一天。 某人领养了一只小兔子，请问第N天以后，他将会得到多少只兔子。
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