/*

给你一个整数数组 nums，将它重新排列成 nums[0] < nums[1] > nums[2] < nums[3]... 的顺序。

你可以假设所有输入数组都可以得到满足题目要求的结果。

 

示例 1：

输入：nums = [1,5,1,1,6,4]
输出：[1,6,1,5,1,4]
解释：[1,4,1,5,1,6] 同样是符合题目要求的结果，可以被判题程序接受。
示例 2：

输入：nums = [1,3,2,2,3,1]
输出：[2,3,1,3,1,2]
 

提示：

1 <= nums.length <= 5 * 104
0 <= nums[i] <= 5000
题目数据保证，对于给定的输入 nums ，总能产生满足题目要求的结果
 

进阶：你能用 O(n) 时间复杂度和 / 或原地 O(1) 额外空间来实现吗？

链接：https://leetcode.cn/problems/wiggle-sort-ii

    vector<int> nums = { 1, 1, 2, 1, 2, 2, 1 };
    Solution temp;
    temp.wiggleSort(nums);
    Print<int>::PrintOneDemionVector(nums);

*/

#include <vector>
#include <algorithm>
using namespace std;

//class Solution {
//public:
//    void wiggleSort(vector<int>& nums) {
//        auto mid_iter = nums.begin() + nums.size() / 2;
//        nth_element(nums.begin(), mid_iter, nums.end());
//        int mid = *mid_iter;
//        int k = nums.size() - 1;
//        int i = 0;
//        int j = 0;
//        while (j <= k) {
//            if (nums[j] > mid)
//                swap(nums[j], nums[k--]);
//            else if (nums[j] < mid)
//                swap(nums[i++], nums[j++]);
//            else
//                j++;
//        }
//        if (nums.size() % 2 == 1)
//            ++mid_iter;
//        vector<int> temp1(nums.begin(), mid_iter);
//        vector<int> temp2(mid_iter, nums.end());
//        for (int i = 0; i < temp1.size(); ++i)
//            nums[2 * i] = temp1[temp1.size() - 1 - i];
//        for (int i = 0; i < temp2.size(); ++i)
//            nums[2 * i + 1] = temp2[temp2.size() - 1 - i];
//    }
//};


class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        auto mid_iter = nums.begin() + n / 2;
        nth_element(nums.begin(), mid_iter, nums.end());
        int mid = *mid_iter;
        int k = n - 1;
        int i = 0, j = 0;

//#define A(i) nums[(1 + 2 * (i)) % ( n|1)]
#define A(i) nums[(1 + 2 * (i)) % ( n|1)]
        while (j <= k) {
            if (A(j) > mid)
                swap(A(j), A(k--));
            else if (A(j) < mid)
                swap(A(i++), A(j++));
            else
                j++;
        }
    }
};