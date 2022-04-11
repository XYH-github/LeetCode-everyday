/*

给你一个整数数组 nums ，请你找出 nums 子集 按位或 可能得到的 最大值 ，并返回按位或能得到最大值的 不同非空子集的数目 。

如果数组 a 可以由数组 b 删除一些元素（或不删除）得到，则认为数组 a 是数组 b 的一个 子集 。如果选中的元素下标位置不一样，则认为两个子集 不同 。

对数组 a 执行 按位或 ，结果等于 a[0] OR a[1] OR ... OR a[a.length - 1]（下标从 0 开始）。

 

示例 1：

输入：nums = [3,1]
输出：2
解释：子集按位或能得到的最大值是 3 。有 2 个子集按位或可以得到 3 ：
- [3]
- [3,1]
示例 2：

输入：nums = [2,2,2]
输出：7
解释：[2,2,2] 的所有非空子集的按位或都可以得到 2 。总共有 23 - 1 = 7 个子集。
示例 3：

输入：nums = [3,2,1,5]
输出：6
解释：子集按位或可能的最大值是 7 。有 6 个子集按位或可以得到 7 ：
- [3,5]
- [3,1,5]
- [3,2,5]
- [3,2,1,5]
- [2,5]
- [2,1,5]
 

提示：

1 <= nums.length <= 16
1 <= nums[i] <= 105

链接：https://leetcode-cn.com/problems/count-number-of-maximum-bitwise-or-subsets

    vector<int> nums = { 3, 1};
    Solution temp;
    int ret = temp.countMaxOrSubsets(nums);
    cout << ret << endl;

*/

#include <vector>
#include <functional>
using namespace std;

//class Solution {
//public:
//    int countMaxOrSubsets(vector<int>& nums) {
//        int len = nums.size();
//        int max = 0;
//        for (int num : nums) {
//            max |= num;
//        }
//        function<int(int, int)> dfs = [&](int cur_index, int cur_value) {
//            if (cur_value == max) {
//                return 1 << (len - cur_index);
//            }
//            if (cur_index == len) {
//                return 0;
//            }
//            return dfs(cur_index + 1, cur_value | nums[cur_index]) + dfs(cur_index + 1, cur_value);
//        };
//        return dfs(0, 0);
//    }
//};

class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int len = nums.size();
        int iter_num = 1 << len;
        int max = 0;
        int ret = 0;
        for (int i = 0; i < iter_num; ++i) {
            int now_max = 0;
            for (int j = 0; j < len; ++j) {
                if ((i >> j) & 1) {
                    now_max |= nums[j];
                }
            }
            if (now_max > max) {
                max = now_max;
                ret = 1;
            }
            else if (now_max == max) {
                ret++;
            }
        }
        return ret;
    }
};