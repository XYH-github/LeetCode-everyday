/*

给定整数数组 nums 和整数 k，请返回数组中第 k 个最大的元素。

请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。

 

示例 1:

输入: [3,2,1,5,6,4] 和 k = 2
输出: 5
示例 2:

输入: [3,2,3,1,2,4,5,5,6] 和 k = 4
输出: 4
 

提示：

1 <= k <= nums.length <= 104
-104 <= nums[i] <= 104

链接：https://leetcode.cn/problems/kth-largest-element-in-an-array

    vector<int> input_vec = { 3, 2, 1, 5, 6, 4 };
    int k = 2;
    Solution temp;
    int ret = temp.findKthLargest(input_vec, k);
    cout << ret << endl;

*/

#include <vector>
#include "time.h"
using namespace std;

//class Solution {
//public:
//    int dfs(vector<int>& nums, int left, int right, int index) {
//        int temp = rand() % (right - left + 1) + left;
//        swap(nums[temp], nums[left]);
//        int cmp_num = nums[left];
//        int start = left;
//        int end = right;
//        while (start < end) {
//            while (start < end && nums[end] <= cmp_num)
//                end--;
//            nums[start] = nums[end];
//            while (start < end && nums[start] >= cmp_num)
//                start++;
//            nums[end] = nums[start];
//        }
//        nums[start] = cmp_num;
//        if (start == index)
//            return nums[start];
//        return start < index ? dfs(nums, start + 1, right, index) : dfs(nums, left, start - 1, index);
//    }
//
//
//    int findKthLargest(vector<int>& nums, int k) {
//        srand((unsigned)time(NULL));
//        return dfs(nums, 0, nums.size() - 1, k - 1);
//    }
//};


class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        _nums = nums;
        int len = _nums.size();
        buildHeap(len);
        int i = 1;
        while (--k) {
            swap(_nums[0], _nums[nums.size() - i++]);
            adjustHeap(0, --len);
        }
        return _nums[0];
    }

private:
    vector<int> _nums;

    void adjustHeap(int node, int len) {
        int left = 2 * node + 1;
        int right = 2 * node + 2;
        int max = node;
        if (left < len && _nums[left] > _nums[max])
            max = left;
        if (right < len && _nums[right] > _nums[max])
            max = right;
        if (max != node) {
            swap(_nums[node], _nums[max]);
            adjustHeap(max, len);
        }
    }

    void buildHeap(int len) {
        for (int i = len / 2; i >= 0; --i)
            adjustHeap(i, len);
    }
};