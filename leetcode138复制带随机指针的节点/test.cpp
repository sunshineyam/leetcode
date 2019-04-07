//给定一个链表，每个节点包含一个额外增加的随机指针，该指针可以指向链表中的任何节点或空节点。
//要求返回这个链表的深拷贝。
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
		//1、拷贝每一个节点到原链表中
		Node* cur = head;
		while (cur)
		{
			Node* copy = new Node(cur->val);
			Node* next = cur->next;
			cur->next = copy;
			copy->next = next;
			cur = next;
		}
		//2、在复制完的新链表中确定random指针
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
		//3、把copy的节点从原链表中拆解下来
		Node* copyhead, *tail;
		copyhead = tail = new Node;
		cur = head;
		while (cur)
		{
			Node* copy = cur->next;
			Node* next = copy->next;
			//新链表的尾插
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