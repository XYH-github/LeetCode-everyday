#include "LinkList.h"

/*
����һ����������������е�����k���ڵ㡣Ϊ�˷��ϴ�����˵�ϰ�ߣ������1��ʼ�������������β�ڵ��ǵ�����1���ڵ㡣

���磬һ�������� 6 ���ڵ㣬��ͷ�ڵ㿪ʼ�����ǵ�ֵ������ 1��2��3��4��5��6���������ĵ����� 3 ���ڵ���ֵΪ 4 �Ľڵ㡣

ʾ����

����һ������: 1->2->3->4->5, �� k = 2.

�������� 4->5.


vector<int> nums = { 1, 2, 3, 4, 5 };
    LinkList *list_ptr = new LinkList();
    list_ptr->CreateLinkList(nums.size(), nums);
    Solution temp;
    ListNode *result = temp.getKthFromEnd(list_ptr->GetHead()->next, 2);
    LinkList::PrintLinkList(result);

*/

//class  Solution {
//public:
//    ListNode* getKthFromEnd(ListNode* head, int k) {
//        ListNode* p = head;
//        ListNode* result = head;
//        while (k--)
//            p = p->next;
//        while (p != NULL) {
//            p = p->next;
//            result = result->next;
//        }
//        return result;
//    }
//
//};
