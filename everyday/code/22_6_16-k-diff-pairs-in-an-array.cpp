﻿/*

给你一个整数数组 nums 和一个整数 k，请你在数组中找出 不同的 k-diff 数对，并返回不同的 k-diff 数对 的数目。

k-diff 数对定义为一个整数对 (nums[i], nums[j]) ，并满足下述全部条件：

0 <= i, j < nums.length
i != j
nums[i] - nums[j] == k
注意，|val| 表示 val 的绝对值。

 

示例 1：

输入：nums = [3, 1, 4, 1, 5], k = 2
输出：2
解释：数组中有两个 2-diff 数对, (1, 3) 和 (3, 5)。
尽管数组中有两个 1 ，但我们只应返回不同的数对的数量。
示例 2：

输入：nums = [1, 2, 3, 4, 5], k = 1
输出：4
解释：数组中有四个 1-diff 数对, (1, 2), (2, 3), (3, 4) 和 (4, 5) 。
示例 3：

输入：nums = [1, 3, 1, 5, 4], k = 0
输出：1
解释：数组中只有一个 0-diff 数对，(1, 1) 。
 

提示：

1 <= nums.length <= 104
-107 <= nums[i] <= 107
0 <= k <= 107

链接：https://leetcode.cn/problems/k-diff-pairs-in-an-array

    vector<int> nums = {3, 1, 4, 1, 5};
    int k = 2;
    Solution temp;
    int ret = temp.findPairs(nums, k);
    cout << ret << endl;

*/

#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

//class Solution {
//public:
//    int findPairs(vector<int>& nums, int k) {
//        int ret = 0;
//        sort(nums.begin(), nums.end());
//        int len = nums.size();
//        if (k == 0) {
//            int i = 1;
//            while (i < len) {
//                if (nums[i] == nums[i - 1]) {
//                    ret++;
//                    i++;
//                    while (i < len && nums[i] == nums[i - 1])
//                        i++;
//                }
//                i++;
//            }
//            return ret;
//        }
//        int first = 0, second = 1;
//        while (second < len && nums[second] == nums[second - 1])
//            second++;
//        while (second < len) {
//            int need_num = nums[second] - k;
//            do {
//                ++second;
//            } while (second < len && nums[second] == nums[second - 1]);
//            
//            while (nums[first] < need_num) {
//                first++;
//            }
//            if (nums[first] == need_num) {
//                ret++;
//                do {
//                    ++first;
//                } while (nums[first] == nums[first - 1]);
//            }
//        }
//        return ret;
//    }
//};



//class Solution {
//public:
//    int findPairs(vector<int>& nums, int k) {
//        unordered_set<int> visited;
//        unordered_set<int> res;
//        for (int num : nums) {
//            if (visited.count(num - k)) {
//                res.emplace(num - k);
//            }
//            if (visited.count(num + k)) {
//                res.emplace(num);
//            }
//            visited.emplace(num);
//        }
//        return res.size();
//    }
//};


class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int ret = 0;
        int len = nums.size();
        sort(nums.begin(), nums.end());
        int first = 0, second = 0;
        while (first < len) {
            if (first == 0 || nums[first] != nums[first - 1]) {
                while (second < len && (second <= first || nums[first] + k > nums[second])) {
                    second++;
                }
                if (second < len && nums[first] + k == nums[second])
                    ret++;
            }
            ++first;
        }
        return ret;
    }
};