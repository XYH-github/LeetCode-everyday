﻿/*

n 位格雷码序列 是一个由 2n 个整数组成的序列，其中：
每个整数都在范围 [0, 2n - 1] 内（含 0 和 2n - 1）
第一个整数是 0
一个整数在序列中出现 不超过一次
每对 相邻 整数的二进制表示 恰好一位不同 ，且
第一个 和 最后一个 整数的二进制表示 恰好一位不同
给你一个整数 n ，返回任一有效的 n 位格雷码
- 11 和 10 有一位不同序列 。

 

示例 1：

输入：n = 2
输出：[0,1,3,2]
解释：
[0,1,3,2] 的二进制表示是 [00,01,11,10] 。
- 00 和 01 有一位不同
- 01 和 11 有一位不同
- 10 和 00 有一位不同
[0,2,3,1] 也是一个有效的格雷码序列，其二进制表示是 [00,10,11,01] 。
- 00 和 10 有一位不同
- 10 和 11 有一位不同
- 11 和 01 有一位不同
- 01 和 00 有一位不同
示例 2：

输入：n = 1
输出：[0,1]

链接：https://leetcode-cn.com/problems/gray-code

    int n = 2;
    Solution temp;
    vector<int> result = temp.grayCode(n);
    Print<int>::PrintOneDemionVector(result);

*/
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> gray_vector(1 << n, 0);
        for (int i = 1; i < gray_vector.size(); ++i) 
            gray_vector[i] = i ^ (i >> 1);
        return gray_vector;
    }
};

//class Solution {
//public:
//    vector<int> grayCode(int n) {
//        vector<int> ret;
//        ret.reserve(1 << n);
//        ret.push_back(0);
//        for (int i = 1; i <= n; i++) {
//            int m = ret.size();
//            for (int j = m - 1; j >= 0; j--) {
//                ret.push_back(ret[j] | (1 << (i - 1)));
//            }
//        }
//        return ret;
//    }
//};


