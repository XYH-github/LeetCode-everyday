/*

给你一个字符串 s ，请你统计并返回这个字符串中 回文子串 的数目。

回文字符串 是正着读和倒过来读一样的字符串。

子字符串 是字符串中的由连续字符组成的一个序列。

具有不同开始位置或结束位置的子串，即使是由相同的字符组成，也会被视作不同的子串。

 

示例 1：

输入：s = "abc"
输出：3
解释：三个回文子串: "a", "b", "c"
示例 2：

输入：s = "aaa"
输出：6
解释：6个回文子串: "a", "a", "a", "aa", "aa", "aaa"
 

提示：

1 <= s.length <= 1000
s 由小写英文字母组成

链接：https://leetcode-cn.com/problems/palindromic-substrings

*/

#include <string>
#include <vector>
using namespace std;

//class Solution {
//public:
//    int countSubstrings(string s) {
//        int len = s.size();
//        int ret = 0;
//        for (int i = 0; i < 2 * len - 1; ++i) {
//            int left = i / 2, right = left + i % 2;
//            while (left >= 0 && right < len && s[left] == s[right])
//                --left, ++right, ret++;
//        }
//        return ret;
//    }
//};

class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        string t = "$#";
        for (const char& c : s) {
            t += c;
            t += '#';
        }
        n = t.size();
        t += '!';

        auto f = vector <int>(n);
        int iMax = 0, rMax = 0, ans = 0;
        for (int i = 1; i < n; ++i) {
            // 初始化 f[i]
            f[i] = (i <= rMax) ? min(rMax - i + 1, f[2 * iMax - i]) : 1;
            // 中心拓展
            while (t[i + f[i]] == t[i - f[i]]) ++f[i];
            // 动态维护 iMax 和 rMax
            if (i + f[i] - 1 > rMax) {
                iMax = i;
                rMax = i + f[i] - 1;
            }
            // 统计答案, 当前贡献为 (f[i] - 1) / 2 上取整
            ans += (f[i] / 2);
        }
        string ret;
        ret.insert('a', 0);

        return ans;
    }
};
