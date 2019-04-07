//����һ������ÿ���ڵ����һ���������ӵ����ָ�룬��ָ�����ָ�������е��κνڵ��սڵ㡣
//Ҫ�󷵻��������������
/*
// Definition for a Node.
class Node {
public:
int val;
Node* next;
Node* random;

Node() {}

Node(int _val, Node* _next, Node* _random) {
val = _val;
next = _next;
random = _random;
}
};
*/
class Solution {
public:
	Node* copyRandomList(Node* head) {
		if (head == NULL)
			return head;
		//1������ÿһ���ڵ㵽ԭ������
		Node* cur = head;
		while (cur)
		{
			Node* copy = new Node(cur->val);
			Node* next = cur->next;
			cur->next = copy;
			copy->next = next;
			cur = next;
		}
		//2���ڸ��������������ȷ��randomָ��
		cur = head;
		while (cur)
		{
			Node* copy = cur->next;
			if (cur->random)
			{
				copy->random = cur->random->next;
			}
			else
				copy->random = NULL;
			cur = copy->next;
		}
		//3����copy�Ľڵ��ԭ�����в������
		Node* copyhead, *tail;
		copyhead = tail = new Node;
		cur = head;
		while (cur)
		{
			Node* copy = cur->next;
			Node* next = copy->next;
			//�������β��
			tail->next = copy;
			tail = copy;
			cur->next = next;
			cur = next;
		}
		Node* newhead = copyhead->next;
		delete copyhead;
		return newhead;
	}
};