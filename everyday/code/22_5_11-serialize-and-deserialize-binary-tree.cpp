/*

序列化是将一个数据结构或者对象转换为连续的比特位的操作，进而可以将转换后的数据存储在一个文件或者内存中，同时也可以通过网络传输到另一个计算机环境，采取相反方式重构得到原数据。

请设计一个算法来实现二叉树的序列化与反序列化。这里不限定你的序列 / 反序列化算法执行逻辑，你只需要保证一个二叉树可以被序列化为一个字符串并且将这个字符串反序列化为原始的树结构。

提示: 输入输出格式与 LeetCode 目前使用的方式一致，详情请参阅 LeetCode 序列化二叉树的格式。你并非必须采取这种方式，你也可以采用其他的方法解决这个问题。

 

示例 1：


输入：root = [1,2,3,null,null,4,5]
输出：[1,2,3,null,null,4,5]
示例 2：

输入：root = []
输出：[]
示例 3：

输入：root = [1]
输出：[1]
示例 4：

输入：root = [1,2]
输出：[1,2]
 

提示：

树中结点数在范围 [0, 104] 内
-1000 <= Node.val <= 1000

链接：https://leetcode.cn/problems/serialize-and-deserialize-binary-tree

*/


///**
// * Definition for a binary tree node.
// * struct TreeNode {
// *     int val;
// *     TreeNode *left;
// *     TreeNode *right;
// *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
// * };
// */
//class Codec {
//public:
//    void rserialize(TreeNode* root, string& str) {
//        if (root == NULL)
//            str += "null,";
//        else {
//            str += to_string(root->val) + ",";
//            rserialize(root->left, str);
//            rserialize(root->right, str);
//        }
//    }
//
//    // Encodes a tree to a single string.
//    string serialize(TreeNode* root) {
//        string str;
//        rserialize(root, str);
//        return str;
//    }
//
//    TreeNode* rdeserialize(list<string> str_list) {
//        if (str_list.front() == "null") {
//            str_list.erase(str_list.begin());
//            return NULL;
//        }
//        TreeNode* cur = new TreeNode(stoi(str_list.front()));
//        str_list.erase(str_list.begin());
//        cur->left = rdeserialize(str_list);
//        cur->right = rdeserialize(str_list);
//        return cur;
//    }
//
//    // Decodes your encoded data to tree.
//    TreeNode* deserialize(string data) {
//        list<string> str_list;
//        int len = data.size();
//        int start = 0;
//        int i = 0;
//        while (i < len) {
//            if (data[i] == ',') {
//                str_list.emplace_back(data.substr(start, i - start));
//                start = i + 1;
//            }
//            i++;
//        }
//        if (start != len) {
//            str_list.emplace_back(data.substr(start, len - start));
//        }
//        TreeNode* ret = rdeserialize(str_list);
//        return ret;
//    }
//};
//
//// Your Codec object will be instantiated and called as such:
//// Codec ser, deser;
//// TreeNode* ans = deser.deserialize(ser.serialize(root));