/*

输入两棵二叉树A和B，判断B是不是A的子结构。(约定空树不是任意一个树的子结构)

B是A的子结构， 即 A中有出现和B相同的结构和节点值。

例如:
给定的树 A:

     3
    / \
   4   5
  / \
 1   2
给定的树 B：

   4 
  /
 1
返回 true，因为 B 与 A 的一个子树拥有相同的结构和节点值。

示例 1：

输入：A = [1,2,3], B = [3,1]
输出：false
示例 2：

输入：A = [3,4,5,1,2], B = [4,1]
输出：true
限制：

0 <= 节点个数 <= 10000

链接：https://leetcode-cn.com/problems/shu-de-zi-jie-gou-lcof

    Solution temp;
    int bintree_input[] = { 1, 0, 1, -4, 3};
    temp.CreateBinTreeLevelOrder(bintree_input, sizeof(bintree_input) / sizeof(int));
    Solution temp2;
    int bintree_input2[] = { 1, -4 };
    temp2.CreateBinTreeLevelOrder(bintree_input2, sizeof(bintree_input2) / sizeof(int));
    bool ret = Solution::isSubStructure(temp.GetRootNode(), temp2.GetRootNode());
    cout << ret << endl;

*/

#include "../code/BinaryTree.h"
#include <functional>


//class Solution : public BinaryTree<int>{
//public:
//    static bool isSubStructure(TreeNode<int>* A, TreeNode<int>* B) {
//        function<bool(TreeNode<int>*, TreeNode<int>*)> check = [&](TreeNode<int>* ptr_d, TreeNode<int>* ptr_h) {
//            if (ptr_d == NULL)
//                return false;
//            if (ptr_d->val == ptr_h->val) {
//                if (ptr_h->left != NULL && !check(ptr_d->left, ptr_h->left))
//                    return false;
//                if (ptr_h->right != NULL && !check(ptr_d->right, ptr_h->right))
//                    return false;
//                return true;
//            }
//            return false;
//        };
//
//        function<bool(TreeNode<int>*)> dfs = [&](TreeNode<int>* ptr_a) {
//            if (ptr_a == NULL)
//                return false;
//            if (ptr_a->val == B->val)
//                if (check(ptr_a, B))
//                    return true;
//            if (dfs(ptr_a->left))
//                return true;
//            if (dfs(ptr_a->right))
//                return true;
//            return false;
//        };
//        if (B == NULL)
//            return false;
//        bool ret = dfs(A);
//        return ret;
//    }
//};


class Solution : public BinaryTree<int> {
public:
    static bool isSubStructure(TreeNode<int>* A, TreeNode<int>* B) {
        function<bool(TreeNode<int>*, TreeNode<int>*)> check = [&](TreeNode<int>* ptr_d, TreeNode<int>* ptr_h) {
            if (ptr_h == NULL)
                return true;
            if (ptr_d == NULL || ptr_d->val != ptr_h->val) {
                return false;
            }
            return check(ptr_d->left, ptr_h->left) && check(ptr_d->right, ptr_h->right);
        };

        function<bool(TreeNode<int>*)> dfs = [&](TreeNode<int>* ptr_a) {
            return (ptr_a != NULL && B != NULL) && (check(ptr_a, B) || dfs(ptr_a->left) || dfs(ptr_a->right));
        };
        bool ret = dfs(A);
        return ret;
    }
};