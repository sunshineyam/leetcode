//反转从位置 m 到 n 的链表。请使用一趟扫描完成反转。
//说明 :
//1 ≤ m ≤ n ≤ 链表长度。
//示例 :
//输入 : 1->2->3->4->5->NULL, m = 2, n = 4
//输出 : 1->4->3->2->5->NULL
 struct ListNode {
     int val;
    ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
	ListNode* reverseBetween(ListNode* head, int m, int n) {
		ListNode* newhead = new ListNode(0);
		newhead->next = head;
		ListNode* rbegin = newhead->next;
		ListNode* prev = newhead;
		//找到第一个开始反转的节点
		int M = m - 1;
		while (M--)
		{
			prev = prev->next;
			rbegin = rbegin->next;
		}
		//利用头插反转m-n之间的节点
		for (int i = 0; i<n - m; i++)
		{
			//需要注意的是rbegin一直没变，而每次循环的temp不一样
			ListNode* temp = rbegin->next;
			rbegin->next = temp->next;
			temp->next = prev->next;
			prev->next = temp;
		}
		ListNode* curhead = newhead->next;
		delete newhead;
		return curhead;
	}
};