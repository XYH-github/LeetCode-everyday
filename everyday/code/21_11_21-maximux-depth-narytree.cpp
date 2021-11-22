/*

给定一个 N 叉树，找到其最大深度。

最大深度是指从根节点到最远叶子节点的最长路径上的节点总数。

N 叉树输入按层序遍历序列化表示，每组子节点由空值分隔（请参见示例）。

 

示例 1：



输入：root = [1,null,3,2,4,null,5,6]
输出：3
示例 2：



输入：root = [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
输出：5

链接：https://leetcode-cn.com/problems/maximum-depth-of-n-ary-tree

*/

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

//class Solution {
//public:
//    int maxDepth(Node* root) {
//        if (root == nullptr)
//            return 0;
//        if (root->children.empty())
//            return 1;
//        int maxnum = 0;
//        for (auto index : root->children)
//            maxnum = max(maxnum, maxDepth(index));
//        return 1 + maxnum;
//    }
//};