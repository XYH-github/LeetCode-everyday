/*
 
 
给你一个正整数数组 arr ，请你计算所有可能的奇数长度子数组的和。

子数组 定义为原数组中的一个连续子序列。

请你返回 arr 中 所有奇数长度子数组的和 。

 

示例 1：

输入：arr = [1,4,2,5,3]
输出：58
解释：所有奇数长度子数组和它们的和为：
[1] = 1
[4] = 4
[2] = 2
[5] = 5
[3] = 3
[1,4,2] = 7
[4,2,5] = 11
[2,5,3] = 10
[1,4,2,5,3] = 15
我们将所有值求和得到 1 + 4 + 2 + 5 + 3 + 7 + 11 + 10 + 15 = 58
示例 2：

输入：arr = [1,2]
输出：3
解释：总共只有 2 个长度为奇数的子数组，[1] 和 [2]。它们的和为 3 。
示例 3：

输入：arr = [10,11,12]
输出：66
 

提示：

1 <= arr.length <= 100
1 <= arr[i] <= 1000
 

链接：https://leetcode.cn/problems/sum-of-all-odd-length-subarrays


    vector<int> nums = { 1, 4, 2, 5, 3 };
    Solution temp;
    int result = temp.sumOddLengthSubarrays(nums);
    cout << result << endl;


*/

#include <vector>
#include <numeric>
#include "Print.h"

using namespace std;


//class Solution {
//public:
//    vector<vector<int>> subarrays;
//
//    int sumOddLengthSubarrays(vector<int>& arr) {
//        int all_count = 0;
//        getAllLinearSubarrays(arr, subarrays);
//        Print<int>::PrintTwoDemionVector(subarrays);
//        for (vector<int> arr_temp : subarrays) {
//            if (arr_temp.size() % 2 == 1)
//                all_count += accumulate(arr_temp.begin(), arr_temp.end(), 0);
//        }
//        return all_count;
//    }
//
//    void getAllSubarrays(vector<int> arr, vector<vector<int>>& arrays) {
//        for (int i = 0; i < arr.size(); ++i) {
//            int temp = arrays.size();
//            arrays.push_back(vector<int>(1, arr[i]));
//            for (int j = 0; j < temp; ++j) {
//                arrays.push_back(arrays[j]);
//                arrays[j].push_back(arr[i]);
//            }
//        }
//    }
//
//    void getAllLinearSubarrays(vector<int> arr, vector<vector<int>>& arrays) {
//        int index = 0;
//        for (int i = 0; i < arr.size(); ++i) {
//            int temp = arrays.size();
//            for (int j = index; j < temp; ++j) {
//                arrays.push_back(arrays[j]);
//                arrays[arrays.size() - 1].push_back(arr[i]);
//            }
//            index = temp;
//            arrays.push_back(vector<int>(1, arr[i]));
//        }
//    }
//};


/*
* 利用开始和结束的下标，只维护一个和sum
* 时间 n3
* 空间 o1
class Solution {

public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int sum = 0;
        int n = arr.size();
        for (int start = 0; start < n; ++start) {
            for (int length = 1; start + length <= n; length += 2) {
                int end = start + length - 1;
                for (int i = start; i <= end; i++) {
                    sum += arr[i];
                }
            }
        }
        return sum;
    }

};

*/


/* 提前维护一个前N个数的和
* 时间 n2
* 空间 o1

class Solution {
public:

    int sumOddLengthSubarrays(vector<int>& arr) {
        int n = arr.size();
        vector<int> prefixSums(n + 1);
        for (int i = 0; i < n; ++i) {
            prefixSums[i + 1] = prefixSums[i] + arr[i];
        }
        int sum = 0;
        for (int start = 0; start < n; ++start) {
            for (int j = 1; start + j <= n; j += 2) 
                sum += prefixSums[start + j] - prefixSums[start];
        }
        return sum;
    }

};


*/

/*以每个数字出现在奇数子序列的次数为切入点，分别得到每个元素的左边数字个数
*  和右边数字个数，个数同为奇数或偶数时出现次数+1.
* 时间 n1
* 空间 o1

class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int sum = 0;
        int n = arr.size();
        for (int i = 0; i < n; ++i) {
            int leftCount = i, rightCount = n - i - 1;
            int leftOdd = (leftCount + 1) / 2;
            int rightOdd = (rightCount + 1) / 2;
            int leftEven = leftCount / 2 + 1;
            int rightEven = rightCount / 2 + 1;
            sum += arr[i] * (leftOdd * rightOdd + leftEven * rightEven);
        }
        return sum;
    }

};

*/