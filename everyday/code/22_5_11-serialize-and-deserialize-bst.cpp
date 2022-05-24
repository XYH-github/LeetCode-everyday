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

    int input_vec[] = { 8, 6, 10, 3, 7, 9, 12};
    Codec temp;
    temp.CreateBinTreeLevelOrder(input_vec, sizeof(input_vec) / sizeof(int));
    temp.PrintBinTree();
    string ret = temp.serialize(temp.GetRootNode());
    cout << endl << ret << endl;
    TreeNode<int>* res = temp.deserialize(ret);
    BinaryTree<int>::PrintBinTree(res);

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

//class Codec : public BinaryTree<int>{
//public:
//
//    // Encodes a tree to a single string.
//    string serialize(TreeNode<int>* root) {
//        dfsGetPreInder(root);
//        string ret;
//        int len = pre_vec.size();
//        if (len == 0)
//            return ret;
//        for (int i = 0; i < len - 1; ++i) {
//            ret += to_string(pre_vec[i]) + ",";
//        }
//        ret += to_string(pre_vec[len - 1]);
//        return ret;
//    }
//
//    void dfsGetPreInder(TreeNode<int>* root) {
//        if (root == NULL)
//            return;
//        pre_vec.emplace_back(root->val);
//        dfsGetPreInder(root->left);
//        dfsGetPreInder(root->right);
//    }
//
//    // Decodes your encoded data to tree.
//    TreeNode<int>* deserialize(string data) {
//        vector<int> vec;
//        int len = data.size();
//        if (len == 0)
//            return NULL;
//        int i = 0;
//        int start = 0;
//        while (i < len) {
//            if (data[i] == ',') {
//                vec.emplace_back(stoi(data.substr(start, i - start)));
//                start = i + 1;
//            }
//            i++;
//        }
//        vec.emplace_back(stoi(data.substr(start, len - start)));
//        return dfsDeserialize(vec, INT_MIN, INT_MAX);
//    }
//
//    TreeNode<int>* dfsDeserialize(vector<int>& vec, int lower, int upper) {
//        if (vec.size() == 0 || vec.front() < lower || vec.front() > upper) {
//            return NULL;
//        }
//        int val = vec.front();
//        TreeNode<int>* cur = new TreeNode<int>(val);
//        vec.erase(vec.begin());
//        cur->left = dfsDeserialize(vec, lower, val);
//        cur->right = dfsDeserialize(vec, val, upper);
//        return cur;
//    }
//
//private:
//    vector<int> pre_vec;
//};


//class Codec : public BinaryTree<int> {
//public:
//
//    // Encodes a tree to a single string.
//    string serialize(TreeNode<int>* root) {
//        dfsGetPreInder(root);
//        string ret;
//        int len = pre_vec.size();
//        if (len == 0)
//            return ret;
//        for (int i = 0; i < len - 1; ++i) {
//            ret += to_string(pre_vec[i]) + ",";
//        }
//        ret += to_string(pre_vec[len - 1]);
//        return ret;
//    }
//
//    void dfsGetPreInder(TreeNode<int>* root) {
//        if (root == NULL)
//            return;
//        pre_vec.emplace_back(root->val);
//        dfsGetPreInder(root->left);
//        dfsGetPreInder(root->right);
//    }
//
//    // Decodes your encoded data to tree.
//    TreeNode<int>* deserialize(string data) {
//        vector<int> vec;
//        int len = data.size();
//        if (len == 0)
//            return NULL;
//        int i = 0;
//        int start = 0;
//        while (i < len) {
//            if (data[i] == ',') {
//                vec.emplace_back(stoi(data.substr(start, i - start)));
//                start = i + 1;
//            }
//            i++;
//        }
//        vec.emplace_back(stoi(data.substr(start, len - start)));
//        vector<int> in_vec(vec);
//        sort(in_vec.begin(), in_vec.end());
//        return dfsDeserialize(vec, in_vec, 0, 0, vec.size());
//    }
//
//    TreeNode<int>* dfsDeserialize(vector<int> pre_vec, vector<int> in_vec, int start_pre, int start_in, int len) {
//        if (len == 0)
//            return NULL;
//        TreeNode<int>* cur = new TreeNode<int>(pre_vec[start_pre]);
//        int i = start_in;
//        while (pre_vec[start_pre] != in_vec[i])
//            i++;
//        cur->left = dfsDeserialize(pre_vec, in_vec, start_pre + 1, start_in, i - start_in);
//        cur->right = dfsDeserialize(pre_vec, in_vec, start_pre + i - start_in + 1, i + 1, len - (i - start_in) - 1);
//        return cur;
//    }
//
//private:
//    vector<int> pre_vec;
//};


class Codec : public BinaryTree<int> {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode<int>* root) {
        dfsGetPosInder(root);
        string ret;
        int len = pos_vec.size();
        if (len == 0)
            return ret;
        for (int i = 0; i < len - 1; ++i) {
            ret += to_string(pos_vec[i]) + ",";
        }
        ret += to_string(pos_vec[len - 1]);
        return ret;
    }

    void dfsGetPosInder(TreeNode<int>* root) {
        if (root == NULL)
            return;
        dfsGetPosInder(root->left);
        dfsGetPosInder(root->right);
        pos_vec.emplace_back(root->val);
    }

    // Decodes your encoded data to tree.
    TreeNode<int>* deserialize(string data) {
        vector<int> vec;
        int len = data.size();
        if (len == 0)
            return NULL;
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
        vector<int> in_vec(vec);
        sort(in_vec.begin(), in_vec.end());
        return dfsDeserialize(vec, in_vec, 0, 0, vec.size());
    }

    TreeNode<int>* dfsDeserialize(vector<int> pos_vec, vector<int> in_vec, int start_pos, int start_in, int len) {
        if (len == 0)
            return NULL;
        TreeNode<int>* cur = new TreeNode<int>(pos_vec[start_pos + len - 1]);
        int i = start_in;
        while (pos_vec[start_pos + len - 1] != in_vec[i])
            i++;
        cur->left = dfsDeserialize(pos_vec, in_vec, start_pos, start_in, i - start_in);
        cur->right = dfsDeserialize(pos_vec, in_vec, start_pos + i - start_in, i + 1, len - i + start_in - 1);
        return cur;
    }

private:
    vector<int> pos_vec;
};
