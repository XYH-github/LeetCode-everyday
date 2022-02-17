/*

给你一个整数数组 nums 和一个整数 k ，判断数组中是否存在两个 不同的索引 i 和 j ，满足 nums[i] == nums[j] 且 abs(i - j) <= k 。如果存在，返回 true ；否则，返回 false 。

 

示例 1：

输入：nums = [1,2,3,1], k = 3
输出：true
示例 2：

输入：nums = [1,0,1,1], k = 1
输出：true
示例 3：

输入：nums = [1,2,3,1,2,3], k = 2
输出：false
 

 

提示：

1 <= nums.length <= 105
-109 <= nums[i] <= 109
0 <= k <= 105

链接：https://leetcode-cn.com/problems/contains-duplicate-ii

	vector<int> nums = { 1, 2, 3, 1 };
	int k = 3;
	Solution temp;
	bool result = temp.containsNearbyDuplicate(nums, k);
	cout << result << endl;

*/

#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

//class Solution {
//public:
//    bool containsNearbyDuplicate(vector<int>& nums, int k) {
//        unordered_map<int, int> repeat_map;
//        for (int i = 0; i < nums.size(); ++i)
//            if (repeat_map.count(nums[i]) && i - repeat_map[nums[i]] <= k)
//                return true;
//            else
//                repeat_map[nums[i]] = i;
//        return false;
//    }
//};
class Solution {
public:
	bool containsNearbyDuplicate(vector<int>& nums, int k)  {
		unordered_set<int> repeat_set;
		for (int i = 0; i < nums.size(); ++i) {
			if (i > k)
				repeat_set.erase(nums[i - k - 1]);
			if (repeat_set.count(nums[i]))
				return true;
			else
				repeat_set.emplace(nums[i]);
		}
		return false;
	}
};