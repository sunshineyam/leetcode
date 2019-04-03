//给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照逆序
//的方式存储的，并且它们的每个节点只能存储一位数字。
//如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。
//您可以假设除了数字 0 之外，这两个数都不会以 0 开头。
//示例：
//输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
//输出：7 -> 0 -> 8
//原因：342 + 465 = 807
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
		//进位
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
			//%最终的结果是余数
			ListNode* newnode = new ListNode(Sum % 10);
			head->next = newnode;
			head = head->next;
			// ‘/’最终的结果是商
			Sum = Sum / 10;
		}
		//若两个都是空时,判断一下最终的sum需不需要进位
		if (Sum != 0)
		{
			ListNode* newnode = new ListNode(Sum % 10);
			head->next = newnode;
			head = head->next;
		}
		return newhead->next;
	}
};