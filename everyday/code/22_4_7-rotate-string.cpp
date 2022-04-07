/*

给定两个字符串, s 和 goal。如果在若干次旋转操作之后，s 能变成 goal ，那么返回 true 。

s 的 旋转操作 就是将 s 最左边的字符移动到最右边。 

例如, 若 s = 'abcde'，在旋转一次之后结果就是'bcdea' 。
 

示例 1:

输入: s = "abcde", goal = "cdeab"
输出: true
示例 2:

输入: s = "abcde", goal = "abced"
输出: false
 

提示:

1 <= s.length, goal.length <= 100
s 和 goal 由小写英文字母组成

链接：https://leetcode-cn.com/problems/rotate-string

    string s = "abcde", goal = "cdeab";
    Solution temp;
    bool ret = temp.rotateString(s, goal);
    cout << ret << endl;

*/

#include <string>
using namespace std;

class Solution {
public:
    bool rotateString(string s, string goal) {
        int len_s = s.size();
        int len_g = goal.size();
        if (len_s != len_s)
            return false;
        for (int i = 1; i < len_s; ++i) {
            s = s.substr(1, len_s - 1) + s[0];
            if (s == goal)
                return true;
        }
        return false;
    }
};