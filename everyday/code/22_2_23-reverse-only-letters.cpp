/*

给你一个字符串 s ，根据下述规则反转字符串：

所有非英文字母保留在原有位置。
所有英文字母（小写或大写）位置反转。
返回反转后的 s 。

 

示例 1：

输入：s = "ab-cd"
输出："dc-ba"
示例 2：

输入：s = "a-bC-dEf-ghIj"
输出："j-Ih-gfE-dCba"
示例 3：

输入：s = "Test1ng-Leet=code-Q!"
输出："Qedo1ct-eeLg=ntse-T!"
 

提示

1 <= s.length <= 100
s 仅由 ASCII 值在范围 [33, 122] 的字符组成
s 不含 '\"' 或 '\\'

链接：https://leetcode-cn.com/problems/reverse-only-letters

    string s = "Test1ng-Leet=code-Q!";
    Solution temp;
    string ret = temp.reverseOnlyLetters(s);
    cout << ret << endl;

*/

#include <string>
using namespace std;

class Solution {
public:
    string reverseOnlyLetters(string s) {
        int len = s.size();
        char temp;
        for (int i = 0, j = len - 1; i < j;) {
            if (isalpha(s[i]) && isalpha(s[j])) {
                temp = s[i], s[i] = s[j], s[j] = temp;
                ++i, --j;
                continue;
            }
            if (!isalpha(s[i]) )
                ++i;
            if (!isalpha(s[j]))
                --j;
        }
        return s;
    }
};