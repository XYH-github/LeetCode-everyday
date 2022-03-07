/*

给定一个非负整数 num，反复将各个位上的数字相加，直到结果为一位数。返回这个结果。

 

示例 1:

输入: num = 38
输出: 2
解释: 各位相加的过程为：
38 --> 3 + 8 --> 11
11 --> 1 + 1 --> 2
由于 2 是一位数，所以返回 2。
示例 1:

输入: num = 0
输出: 0
 

提示：

0 <= num <= 231 - 1

链接：https://leetcode-cn.com/problems/add-digits

    int num = 38;
    Solution temp;
    int ret = temp.addDigits(num);
    cout << ret << endl;

*/

class Solution {
public:
    int addDigits(int num) {
        if (num / 10 == 0)
            return num;
        int ret = 0;
        while (num) {
            ret += num % 10;
            num /= 10;
        }
        return addDigits(ret);
    }
};


//class Solution {
//public:
//    int addDigits(int num) {
//        while (num / 10) {
//            int ret = 0;
//            while (num) {
//                ret += num % 10;
//                num /= 10;
//            }
//            num = ret;
//        }
//        return num;
//    }
//};