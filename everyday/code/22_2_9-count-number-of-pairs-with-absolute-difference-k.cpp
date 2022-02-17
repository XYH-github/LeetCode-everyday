/*

给你一个整数数组 nums 和一个整数 k ，请你返回数对 (i, j) 的数目，满足 i < j 且 |nums[i] - nums[j]| == k 。

|x| 的值定义为：

如果 x >= 0 ，那么值为 x 。
如果 x < 0 ，那么值为 -x 。
 

示例 1：

输入：nums = [1,2,2,1], k = 1
输出：4
解释：差的绝对值为 1 的数对为：
- [1,2,2,1]
- [1,2,2,1]
- [1,2,2,1]
- [1,2,2,1]
示例 2：

输入：nums = [1,3], k = 3
输出：0
解释：没有任何数对差的绝对值为 3 。
示例 3：

输入：nums = [3,2,1,5,4], k = 2
输出：3
解释：差的绝对值为 2 的数对为：
- [3,2,1,5,4]
- [3,2,1,5,4]
- [3,2,1,5,4]

链接：https://leetcode-cn.com/problems/count-number-of-pairs-with-absolute-difference-k

    vector<int> nums = { 3, 2, 1, 5, 4};
    int k = 2;
    Solution temp;
    int ret = temp.countKDifference(nums, k);
    cout << ret << endl;

*/
#include <vector>
using namespace std;

//class Solution {
//public:
//    int countKDifference(vector<int>& nums, int k) {
//        int ret = 0;
//        for (int i = 0; i < nums.size() - 1; ++i)
//            for (int j = i + 1; j < nums.size(); ++j)
//                if (nums[j] - nums[i] == k || nums[i] - nums[j] == k)
//                    ++ret;
//        return ret;
//    }
//};

class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        int ret = 0;
        vector<int> count(101);
        for (int index : nums) {
            if (index - k > 0)
                ret += count[index - k];
            if (index + k <= 100)
                ret += count[index + k];
            count[index]++;
        }
        return ret;
    }
};