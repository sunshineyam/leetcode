//����һ������ nums ��һ��ֵ val������Ҫԭ���Ƴ�������ֵ���� val ��Ԫ�أ������Ƴ���������³��ȡ�
//��Ҫʹ�ö��������ռ䣬�������ԭ���޸��������鲢��ʹ�� O(1) ����ռ����������ɡ�
//Ԫ�ص�˳����Ըı䡣�㲻��Ҫ���������г����³��Ⱥ����Ԫ�ء�
//���� nums = [3, 2, 2, 3], val = 3,
//����Ӧ�÷����µĳ��� 2, ���� nums �е�ǰ����Ԫ�ؾ�Ϊ 2��

class Solution {
public:
	int removeElement(vector<int>& nums, int val) {
		if (nums.size() == 0)
			return 0;
		size_t count = 0;
		for (int i = 0; i<nums.size(); i++)
		{
			/*if(nums[i]!=val)
			{
			nums[count]=nums[i];
			count++;
			}*/
			if (nums[i] == val)
			{
				nums.erase(nums.begin() + i);
				//erase֮��Ϊ�˷�ֹ������ʧЧ��i��ָ��vector����һ��λ��
				i--;
			}
		}
		return nums.size();
	}
};