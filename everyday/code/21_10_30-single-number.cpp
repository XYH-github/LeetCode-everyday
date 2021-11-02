/*

给定一个整数数组 nums，其中恰好有两个元素只出现一次，其余所有元素均出现两次。 找出只出现一次的那两个元素。你可以按 任意顺序 返回答案。

 

进阶：你的算法应该具有线性时间复杂度。你能否仅使用常数空间复杂度来实现？

 

示例 1：

输入：nums = [1,2,1,3,2,5]
输出：[3,5]
解释：[5, 3] 也是有效的答案。
示例 2：

输入：nums = [-1,0]
输出：[-1,0]
示例 3：

输入：nums = [0,1]
输出：[1,0]


*/

#include <vector>
#include <unordered_map>
#include <iostream>
#include <algorithm>
using namespace std;

//class Solution {
//public:
//    vector<int> singleNumber(vector<int>& nums) {
//        unordered_map<int, int> hash_map;
//        for (int index : nums)
//            ++hash_map[index];
//        nums.clear();
//        for (auto& index : hash_map)
//            if (index.second == 1)
//                nums.emplace_back(index.first);
//        return nums;
//    }
//};

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int signal = 0;
        for_each(begin(nums), end(nums), [&signal](int x) { signal ^= x; });
        signal = signal == INT_MIN ? signal : signal & -signal;
        int total = 0;
        int type1 = 0, type2 = 0;
        for (auto index : nums)
            index & signal ? type1 ^= index : type2 ^= index;
        return {type1, type2};
    }
};