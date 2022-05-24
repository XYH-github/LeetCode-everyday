/*

给你一个长度为 n 的整数数组 nums ，返回使所有数组元素相等需要的最少移动数。

在一步操作中，你可以使数组中的一个元素加 1 或者减 1 。

 

示例 1：

输入：nums = [1,2,3]
输出：2
解释：
只需要两步操作（每步操作指南使一个元素加 1 或减 1）：
[1,2,3]  =>  [2,2,3]  =>  [2,2,2]
示例 2：

输入：nums = [1,10,2,9]
输出：16
 

提示：

n == nums.length
1 <= nums.length <= 105
-109 <= nums[i] <= 109

链接：https://leetcode.cn/problems/minimum-moves-to-equal-array-elements-ii

    vector<int> input_vec = {1, 10, 2, 9};
    Solution temp;
    int ret = temp.minMoves2(input_vec);
    cout << ret << endl;

*/

#include <vector>
#include <algorithm>
using namespace std;

//class Solution {
//public:
//    int minMoves2(vector<int>& nums) {
//        int len = nums.size();
//        sort(nums.begin(), nums.end());
//        int ret = 0;
//        int mid = nums[len / 2];
//        for (int num : nums) {
//            ret += abs(mid - num);
//        }
//        return ret;
//    }
//};


class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int len = nums.size();
        int ret = 0;
        int mid = getKthNums(nums, len / 2);
        for (int num : nums) {
            ret += abs(mid - num);
        }
        return ret;
    }

    void adjustHeap(vector<int>& nums, int father, int len) {
        int min = father;
        int left = father * 2 + 1;
        int right = father * 2 + 2;
        if (left < len && nums[left] < nums[min])
            min = left;
        if (right < len && nums[right] < nums[min])
            min = right;
        if (min != father) {
            swap(nums[min], nums[father]);
            adjustHeap(nums, min, len);
        }
    }

    void buildHeap(vector<int>& nums, int len) {
        for (int i = len / 2; i >= 0; --i) {
            adjustHeap(nums, i, len);
        }
    }

    int getKthNums(vector<int>& nums, int k) {
        int len = nums.size();
        buildHeap(nums, len);
        for (int i = 0; i < k; ++i) {
            swap(nums[0], nums[nums.size() - 1 - i]);
            --len;
            adjustHeap(nums, 0, len);
        }
        return nums[0];
    }
};