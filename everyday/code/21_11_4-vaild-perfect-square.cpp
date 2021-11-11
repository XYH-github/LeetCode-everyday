/*

给定一个 正整数 num ，编写一个函数，如果 num 是一个完全平方数，则返回 true ，否则返回 false 。

进阶：不要 使用任何内置的库函数，如  sqrt 。

 

示例 1：

输入：num = 16
输出：true
示例 2：

输入：num = 14
输出：false

链接：https://leetcode-cn.com/problems/valid-perfect-square

*/

//class Solution {
//public:
//    bool isPerfectSquare(int num) {
//        long x = 1, square = 1;
//        while (square <= num) {
//            if (square <= num)
//                return true;
//            ++x;
//            square = x * x;
//        }
//        return false;
//    }
//};

//class Solution {
//public:
//    bool isPerfectSquare(int num) {
//        int right = num, left = 0;
//        while (left <= right) {
//            int mid = (right - left) / 2 + left;
//            long squard = (long)mid * mid;
//            if (squard < num)
//                left = mid + 1;
//            else if (squard > num)
//                right = mid - 1;
//            else
//                return true;
//        }
//        return false;
//    }
//};

class Solution {
public:
    bool isPerfectSquare(int num) {
        double x0 = num;
        while (true) {
            double x1 = (x0 + num / x0) / 2;
            if (x0 - x1 < 1e-6)
                break;
            x0 = x1;
        }
        int x = (int)x0;
        return x * x == num;
    }
};