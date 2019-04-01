//����һ�������� L��L0��L1������Ln - 1��Ln ��
//�����������к��Ϊ�� L0��Ln��L1��Ln - 1��L2��Ln - 2����
//�㲻��ֻ�ǵ����ĸı�ڵ��ڲ���ֵ��������Ҫʵ�ʵĽ��нڵ㽻����
//ʾ�� 1:
//�������� 1->2->3->4, ��������Ϊ 1->4->2->3.
/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
class Solution {
public:
	ListNode* Reverse(ListNode* head)
	{
		ListNode* prev = NULL;
		ListNode* cur = head;
		while (cur)
		{
			ListNode* next = cur->next;
			cur->next = prev;
			prev = cur;
			cur = next;
		}
		return prev;
	}
	void reorderList(ListNode* head) {
		if (!head || !head->next)
			return;
		ListNode* fast = head;
		ListNode* slow = head;
		ListNode* cur = head;
		//�ҵ��м���
		while (fast->next && fast->next->next)
		{
			slow = slow->next;
			fast = fast->next->next;
		}
		//���м�ڵ��Ժ�ĺ�֮ǰ�Ĳ�ֳ���������
		ListNode* midhead = slow->next;
		slow->next = NULL;
		//���м�ڵ�֮��Ľڵ�����֮������м�ڵ�֮ǰ������ķ�϶��
		midhead = Reverse(midhead);
		while (cur && midhead)
		{
			ListNode* next = cur->next;
			ListNode* cursecond = midhead;
			midhead = midhead->next;
			cur->next = cursecond;
			cursecond->next = next;
			cur = next;
		}
	}
};