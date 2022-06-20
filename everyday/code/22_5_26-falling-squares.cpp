/*

在二维平面上的 x 轴上，放置着一些方块。

给你一个二维整数数组 positions ，其中 positions[i] = [lefti, sideLengthi] 表示：第 i 个方块边长为 sideLengthi ，其左侧边与 x 轴上坐标点 lefti 对齐。

每个方块都从一个比目前所有的落地方块更高的高度掉落而下。方块沿 y 轴负方向下落，直到着陆到 另一个正方形的顶边 或者是 x 轴上 。一个方块仅仅是擦过另一个方块的左侧边或右侧边不算着陆。一旦着陆，它就会固定在原地，无法移动。

在每个方块掉落后，你必须记录目前所有已经落稳的 方块堆叠的最高高度 。

返回一个整数数组 ans ，其中 ans[i] 表示在第 i 块方块掉落后堆叠的最高高度。

 

示例 1：


输入：positions = [[1,2],[2,3],[6,1]]
输出：[2,5,5]
解释：
第 1 个方块掉落后，最高的堆叠由方块 1 组成，堆叠的最高高度为 2 。
第 2 个方块掉落后，最高的堆叠由方块 1 和 2 组成，堆叠的最高高度为 5 。
第 3 个方块掉落后，最高的堆叠仍然由方块 1 和 2 组成，堆叠的最高高度为 5 。
因此，返回 [2, 5, 5] 作为答案。
示例 2：

输入：positions = [[100,100],[200,100]]
输出：[100,100]
解释：
第 1 个方块掉落后，最高的堆叠由方块 1 组成，堆叠的最高高度为 100 。
第 2 个方块掉落后，最高的堆叠可以由方块 1 组成也可以由方块 2 组成，堆叠的最高高度为 100 。
因此，返回 [100, 100] 作为答案。
注意，方块 2 擦过方块 1 的右侧边，但不会算作在方块 1 上着陆。
 

提示：

1 <= positions.length <= 1000
1 <= lefti <= 108
1 <= sideLengthi <= 106

链接：https://leetcode.cn/problems/falling-squares

    vector<vector<int>> positions = { {1, 2},{2, 3},{6, 1} };
    Solution temp;
    vector<int> ret = temp.fallingSquares(positions);
    Print<int>::PrintOneDemionVector(ret);

*/

#include <vector>
#include <map>
using namespace std;


class Solution {
public:
    vector<int> fallingSquares(vector<vector<int>>& positions) {
        int len = positions.size();
        vector<int> ret(len);
        height_map[0] = 0;
        for (int i = 0; i < len; ++i) {
            int height = positions[i][1];
            int left = positions[i][0];
            int right = positions[i][0] + positions[i][1] - 1;
            auto lp = height_map.upper_bound(left), rp = height_map.upper_bound(right);
            int temp = prev(rp)->second;
            for (auto iter = prev(lp); iter != rp; iter++) {
                height = max(height, positions[i][1] + iter->second);
            }
            height_map.erase(lp, rp);
            height_map[left] = height;
            if (rp == height_map.end() || rp->first != right + 1)
                height_map[right + 1] = temp;
            ret[i] = i > 0 ? max(ret[i - 1], height) : height;
        }
        return ret;
    }

private:
    map<int, int> height_map;
};


//class Solution {
//public:
//    vector<int> fallingSquares(vector<vector<int>>& positions) {
//        int len = positions.size();
//        vector<int> height(len);
//        for (int i = 0; i < len; ++i) {
//            height[i] = positions[i][1];
//            for (int j = 0; j < i; ++j) {
//                if (positions[j][0] + positions[j][1] - positions[i][0] > 0 &&
//                    positions[j][0] - positions[i][0] < positions[i][1]) {
//                    height[i] = max(height[i], height[j] + positions[i][1]);
//                }
//            }
//        }
//        for (int i = 1; i < len; ++i) {
//            height[i] = max(height[i - 1], height[i]);
//        }
//        return height;
//    }
//};


