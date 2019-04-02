//���������㷨��
//���������ǵ����ģ�ÿ��ֻ�ƶ�һ��Ԫ�أ�ֱ������Ԫ�ؿ����γ�һ�����������б�
//ÿ�ε����У���������ֻ�������������Ƴ�һ���������Ԫ�أ��ҵ������������ʵ���λ�ã���������롣
//�ظ�ֱ�������������ݲ�����Ϊֹ��
//����: 4->2->1->3
//��� : 1->2->3->4
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* insertionSortList(ListNode* head) {
		if (head == NULL)
			return NULL;
		ListNode* newhead = new ListNode(0);
		newhead->next = head;
		ListNode* prev = head;
		ListNode* cur = head->next;
		while (cur)
		{
			if (cur->val >= prev->val)
			{
				prev = cur;
				cur = cur->next;
			}
			else
			{
				//����node����cur��node--cur֮������нڵ�Ƚ� 
				ListNode* node = newhead;
				while (cur->val>node->next->val)
				{
					//ListNode* newprev=node;
					node = node->next;
				}
				//ע��ÿ���ڵ�ָ����Ⱥ�˳�� 
				prev->next = cur->next;
				cur->next = node->next;
				node->next = cur;
				cur = prev->next;
			}
		}
		ListNode* curhead = newhead->next;
		delete newhead;
		return curhead;
	}
};