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
using namespace std;

//class Solution {
//public:
//    int dfs(vector<int>& nums, int left, int right, int index) {
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
//        return dfs(nums, 0, nums.size() - 1, k - 1);
//    }
//};


class Solution {
public:
    void adjust_heap(vector<int>& nums, int father, int len) {
        int left = 2 * father + 1;
        int right = 2 * father + 2;
        int max = father;
        if (left < len && nums[left] > nums[max])
            max = left;
        if (right < len && nums[right] > nums[max])
            max = right;
        if (max != father) {
            swap(nums[father], nums[max]);
            adjust_heap(nums, max, len);
        }
    }

    void buildMaxHeap(vector<int>& nums, int len) {
        for (int i = len / 2; i >= 0; --i) {
            adjust_heap(nums, i, len);
        }
    }


    int findKthLargest(vector<int>& nums, int k) {
        int len = nums.size();
        buildMaxHeap(nums, len);
        for (int i = 0; i < k; ++i) {
            swap(nums[0], nums[nums.size() - 1 - i]);
            --len;
            adjust_heap(nums, 0, len);
        }
        return nums[0];
    }
};