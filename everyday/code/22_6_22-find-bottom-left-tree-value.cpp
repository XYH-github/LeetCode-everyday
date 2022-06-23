/*

给定一个二叉树的 根节点 root，请找出该二叉树的 最底层 最左边 节点的值。

假设二叉树中至少有一个节点。

 

示例 1:



输入: root = [2,1,3]
输出: 1
示例 2:



输入: [1,2,3,4,null,5,6,null,null,7]
输出: 7
 

提示:

二叉树的节点个数的范围是 [1,104]
-231 <= Node.val <= 231 - 1 

链接：https://leetcode.cn/problems/find-bottom-left-tree-value

*/


//class Solution {
//public:
//    int findBottomLeftValue(TreeNode* root) {
//        dfs(root);
//        return ret;
//    }
//
//    void dfs(TreeNode* root) {
//        _cell++;
//        if (!root->left && !root->right) {
//            if (_cell > max) {
//                max = _cell;
//                ret = root->val;
//            }
//            _cell--;
//            return;
//        }
//        if (root->left)
//            dfs(root->left);
//        if (root->right)
//            dfs(root->right);
//        _cell--;
//    }
//
//private:
//    int _cell = 0;
//    int max = 0;
//    int ret;
//};