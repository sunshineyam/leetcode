//设计一个双向链表
class MyLinkedList {
public:
	/** Initialize your data structure here. */
	MyLinkedList() {
		_head = new ListNode;
		_head->_next = _head;
		_head->_prev = _head;
		size = 0;
	}
	/*void print()
	{
	ListNode* cur=_head->_next;
	for(int i=0;i<size;i++)
	{
	cout<<cur->_val<<" ";
	cur=cur->_next;
	}
	cout<<endl;
	}*/
	/** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
	int get(int index) {
		if (index < 0 || index>size - 1)
			return -1;
		ListNode* cur = _head->_next;
		while (index--)
		{
			cur = cur->_next;
		}
		return cur->_val;
	}

	/** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
	void addAtHead(int val) {
		ListNode* newnode = new ListNode(val);
		ListNode* cur = _head->_next;
		newnode->_prev = _head;
		newnode->_next = cur;
		cur->_prev = newnode;
		_head->_next = newnode;
		++size;
	}

	/** Append a node of value val to the last element of the linked list. */
	void addAtTail(int val) {
		ListNode* newnode = new ListNode(val);
		ListNode* tail = _head->_prev;
		tail->_next = newnode;
		newnode->_prev = tail;
		newnode->_next = _head;
		_head->_prev = newnode;

		++size;
	}

	/** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
	void addAtIndex(int index, int val) {
		if (index<0 || index>size)
			return;
		if (index == size)
		{
			addAtTail(val);
			return;
		}
		ListNode* cur = _head->_next;
		while (index--)
		{
			cur = cur->_next;
		}
		ListNode* newnode = new ListNode(val);
		ListNode* prev = cur->_prev;
		prev->_next = newnode;
		newnode->_prev = prev;
		newnode->_next = cur;
		cur->_prev = newnode;
		++size;
	}

	/** Delete the index-th node in the linked list, if the index is valid. */
	void deleteAtIndex(int index) {
		if (index<size && index>0)
		{
			ListNode* cur = _head->_next;
			while (index--)
			{
				cur = cur->_next;
			}
			ListNode* next = cur->_next;
			ListNode* prev = cur->_prev;
			prev->_next = next;
			next->_prev = prev;
			delete cur;
			--size;
		}
		else
			return;
	}
private:
	struct ListNode
	{
		int _val;
		ListNode* _next;
		ListNode* _prev;

		//构造函数，初始化
		ListNode(int val = 0)
			:_val(val)
			, _next(nullptr)
			, _prev(nullptr)
		{}
	};
	ListNode* _head;
	int size;
};