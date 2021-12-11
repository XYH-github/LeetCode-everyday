/*

给你一个整数 n ，请你在无限的整数序列 [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ...] 中找出并返回第 n 位上的数字。

 

示例 1：

输入：n = 3
输出：3
示例 2：

输入：n = 11
输出：0
解释：第 11 位数字在序列 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ... 里是 0 ，它是 10 的一部分。
 

提示：

1 <= n <= 231 - 1
第 n 位上的数字是按计数单位（digit）从前往后数的第 n 个数，参见 示例 2 。

链接：https://leetcode-cn.com/problems/nth-digit
int n = 3;
    Solution temp;
    int result = temp.findNthDigit(n);
    cout << result << endl;

*/
#include <math.h>

class Solution {
public:
    int findNthDigit(int n) {
        int digit_len = 1;
        int len_max = 9;
        int pre_max = 0;
        while (len_max < n) {
            pre_max = len_max;
            len_max += pow(10, digit_len) * 9 * (digit_len++ + 1);
        }
        n = n - pre_max;
        int iter_nums = 1;
        if (n % digit_len != 0)
            iter_nums = digit_len - n % digit_len + 1;
        n = (n - 1) / digit_len + pow(10, digit_len - 1);
        int result;
        while (iter_nums--) {
            result = n % 10;
            n /= 10;
        }
        return result;
    }
};