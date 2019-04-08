//编写一个程序，找到两个单链表相交的起始节点。
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
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		if (headA == NULL || headB == NULL)
			return NULL;
		struct ListNode* LA = headA;
		struct ListNode* LB = headB;
		struct ListNode* tmp = NULL;
		int numa = 0;
		int numb = 0;
		while (LA)
		{
			if (LA->next)
			{
				LA = LA->next;
			}
			else
				break;
			numa++;
		}
		while (LB)
		{
			if (LB->next)
			{
				LB = LB->next;
			}
			else
				break;
			numb++;
		}

		LA = headA;
		LB = headB;
		if (numa>numb)
		{
			int num = numa - numb;
			while (num--)
			{

				LA = LA->next;
			}
		}
		if (numa<numb)
		{
			int num = numb - numa;
			while (num--)
			{

				LB = LB->next;
			}
		}
		while (LA && LB)
		{
			if (LA == LB)
			{
				break;
			}
			LA = LA->next;
			LB = LB->next;
		}
		return LA;
	}
};