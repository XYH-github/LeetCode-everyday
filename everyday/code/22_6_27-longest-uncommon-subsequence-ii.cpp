/*

给定字符串列表 strs ，返回其中 最长的特殊序列 。如果最长特殊序列不存在，返回 -1 。

特殊序列 定义如下：该序列为某字符串 独有的子序列（即不能是其他字符串的子序列）。

 s 的 子序列可以通过删去字符串 s 中的某些字符实现。

例如，"abc" 是 "aebdc" 的子序列，因为您可以删除"aebdc"中的下划线字符来得到 "abc" 。"aebdc"的子序列还包括"aebdc"、 "aeb" 和 "" (空字符串)。
 

示例 1：

输入: strs = ["aba","cdc","eae"]
输出: 3
示例 2:

输入: strs = ["aaa","aaa","aa"]
输出: -1
 

提示:

2 <= strs.length <= 50
1 <= strs[i].length <= 10
strs[i] 只包含小写英文字母

链接：https://leetcode.cn/problems/longest-uncommon-subsequence-ii

    vector<string> strs = { "aba", "csc", "eae" };
    Solution temp;
    int ret = temp.findLUSlength(strs);
    cout << ret << endl;

*/

#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findLUSlength(vector<string>& strs) {
        sort(strs.begin(), strs.end(), [&](const string str1, const string str2) {
            return str1.size() > str2.size();
            });
        int len = strs.size();
        for (int i = 0; i < len; ++i) {
            int l = strs[i].size();
            bool check = true;
            int k = 0;
            while (k < len && strs[k].size() >= l) {
                if (k != i && cmp(strs[k], strs[i]))
                    check = false;
                ++k;
            }
            if (check)
                return l;
        }
        return -1;
    }

    bool cmp(string s, string p) {
        int len_s = s.size(), len_p = p.size();
        if (len_s < len_p)
            return false;
        int i_s = 0;
        while (i_s < len_s - len_p + 1) {
            int i_p = 0, pos = i_s;
            while (pos < len_s && i_p < len_p) {
                if (s[pos] ==  p[i_p])
                    i_p++;
                pos++;
            }
            if (i_p == len_p)
                return true;
            i_s++;
        }
        return false;
    }
};

