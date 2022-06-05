﻿/*

给你一个可能含有 重复元素 的整数数组 nums ，请你随机输出给定的目标数字 target 的索引。你可以假设给定的数字一定存在于数组中。

实现 Solution 类：

Solution(int[] nums) 用数组 nums 初始化对象。
int pick(int target) 从 nums 中选出一个满足 nums[i] == target 的随机索引 i 。如果存在多个有效的索引，则每个索引的返回概率应当相等。
 

示例：

输入
["Solution", "pick", "pick", "pick"]
[[[1, 2, 3, 3, 3]], [3], [1], [3]]
输出
[null, 4, 0, 2]

解释
Solution solution = new Solution([1, 2, 3, 3, 3]);
solution.pick(3); // 随机返回索引 2, 3 或者 4 之一。每个索引的返回概率应该相等。
solution.pick(1); // 返回 0 。因为只有 nums[0] 等于 1 。
solution.pick(3); // 随机返回索引 2, 3 或者 4 之一。每个索引的返回概率应该相等。
 

提示：

1 <= nums.length <= 2 * 104
-231 <= nums[i] <= 231 - 1
target 是 nums 中的一个整数
最多调用 pick 函数 104 次

链接：https://leetcode.cn/problems/random-pick-index

    vector<int> nums = { 1, 2, 3, 3, 3 };
    Solution temp(nums);
    cout << temp.pick(3) << endl;
    cout << temp.pick(3) << endl;
    cout << temp.pick(3) << endl;
    cout << temp.pick(1) << endl;

*/

#include <vector>
#include <unordered_map>
#include "time.h"
using namespace std;

//class Solution {
//public:
//    Solution(vector<int>& nums) {
//        srand((unsigned)time(NULL));
//        int len = nums.size();
//        for (int i = 0; i < len; ++i) {
//            map[nums[i]].emplace_back(i);
//        }
//    }
//
//    int pick(int target) {
//        int time = map[target].size();
//        return map[target][rand() % time];
//    }
//
//private:
//    unordered_map<int, vector<int>> map;
//};


class Solution {
public:
    Solution(vector<int>& nums) : nums(nums){}

    int pick(int target) {
        int ret;
        for (int i = 0, cnt = 0; i < nums.size(); ++i) {
            if (nums[i] == target) {
                ++cnt;
                if (rand() % cnt == 0)
                    ret = i;
            }
        }
        return ret;
    }

private:
    vector<int> nums;
};