//1���ж������Ƿ��л�
//����һ�������ж��������Ƿ��л���
//Ϊ�˱�ʾ���������еĻ�������ʹ������ pos ����ʾ����β��
//�ӵ������е�λ�ã������� 0 ��ʼ���� ��� pos �� - 1�����ڸ�������û�л���
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
	bool hasCycle(ListNode *head) {
		if (head == NULL || head->next == NULL)
			return false;
		ListNode* slow = head;
		ListNode* fast = head;
		while (fast && fast->next)
		{
			slow = slow->next;
			fast = fast->next->next;
			if (fast == slow)
				return true;
		}
		return false;
	}
};

//2������һ��������������ʼ�뻷�ĵ�һ���ڵ㡣 ��������޻����򷵻� null��
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
	ListNode* hascycle(ListNode* head)
	{
		if (head == NULL || head->next == NULL)
			return NULL;
		ListNode* slow = head;
		ListNode* fast = head;
		while (fast && fast->next)
		{
			slow = slow->next;
			fast = fast->next->next;
			if (fast == slow)
				return fast;
		}
		return NULL;
	}
	//ֻ�е�fast��slow��ͬһ��λ�ó���ʱ���������㹫ʽ
	ListNode *detectCycle(ListNode *head) {
		ListNode* meet = hascycle(head);
		if (meet != NULL)
		{
			while (head != meet)
			{
				head = head->next;
				meet = meet->next;
			}
			return meet;
		}
		else
			return NULL;
	}
};