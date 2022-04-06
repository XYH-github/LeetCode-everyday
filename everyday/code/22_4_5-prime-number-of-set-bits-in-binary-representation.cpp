/*

给你两个整数 left 和 right ，在闭区间 [left, right] 范围内，统计并返回 计算置位位数为质数 的整数个数。

计算置位位数 就是二进制表示中 1 的个数。

例如， 21 的二进制表示 10101 有 3 个计算置位。
 

示例 1：

输入：left = 6, right = 10
输出：4
解释：
6 -> 110 (2 个计算置位，2 是质数)
7 -> 111 (3 个计算置位，3 是质数)
9 -> 1001 (2 个计算置位，2 是质数)
10-> 1010 (2 个计算置位，2 是质数)
共计 4 个计算置位为质数的数字。
示例 2：

输入：left = 10, right = 15
输出：5
解释：
10 -> 1010 (2 个计算置位, 2 是质数)
11 -> 1011 (3 个计算置位, 3 是质数)
12 -> 1100 (2 个计算置位, 2 是质数)
13 -> 1101 (3 个计算置位, 3 是质数)
14 -> 1110 (3 个计算置位, 3 是质数)
15 -> 1111 (4 个计算置位, 4 不是质数)
共计 5 个计算置位为质数的数字。
 

提示：

1 <= left <= right <= 106
0 <= right - left <= 104
通过次数48,915提交次数64,594

链接：https://leetcode-cn.com/problems/prime-number-of-set-bits-in-binary-representation

    int left = 6, right = 10;
    Solution temp;
    int ret = temp.countPrimeSetBits(left, right);
    cout << ret << endl;

*/

#define __builtin_popcount __popcnt
//
//class Solution {
//public:
//    int countPrimeSetBits(int left, int right) {
//        int ret = 0;
//        for (int i = left; i <= right; ++i) {
//            int nums = 0;
//            int temp = i;
//            while (temp) {
//                nums += temp & 1;
//                temp >>= 1;
//            }
//            if (check(nums))
//                ret++;
//        }
//        return ret;
//    }
//
//    bool check(int num) {
//        if (num < 2)
//            return false;
//        int i = 2;
//        while (i * i <= num) {
//            if (num % i == 0)
//                return false;
//            i++;
//        }
//        return true;
//    }
//};


class Solution {
public:
    // 2 3 5 7 11 13 17 19 23
    int countPrimeSetBits(int left, int right) {
        int ret = 0;
        for (int i = left; i <= right; ++i) {
            if ((1 << __builtin_popcount(i)) & 0xa28ac) {
                ++ret;
            }
        }
        return ret;
    }

};