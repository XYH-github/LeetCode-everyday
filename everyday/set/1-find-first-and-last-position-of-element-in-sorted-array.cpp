/*

给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。

如果数组中不存在目标值 target，返回 [-1, -1]。

进阶：

你可以设计并实现时间复杂度为 O(log n) 的算法解决此问题吗？
 

示例 1：

输入：nums = [5,7,7,8,8,10], target = 8
输出：[3,4]
示例 2：

输入：nums = [5,7,7,8,8,10], target = 6
输出：[-1,-1]
示例 3：

输入：nums = [], target = 0
输出：[-1,-1]
 

提示：

0 <= nums.length <= 105
-109 <= nums[i] <= 109
nums 是一个非递减数组
-109 <= target <= 109

链接：https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array

*/

#include <vector>
using namespace std;

//class Solution {
//public:
//    vector<int> searchRange(vector<int>& nums, int target) {
//        int len = nums.size();
//        if (len == 0)
//            return { -1, -1 };
//        int left = 0, right = len - 1;
//        while (left <= right) {
//            int mid = left + ((right - left) >> 1);
//            if (nums[mid] <= target)
//                left = mid + 1;
//            else
//                right = mid - 1;
//        }
//        int temp = right;
//        left = 0, right = len - 1;
//        while (left <= right) {
//            int mid = left + ((right - left) >> 1);
//            if (nums[mid] < target)
//                left = mid + 1;
//            else
//                right = mid - 1;
//        }
//        if (left < len || temp >= 0 && nums[temp] == target && nums[left] == target)
//            return { left, temp };
//        else
//            return { -1, -1 };
//    }
//};


//class Solution {
//public:
//    vector<int> searchRange(vector<int>& nums, int target) {
//        int len = nums.size();
//        if (len == 0)
//            return { -1, -1 };
//        int left = 0, right = len - 1;
//        while (left < right) {
//            int mid = left + ((right - left) >> 1);
//            if (nums[mid] <= target)
//                left = mid + 1;
//            else
//                right = mid;
//        }
//        int temp = nums[left] == target ? left : left - 1;
//        left = 0, right = len - 1;
//        while (left < right) {
//            int mid = left + ((right - left + 1) >> 1);
//            if (nums[mid] < target)
//                left = mid;
//            else
//                right = mid - 1;
//        }
//        left = nums[left] == target ? left : left + 1;
//        if (left < len && temp >= 0 && nums[temp] == target && nums[left] == target)
//            return { left, temp };
//        else
//            return { -1, -1 };
//    }
//};


class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int len = nums.size();
        if (len == 0)
            return { -1, -1 };
        int left = 0, right = len - 1;
        while (left < right) {
            int mid = left + ((right - left) >> 1);
            if (nums[mid] <= target)
                left = mid + 1;
            else
                right = mid;
        }
        int temp = nums[left] == target ? left : left - 1;
        if (temp < 0 || nums[temp] != target)
            return { -1, -1 };
        int b = temp;
        while (temp--)
            if (nums[temp] != target)
                break;
        return { temp + 1, b };
    }
};