/*

给你一个整数 n ，按字典序返回范围 [1, n] 内所有整数。

你必须设计一个时间复杂度为 O(n) 且使用 O(1) 额外空间的算法。

 

示例 1：

输入：n = 13
输出：[1,10,11,12,13,2,3,4,5,6,7,8,9]
示例 2：

输入：n = 2
输出：[1,2]
 

提示：

1 <= n <= 5 * 104

链接：https://leetcode.cn/problems/lexicographical-numbers

    int n = 13;
    Solution temp;
    vector<int> ret = temp.lexicalOrder(n);
    Print<int>::PrintOneDemionVector(ret);

*/

#include <vector>
using namespace std;

//class Solution {
//public:
//    vector<int> ret;
//    vector<int> lexicalOrder(int n) {
//        dfs(1, n);
//        return ret;
//    }
//    void dfs(int index, int n) {
//        int end = index == 1 ? 9 : index + 9;
//        if (end >= n) {
//            for (int i = index; i <= n; ++i) {
//                ret.emplace_back(i);
//            }
//            return;
//        }
//        else {
//            for (int i = index; i <= end; ++i) {
//                ret.emplace_back(i);
//                dfs(i * 10, n);
//            }
//        }
//    }
//};


class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> ret(n);
        int number = 1;
        for (int i = 0; i < n; i++) {
            ret[i] = number;
            if (number * 10 <= n) {
                number *= 10;
            }
            else {
                while (number % 10 == 9 || number + 1 > n) {
                    number /= 10;
                }
                number++;
            }
        }
        return ret;
    }
};
