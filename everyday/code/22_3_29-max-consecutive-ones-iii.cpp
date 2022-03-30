/*

给定一个二进制数组 nums 和一个整数 k，如果可以翻转最多 k 个 0 ，则返回 数组中连续 1 的最大个数 。

 

示例 1：

输入：nums = [1,1,1,0,0,0,1,1,1,1,0], K = 2
输出：6
解释：[1,1,1,0,0,1,1,1,1,1,1]
粗体数字从 0 翻转到 1，最长的子数组长度为 6。
示例 2：

输入：nums = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], K = 3
输出：10
解释：[0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1]
粗体数字从 0 翻转到 1，最长的子数组长度为 10。
 

提示：

1 <= nums.length <= 105
nums[i] 不是 0 就是 1
0 <= k <= nums.length

链接：https://leetcode-cn.com/problems/max-consecutive-ones-iii

    vector<int> input_vec = { 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1 };
    int k = 3;
    Solution temp;
    int ret = temp.longestOnes(input_vec, k);
    cout << ret << endl;

*/

#include <vector>
using namespace std;

//class Solution {
//public:
//    int longestOnes(vector<int>& nums, int k) {
//        int len = nums.size();
//        vector<int> up_sum(len + 1);
//        up_sum[0] = 0;
//        for (int i = 1; i < len + 1; ++i)
//            up_sum[i] = up_sum[i - 1] + (1 - nums[i - 1]);
//        int pre_num = 0;
//        int temp_ret = 0;
//        int ret = 0;
//        for (int i = 0; i < len; ++i) {
//            if (up_sum[i + 1] == pre_num)
//                temp_ret++;
//            else {
//                ret = max(temp_ret, ret);
//                temp_ret = lower_bound(up_sum.begin(), up_sum.end(), up_sum[i + 1] - k) - up_sum.begin();
//                temp_ret = i - temp_ret + 1;
//                pre_num = up_sum[i];
//            }
//        }
//        ret = max(ret, temp_ret);
//        return ret;
//    }
//};


class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int len = nums.size();
        int i = 0;
        int back = -1;
        int ret = 0;
        while (i < len) {
            if (nums[i] == 0) {
                ret = max(ret, i - back - 1);
                k--;
            }
            while (k < 0) {
                back++;
                if (nums[back] == 0)
                    k++;
            }
            i++;
        }
        ret = max(ret, i - back - 1);
        return ret;
    }
};