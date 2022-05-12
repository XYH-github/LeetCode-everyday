/*

序列化是将数据结构或对象转换为一系列位的过程，以便它可以存储在文件或内存缓冲区中，或通过网络连接链路传输，以便稍后在同一个或另一个计算机环境中重建。

设计一个算法来序列化和反序列化 二叉搜索树 。 对序列化/反序列化算法的工作方式没有限制。 您只需确保二叉搜索树可以序列化为字符串，并且可以将该字符串反序列化为最初的二叉搜索树。

编码的字符串应尽可能紧凑。

 

示例 1：

输入：root = [2,1,3]
输出：[2,1,3]
示例 2：

输入：root = []
输出：[]
 

提示：

树中节点数范围是 [0, 104]
0 <= Node.val <= 104
题目数据 保证 输入的树是一棵二叉搜索树。

链接：https://leetcode.cn/problems/serialize-and-deserialize-bst

*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#include <string>
#include "BinaryTree.h"
using namespace std;

class Codec : public BinaryTree<int>{
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode<int>* root) {
        dfsGetPreInder(root);
        string ret;
        int len = pre_vec.size();
        for (int i = 0; i < len - 1; ++i) {
            ret += to_string(pre_vec[i]) + ",";
        }
        ret += to_string(pre_vec[len - 1]);
        return ret;
    }

    void dfsGetPreInder(TreeNode<int>* root) {
        if (root == NULL)
            return;
        pre_vec.emplace_back(root->val);
        dfsGetPreInder(root->left);
        dfsGetPreInder(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode<int>* deserialize(string data) {
        vector<int> vec;
        int len = data.size();
        int i = 0;
        int start = 0;
        while (i < len) {
            if (data[i] == ',') {
                vec.emplace_back(stoi(data.substr(start, i - start)));
                start = i + 1;
            }
            i++;
        }
        vec.emplace_back(stoi(data.substr(start, len - start)));
        return dfsDeserialize(vec, INT_MIN, INT_MAX);
    }

    TreeNode<int>* dfsDeserialize(vector<int>& vec, int lower, int upper) {
        if (vec.size() == 0 || vec.front() > lower || vec.front() < upper) {
            return NULL;
        }
        int val = vec.front();
        TreeNode<int>* cur = new TreeNode<int>(val);
        vec.erase(vec.begin());
        cur->left = dfsDeserialize(vec, lower, val);
        cur->right = dfsDeserialize(vec, val, upper);
        return cur;
    }

private:
    vector<int> pre_vec;
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;