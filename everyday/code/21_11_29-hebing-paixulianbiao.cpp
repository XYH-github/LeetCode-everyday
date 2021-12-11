/*

给你一个链表数组，每个链表都已经按升序排列。

请你将所有链表合并到一个升序链表中，返回合并后的链表。

 

示例 1：

输入：lists = [[1,4,5],[1,3,4],[2,6]]
输出：[1,1,2,3,4,4,5,6]
解释：链表数组如下：
[
  1->4->5,
  1->3->4,
  2->6
]
将它们合并到一个有序链表中得到。
1->1->2->3->4->4->5->6
示例 2：

输入：lists = []
输出：[]
示例 3：

输入：lists = [[]]
输出：[]
 

提示：

k == lists.length
0 <= k <= 10^4
0 <= lists[i].length <= 500
-10^4 <= lists[i][j] <= 10^4
lists[i] 按 升序 排列
lists[i].length 的总和不超过 10^4

链接：https://leetcode-cn.com/problems/merge-k-sorted-lists

LinkList list1;
    LinkList list2;
    LinkList list3;
    list1.CreateLinkList(3, {1, 4, 5});
    list2.CreateLinkList(3, { 1, 3, 4 });
    list3.CreateLinkList(2, { 2, 6 });
    vector<ListNode*> listnode_list = { list1.GetHead()->next,
        list2.GetHead()->next, list3.GetHead()->next };
    list1.GetHead()->next = NULL;
    list2.GetHead()->next = NULL;
    list3.GetHead()->next = NULL;
    Solution temp;
    ListNode* result = temp.mergeKLists(listnode_list);
    LinkList::PrintLinkList(result);

*/
#include "LinkList.h"
#include <vector>
#include <queue>
using namespace std;



class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        priority_queue < ListNode*, vector<ListNode*>, cmp> queue;
        for (ListNode* node : lists)
            if (node)
                queue.push(node);
        ListNode * tail = new ListNode;
        ListNode* head = tail;
        while (!queue.empty()) {
            auto f = queue.top();
            queue.pop();
            tail->next = f;
            tail = tail->next;
            if (f->next)
                queue.push(f->next);
        }
        return head->next;
    }
    struct cmp {
        bool operator ()(const ListNode* a, const ListNode* b) {
            return a->val > b->val;
        }
    }; 
};


