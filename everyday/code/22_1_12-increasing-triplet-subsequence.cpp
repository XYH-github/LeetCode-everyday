/*

给你一个整数数组 nums ，判断这个数组中是否存在长度为 3 的递增子序列。

如果存在这样的三元组下标 (i, j, k) 且满足 i < j < k ，使得 nums[i] < nums[j] < nums[k] ，返回 true ；否则，返回 false 。

 

示例 1：

输入：nums = [1,2,3,4,5]
输出：true
解释：任何 i < j < k 的三元组都满足题意
示例 2：

输入：nums = [5,4,3,2,1]
输出：false
解释：不存在满足题意的三元组
示例 3：

输入：nums = [2,1,5,0,4,6]
输出：true
解释：三元组 (3, 4, 5) 满足题意，因为 nums[3] == 0 < nums[4] == 4 < nums[5] == 6
 

提示：

1 <= nums.length <= 5 * 105
-231 <= nums[i] <= 231 - 1

链接：https://leetcode-cn.com/problems/increasing-triplet-subsequence

    vector<int> nums = { 2, 1, 5, 0, 4, 6 };
    Solution temp;
    bool ret = temp.increasingTriplet(nums);
    cout << ret << endl;

    vector<int> nums = { 2, 1, 5, 0, 4, 6, 16, 24, 18, 12, 25, 32, 8, 7, 21 };
    Solution temp;
    bool ret = temp.increasingNtrible(nums, 7);
    cout << ret << endl;

*/

#include <vector>
using namespace std;

class Solution {
public:
    //bool increasingTriplet(vector<int>& nums) {
    //    int min_fir = INT_MAX;
    //    int min_sec = INT_MAX;
    //    for (int index : nums) {
    //        if (index > min_sec)
    //            return true;
    //        if (index > min_fir)
    //            min_sec = min(min_sec, index);
    //        min_fir = min(index, min_fir);
    //    }
    //    return false;
    //}

    bool increasingNtrible(vector<int>& nums, int n) {
        vector<int> min_vec(n - 1, INT_MAX);
        for (int index : nums) {
            if (index > min_vec[0])
                return true;
            for (int i = 1; i <= n - 2; ++i)
                if (index > min_vec[i])
                    min_vec[i - 1] = min(min_vec[i - 1], index);
            min_vec[n - 2] = min(index, min_vec[n - 2]);
        }
        return false;
    }
    
};