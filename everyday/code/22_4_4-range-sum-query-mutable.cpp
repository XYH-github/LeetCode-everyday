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


class NumArray {
private:
    void build(int start, int end, int index) {
        if (start == end) {
            _nums[index] = _matrix[start];
            return;
        }
        int mid = start + (end - start) / 2;
        build(start, mid, 2 * index + 1);
        build(mid + 1, end, 2 * index + 2);
        _nums[index] = _nums[2 * index + 1] + _nums[2 * index + 2];
    }

    void change(int pre_index, int start, int end, int index, int num) {
        if (start == end) {
            _nums[index] = num;
            return;
        }
        int mid = start + (end - start) / 2;
        if (mid < pre_index) {
            change(pre_index, mid + 1, end, 2 * index + 2, num);
        }
        else {
            change(pre_index, start, mid, 2 * index + 1, num);
        }
        _nums[index] = _nums[2 * index + 1] + _nums[2 * index + 2];
    }

    int sum(int left, int right, int start, int end, int index) {
        if (left == start && right == end) {
            return _nums[index];
        }
        int mid = start + (end - start) / 2;
        if (mid >= right)
            return sum(left, right, start, mid, 2 * index + 1);
        else if (mid < left)
            return sum(left, right, mid + 1, end, 2 * index + 2);
        else
            return sum(left, mid, start, mid, 2 * index + 1) +
            sum(mid + 1, right, mid + 1, end, 2 * index + 2);
    }

public:
    NumArray(vector<int>& nums) : _matrix(nums), _nums(nums.size() * 4), _size(nums.size()) {
        build(0, _size - 1, 0);
    }


    void update(int index, int val) {
        change(index, 0, _size - 1, 0, val);
    }

    int sumRange(int left, int right) {
        return sum(left, right, 0, _size - 1, 0);
    }

private:
    vector<int> _nums;
    vector<int> _matrix;
    int _size;
};



//class NumArray {
//public:
//    NumArray(vector<int>& nums) : _nums(nums), tree(nums.size() + 1), _len(nums.size() + 1) {
//        for (int i = 0; i < _len - 1; ++i)
//            add(i + 1, _nums[i]);
//    }
//
//    void update(int index, int val) {
//        add(index + 1, val - _nums[index]);
//        _nums[index] = val;
//    }
//
//    int sumRange(int left, int right) {
//        return query(right + 1) - query(left);
//    }
//
//private:
//    int lowBit(int nums) {
//        return nums & -nums;
//    }
//
//    void add(int index, int val) {
//        while (index < _len) {
//            tree[index] += val;
//            index += lowBit(index);
//        }
//    }
//
//    int query(int index) {
//        int ret = 0;
//        while (index > 0) {
//            ret += tree[index];
//            index -= lowBit(index);
//        }
//        return ret;
//    }
//
//
//private:
//    vector<int> _nums;
//    vector<int> tree;
//    int _len;
//};

