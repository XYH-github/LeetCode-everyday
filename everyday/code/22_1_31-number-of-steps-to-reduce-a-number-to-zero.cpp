/*

给你一个非负整数 num ，请你返回将它变成 0 所需要的步数。 如果当前数字是偶数，你需要把它除以 2 ；否则，减去 1 。

 

示例 1：

输入：num = 14
输出：6
解释：
步骤 1) 14 是偶数，除以 2 得到 7 。
步骤 2） 7 是奇数，减 1 得到 6 。
步骤 3） 6 是偶数，除以 2 得到 3 。
步骤 4） 3 是奇数，减 1 得到 2 。
步骤 5） 2 是偶数，除以 2 得到 1 。
步骤 6） 1 是奇数，减 1 得到 0 。
示例 2：

输入：num = 8
输出：4
解释：
步骤 1） 8 是偶数，除以 2 得到 4 。
步骤 2） 4 是偶数，除以 2 得到 2 。
步骤 3） 2 是偶数，除以 2 得到 1 。
步骤 4） 1 是奇数，减 1 得到 0 。
示例 3：

输入：num = 123
输出：12
 

提示：

0 <= num <= 10^6

链接：https://leetcode-cn.com/problems/number-of-steps-to-reduce-a-number-to-zero

    int num = 8;
    Solution temp;
    int result = temp.numberOfSteps(num);
    cout << result << endl;

*/

//class Solution {
//public:
//    int numberOfSteps(int num) {
//        int ret = 0;
//        while (num) {
//            ret += 1;
//            if (num % 2)
//                num -= 1;
//            else
//                num >>= 1;
//        }
//        return ret;
//    }
//};

//class Solution {
//public:
//    int numberOfSteps(int num) {
//        int ret = 0;
//        if (num == 0)
//            return ret;
//        while (num != 1) {
//            if (num & 1)
//                ret++;
//            num >>= 1;
//            ret++;
//        }
//        return ret + 1;
//    }
//};

class Solution {
public:
    int numberOfSteps(int num) {
        if (num == 0)
            return 0;
        return 32 - length(num) - 1 + count(num);
    }

    int length(int num) {
        int ret = 0;
        if (num >> 16 == 0) {
            ret += 16;
            num <<= 16;
        }
        if (num >> 24 == 0) {
            ret += 8;
            num <<= 8;
        }
        if (num >> 28 == 0) {
            ret += 4;
            num <<= 4;
        }
        if (num >> 30 == 0) {
            ret += 2;
            num <<= 2;
        }
        if (num >> 31 == 0) {
            ret += 1;
        }
        return ret;
    }

    int count(int num) {
        num = (num & 0x55555555) + ((num >> 1) & 0x55555555);
        num = (num & 0x33333333) + ((num >> 2) & 0x33333333);
        num = (num & 0x0f0f0f0f) + ((num >> 4) & 0x0f0f0f0f);
        num = (num & 0x00ff00ff) + ((num >> 8) & 0x00ff00ff);
        num = (num & 0x0000ffff) + ((num >> 16) & 0x0000ffff);
        return num;
    }
};