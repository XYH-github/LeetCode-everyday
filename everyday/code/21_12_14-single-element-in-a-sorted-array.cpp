/*

给你一个仅由整数组成的有序数组，其中每个元素都会出现两次，唯有一个数只会出现一次。

请你找出并返回只出现一次的那个数。

你设计的解决方案必须满足 O(log n) 时间复杂度和 O(1) 空间复杂度。

 

示例 1:

输入: nums = [1,1,2,3,3,4,4,8,8]
输出: 2
示例 2:

输入: nums =  [3,3,7,7,10,11,11]
输出: 10
 

提示:

1 <= nums.length <= 105
0 <= nums[i] <= 105

链接：https://leetcode-cn.com/problems/single-element-in-a-sorted-array

    vector<int> nums = { 3,3,7,7,10,11,11 };
    Solution temp;
    int ret = temp.singleNonDuplicate(nums);
    cout << ret << endl;

*/

#include <vector>
using namespace std;

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int len = nums.size();
        int left = 0;
        int right = len - 1;
        while (left < right) {
            int mid = left + ((right - left) >> 1);
            int flag = (mid - left) % 2;
            if (flag == 0 && nums[mid] == nums[mid + 1])
                left = mid;
            else if (flag == 0 && nums[mid] != nums[mid + 1])
                right = mid;
            else if (flag && nums[mid] == nums[mid - 1])
                left = mid + 1;
            else if (flag && nums[mid] != nums[mid - 1])
                right = mid - 1;
        }
        return nums[left];
    }
};
