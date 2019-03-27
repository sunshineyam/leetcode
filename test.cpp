//��ת��λ�� m �� n ��������ʹ��һ��ɨ����ɷ�ת��
//˵�� :
//1 �� m �� n �� �����ȡ�
//ʾ�� :
//���� : 1->2->3->4->5->NULL, m = 2, n = 4
//��� : 1->4->3->2->5->NULL
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
		//�ҵ���һ����ʼ��ת�Ľڵ�
		int M = m - 1;
		while (M--)
		{
			prev = prev->next;
			rbegin = rbegin->next;
		}
		//����ͷ�巴תm-n֮��Ľڵ�
		for (int i = 0; i<n - m; i++)
		{
			//��Ҫע�����rbeginһֱû�䣬��ÿ��ѭ����temp��һ��
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