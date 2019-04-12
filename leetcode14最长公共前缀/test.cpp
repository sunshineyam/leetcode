//编写一个函数来查找字符串数组中的最长公共前缀。
//如果不存在公共前缀，返回空字符串 ""。
//示例 1:
//输入 : ["flower", "flow", "flight"]
//输出 : "fl"
//示例 2 :
//输入 : ["dog", "racecar", "car"]
//输出 : ""
//解释 : 输入不存在公共前缀。
class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		if (strs.size() == 0)
			//函数返回的是字符串，所以不能返回nullptr
			return "";
		string s = "";
		int min = strs[0].size();
		//也可以不找出前缀的最大长度,下面的while循环会直接跳出
		/*for (int i = 0; i<strs.size(); i++)
		{
		//找出公共前缀的最大长度
		if (strs[i].size()<min)
		{
		min = strs[i].size();
		}
		}*/
		int col = 0;
		int flag;
		while (col < min)
		{
			//找出每一列公共的
			int row = 0;
			while (row + 1<strs.size())
			{
				flag = 1;
				if (strs[row][col] != strs[row + 1][col])
				{
					flag = 0;
					break;
				}
				row++;
			}
			//把公共前缀连接起来
			if (flag == 1)
			{
				s += strs[row][col];
				col++;
			}
			else
				return s;
		}
		return s;
	}
};