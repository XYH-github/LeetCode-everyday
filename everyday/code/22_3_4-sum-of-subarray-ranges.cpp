/*

给你一个整数数组 nums 。nums 中，子数组的 范围 是子数组中最大元素和最小元素的差值。

返回 nums 中 所有 子数组范围的 和 。

子数组是数组中一个连续 非空 的元素序列。

 

示例 1：

输入：nums = [1,2,3]
输出：4
解释：nums 的 6 个子数组如下所示：
[1]，范围 = 最大 - 最小 = 1 - 1 = 0
[2]，范围 = 2 - 2 = 0
[3]，范围 = 3 - 3 = 0
[1,2]，范围 = 2 - 1 = 1
[2,3]，范围 = 3 - 2 = 1
[1,2,3]，范围 = 3 - 1 = 2
所有范围的和是 0 + 0 + 0 + 1 + 1 + 2 = 4
示例 2：

输入：nums = [1,3,3]
输出：4
解释：nums 的 6 个子数组如下所示：
[1]，范围 = 最大 - 最小 = 1 - 1 = 0
[3]，范围 = 3 - 3 = 0
[3]，范围 = 3 - 3 = 0
[1,3]，范围 = 3 - 1 = 2
[3,3]，范围 = 3 - 3 = 0
[1,3,3]，范围 = 3 - 1 = 2
所有范围的和是 0 + 0 + 0 + 2 + 0 + 2 = 4
示例 3：

输入：nums = [4,-2,-3,4,1]
输出：59
解释：nums 中所有子数组范围的和是 59
 

提示：

1 <= nums.length <= 1000
-109 <= nums[i] <= 109

链接：https://leetcode-cn.com/problems/sum-of-subarray-ranges

    vector<int> nums = { 4, -2, -3, 4, 1};
    Solution temp;
    long long ret = temp.subArrayRanges(nums);
    cout << ret << endl;

*/

#include <vector>
#include <stack>
using namespace std;

//class Solution {
//public:
//    long long subArrayRanges(vector<int>& nums) {
//        long long ret = 0;
//        int len = nums.size();
//        for (int i = 0; i < len; ++i) {
//            int temp_max = nums[i];
//            int temp_min = nums[i];
//            for (int j = i; j < len; ++j) {
//                if (temp_max < nums[j])
//                    temp_max = nums[j];
//                else if (temp_min > nums[j])
//                    temp_min = nums[j];
//                ret += temp_max - temp_min;
//            }
//        }
//        return ret;
//    }
//};


class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        long long ret_max = 0, ret_min = 0;
        int len = nums.size();
        vector<int> min_left(len), min_right(len), max_left(len), max_right(len);
        stack<int> min_stk, max_stk;
        for (int i = 0; i < len; ++i) {
            while (!min_stk.empty() && nums[min_stk.top()] > nums[i])
                min_stk.pop();
            min_left[i] = min_stk.empty() ? -1 : min_stk.top();
            min_stk.emplace(i);

            while (!max_stk.empty() && nums[max_stk.top()] <= nums[i])
                max_stk.pop();
            max_left[i] = max_stk.empty() ? -1 : max_stk.top();
            max_stk.emplace(i);
        }
        min_stk = stack<int>();
        max_stk = stack<int>();
        for (int i = len - 1; i >= 0; --i) {
            while (!min_stk.empty() && nums[min_stk.top()] >= nums[i])
                min_stk.pop();
            min_right[i] = min_stk.empty() ? len : min_stk.top();
            min_stk.emplace(i);

            while (!max_stk.empty() && nums[max_stk.top()] < nums[i])
                max_stk.pop();
            max_right[i] = max_stk.empty() ? len : max_stk.top();
            max_stk.emplace(i);
        }
        for (int i = 0; i < len; ++i) {
            ret_max += static_cast<long long>(max_right[i] - i) * (i - max_left[i]) * nums[i];
            ret_min += static_cast<long long>(min_right[i] - i) * (i - min_left[i]) * nums[i];
        }
        return ret_max - ret_min;
    }
};