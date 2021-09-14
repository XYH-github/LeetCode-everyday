#pragma once
#include <cstddef>
#include <iostream>
#include <vector>

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {};
};

class LinkList {
public:
	LinkList();
	~LinkList();
	void CreateLinkList(int n);
	void CreateLinkList(int n, std::vector<int> array);
	int GetLength() { return m_size; };
	ListNode* GetHead() { return m_head; };
	bool IsEmpty() { return m_size == 0; };

	ListNode* GetCurrNode() { return m_head; };

	static void PrintLinkList(ListNode* ptr);

private:
	ListNode* m_head;
	int m_size;
};