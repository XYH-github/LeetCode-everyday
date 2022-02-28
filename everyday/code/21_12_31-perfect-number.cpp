/*

对于一个 正整数，如果它和除了它自身以外的所有 正因子 之和相等，我们称它为 「完美数」。

给定一个 整数 n， 如果是完美数，返回 true；否则返回 false。

 

示例 1：

输入：num = 28
输出：true
解释：28 = 1 + 2 + 4 + 7 + 14
1, 2, 4, 7, 和 14 是 28 的所有正因子。
示例 2：

输入：num = 7
输出：false
 

提示：

1 <= num <= 108

链接：https://leetcode-cn.com/problems/perfect-number

    int num = 28;
    Solution temp;
    bool ret = temp.checkPerfectNumber(num);
    cout << ret << endl;

*/

#include <cmath>

//class Solution {
//public:
//    bool checkPerfectNumber(int num) {
//        if (num == 1)
//            return false;
//        int temp = sqrt(num);
//        int now_num = num;
//        while (temp > 1) {
//            if (now_num < 1)
//                return false;
//            if (num % temp == 0) {
//                if (temp != num / temp)
//                    now_num -= num / temp;
//                now_num -= temp;
//            }
//            temp--;
//        }
//        if (now_num == 1)
//            return true;
//        return false;
//    }
//};


//class Solution {
//public:
//    bool checkPerfectNumber(int num) {
//        return num == 6 || num == 28 || num == 496 || num == 8128 || num == 33550336;
//    }
//};


class Solution {
public:
    bool checkPerfectNumber(int num) {
        if (num == 1) 
            return false;

        int sum = 1;
        for (int d = 2; d * d <= num; ++d) {
            if (num % d == 0) {
                sum += d;
                if (d * d < num) {
                    sum += num / d;
                }
            }
        }
        return sum == num;
    }
};
