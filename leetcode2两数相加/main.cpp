//�������� �ǿ� ������������ʾ�����Ǹ������������У����Ǹ��Ե�λ���ǰ�������
//�ķ�ʽ�洢�ģ��������ǵ�ÿ���ڵ�ֻ�ܴ洢һλ���֡�
//��������ǽ��������������������᷵��һ���µ���������ʾ���ǵĺ͡�
//�����Լ���������� 0 ֮�⣬���������������� 0 ��ͷ��
//ʾ����
//���룺(2 -> 4 -> 3) + (5 -> 6 -> 4)
//�����7 -> 0 -> 8
//ԭ��342 + 465 = 807
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		/*if(l1->val==0)
		return l2;
		if(l2->val==0)
		return l1;
		ListNode* newhead=new ListNode(0);
		ListNode* node=newhead;
		ListNode* cur1=l1;
		ListNode* cur2=l2;
		//��λ
		int flag=0;
		while(cur1 && cur2)
		{
		int Sum=0;
		Sum=cur1->val+cur2->val+flag;
		if(Sum/10>0)
		{
		flag=1;
		Sum=Sum%10;
		}
		else
		flag=0;
		ListNode* newnode=new ListNode(Sum);
		node->next=newnode;
		node=node->next;
		cur1=cur1->next;
		cur2=cur2->next;
		}
		while(cur1!=NULL)
		{
		node->next=cur1;
		cur1=cur1->next;
		}
		while(cur2!=NULL)
		{
		node->next=cur2;
		cur2=cur2->next;
		}
		return newhead->next;;*/

		ListNode* newhead = new ListNode(0);
		ListNode* head = newhead;
		ListNode* cur1 = l1;
		ListNode* cur2 = l2;
		int Sum = 0;
		while (cur1 || cur2)
		{
			if (cur1 != NULL)
			{
				Sum += cur1->val;
				cur1 = cur1->next;
			}
			if (cur2 != NULL)
			{
				Sum += cur2->val;
				cur2 = cur2->next;
			}
			//%���յĽ��������
			ListNode* newnode = new ListNode(Sum % 10);
			head->next = newnode;
			head = head->next;
			// ��/�����յĽ������
			Sum = Sum / 10;
		}
		//���������ǿ�ʱ,�ж�һ�����յ�sum�費��Ҫ��λ
		if (Sum != 0)
		{
			ListNode* newnode = new ListNode(Sum % 10);
			head->next = newnode;
			head = head->next;
		}
		return newhead->next;
	}
};