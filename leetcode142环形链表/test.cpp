//1、判断链表是否有环
//给定一个链表，判断链表中是否有环。
//为了表示给定链表中的环，我们使用整数 pos 来表示链表尾连
//接到链表中的位置（索引从 0 开始）。 如果 pos 是 - 1，则在该链表中没有环。
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

//2、给定一个链表，返回链表开始入环的第一个节点。 如果链表无环，则返回 null。
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
	//只有当fast和slow从同一个位置出发时，才能满足公式
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