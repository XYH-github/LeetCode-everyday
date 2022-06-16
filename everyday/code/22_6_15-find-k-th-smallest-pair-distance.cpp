/*

数对 (a,b) 由整数 a 和 b 组成，其数对距离定义为 a 和 b 的绝对差值。

给你一个整数数组 nums 和一个整数 k ，数对由 nums[i] 和 nums[j] 组成且满足 0 <= i < j < nums.length 。返回 所有数对距离中 第 k 小的数对距离。

 

示例 1：

输入：nums = [1,3,1], k = 1
输出：0
解释：数对和对应的距离如下：
(1,3) -> 2
(1,1) -> 0
(3,1) -> 2
距离第 1 小的数对是 (1,1) ，距离为 0 。
示例 2：

输入：nums = [1,1,1], k = 2
输出：0
示例 3：

输入：nums = [1,6,1], k = 3
输出：5
 

提示：

n == nums.length
2 <= n <= 104
0 <= nums[i] <= 106
1 <= k <= n * (n - 1) / 2

链接：https://leetcode.cn/problems/find-k-th-smallest-pair-distance

    vector<int> nums = { 1, 1, 3 };
    int k = 1;
    Solution temp;
    int ret = temp.smallestDistancePair(nums, k);
    cout << ret << endl;

*/

#include <vector>
#include <algorithm>
using namespace std;

//class Solution {
//public:
//    int smallestDistancePair(vector<int>& nums, int k) {
//        int len = nums.size();
//        sort(nums.begin(), nums.end());
//        int left = 0;
//        int right = *max_element(nums.begin(), nums.end()) - *min_element(nums.begin(), nums.end());
//        while (left < right) {
//            int mid = left + ((right - left) >> 1);
//            int cnt = 0;
//            for (int i = 0; i < len - 1; ++i) {
//                int pos = upper_bound(nums.begin() + i, nums.end(), mid + nums[i]) - nums.begin();
//                cnt += pos - i - 1;
//            }
//            if (cnt >= k)
//                right = mid;
//            else
//                left = mid + 1;
//        }
//        return left;
//    }
//};



class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        int len = nums.size();
        sort(nums.begin(), nums.end());
        int left = 0;
        int right = *max_element(nums.begin(), nums.end()) - *min_element(nums.begin(), nums.end());
        while (left < right) {
            int mid = left + ((right - left) >> 1);
            int cnt = 0;
            int first = 0, second = 1;
            while (second < len) {
                while (nums[second] - nums[first] > mid && first <= second)
                    first++;
                cnt += second - first;
                second++;
            }
            if (cnt >= k)
                right = mid;
            else
                left = mid + 1;
        }
        return left;
    }
};