//����һ���������� nums ��һ��Ŀ��ֵ target��
//�����ڸ��������ҳ���ΪĿ��ֵ�����������������������ǵ������±ꡣ
//����Լ���ÿ������ֻ���Ӧһ���𰸡����ǣ��㲻���ظ��������������ͬ����Ԫ�ء�
class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		vector<int> mark;
		for (int i = 0; i<nums.size(); i++)
		{
			for (int j = i + 1; j<nums.size(); j++)
			{
				if (nums[i] + nums[j] == target)
				{
					mark.push_back(i);
					mark.push_back(j);
				}
			}
		}
		return mark;
	}
};