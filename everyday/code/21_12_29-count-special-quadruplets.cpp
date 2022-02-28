/*

给你一个 下标从 0 开始 的整数数组 nums ，返回满足下述条件的 不同 四元组 (a, b, c, d) 的 数目 ：

nums[a] + nums[b] + nums[c] == nums[d] ，且
a < b < c < d
 

示例 1：

输入：nums = [1,2,3,6]
输出：1
解释：满足要求的唯一一个四元组是 (0, 1, 2, 3) 因为 1 + 2 + 3 == 6 。
示例 2：

输入：nums = [3,3,6,4,5]
输出：0
解释：[3,3,6,4,5] 中不存在满足要求的四元组。
示例 3：

输入：nums = [1,1,1,3,5]
输出：4
解释：满足要求的 4 个四元组如下：
- (0, 1, 2, 3): 1 + 1 + 1 == 3
- (0, 1, 3, 4): 1 + 1 + 3 == 5
- (0, 2, 3, 4): 1 + 1 + 3 == 5
- (1, 2, 3, 4): 1 + 1 + 3 == 5
 

提示：

4 <= nums.length <= 50
1 <= nums[i] <= 100

链接：https://leetcode-cn.com/problems/count-special-quadruplets

    vector<int> nums = { 1, 1, 1, 3, 5 };
    Solution temp;
    int ret = temp.countQuadruplets(nums);
    cout << ret << endl;

*/

#include <vector>
#include <unordered_map>
using namespace std;

//class Solution {
//public:
//    int countQuadruplets(vector<int>& nums) {
//        int ret = 0;
//        int len = nums.size();
//        for (int i = 0; i < len - 3; ++i)
//            for (int j = i + 1; j < len - 2; ++j)
//                for (int k = j + 1; k < len - 1; ++k)
//                    for (int d = k + 1; d < len; ++d)
//                        if (nums[d] == nums[i] + nums[j] + nums[k])
//                            ret++;
//        return ret;
//    }
//};


//class Solution {
//public:
//    int countQuadruplets(vector<int>& nums) {
//        int ret = 0;
//        int len = nums.size();
//        unordered_map<int, int> nums_map;
//        for (int k = len - 2; k >= 2; --k) {
//            nums_map[nums[k + 1]]++;
//            for (int i = 0; i < k - 1; ++i)
//                for (int j = i + 1; j < k; ++j)
//                    ret += nums_map[nums[i] + nums[j] + nums[k]];
//        }
//                    
//        return ret;
//    }
//};


class Solution {
public:
    int countQuadruplets(vector<int>& nums) {
        int ret = 0;
        int len = nums.size();
        unordered_map<int, int> nums_map;

        for (int j = len - 3; j >= 1; --j) {
            for (int d = len - 1; d > j + 1; --d)
                nums_map[nums[d] - nums[j + 1]]++;
            for (int i = 0; i < j; ++i)
                    ret += nums_map[nums[i] + nums[j]];
        }
        return ret;
    }
};