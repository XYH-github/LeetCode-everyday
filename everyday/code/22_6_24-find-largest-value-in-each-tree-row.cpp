/*

给定一棵二叉树的根节点 root ，请找出该二叉树中每一层的最大值。

 

示例1：



输入: root = [1,3,2,5,3,null,9]
输出: [1,3,9]
示例2：

输入: root = [1,2,3]
输出: [1,3]
 

提示：

二叉树的节点个数的范围是 [0,104]
-231 <= Node.val <= 231 - 1

链接：https://leetcode.cn/problems/find-largest-value-in-each-tree-row

*/


//class Solution {
//public:
//    vector<int> largestValues(TreeNode* root) {
//        dfs(root);
//        return ret;
//    }
//
//    void dfs(TreeNode* root) {
//        if (!root)
//            return;
//        ++_cell;
//        if (ret.size() < _cell)
//            ret.emplace_back(root->val);
//        else
//            ret[_cell - 1] = max(ret[_cell - 1], root->val);
//        dfs(root->left);
//        dfs(root->right);
//        --_cell;
//    }
//
//private:
//    vector<int> ret;
//    int _cell = 0;
//};