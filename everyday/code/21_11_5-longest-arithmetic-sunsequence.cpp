/*

给你一个整数数组 arr 和一个整数 difference，请你找出并返回 arr 中最长等差子序列的长度，该子序列中相邻元素之间的差等于 difference 。

子序列 是指在不改变其余元素顺序的情况下，通过删除一些元素或不删除任何元素而从 arr 派生出来的序列。

 

示例 1：

输入：arr = [1,2,3,4], difference = 1
输出：4
解释：最长的等差子序列是 [1,2,3,4]。
示例 2：

输入：arr = [1,3,5,7], difference = 1
输出：1
解释：最长的等差子序列是任意单个元素。
示例 3：

输入：arr = [1,5,7,8,5,3,4,2,1], difference = -2
输出：4
解释：最长的等差子序列是 [7,5,3,1]。

链接：https://leetcode-cn.com/problems/longest-arithmetic-subsequence-of-given-difference

[1,5,7,8,5,3,4,2,1]
-2

*/
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        int result = 1;
        int n = arr.size();
        vector<vector<int>> temp(n + 1, vector<int>(n, 1));
        for (int i = 0; i < n; ++i)
            temp[n][i] = i;
        for (int i = 1; i < n; ++i)
            for (int j = 0; j < i; ++j) 
                if (arr[i] - arr[temp[n][j]] == difference) {
                    temp[i][j] = temp[i - 1][j] + 1;
                    temp[n][j] = i;
                }
                else
                    temp[i][j] = temp[i - 1][j];
        for (int i = 0; i < n; ++i)
            result = max(result, temp[n - 1][i]);
        return result;
    }
};

//class Solution {
//public:
//	int longestSubsequence(vector<int>& arr, int difference) {
//		int result = 0;
//		unordered_map<int, int> temp;
//		for (int index : arr) {
//			temp[index] = temp[index - difference] + 1;
//			result = max(result, temp[index]);
//		}
//		return result;
//	}
//};