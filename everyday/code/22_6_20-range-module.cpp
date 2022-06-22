/*

Range模块是跟踪数字范围的模块。设计一个数据结构来跟踪表示为 半开区间 的范围并查询它们。

半开区间 [left, right) 表示所有 left <= x < right 的实数 x 。

实现 RangeModule 类:

RangeModule() 初始化数据结构的对象。
void addRange(int left, int right) 添加 半开区间 [left, right)，跟踪该区间中的每个实数。添加与当前跟踪的数字部分重叠的区间时，应当添加在区间 [left, right) 中尚未跟踪的任何数字到该区间中。
boolean queryRange(int left, int right) 只有在当前正在跟踪区间 [left, right) 中的每一个实数时，才返回 true ，否则返回 false 。
void removeRange(int left, int right) 停止跟踪 半开区间 [left, right) 中当前正在跟踪的每个实数。
 

示例 1：

输入
["RangeModule", "addRange", "removeRange", "queryRange", "queryRange", "queryRange"]
[[], [10, 20], [14, 16], [10, 14], [13, 15], [16, 17]]
输出
[null, null, null, true, false, true]

解释
RangeModule rangeModule = new RangeModule();
rangeModule.addRange(10, 20);
rangeModule.removeRange(14, 16);
rangeModule.queryRange(10, 14); 返回 true （区间 [10, 14) 中的每个数都正在被跟踪）
rangeModule.queryRange(13, 15); 返回 false（未跟踪区间 [13, 15) 中像 14, 14.03, 14.17 这样的数字）
rangeModule.queryRange(16, 17); 返回 true （尽管执行了删除操作，区间 [16, 17) 中的数字 16 仍然会被跟踪）
 

提示：

1 <= left < right <= 109
在单个测试用例中，对 addRange 、  queryRange 和 removeRange 的调用总数不超过 104 次

链接：https://leetcode.cn/problems/range-module

*/



class Node {
public:
    Node* left_node;
    Node* right_node;

    int left;
    int right;
    int mid;
    bool val;
    bool lazy;

    Node(int left, int right) {
        this->left = left;
        this->right = right;
        this->lazy = false;
        this->mid = left + (right - left) / 2;
        this->left_node = this->right_node = nullptr;
        this->val = false;
    }
};

class SegmentTree {

private:
    Node* root;

    void modify(int left, int right, bool val, Node* node) {
        if (left > right)
            return;
        if (left <= node->left && right >= node->right) {
            node->val = val;
            node->lazy = true;
            return;
        }
        pushdown(node);
        if (left <= node->mid)
            modify(left, right, val, node->left_node);
        if (right > node->mid)
            modify(left, right, val, node->right_node);
        pushup(node);
    }

    bool query(int left, int right, Node* node) {
        if (left > right)
            return false;
        if (left <= node->left && right >= node->right) {
            return node->val;
        }
        pushdown(node);
        if (right <= node->mid)
            return query(left, right, node->left_node);
        else if (left > node->mid)
            return query(left, right, node->right_node);
        else
            return query(left, right, node->left_node) && query(left, right, node->right_node);
    }

    void pushdown(Node* node) {
        if (!node->left_node)
            node->left_node = new Node(node->left, node->mid);
        if (!node->right_node)
            node->right_node = new Node(node->mid + 1, node->right);
        if (node->lazy) {
            Node* left = node->left_node;
            Node* right = node->right_node;
            left->val = node->val;
            right->val = node->val;
            left->lazy = node->lazy;
            right->lazy = node->lazy;
            node->lazy = false;
        }
    }

    void pushup(Node* node) {
        if (node->left_node->val && node->right_node->val)
            node->val = true;
        else
            node->val = false;
    }

public:
    SegmentTree() {
        root = new Node(1, 1e9 + 1);
    }

    bool query(int left, int right) {
        return query(left, right, root);
    }

    void modify(int left, int right, bool val) {
        modify(left, right, val, root);
    }

};



class RangeModule {
public:
    RangeModule() {
        tree = new SegmentTree();
    }

    void addRange(int left, int right) {
        tree->modify(left, right - 1, true);
    }

    bool queryRange(int left, int right) {
        return tree->query(left, right - 1);
    }

    void removeRange(int left, int right) {
        tree->modify(left, right - 1, false);
    }

private:
    SegmentTree* tree;
};