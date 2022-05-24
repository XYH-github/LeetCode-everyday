/*

给你一个整数数组 nums 和一个整数 k ，请你返回子数组内所有元素的乘积严格小于 k 的连续子数组的数目。
 

示例 1：

输入：nums = [10,5,2,6], k = 100
输出：8
解释：8 个乘积小于 100 的子数组分别为：[10]、[5]、[2],、[6]、[10,5]、[5,2]、[2,6]、[5,2,6]。
需要注意的是 [10,5,2] 并不是乘积小于 100 的子数组。
示例 2：

输入：nums = [1,2,3], k = 0
输出：0
 

提示: 

1 <= nums.length <= 3 * 104
1 <= nums[i] <= 1000
0 <= k <= 106

链接：https://leetcode.cn/problems/subarray-product-less-than-k

    vector<int> nums = { 10, 5, 2, 6 };
    int k = 100;
    Solution temp;
    int ret = temp.numSubarrayProductLessThanK(nums, k);
    cout << ret << endl;

*/

#include <vector>
using namespace std;

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int len = nums.size();
        int front = 0;
        int second = 0;
        int temp = 1;
        int ret = 0;
        while (front < len) {
            temp *= nums[front];
            while (second <= front && temp >= k) {
                temp /= nums[second];
                second++;
            }
            front++;
            ret += front - second;
        }
        return ret;
    }
};
