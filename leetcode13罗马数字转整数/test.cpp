//#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	int romanToInt(string s) {
		vector<char> str;
		str = { 'I', 'V', 'X', 'L', 'C', 'D', 'M' };
		vector<int> num;
		num = { 1, 5, 10, 50, 100, 500, 1000 };
		int i = 0;
		int sum = 0;
		while (i<s.size())
		{
			//1、分析特殊情况I\X\C,注意从大到小分析，不然当s=MCMXCIV，CM完了之后会跳过XC 
			if (s[i] == 'C')
			{
				if (s[i + 1] == 'D')
				{
					sum += 400;
					i += 2;
				}
				else if (s[i + 1] == 'M')
				{
					sum += 900;
					i += 2;
				}
			}
			if (s[i] == 'X')
			{
				if (s[i + 1] == 'L')
				{
					sum += 40;
					i += 2;
				}
				else if (s[i + 1] == 'C')
				{
					sum += 90;
					i += 2;
				}
			}
			if (s[i] == 'I')
			{
				if (s[i + 1] == 'V')
				{
					sum += 4;
					i += 2;
				}
				else if (s[i + 1] == 'X')
				{
					sum += 9;
					i += 2;
				}
			}
			//2、普通情况
			int j = 0;
			while (j<num.size())
			{
				if (s[i] == str[j])
				{
					sum += num[j];
				}
				j++;
			}
			i++;
		}
		return sum;
	}
};
int main()
{
	Solution ps;
	cout << ps.romanToInt("MCMXCIV") << endl;
	system("pause");

	return 0;
}