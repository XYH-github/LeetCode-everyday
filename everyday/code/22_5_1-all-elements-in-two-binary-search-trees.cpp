/*

给你 root1 和 root2 这两棵二叉搜索树。请你返回一个列表，其中包含 两棵树 中的所有整数并按 升序 排序。.

 

示例 1：



输入：root1 = [2,1,4], root2 = [1,0,3]
输出：[0,1,1,2,3,4]
示例 2：



输入：root1 = [1,null,8], root2 = [8,1]
输出：[1,1,8,8]
 

提示：

每棵树的节点数在 [0, 5000] 范围内
-105 <= Node.val <= 105

链接：https://leetcode.cn/problems/all-elements-in-two-binary-search-trees

    int input1[] = { 2, 1, 4 }, input2[] = {1, 0, 3};
    Solution temp1, temp2;
    temp1.CreateBinTreeLevelOrder(input1, sizeof(input1) / sizeof(int));
    temp2.CreateBinTreeLevelOrder(input2, sizeof(input2) / sizeof(int));
    vector<int> ret = temp1.getAllElements(temp1.GetRootNode(), temp2.GetRootNode());
    Print<int>::PrintOneDemionVector(ret);

*/

#include <vector>
#include "BinaryTree.h"
using namespace std;

class Solution : public BinaryTree<int>{
public:
    void inorder(TreeNode<int>* node, vector<int>& res) {
        if (node) {
            inorder(node->left, res);
            res.push_back(node->val);
            inorder(node->right, res);
        }
    }

    vector<int> getAllElements(TreeNode<int>* root1, TreeNode<int>* root2) {
        vector<int> num1, num2;
        inorder(root1, num1);
        inorder(root2, num2);

        vector<int> ret;
        vector<int>::iterator p1 = num1.begin(), p2 = num2.begin();
        while (true) {
            if (p1 == num1.end()) {
                ret.insert(ret.end(), p2, num2.end());
                break;
            }
            if (p2 == num2.end()) {
                ret.insert(ret.end(), p1, num1.end());
                break;
            }
            if (*p1 < *p2) {
                ret.push_back(*p1++);
            }
            else {
                ret.push_back(*p2++);
            }
        }
        return ret;
    }
};