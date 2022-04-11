/*

给你一个整数 n ，统计并返回各位数字都不同的数字 x 的个数，其中 0 <= x < 10n 。
 

示例 1：

输入：n = 2
输出：91
解释：答案应为除去 11、22、33、44、55、66、77、88、99 外，在 0 ≤ x < 100 范围内的所有数字。
示例 2：

输入：n = 0
输出：1
 

提示：

0 <= n <= 8

链接：https://leetcode-cn.com/problems/count-numbers-with-unique-digits

    int n = 2;
    Solution temp;
    int ret = temp.countNumbersWithUniqueDigits(n);
    cout << ret << endl;

*/

//class Solution {
//public:
//    int countNumbersWithUniqueDigits(int n) {
//        int pre_pre = 1;
//        int pre = 10;
//        if (n == 0)
//            return pre_pre;
//        if (n == 1)
//            return pre;
//        int i = 2;
//        int ret;
//        while (i <= n) {
//            ret = pre + (pre - pre_pre) * (11 - i);
//            pre_pre = pre;
//            pre = ret;
//            i++;
//        }
//        return ret;
//    }
//};


class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if (n == 0)
            return 1;
        if (n == 1)
            return 10;
        int ret = 10;
        int cur = 9;
        for (int i = 0; i < n - 1; ++i) {
            cur *= 9 - i;
            ret += cur;
        }
        return ret;
    }
};