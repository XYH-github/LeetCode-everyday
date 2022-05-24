/*

给你一个二维矩阵 matrix 和一个整数 k ，矩阵大小为 m x n 由非负整数组成。

矩阵中坐标 (a, b) 的 值 可由对所有满足 0 <= i <= a < m 且 0 <= j <= b < n 的元素 matrix[i][j]（下标从 0 开始计数）执行异或运算得到。

请你找出 matrix 的所有坐标中第 k 大的值（k 的值从 1 开始计数）。

 

示例 1：

输入：matrix = [[5,2],[1,6]], k = 1
输出：7
解释：坐标 (0,1) 的值是 5 XOR 2 = 7 ，为最大的值。
示例 2：

输入：matrix = [[5,2],[1,6]], k = 2
输出：5
解释：坐标 (0,0) 的值是 5 = 5 ，为第 2 大的值。
示例 3：

输入：matrix = [[5,2],[1,6]], k = 3
输出：4
解释：坐标 (1,0) 的值是 5 XOR 1 = 4 ，为第 3 大的值。
示例 4：

输入：matrix = [[5,2],[1,6]], k = 4
输出：0
解释：坐标 (1,1) 的值是 5 XOR 2 XOR 1 XOR 6 = 0 ，为第 4 大的值。
 

提示：

m == matrix.length
n == matrix[i].length
1 <= m, n <= 1000
0 <= matrix[i][j] <= 106
1 <= k <= m * n

链接：https://leetcode.cn/problems/find-kth-largest-xor-coordinate-value

    vector<vector<int>> matrix = { {10, 9, 5},{2, 0, 4}, {1, 0, 9}, {3, 4, 8} };
    int k = 10;
    Solution temp;
    int ret = temp.kthLargestValue(matrix, k);
    cout << ret << endl;

*/

#include <vector>
#include <time.h>
#include <algorithm>
using namespace std;

//class Solution {
//public:
//    int kthLargestValue(vector<vector<int>>& matrix, int k) {
//        int m = matrix.size();
//        int n = matrix[0].size();
//        vector<int> prio_vec;
//        vector<vector<int>> pri_sum(m + 1, vector<int>(n + 1));
//        for (int i = 1; i < m + 1; ++i) {
//            for (int j = 1; j < n + 1; ++j) {
//                pri_sum[i][j] = pri_sum[i - 1][j] ^ pri_sum[i][j - 1] ^ pri_sum[i - 1][j - 1] ^ matrix[i - 1][j - 1];
//                prio_vec.emplace_back(pri_sum[i][j]);
//            }
//        }
//        //nth_element(prio_vec.begin(), prio_vec.begin() + k - 1, prio_vec.end(), greater<int>());
//        //return prio_vec[k - 1];
//        return getNthMax(prio_vec, k);
//    }
//
//    void adjustHeap(vector<int>& nums, int father, int len) {
//        int max = father;
//        int left = 2 * father + 1;
//        int right = 2 * father + 2;
//        if (left < len && nums[left] > nums[max])
//            max = left;
//        if (right < len && nums[right] > nums[max])
//            max = right;
//        if (max != father) {
//            swap(nums[max], nums[father]);
//            adjustHeap(nums, max, len);
//        }
//    }
//
//    void buildHeap(vector<int>& nums) {
//        int len = nums.size();
//        for (int i = len / 2; i >= 0; --i) {
//            adjustHeap(nums, i, len);
//        }
//    }
//
//    int getNthMax(vector<int>& nums, int k) {
//        int len = nums.size();
//        buildHeap(nums);
//        for (int i = 0; i < k - 1; ++i) {
//            swap(nums[0], nums[nums.size() - i - 1]);
//            --len;
//            adjustHeap(nums, 0, len);
//        }
//        return nums[0];
//    }
//};


class Solution {
public:
    int kthLargestValue(vector<vector<int>>& matrix, int k) {
        srand((unsigned)time(NULL));
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> prio_vec;
        vector<vector<int>> pri_sum(m + 1, vector<int>(n + 1));
        for (int i = 1; i < m + 1; ++i) {
            for (int j = 1; j < n + 1; ++j) {
                pri_sum[i][j] = pri_sum[i - 1][j] ^ pri_sum[i][j - 1] ^ pri_sum[i - 1][j - 1] ^ matrix[i - 1][j - 1];
                prio_vec.emplace_back(pri_sum[i][j]);
            }
        }
        //nth_element(prio_vec.begin(), prio_vec.begin() + k - 1, prio_vec.end(), greater<int>());
        //return prio_vec[k - 1];
        return getNthMax(prio_vec, 0, prio_vec.size() - 1, k - 1);
    }

    int getNthMax(vector<int>& nums, int start, int end, int k) {
        int index = rand() % (end - start + 1) + start;
        swap(nums[index], nums[start]);
        int cmp_nums = nums[start];
        int left = start;
        int right = end;
        while (left < right) {
            while (left < right && nums[right] <= cmp_nums)
                right--;
            nums[left] = nums[right];
            while (left < right && nums[left] >= cmp_nums)
                left++;
            nums[right] = nums[left];
        }
        nums[left] = cmp_nums;
        if (left == k)
            return nums[left];
        else
            return left < k ? getNthMax(nums, left + 1, end, k) : getNthMax(nums, start, left - 1, k);
    }
};