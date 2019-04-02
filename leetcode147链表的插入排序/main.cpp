//插入排序算法：
//插入排序是迭代的，每次只移动一个元素，直到所有元素可以形成一个有序的输出列表。
//每次迭代中，插入排序只从输入数据中移除一个待排序的元素，找到它在序列中适当的位置，并将其插入。
//重复直到所有输入数据插入完为止。
//输入: 4->2->1->3
//输出 : 1->2->3->4
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
				//定义node，让cur与node--cur之间的所有节点比较 
				ListNode* node = newhead;
				while (cur->val>node->next->val)
				{
					//ListNode* newprev=node;
					node = node->next;
				}
				//注意每个节点指向的先后顺序 
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