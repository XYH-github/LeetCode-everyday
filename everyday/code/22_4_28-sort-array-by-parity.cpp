/*

给你一个整数数组 nums，将 nums 中的的所有偶数元素移动到数组的前面，后跟所有奇数元素。

返回满足此条件的 任一数组 作为答案。

 

示例 1：

输入：nums = [3,1,2,4]
输出：[2,4,3,1]
解释：[4,2,3,1]、[2,4,1,3] 和 [4,2,1,3] 也会被视作正确答案。
示例 2：

输入：nums = [0]
输出：[0]
 

提示：

1 <= nums.length <= 5000
0 <= nums[i] <= 5000

链接：https://leetcode.cn/problems/sort-array-by-parity

    vector<int> nums = { 3, 1, 2, 4 };
    Solution temp;
    vector<int> ret = temp.sortArrayByParity(nums);
    Print<int>::PrintOneDemionVector(ret);

*/

#include <vector>
using namespace std;

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            while (left < right && nums[left] % 2 == 0)
                ++left;
            while (left < right && nums[right] % 2)
                --right;
            swap(nums[left], nums[right]);
        }
        return nums;
    }
};