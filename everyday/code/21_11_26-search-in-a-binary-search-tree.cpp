/*

给定二叉搜索树（BST）的根节点 root 和一个整数值 val。

你需要在 BST 中找到节点值等于 val 的节点。 返回以该节点为根的子树。 如果节点不存在，则返回 null 。

 

示例 1:



输入：root = [4,2,7,1,3], val = 2
输出：[2,1,3]
Example 2:


输入：root = [4,2,7,1,3], val = 5
输出：[]
 

提示：

数中节点数在 [1, 5000] 范围内
1 <= Node.val <= 107
root 是二叉搜索树
1 <= val <= 107

链接：https://leetcode-cn.com/problems/search-in-a-binary-search-tree

    Solution temp;
    int table[] = { 4, 2, 7, 1, 3 };
    temp.CreateBinTreeLevelOrder(table, sizeof(table) / sizeof(int));
    TreeNode<int>* now = temp.searchBST(temp.GetRootNode(), 3);
    BinaryTree<int>::PrintBinTree(now);

*/

#include "BinaryTree.h"

class Solution : public BinaryTree<int>{
public:
    TreeNode<int>* searchBST(TreeNode<int>* root, int val) {
        if (root == NULL)
            return NULL;
        if (root->val == val)
            return root;
        TreeNode<int>* temp;
        temp = searchBST(root->left, val);
        if (temp != NULL)
            return temp;
        temp = searchBST(root->right, val);
        if (temp != NULL)
            return temp;
        return NULL;
    }
};