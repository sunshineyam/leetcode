//����һ�����������һ��Ŀ��ֵ�����������ҵ�Ŀ��ֵ����������������
//���Ŀ��ֵ�������������У����������ᱻ��˳������λ�á�
//����Լ������������ظ�Ԫ�ء�
//���� : [1, 3, 5, 6], 7
//��� : 4
class Solution {
public:
	int searchInsert(vector<int>& nums, int target) {
		for (int i = 0; i<nums.size(); i++)
		{
			if (target <= nums[i])
			{
				return i;
			}
		}
		return nums.size();
	}
};