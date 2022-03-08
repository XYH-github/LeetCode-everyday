/*

给定一个 正整数 num ，编写一个函数，如果 num 是一个完全平方数，则返回 true ，否则返回 false 。

进阶：不要 使用任何内置的库函数，如  sqrt 。

 

示例 1：

输入：num = 16
输出：true
示例 2：

输入：num = 14
输出：false
 

提示：

1 <= num <= 2^31 - 1

链接：https://leetcode-cn.com/problems/valid-perfect-square

    int num = 16;
    Solution temp;
    bool ret = temp.isPerfectSquare(num);
    cout << ret << endl;

*/


class Solution {
public:
    bool isPerfectSquare(int num) {
        double x = num;
        double x1;
        while (true) {
            x1 = (num / x + x) / 2;
            if (x - x1 < 1e-9)
                break;
            x = x1;
        }
        x = int(x);
        return x * x == num;
    }
};