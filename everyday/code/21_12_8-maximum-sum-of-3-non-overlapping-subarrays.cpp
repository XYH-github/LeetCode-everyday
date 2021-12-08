/*

给你一个整数数组 nums 和一个整数 k ，找出三个长度为 k 、互不重叠、且 3 * k 项的和最大的子数组，并返回这三个子数组。

以下标的数组形式返回结果，数组中的每一项分别指示每个子数组的起始位置（下标从 0 开始）。如果有多个结果，返回字典序最小的一个。

 

示例 1：

输入：nums = [1,2,1,2,6,7,5,1], k = 2
输出：[0,3,5]
解释：子数组 [1, 2], [2, 6], [7, 5] 对应的起始下标为 [0, 3, 5]。
也可以取 [2, 1], 但是结果 [1, 3, 5] 在字典序上更大。
示例 2：

输入：nums = [1,2,1,2,1,2,1,2,1], k = 2
输出：[0,2,4]
 

提示：

1 <= nums.length <= 2 * 104
1 <= nums[i] < 216
1 <= k <= floor(nums.length / 3)

链接：https://leetcode-cn.com/problems/maximum-sum-of-3-non-overlapping-subarrays

vector<int> nums = {4, 3, 2, 1};
	int k = 1;
	Solution temp;
	vector<int> result = temp.maxSumOfThreeSubarrays(nums, k);
	Print<int>::PrintOneDemionVector(result);

*/
#include <vector>
#include <numeric>
using namespace std;


//class Solution {
//public:
//    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
//        vector<int> sum_arr(nums.size() - k + 1);
//        sum_arr[0] = accumulate(nums.begin(), nums.begin() + k, 0);
//        for (int i = 1; i < sum_arr.size(); ++i)
//            sum_arr[i] = sum_arr[i - 1] - nums[i - 1] + nums[i + k - 1];
//        vector<int> result;
//        int sum = 0;
//        for (int i = 0; i < sum_arr.size() - k * 2; ++i)
//            for (int j = i + k; j < sum_arr.size() - k; ++j)
//                for (int t = j + k; t < sum_arr.size(); ++t)
//                    if (sum < sum_arr[i] + sum_arr[j] + sum_arr[t]) {
//                        sum = sum_arr[i] + sum_arr[j] + sum_arr[t];
//                        result = {i, j, t};
//                    }
//        return result;
//    }
//};

//class Solution {
//public:
//	vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
//		int first_sum = 0, second_sum = 0, third_sum = 0;
//		int first_idx = 0, second_idx = k, second_sum_first_idx = 0;
//		int first_max = 0, second_max = 0, third_max = 0;
//		vector<int> result;
//		for (int i = 2 * k; i < nums.size(); ++i) {
//			first_sum += nums[i - 2 * k];
//			second_sum += nums[i - k];
//			third_sum += nums[i];
//			if (i >= 3 * k - 1) {
//				if (first_sum > first_max) {
//					first_max = first_sum;
//					first_idx = i - 3 * k + 1;
//				}
//				if (first_max + second_sum > second_max) {
//					second_max = first_max + second_sum;
//					second_sum_first_idx = first_idx;
//					second_idx = i - 2 * k + 1;
//				}
//				if (second_max + third_sum > third_max) {
//					result = { second_sum_first_idx, second_idx , i - k + 1 };
//					third_max = second_max + third_sum;
//				}
//				first_sum -= nums[i - k * 3 + 1];
//				second_sum -= nums[i - k * 2 + 1];
//				third_sum -= nums[i - k + 1];
//			}
//		}
//		return result;
//	}
//};

class Solution {
public:
	vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
		vector<vector<int>> dp(3, vector<int>(nums.size() - k + 1, 0));
		vector<int> sum_arr(nums.size() - k + 1);
		vector<int> result(3);
		sum_arr[0] = accumulate(nums.begin(), nums.begin() + k, 0);
		for (int i = 1; i < sum_arr.size(); ++i)
			sum_arr[i] = sum_arr[i - 1] - nums[i - 1] + nums[i + k - 1];
		int temp = 0;
		for (int i = 0; i < 3; ++i) {
			for (int j = i * k; j < nums.size() - k + 1; ++j) {
				if (i == 0)
					temp = sum_arr[j];
				else
					temp = dp[i - 1][j - k] + sum_arr[j];
				if (j == i * k)
					dp[i][j] = temp;
				else
					dp[i][j] = max(dp[i][j - 1], temp);
			}
		}
		int j = nums.size() - k;
		for (int i = 2; i >= 0; --i) {
			while (j != 0 && dp[i][j] == dp[i][j - 1])
				j--;
			result[i] = j;
			j = j - k;
		}
		return result;
	}
};