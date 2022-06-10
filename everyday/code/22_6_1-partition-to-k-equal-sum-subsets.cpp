/*

给定一个整数数组  nums 和一个正整数 k，找出是否有可能把这个数组分成 k 个非空子集，其总和都相等。

 

示例 1：

输入： nums = [4, 3, 2, 3, 5, 2, 1], k = 4
输出： True
说明： 有可能将其分成 4 个子集（5），（1,4），（2,3），（2,3）等于总和。
示例 2:

输入: nums = [1,2,3,4], k = 3
输出: false
 

提示：

1 <= k <= len(nums) <= 16
0 < nums[i] < 10000
每个元素的频率在 [1,4] 范围内

链接：https://leetcode.cn/problems/partition-to-k-equal-sum-subsets

    vector<int> nums = { 4, 3, 2, 3, 5, 2, 1 };
    int k = 4;
    Solution temp;
    bool ret = temp.canPartitionKSubsets(nums, k);
    cout << ret << endl;

*/

#include <vector>
#include <numeric>
#include <functional>
using namespace std;

//class Solution {
//public:
//    bool canPartitionKSubsets(vector<int>& nums, int k) {
//        int num_all = accumulate(nums.begin(), nums.end(), 0);
//        int len = nums.size();
//        if (num_all % k != 0)
//            return false;
//        num_all /= k;
//        vector<int> vec(k);
//        function<bool(int)> dfs = [&](int index) {
//            if (index >= len)
//                return true;
//            for (int i = 0; i < k; ++i) {
//                if (vec[i] + nums[index] <= num_all) {
//                    vec[i] += nums[index];
//                    if (dfs(index + 1))
//                        return true;
//                    vec[i] -= nums[index];
//                }      
//            }
//            return false;
//        };
//        return dfs(0);
//    }
//};


class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int num_all = accumulate(nums.begin(), nums.end(), 0);
        int len = nums.size();
        if (num_all % k != 0)
            return false;
        num_all /= k;
        vector<int> dp(1 << len, -1);
        dp[0] = 0;
        for (int s = 1; s < (1 << len); ++s) {
            for (int k = 0; k < len; ++k) {
                if ((s & (1 << k)) == 0)
                    continue;
                int s1 = s & ~(1 << k);
                if (dp[s1] >= 0 && dp[s1] + nums[k] <= num_all) {
                    dp[s] = (dp[s1] + nums[k]) % num_all;
                    break;
                }
            }
        }
        return dp[(1 << len) - 1] == 0;
    }
};