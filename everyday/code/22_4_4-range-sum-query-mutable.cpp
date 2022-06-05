/*

给你一个数组 nums ，请你完成两类查询。

其中一类查询要求 更新 数组 nums 下标对应的值
另一类查询要求返回数组 nums 中索引 left 和索引 right 之间（ 包含 ）的nums元素的 和 ，其中 left <= right
实现 NumArray 类：

NumArray(int[] nums) 用整数数组 nums 初始化对象
void update(int index, int val) 将 nums[index] 的值 更新 为 val
int sumRange(int left, int right) 返回数组 nums 中索引 left 和索引 right 之间（ 包含 ）的nums元素的 和 （即，nums[left] + nums[left + 1], ..., nums[right]）
 

示例 1：

输入：
["NumArray", "sumRange", "update", "sumRange"]
[[[1, 3, 5]], [0, 2], [1, 2], [0, 2]]
输出：
[null, 9, null, 8]

解释：
NumArray numArray = new NumArray([1, 3, 5]);
numArray.sumRange(0, 2); // 返回 1 + 3 + 5 = 9
numArray.update(1, 2);   // nums = [1,2,5]
numArray.sumRange(0, 2); // 返回 1 + 2 + 5 = 8
 

提示：

1 <= nums.length <= 3 * 104
-100 <= nums[i] <= 100
0 <= index < nums.length
-100 <= val <= 100
0 <= left <= right < nums.length
调用 update 和 sumRange 方法次数不大于 3 * 104 

链接：https://leetcode-cn.com/problems/range-sum-query-mutable

    vector<int> input_vec = {1, 3, 5};
    NumArray temp(input_vec);
    temp.sumRange(0, 2);
    temp.update(1, 2);
    temp.sumRange(0, 2);

*/

#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

//class NumArray {
//public:
//    NumArray(vector<int>& nums) : _nums(nums) {
//        int len = nums.size();
//        this->_size = sqrt(len);
//        int n = (len + _size - 1) / _size;
//        _sum.resize(n);
//        for (int i = 0; i < len; ++i) {
//            _sum[i / _size] += nums[i];
//        }
//    }
//
//    void update(int index, int val) {
//        _sum[index / _size] += val - _nums[index];
//        _nums[index] = val;
//    }
//
//    int sumRange(int left, int right) {
//        int l = left / _size;
//        int li = left % _size;
//        int r = right / _size;
//        int ri = right % _size;
//        if (l == r)
//            return accumulate(_nums.begin() + l * _size + li, _nums.begin() + r * _size + ri + 1, 0);
//        int sum1 = accumulate(_nums.begin() + l * _size + li, _nums.begin() + l * _size + _size, 0);
//        int sum2 = accumulate(_nums.begin() + r * _size, _nums.begin() + r * _size + ri + 1, 0);
//        int sum3 = accumulate(_sum.begin() + l + 1, _sum.begin() + r, 0);
//        return sum1 + sum2 + sum3;
//    }
//
//private:
//    vector<int> _nums;
//    vector<int> _sum;
//    int _size;
//};


//class NumArray {
//private:
//    vector<int> segmentTree;
//    int n;
//
//    void build(int node, int s, int e, vector<int>& nums) {
//        if (s == e) {
//            segmentTree[node] = nums[s];
//            return;
//        }
//        int m = s + (e - s) / 2;
//        build(node * 2 + 1, s, m, nums);
//        build(node * 2 + 2, m + 1, e, nums);
//        segmentTree[node] = segmentTree[node * 2 + 1] + segmentTree[node * 2 + 2];
//    }
//
//    void change(int index, int val, int node, int s, int e) {
//        if (s == e) {
//            segmentTree[node] = val;
//            return;
//        }
//        int m = s + (e - s) / 2;
//        if (index <= m) {
//            change(index, val, node * 2 + 1, s, m);
//        }
//        else {
//            change(index, val, node * 2 + 2, m + 1, e);
//        }
//        segmentTree[node] = segmentTree[node * 2 + 1] + segmentTree[node * 2 + 2];
//    }
//
//    int range(int left, int right, int node, int s, int e) {
//        if (left == s && right == e) {
//            return segmentTree[node];
//        }
//        int m = s + (e - s) / 2;
//        if (right <= m) {
//            return range(left, right, node * 2 + 1, s, m);
//        }
//        else if (left > m) {
//            return range(left, right, node * 2 + 2, m + 1, e);
//        }
//        else {
//            return range(left, m, node * 2 + 1, s, m) + range(m + 1, right, node * 2 + 2, m + 1, e);
//        }
//    }
//
//public:
//    NumArray(vector<int>& nums) : n(nums.size()), segmentTree(nums.size() * 4) {
//        build(0, 0, n - 1, nums);
//    }
//
//    void update(int index, int val) {
//        change(index, val, 0, 0, n - 1);
//    }
//
//    int sumRange(int left, int right) {
//        return range(left, right, 0, 0, n - 1);
//    }
//};


class NumArray {
private:
    vector<int> tree;
    vector<int>& nums;

    int lowBit(int x) {
        return x & -x;
    }

    void add(int index, int val) {
        while (index < tree.size()) {
            tree[index] += val;
            index += lowBit(index);
        }
    }

    int prefixSum(int index) {
        int sum = 0;
        while (index > 0) {
            sum += tree[index];
            index -= lowBit(index);
        }
        return sum;
    }

public:
    NumArray(vector<int>& nums) : tree(nums.size() + 1), nums(nums) {
        for (int i = 0; i < nums.size(); i++) {
            add(i + 1, nums[i]);
        }
    }

    void update(int index, int val) {
        add(index + 1, val - nums[index]);
        nums[index] = val;
    }

    int sumRange(int left, int right) {
        return prefixSum(right + 1) - prefixSum(left);
    }
};

