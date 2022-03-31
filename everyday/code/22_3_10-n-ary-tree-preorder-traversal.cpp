/*

给定一个 n 叉树的根节点  root ，返回 其节点值的 前序遍历 。

n 叉树 在输入中按层序遍历进行序列化表示，每组子节点由空值 null 分隔（请参见示例）。


示例 1：



输入：root = [1,null,3,2,4,null,5,6]
输出：[1,3,5,6,2,4]
示例 2：



输入：root = [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
输出：[1,2,3,6,7,11,14,4,8,12,5,9,13,10]
 

提示：

节点总数在范围 [0, 104]内
0 <= Node.val <= 104
n 叉树的高度小于或等于 1000
 

进阶：递归法很简单，你可以使用迭代法完成此题吗?

链接：https://leetcode-cn.com/problems/n-ary-tree-preorder-traversal

    Solution temp;
    int table[] = { 1,NULL,2,3,4,5,NULL,NULL,6,7,NULL,8,NULL,9,10,NULL,NULL,11,NULL,12,NULL,13,NULL,NULL,14 };
    temp.CreateNArrTreeLevelOrder(table, sizeof(table) / sizeof(table[0]));
    temp.LevelOrder();

*/

#include "NAryTree.h"

class Solution : public NAryTree<int> {
public:
    vector<int> ret;
    vector<int> preorder(TreeNode<int>* root) {
        ret.emplace_back(root->val);
        for (auto index : root->children) {
            if (index != nullptr)
                preorder(index);
        }
        return ret;
    }
};


//class Solution {
//public:
//
//    vector<int> preorder(Node* root) {
//        vector<int> ret;
//        stack<Node*> stk;
//        unordered_set<Node*> node_set;
//        Node* p = root;
//        while (p != nullptr && !stk.empty()) {
//            while (p != nullptr) {
//                ret.emplace_back(p->val);
//                stk.emplace(p);
//                if (p->children.size() != 0) {
//                    p = *(p->children.begin());
//                    p->children.erase(p->children.begin());
//                }
//                else
//                    p = nullptr;
//            }
//            if (!stk.empty()) {
//                p = stk.top();
//                if (!node_set.count(p)) {
//                    node_set.emplace(p);
//                    ret.emplace_back(p->val);
//                }
//                if (p->children.size() != 0) {
//                    p = *(p->children.begin());
//                    p->children.erase(p->children.begin());
//                }
//                else {
//                    p = nullptr;
//                    stk.pop();
//                }
//            }
//        }
//        return ret;
//    }
//};


//class Solution {
//public:
//    vector<int> preorder(Node* root) {
//        vector<int> ret;
//        stack<Node*> stk;
//        if (root == nullptr)
//            return ret;
//        stk.push(root);
//        while (!stk.empty()) {
//            Node* p = stk.top();
//            stk.pop();
//            ret.emplace_back(p->val);
//            vector<Node*> temp = p->children;
//            if (temp.size() != 0) {
//                for (auto iter = temp.rbegin(); iter != temp.rend(); ++iter)
//                    stk.push(*iter);
//            }
//        }
//
//        return ret;
//    }
//};