//class Solution {
//public:
//    vector<int> fallingSquares(vector<vector<int>>& positions) {
//        int n = positions.size();
//        vector<int> ret(n);
//        map<int, int> height_map;
//        height_map[0] = 0;
//        for (int i = 0; i < n; ++i) {
//            int size = positions[i][1];
//            int left = positions[i][0];
//            int right = positions[i][0] + positions[i][1] - 1;
//            auto lp = height_map.upper_bound(left);
//            auto rp = height_map.upper_bound(right);
//            int rheight = prev(rp)->second;
//
//            int height = 0;
//            for (auto p = prev(lp); p != rp; p++) {
//                height = max(height, p->second + size);
//            }
//
//            height_map.erase(lp, rp);
//
//            height_map[left] = height;
//            if (rp == height_map.end() || rp->first != right + 1) {
//                height_map[right + 1] = rheight;
//            }
//            ret[i] = i > 0 ? max(ret[i - 1], height) : height;
//        }
//        return ret;
//    }
//};

//class Node {
//public:
//    Node* left_node;
//    Node* right_node;
//    int left;
//    int right;
//    int mid;
//    int val;
//    bool lazy;
//
//    Node(int left, int right) {
//        this->left = left;
//        this->right = right;
//        this->mid = left + (right - left) / 2;
//        this->left_node = this->right_node = nullptr;
//        this->lazy = false;
//        this->val = 0;
//    }
//};
//
//class SegmentTree {
//private:
//    Node* root;
//
//    void modify(int left, int right, int val, Node* node) {
//        if (left > right)
//            return;
//        if (node->left >= left && node->right <= right) {
//            node->val = val;
//            node->lazy = true;
//            return;
//        }
//        pushdown(node);
//        if (left <= node->mid)
//            modify(left, right, val, node->left_node);
//        if (right > node->mid)
//            modify(left, right, val, node->right_node);
//        pushup(node);
//    }
//
//    int query(int left, int right, Node* node) {
//        if (left > right)
//            return 0;
//        if (node->left >= left && node->right <= right)
//            return node->val;
//        pushdown(node);
//        int val = 0;
//        if (left <= node->mid)
//            val = max(val, query(left, right, node->left_node));
//        if (right > node->mid)
//            val = max(val, query(left, right, node->right_node));
//        return val;
//    }
//
//    void pushdown(Node *node) {
//        if (!node->left_node)
//            node->left_node = new Node(node->left, node->mid);
//        if (!node->right_node)
//            node->right_node = new Node(node->mid + 1, node->right);
//        if (node->lazy) {
//            Node* left = node->left_node;
//            Node* right = node->right_node;
//            left->val = node->val;
//            right->val = node->val;
//            left->lazy = node->lazy;
//            right->lazy = node->lazy;
//            node->lazy = false;
//        }
//    }
//
//    void pushup(Node* node) {
//        node->val = max(node->left_node->val, node->right_node->val);
//    }
//
//public:
//    SegmentTree() {
//        root = new Node(1, 1e9);
//    }
//
//    void modify(int left, int right, int val) {
//        modify(left, right, val, root);
//    }
//
//    int query(int left, int right) {
//        return query(left, right, root);
//    }
//
//};
//
//
//class Solution {
//public:
//    vector<int> fallingSquares(vector<vector<int>>& positions) {
//        int len = positions.size();
//        vector<int> ret(len + 1);
//        SegmentTree* tree = new SegmentTree();
//        ret[0] = 0;
//        for (int i = 1; i <= len; ++i) {
//            int left = positions[i - 1][0];
//            int size = positions[i - 1][1];
//            int right = left + size - 1;
//            int high = tree->query(left, right) + size;
//            ret[i] = max(ret[i - 1], high);
//            tree->modify(left, right, high);
//        }
//        ret.erase(ret.begin());
//        return ret;
//    }
//};