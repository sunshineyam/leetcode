//��дһ�������������ַ��������е������ǰ׺��
//��������ڹ���ǰ׺�����ؿ��ַ��� ""��
//ʾ�� 1:
//���� : ["flower", "flow", "flight"]
//��� : "fl"
//ʾ�� 2 :
//���� : ["dog", "racecar", "car"]
//��� : ""
//���� : ���벻���ڹ���ǰ׺��
class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		if (strs.size() == 0)
			//�������ص����ַ��������Բ��ܷ���nullptr
			return "";
		string s = "";
		int min = strs[0].size();
		//Ҳ���Բ��ҳ�ǰ׺����󳤶�,�����whileѭ����ֱ������
		/*for (int i = 0; i<strs.size(); i++)
		{
		//�ҳ�����ǰ׺����󳤶�
		if (strs[i].size()<min)
		{
		min = strs[i].size();
		}
		}*/
		int col = 0;
		int flag;
		while (col < min)
		{
			//�ҳ�ÿһ�й�����
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
			//�ѹ���ǰ׺��������
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