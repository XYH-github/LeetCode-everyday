/*
给定两个整数，分别表示分数的分子 numerator 和分母 denominator，以 字符串形式返回小数 。

如果小数部分为循环小数，则将循环的部分括在括号内。

如果存在多个答案，只需返回 任意一个 。

对于所有给定的输入，保证 答案字符串的长度小于 104 。

 

示例 1：

输入：numerator = 1, denominator = 2
输出："0.5"
示例 2：

输入：numerator = 2, denominator = 1
输出："2"
示例 3：

输入：numerator = 2, denominator = 3
输出："0.(6)"
示例 4：

输入：numerator = 4, denominator = 333
输出："0.(012)"
示例 5：

输入：numerator = 1, denominator = 5
输出："0.2"

Solution temp;
    string result = temp.fractionToDecimal(-2147483648, 1);
    cout << result << endl;

*/

#include <string>
using namespace std;

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        int iter_count = 1;
        int zf_flag = 0;
        string result;
        if ((numerator > 0 && denominator < 0) || (numerator < 0 && denominator > 0)) {
            
            zf_flag = 1;
            ++iter_count;
        }
        numerator = abs(numerator);
        denominator = abs(denominator);
        long temp;
        if (numerator / denominator == 0) {
            result.push_back('0');
            ++iter_count;
        }
        else {
            temp = numerator / denominator;
            while (temp != 0) {
                result = char(temp % 10 + '0') + result;
                temp = temp / 10;
                ++iter_count;
            }
        }
        if (zf_flag == 1)
            result = '-' + result;
        if ((temp = numerator % denominator) == 0)
            return result;

        result.push_back('.');
        ++iter_count;
        while (iter_count < 1e+4) {
            temp *= 10;
            result.push_back(char( temp / denominator + '0'));
            ++iter_count;
            if ((temp = temp % denominator) == 0)
                break;
            if (JudgeLoop(result) == true)
                break;
        }
        return result;
    }

    bool JudgeLoop(string& str) {
        char LOOP_COUNT = 10;
        int length = str.size();
        int max_len = length / LOOP_COUNT;
        for (int i = 1; i <= max_len; ++i) {
            bool loop_flag = 1;
            for (int j = 1; j <= i; ++j) {
                for (int k = 1; k < LOOP_COUNT; ++k) {
                    if (str[length - j] != str[length - k * i - j]) {
                        loop_flag = 0;
                        break;
                    }
                }
                if (loop_flag == 0)
                    break;
            }
            if (loop_flag == 1) {
                str = str.substr(0, length - (LOOP_COUNT - 1) * i);
                str.insert(length - LOOP_COUNT * i, "(");
                str.push_back(')');
                return true;
            }
        }
        return false;
    }
};
