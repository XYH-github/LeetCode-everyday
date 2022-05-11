/*

给你一个长度为 n 的整数数组 nums ，其中 nums 的所有整数都在范围 [1, n] 内，且每个整数出现 一次 或 两次 。请你找出所有出现 两次 的整数，并以数组形式返回。

你必须设计并实现一个时间复杂度为 O(n) 且仅使用常量额外空间的算法解决此问题。

 

示例 1：

输入：nums = [4,3,2,7,8,2,3,1]
输出：[2,3]
示例 2：

输入：nums = [1,1,2]
输出：[1]
示例 3：

输入：nums = [1]
输出：[]
 

提示：

n == nums.length
1 <= n <= 105
1 <= nums[i] <= n
nums 中的每个元素出现 一次 或 两次

链接：https://leetcode.cn/problems/find-all-duplicates-in-an-array

    vector<int> nums = { 4, 3, 2, 7, 8, 2, 3, 1 };
    Solution temp;
    vector<int> ret = temp.findDuplicates(nums);
    Print<int>::PrintOneDemionVector(ret);

*/

#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int len = nums.size();
        for (int i = 0; i < len; ++i) {
            while (nums[nums[i] - 1] != nums[i]) {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }
        int i = 1;
        for (auto iter = nums.begin(); iter != nums.end();) {
            if (*iter == i) {
                iter = nums.erase(iter);
            }
            else {
                iter++;
            }
            i++;
        }
        return nums;
    }
};

//class Solution {
//public:
//    vector<int> findDuplicates(vector<int>& nums) {
//        int n = nums.size();
//        for (int i = 0; i < n; ++i) {
//            while (nums[i] != nums[nums[i] - 1]) {
//                swap(nums[i], nums[nums[i] - 1]);
//            }
//        }
//        vector<int> ans;
//        for (int i = 0; i < n; ++i) {
//            if (nums[i] - 1 != i) {
//                ans.push_back(nums[i]);
//            }
//        }
//        return ans;
//    }
//};
