/*

给定一个整数 num，将其转化为 7 进制，并以字符串形式输出。

 

示例 1:

输入: num = 100
输出: "202"
示例 2:

输入: num = -7
输出: "-10"

链接：https://leetcode-cn.com/problems/base-7

    Solution temp;
    int num = -100;
    string ret = temp.convertToBase7(num);
    cout << ret << endl;

*/

#include <string>
using namespace std;

class Solution {
public:
    string convertToBase7(int num) {
        if (num == 0)
            return "0";
        string ret;
        bool flag = false;
        if (num < 0) {
            num = -num;
            flag = true;
        }
        while (num) {
            ret.push_back(num % 7 + '0');
            num /= 7;
        }
        reverse(ret.begin(), ret.end());
        if (flag)
            ret.insert(0, 1, '-');
        return ret;
    }
};