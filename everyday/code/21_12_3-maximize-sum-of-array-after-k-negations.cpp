/*

给你一个整数数组 nums 和一个整数 k ，按以下方法修改该数组：

选择某个下标 i 并将 nums[i] 替换为 -nums[i] 。
重复这个过程恰好 k 次。可以多次选择同一个下标 i 。

以这种方式修改数组后，返回数组 可能的最大和 。

 

示例 1：

输入：nums = [4,2,3], k = 1
输出：5
解释：选择下标 1 ，nums 变为 [4,-2,3] 。
示例 2：

输入：nums = [3,-1,0,2], k = 3
输出：6
解释：选择下标 (1, 2, 2) ，nums 变为 [3,1,0,2] 。
示例 3：

输入：nums = [2,-3,-1,5,-4], k = 2
输出：13
解释：选择下标 (1, 4) ，nums 变为 [2,3,-1,5,4] 。
 

提示：

1 <= nums.length <= 104
-100 <= nums[i] <= 100
1 <= k <= 104

链接：https://leetcode-cn.com/problems/maximize-sum-of-array-after-k-negations

vector<int> nums = { -8, 3, -5, -3, -5, -2 };
	int k = 6;
	Solution temp;
	int result = temp.largestSumAfterKNegations(nums, k);
	cout << result << endl;

*/
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <numeric>
#include <queue>
using namespace std;

//class Solution {
//public:
//    int largestSumAfterKNegations(vector<int>& nums, int k) {
//        sort(nums.begin(), nums.end(), less<int>());
//        int length = nums.size();
//        int result = 0;
//        int poi = 0;
//        while (nums[poi] < 0 && poi < length && k-- > 0)
//            result -= nums[poi++];
//        if (k % 2 == 1 && poi == 0)
//            nums[poi] = -nums[poi];
//        if (k % 2 == 1 && poi == length)
//            result += nums[poi - 1] + nums[poi - 1];
//        if (k % 2 == 1 && poi != 0 && poi != length)
//            if (-nums[poi - 1] >= nums[poi])
//                nums[poi] = -nums[poi];
//            else
//                result += nums[poi - 1] + nums[poi - 1];
//        while (poi < length)
//            result += nums[poi++];
//        return result;
//    }
//};

//class Solution {
//public:
//	int largestSumAfterKNegations(vector<int>& nums, int k) {
//		unordered_map<int, int> freq;
//		for (int num : nums)
//			freq[num] += 1;
//		int ans = accumulate(nums.begin(), nums.end(), 0);
//		for (int i = -100; i < 0; ++i) {
//			if (freq[i]) {
//				int ops = min(k, freq[i]);
//				ans += (-i) * ops * 2;
//				freq[i] -= ops;
//				freq[-i] += ops;
//				k -= ops;
//				if (k == 0)
//					break;
//			}
//		}
//		if (k > 0 && k % 2 == 1 && !freq[0])
//			for (int i = 1; i <= 100; ++i)
//				if (freq[i]) {
//					ans -= i * 2;
//					break;
//				}
//		return ans;
//	}
//};

class Solution {
public:
	int largestSumAfterKNegations(vector<int>& nums, int k) {
		priority_queue<int, vector<int>, greater<int>> queue;
		int result = 0;
		for (int index : nums) {
			queue.push(index);
			result += index;
		}
		while (k--) {
			int num = queue.top();
			queue.pop();
			result -= num * 2;
			queue.push(-num);
		}
		return result;
	}
};