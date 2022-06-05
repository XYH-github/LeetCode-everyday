/*

如果二叉树每个节点都具有相同的值，那么该二叉树就是单值二叉树。

只有给定的树是单值二叉树时，才返回 true；否则返回 false。

 

示例 1：



输入：[1,1,1,1,1,null,1]
输出：true
示例 2：



输入：[2,2,2,5,2]
输出：false
 

提示：

给定树的节点数范围是 [1, 100]。
每个节点的值都是整数，范围为 [0, 99] 。

链接：https://leetcode.cn/problems/univalued-binary-tree

*/


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */


//class Solution {
//public:
//    bool isUnivalTree(TreeNode* root) {
//        if (root == nullptr)
//            return true;
//        int val = root->val;
//        if (!isVaild(root, val)) {
//            return false;
//        }
//        return true;
//    }
//    bool isVaild(TreeNode* root, int val) {
//        if (root == nullptr)
//            return true;
//        if (root->val != val)
//            return false;
//        if (isVaild(root->left, val) && isVaild(root->right, val))
//            return true;
//        return false;
//    }
//};