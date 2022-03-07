/*

将一个给定字符串 s 根据给定的行数 numRows ，以从上往下、从左到右进行 Z 字形排列。

比如输入字符串为 "PAYPALISHIRING" 行数为 3 时，排列如下：

P   A   H   N
A P L S I I G
Y   I   R
之后，你的输出需要从左往右逐行读取，产生出一个新的字符串，比如："PAHNAPLSIIGYIR"。

请你实现这个将字符串进行指定行数变换的函数：

string convert(string s, int numRows);
 

示例 1：

输入：s = "PAYPALISHIRING", numRows = 3
输出："PAHNAPLSIIGYIR"
示例 2：
输入：s = "PAYPALISHIRING", numRows = 4
输出："PINALSIGYAHRPI"
解释：
P     I    N
A   L S  I G
Y A   H R
P     I
示例 3：

输入：s = "A", numRows = 1
输出："A"
 

提示：

1 <= s.length <= 1000
s 由英文字母（小写和大写）、',' 和 '.' 组成
1 <= numRows <= 1000

链接：https://leetcode-cn.com/problems/zigzag-conversion

    string s = "PAYPALISHIRING";
    int numRows = 4;
    Solution temp;
    string ret = temp.convert(s, numRows);
    cout << ret << endl;

*/

#include <string>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        int len = s.size();
        if (numRows == 1)
            return s;
        string ret;
        int num = (numRows << 1) - 2;
        for (int i = 0; i < len; ++i)
            if (i % num == 0)
                ret.push_back(s[i]);
        for (int i = 1; i < numRows - 1; ++i)
            for (int j = i; j < len; ++j)
                if (j % num == i || j % num == num - i)
                    ret.push_back(s[j]);
        for (int i = numRows - 1; i < len; ++i)
            if (i % num == numRows - 1)
                ret.push_back(s[i]);
        return ret;
    }
};