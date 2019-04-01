//给定一个单链表 L：L0→L1→…→Ln - 1→Ln ，
//将其重新排列后变为： L0→Ln→L1→Ln - 1→L2→Ln - 2→…
//你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。
//示例 1:
//给定链表 1->2->3->4, 重新排列为 1->4->2->3.
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
		//找到中间结点
		while (fast->next && fast->next->next)
		{
			slow = slow->next;
			fast = fast->next->next;
		}
		//把中间节点以后的和之前的拆分成两个链表
		ListNode* midhead = slow->next;
		slow->next = NULL;
		//把中间节点之后的节点逆置之后插入中间节点之前的链表的缝隙中
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