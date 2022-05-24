/*

设计一个算法，找出二叉搜索树中指定节点的“下一个”节点（也即中序后继）。

如果指定节点没有对应的“下一个”节点，则返回null。

示例 1:

输入: root = [2,1,3], p = 1

  2
 / \
1   3

输出: 2
示例 2:

输入: root = [5,3,6,2,4,null,null,1], p = 6

      5
     / \
    3   6
   / \
  2   4
 /
1

输出: null

链接：https://leetcode.cn/problems/successor-lcci

    Solution temp;
    int input[] = { 2, 1, 3 };
    temp.CreateBinTreeLevelOrder(input, sizeof(input) / sizeof(int));
    TreeNode<int>* ret = temp.inorderSuccessor(temp.GetRootNode(), temp.GetRootNode()->left);
    cout << ret->val << endl;

*/

#include <stack>
#include "BinaryTree.h"
using namespace std;

class Solution : public BinaryTree<int>{
public:
    TreeNode<int>* inorderSuccessor(TreeNode<int>* root, TreeNode<int>* p) {
        stack<TreeNode<int>*> stk;
        TreeNode<int>* ptr = root;
        bool flag = false;
        while (ptr != NULL || !stk.empty()) {
            while (ptr != NULL) {
                stk.emplace(ptr);
                ptr = ptr->left;
            }
            if (!stk.empty()) {
                ptr = stk.top();
                stk.pop();
                if (flag) {
                    return ptr;
                }
                if (p == ptr) {
                    flag = true;
                }
                ptr = ptr->right;
            }
        }
        return NULL;
    }
};


//class Solution {
//public:
//    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
//        TreeNode* successor = nullptr;
//        if (p->right != nullptr) {
//            successor = p->right;
//            while (successor->left != nullptr) {
//                successor = successor->left;
//            }
//            return successor;
//        }
//        TreeNode* node = root;
//        while (node != nullptr) {
//            if (node->val > p->val) {
//                successor = node;
//                node = node->left;
//            }
//            else {
//                node = node->right;
//            }
//        }
//        return successor;
//    }
//};
