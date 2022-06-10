/*

给定一个二叉搜索树的根节点 root 和一个值 key，删除二叉搜索树中的 key 对应的节点，并保证二叉搜索树的性质不变。返回二叉搜索树（有可能被更新）的根节点的引用。

一般来说，删除节点可分为两个步骤：

首先找到需要删除的节点；
如果找到了，删除它。
 

示例 1:



输入：root = [5,3,6,2,4,null,7], key = 3
输出：[5,4,6,2,null,null,7]
解释：给定需要删除的节点值是 3，所以我们首先找到 3 这个节点，然后删除它。
一个正确的答案是 [5,4,6,2,null,null,7], 如下图所示。
另一个正确答案是 [5,2,6,null,4,null,7]。


示例 2:

输入: root = [5,3,6,2,4,null,7], key = 0
输出: [5,3,6,2,4,null,7]
解释: 二叉树不包含值为 0 的节点
示例 3:

输入: root = [], key = 0
输出: []
 

提示:

节点数的范围 [0, 104].
-105 <= Node.val <= 105
节点值唯一
root 是合法的二叉搜索树
-105 <= key <= 105
 

进阶： 要求算法时间复杂度为 O(h)，h 为树的高度。

链接：https://leetcode.cn/problems/delete-node-in-a-bst

*/



//class Solution {
//public:
//    TreeNode* deleteNode(TreeNode* root, int key) {
//        if (!root)
//            return nullptr;
//        if (root->val > key) {
//            root->left = deleteNode(root->left, key);
//            return root;
//        }
//        else if (root->val < key) {
//            root->right = deleteNode(root->right, key);
//            return root;
//        }
//        else {
//            if (!root->left && !root->right)
//                return nullptr;
//            if (!root->left)
//                return root->right;
//            if (!root->right)
//                return root->left;
//            TreeNode* now_node = root->right;
//            while (now_node->left)
//                now_node = now_node->left;
//            root->right = deleteNode(root->right, now_node->val);
//            now_node->left = root->left;
//            now_node->right = root->right;
//            return now_node;
//        }
//    }
//};



//class Solution {
//public:
//    TreeNode* deleteNode(TreeNode* root, int key) {
//        TreeNode* cur = root, * cur_par = nullptr;
//        while (cur && cur->val != key) {
//            cur_par = cur;
//            if (cur->val > key)
//                cur = cur->left;
//            else if (cur->val < key)
//                cur = cur->right;
//        }
//        if (!cur)
//            return root;
//        if (!cur->left && !cur->right)
//            cur = nullptr;
//        else if (!cur->left)
//            cur = cur->right;
//        else if (!cur->right)
//            cur = cur->left;
//        else {
//            TreeNode* now_node = cur->right, * pre_node = cur;
//            while (now_node->left) {
//                pre_node = now_node;
//                now_node = now_node->left;
//            }
//            if (pre_node == cur)
//                pre_node->right = now_node->right;
//            else
//                pre_node->left = now_node->right;
//            now_node->left = cur->left;
//            now_node->right = cur->right;
//            cur = now_node;
//        }
//        if (!cur_par)
//            return cur;
//        if (cur_par->val > key)
//            cur_par->left = cur;
//        else
//            cur_par->right = cur;
//        return root;
//    }
//};