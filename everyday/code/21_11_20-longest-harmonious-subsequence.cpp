﻿/*

和谐数组是指一个数组里元素的最大值和最小值之间的差别 正好是 1 。

现在，给你一个整数数组 nums ，请你在所有可能的子序列中找到最长的和谐子序列的长度。

数组的子序列是一个由数组派生出来的序列，它可以通过删除一些元素或不删除元素、且不改变其余元素的顺序而得到。

 

示例 1：

输入：nums = [1,3,2,2,5,2,3,7]
输出：5
解释：最长的和谐子序列是 [3,2,2,2,3]
示例 2：

输入：nums = [1,2,3,4]
输出：2
示例 3：

输入：nums = [1,1,1,1]
输出：0
 

提示：

1 <= nums.length <= 2 * 104
-109 <= nums[i] <= 109

链接：https://leetcode-cn.com/problems/longest-harmonious-subsequence

*/
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

//class Solution {
//public:
//    int findLHS(vector<int>& nums) {
//        sort(nums.begin(), nums.end());
//        int begin = 0;
//        int res = 0;
//        for (int end = 0; end < nums.size(); ++end) {
//            while (nums[end] - nums[begin] > 1)
//                begin++;
//            if (nums[end] - nums[begin] == 1)
//                res = max(res, end - begin + 1);
//        }
//        return res;
//    }
//};

class Solution {
public:
    int findLHS(vector<int>& nums) {
        int result = 0;
        unordered_map<int, int> temp;
        for (auto index : nums)
            temp[index]++;
        for (auto index : temp) 
            if (temp.count(index.first + 1))
                result = max(result, index.second + temp[index.first + 1]);
        return result;
    }
};