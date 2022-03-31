/*

给定一个二叉搜索树 root 和一个目标结果 k，如果 BST 中存在两个元素且它们的和等于给定的目标结果，则返回 true。

 

示例 1：


输入: root = [5,3,6,2,4,null,7], k = 9
输出: true
示例 2：


输入: root = [5,3,6,2,4,null,7], k = 28
输出: false
 

提示:

二叉树的节点个数的范围是  [1, 104].
-104 <= Node.val <= 104
root 为二叉搜索树
-105 <= k <= 105

链接：https://leetcode-cn.com/problems/two-sum-iv-input-is-a-bst

*/

#include <unordered_set>
using namespace std;

//class Solution {
//public:
//    unordered_set<int> val_set;
//    bool findTarget(TreeNode* root, int k) {
//        if (root == nullptr)
//            return false;
//        if (val_set.count(k - root->val))
//            return true;
//        val_set.emplace(root->val);
//        return findTarget(root->left, k) || findTarget(root->right, k);
//    }
//};

//class Solution {
//public:
//    bool findTarget(TreeNode* root, int k) {
//        unordered_set<int> hashTable;
//        queue<TreeNode*> que;
//        que.push(root);
//        while (!que.empty()) {
//            TreeNode* node = que.front();
//            que.pop();
//            if (hashTable.count(k - node->val)) {
//                return true;
//            }
//            hashTable.insert(node->val);
//            if (node->left != nullptr) {
//                que.push(node->left);
//            }
//            if (node->right != nullptr) {
//                que.push(node->right);
//            }
//        }
//        return false;
//    }
//};


//class Solution {
//public:
//    vector<int> vec;
//
//    void inorderTraversal(TreeNode* node) {
//        if (node == nullptr) {
//            return;
//        }
//        inorderTraversal(node->left);
//        vec.push_back(node->val);
//        inorderTraversal(node->right);
//    }
//
//    bool findTarget(TreeNode* root, int k) {
//        inorderTraversal(root);
//        int left = 0, right = vec.size() - 1;
//        while (left < right) {
//            if (vec[left] + vec[right] == k) {
//                return true;
//            }
//            if (vec[left] + vec[right] < k) {
//                left++;
//            }
//            else {
//                right--;
//            }
//        }
//        return false;
//    }
//};


//class Solution {
//public:
//    TreeNode* getLeft(stack<TreeNode*>& stk) {
//        TreeNode* root = stk.top();
//        stk.pop();
//        TreeNode* node = root->right;
//        while (node != nullptr) {
//            stk.emplace(node);
//            node = node->left;
//        }
//        return root;
//    }
//
//    TreeNode* getRight(stack<TreeNode*>& stk) {
//        TreeNode* root = stk.top();
//        stk.pop();
//        TreeNode* node = root->left;
//        while (node != nullptr) {
//            stk.emplace(node);
//            node = node->right;
//        }
//        return root;
//    }
//
//    bool findTarget(TreeNode* root, int k) {
//        TreeNode* left = root, * right = root;
//        stack<TreeNode*> leftStack, rightStack;
//
//        while (left != nullptr) {
//            leftStack.emplace(left);
//            left = left->left;
//        }
//
//        while (right != nullptr) {
//            rightStack.emplace(right);
//            right = right->right;
//        }
//        left = getLeft(leftStack);
//        right = getRight(rightStack);
//        while (left != right) {
//            if (left->val + right->val == k) {
//                return true;
//            }
//            if (left->val + right->val < k) {
//                left = getLeft(leftStack);
//            }
//            else {
//                right = getRight(rightStack);
//            }
//        }
//        return false;
//    }
//};

