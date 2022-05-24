/*

给定一个整数 n ，返回 可表示为两个 n 位整数乘积的 最大回文整数 。因为答案可能非常大，所以返回它对 1337 取余 。

 

示例 1:

输入：n = 2
输出：987
解释：99 x 91 = 9009, 9009 % 1337 = 987
示例 2:

输入： n = 1
输出： 9

链接：https://leetcode.cn/problems/largest-palindrome-product

    Solution temp;
    int ret = temp.largestPalindrome(2);
    cout << ret << endl;

*/

#include <iostream>
#include <math.h>
using namespace std;

class Solution {
public:
    int largestPalindrome(int n) {
        if (n == 1)
            return 9;
        int now_a = pow(10, n) - 1;
        for (int left = now_a;; --left) {
            long long p = left;
            for (int x = left; x > 0; x /= 10) {
                p = p * 10 + x % 10;
            }
            for (long long x = now_a; x * x >= p; --x) {
                if (p % x == 0)
                    return p % 1337;
            }
        }
    }
};