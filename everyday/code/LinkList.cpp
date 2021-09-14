#include "LinkList.h"

LinkList::LinkList() {
	this->m_head = new ListNode(0);
	this->m_size = 0;
}

LinkList::~LinkList() {
	ListNode* temp = this->m_head;
	ListNode* del = NULL;
	while (temp) {
		del = temp;
		temp = temp->next;
		free(del);
	}
	
	
}

void LinkList::CreateLinkList(int n, std::vector<int> array) {
	if (n < 0 || array.size() != n) {
		std::cout << "error!" << std::endl;
		return;
	}
	ListNode* former = this->m_head;
	ListNode* temp = NULL;

	this->m_size = n;
	for (int i = 0; i < n; ++i) {
		temp = new ListNode(array[i]);
		temp->next = NULL;
		former->next = temp;
		former = temp;
	}
}

void LinkList::CreateLinkList(int n) {
	CreateLinkList(n, std::vector<int>(n, 0));
}

void LinkList::PrintLinkList(ListNode* ptr) {
	if (ptr == NULL)
		return;
	ListNode* temp = ptr;
	std::cout << temp->val;
	temp = temp->next;
	while (temp) {
		std::cout << " -> " << temp->val;
		temp = temp->next;
	}
}


